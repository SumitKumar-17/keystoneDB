#include <iostream>

#include "sql/parser_result.h"
#include "rocksdb/db.h"
#include "fort.hpp"
#include "version.h"
#include <csignal>
#include "common/codec/db.pb.h"
#include "execution/executor.h"

int wrapped_parse(const char *text, skDB::ParserResult *result);

std::string s;

void read_loop();

const auto welcome = "Welcome to the skDB. skDB is a DBMS built on RocksDB.";
const auto copyright = "Copyright (c) 2024-present Ruitian Zhong All rights reserved.";
const auto author = "Written by Ruitian Zhong <https://github.com/SumitKumar-17>.";
const auto license = "Source code git repository: <https://github.com/SumitKumar-17/skDB>.";

void printInfo() {
    std::cout << welcome << std::endl;

    std::cout << "skDB VERSION: v" << SKDB_MAJOR << "." << SKDB_MINOR << "." << SKDB_PATCH << std::endl << std::endl;

    std::cout << copyright << std::endl;
    std::cout << author << std::endl;
    std::cout << license << std::endl;
    std::cout << std::endl;
}


void signal_handler(int sig) {
    std::cout << std::endl << "skDB> ";
    std::fflush(stdout);
}

void setup_signal() {
    // register SIGINT handler
    signal(SIGINT, signal_handler);
}

void read_loop() {
    skDB::Executor executor;

    executor.init();
    while (true) {
        std::cout << "skDB> ";
        std::getline(std::cin, s);
        const auto result = new skDB::ParserResult();
        wrapped_parse(s.c_str(), result);
        if (!executor.execute(result)) {
            break;
        }
        // TODO: delete result
    }
    executor.shutdown();
    std::cout << "Bye" << std::endl;
}


int main(int argc, char **argv) {
    printInfo();
    setup_signal();
    GOOGLE_PROTOBUF_VERIFY_VERSION;
    read_loop();
    return 0;
}
