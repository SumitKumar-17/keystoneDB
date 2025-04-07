## Project Proposal Report: Development of keystoneDB - A Custom Database Management System (DBMS)

### 1. Project Title

**keystoneDB: A Custom Database Management System**

### 2. Introduction and Motivation

Database Management Systems (DBMS) are critical software systems used extensively in almost every software application today. Understanding the internal workings of a DBMS, such as parsing SQL queries, executing commands, managing storage, and ensuring data integrity, is essential for computer science students and software developers.

The motivation behind this project is to practically explore and implement core database concepts, compiler principles, and storage mechanisms from scratch. The project "keystoneDB" aims to provide a hands-on opportunity to deeply understand how databases work internally by designing and implementing a custom DBMS.

### 3. Project Objectives

The main objectives of this project are:

- **Educational Objective:**  
  To gain practical knowledge of database internals, including parsing SQL queries, executing statements, managing data storage, and enforcing data constraints.

- **Technical Objective:**  
  To implement a functional DBMS supporting essential SQL features such as:
  - SQL Parsing using lexical and syntax analysis tools.
  - Intermediate representation (IR) for parsed SQL statements.
  - Execution engine capable of processing IR.
  - Persistent storage management using an LSM-tree based key-value store (RocksDB).
  - Support for common data types (`INT`, `FLOAT`, `CHAR(N)`).
  - Enforcement of constraints (`NOT NULL`).
  - Nested expression evaluation.
  - Multi-line query support.
  - Interactive command-line interface with history and line editing capabilities.
  - Multi-table selection queries.

- **Learning Objective:**  
  To enhance skills in compiler design (using Flex/Bison), visitor pattern implementation for expression evaluation, integration of third-party libraries (RocksDB), unit testing practices (googletest), and modern C++ development practices.

### 4. Detailed Methodology

The project will follow a structured methodology:

#### Phase I: Research & Planning
- Study existing DBMS architectures (SQLite, PostgreSQL).
- Understand SQL parsing techniques using Flex and Bison.
- Research persistent storage techniques (LSM-trees, RocksDB).

#### Phase II: Design
- Define system architecture clearly separating parser, executor, IR representation, expression evaluation processor, and storage engine.
- Design intermediate representation structures for parsed SQL queries.
- Plan visitor pattern-based execution logic for evaluating nested expressions.

#### Phase III: Implementation
- Implement lexical analyzer (`sql.l`) using Flex.
- Implement syntax analyzer (`sql.y`) using Bison.
- Develop IR classes representing parsed SQL commands.
- Implement executor logic to process IR commands.
- Integrate RocksDB as persistent storage backend.
- Develop interactive shell with multi-line input support and command history management.

#### Phase IV: Testing & Validation
- Write unit tests using googletest framework to validate individual components.
- Conduct integration tests to ensure end-to-end functionality.
- Test edge cases like constraint violations (`NOT NULL`), invalid queries handling, multi-table query correctness.

#### Phase V: Documentation & Reporting
- Prepare comprehensive documentation detailing system architecture, usage guidelines, implementation details, and testing results.

### 5. Tools and Technologies Used

The following tools and technologies will be used in this project:

| Tool/Technology | Purpose |
|-----------------|---------|
| **Flex** | Lexical analysis (tokenizing SQL queries) |
| **Bison** | Syntax analysis (parsing SQL grammar) |
| **C++17** | Main programming language for implementation |
| **CMake** | Build system management |
| **RocksDB** | Persistent key-value storage backend based on LSM-tree |
| **googletest** | Unit testing framework |
| **Git & GitHub** | Version control and collaboration |


### 6. Learning Outcomes

Upon completion of this project, the following learning outcomes will be achieved:

- Deep understanding of how database systems parse, interpret, execute SQL queries internally.
- Practical experience in compiler design concepts including lexical analysis (Flex), syntax analysis (Bison), intermediate representations (IR), and visitor patterns for expression evaluation.
- Hands-on experience integrating persistent storage solutions like RocksDB into applications.
- Improved proficiency in modern C++ development practices including modular design patterns, memory management techniques, unit testing methodologies using googletest framework.
- Enhanced ability to manage complex software projects through structured planning, version control systems like Git/GitHub, systematic testing strategies.

### 7. Timeline & Milestones

The following timeline was followed during the project's execution:

| Week(s) | Activities / Milestones |
|---------|-------------------------|
| Week 1 | Initial research on DBMS architectures; study Flex/Bison; RocksDB exploration |
| Week 1 | System architecture design; IR structure definition; parser design |
| Week 2 | Implementation of lexical analyzer (`sql.l`) & syntax analyzer (`sql.y`) |
| Week 2 | Development of IR classes; executor logic implementation |
| Week 3 | Integration with RocksDB; expression evaluation via visitor pattern |
| Week 3 | Interactive shell implementation; multi-line input support; history management |
| Week 4 | Unit testing with googletest; integration testing; debugging & fixes |
| Week 4 | Final documentation preparation; submission readiness |

### 8. Deliverables

At the end of this project, the following deliverables were produced:

1. **Fully Functional DBMS ("keystoneDB")**
   - Supports parsing/execution of subset SQL commands
   - Persistent data storage via RocksDB backend
   - Interactive shell with command history & multi-line support
  
2. **Comprehensive Documentation**
   - Architecture overview
   - Implementation details
   - Usage instructions
  
3. **Testing Suite**
   - Unit tests covering individual components
   - Integration tests validating overall functionality

### 9. Conclusion

This project provided significant practical experience in database system internals, compiler principles implementation using Flex/Bison tools, visitor pattern-based execution logic design, integration with persistent storage solutions like RocksDB, modern C++ programming practices, systematic testing strategies using googletest framework.

The successful completion of "keystoneDB" demonstrates comprehensive understanding of DBMS concepts along with valuable hands-on experience beneficial for future academic or professional endeavors in software engineering or database technology fields.