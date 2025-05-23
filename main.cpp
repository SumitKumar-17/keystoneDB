#include <iostream>

#include "sql/parser_result.h"
#include "rocksdb/db.h"
#include "fort.hpp"
#include "version.h"
#include <csignal>
#include "common/codec/db.pb.h"
#include "execution/executor.h"
#include "linenoise.h"
#include <gflags/gflags.h>
#include <fstream>

DEFINE_bool(disable_line_editing, false, "specify this flag if you want to disable line editing(e.g., in docker)");
DEFINE_string(filepath, "", "path for the *.sql file");

int wrapped_parse(const char *text, keystoneDB::ParserResult *result);


void read_loop();

const auto welcome = "Welcome to the keystoneDB. keystoneDB is a relational DBMS built on RocksDB.";
// const auto copyright = "Copyright (c) 2025-present Sumit Kumar All rights reserved.";
// const auto author = "Written by Sumit Kumar <https://github.com/SumitKumar-17>.";
const auto license = "Source code git repository: <https://github.com/SumitKumar-17/keystoneDB>.";
const auto website = "The website for the Architecture and the Demos of the Database is <https://sumitkumar-17.github.io/keystoneDB>.";

void printInfo() {
    std::cout << welcome << std::endl;

    std::cout << "keystoneDB VERSION: v" << KEYSTONEDB_MAJOR << "." << KEYSTONEDB_MINOR << "." << KEYSTONEDB_PATCH << std::endl << std::endl;

    // std::cout << copyright << std::endl;
    // std::cout << author << std::endl;
    std::cout << website << std::endl;
    std::cout << license << std::endl;
    std::cout << std::endl;
}


void setup_signal() {
}

bool getLine(bool debug, std::string &s, const std::string &prompt) {
    if (debug) {
        std::cout << prompt;
        std::getline(std::cin, s);
    } else {
        char *query_c_str = linenoise(prompt.c_str());
        if (query_c_str == nullptr) return false;
        s = query_c_str;
        linenoiseFree(query_c_str);
    }
    return true;
}

void read_loop() {
    keystoneDB::Executor executor;
    executor.init();
    if (FLAGS_filepath.empty()) {
        std::string pending_query, pending_no_blank_query;
        int count = 0;
        bool firstline = true;
        linenoiseSetMultiLine(1);
        linenoiseHistorySetMaxLen(1024);
        while (true) {
            auto prompt = firstline ? "keystoneDB> " : "   -> ";
            std::string q;
            if (!getLine(FLAGS_disable_line_editing, q, prompt)) {
                pending_no_blank_query.clear();
                pending_query.clear();
                count = 0;
                firstline = true;
                continue;
            }
            std::string final_query;
            std::string final_no_blank_query;

            for (unsigned int i = 0; i < q.length(); i++) {
                pending_query.append(std::string(1, q[i]));
                pending_no_blank_query.append(std::string(1, q[i]));
                if (q[i] == ';' && count % 2 == 0) {
                    final_query += pending_query;
                    final_no_blank_query += pending_no_blank_query;
                    pending_query.clear();
                    pending_no_blank_query.clear();
                }
                if (q[i] == '\'') {
                    count++;
                }
            }
            if (!pending_query.empty()) {
                firstline = false;
            } else {
                firstline = true;
            }
            pending_query.append(" ");
            pending_no_blank_query.append("\n");
            if (final_query.empty()) {
                continue;
            }
            const auto result = new keystoneDB::ParserResult();
            linenoiseHistoryAdd(final_query.c_str());

            wrapped_parse(final_no_blank_query.c_str(), result);
            if (!executor.execute(result)) {
                break;
            }
            // TODO: delete result
        }
    } else {
        std::ifstream ifstream(FLAGS_filepath);
        if (!ifstream.is_open()) {
            std::cout << "Can not open file " << FLAGS_filepath << std::endl;
            executor.shutdown();
            return;
        }
        std::string line, lines;
        while (std::getline(ifstream, line)) {
            lines += line + "\n";
        }
        ifstream.close();
        const auto result = new keystoneDB::ParserResult();
        wrapped_parse(lines.c_str(), result);
        executor.execute(result);
    }

    executor.shutdown();
    std::cout << "Bye" << std::endl;
}


int main(int argc, char **argv) {
    gflags::SetUsageMessage("--filepath=FILEPATH execute sql file\n     --disable_line_edit\n ");
    gflags::ParseCommandLineFlags(&argc, &argv, true);
    printInfo();
    setup_signal();
    GOOGLE_PROTOBUF_VERIFY_VERSION;
    read_loop();
    return 0;
}
