# skDB


## Build 

To get the third party dependencies, run:

```shell
git submodule init
git submodule update
```

```shell
# required by rocksdb
sudo apt-get install libgflags-dev libzstd-dev libsnappy-dev zlib1g-dev libbz2-dev liblz4-dev
# required by protobuf
sudo apt-get install libprotobuf-dev protobuf-compiler
```

## Supported SQL Example

```sql
CREATE DATABASE example;
USE example;
CREATE TABLE user (id int);
SHOW TABLES;
INSERT INTO user (id) VALUES (1);
SELECT id from user WHERE id = 42;
UPDATE user SET id=1 WHERE id=42;
DELETE FROM user WHERE id=42;
DROP TABLE user;
```

## Build

```shell
mkdir build
cd build
cmake ..
make
```

```shell
git submodule add https://github.com/google/googletest.git third_party/googletest
cd third_party/googletest
git checkout fa6de7f4382f5c8fb8b9e32eea28a2eb44966c32cd third_party/googletest
git checkout fa6de7f4382f5c8fb8b9e32eea28a2eb44966c32


cd ../../

git submodule add https://github.com/facebook/rocksdb.git third_party/rocksdb
cd third_party/rocksdb
git checkout b75438f9860e3cff5e713917ed22e0ac394a758c


cd ../../

git submodule add https://github.com/seleznevae/libfort.git third_party/libfort

cd third_party/libfort
git checkout 41237162a9bd34a30a88069ee4e230584ae8d674


```



## Tentative Structure

## Resources

+ [sqllogictest](https://www.sqlite.org/sqllogictest/doc/trunk/about.wiki)
+ [HuaDB](https://thu-db.github.io/huadb-doc/)
+ [BusTub](https://15445.courses.cs.cmu.edu/fall2022/schedule.html)
+ [USTC Compiler Principles](https://ustc-compiler-principles.github.io)
+ [SQL Parser](https://github.com/hyrise/sql-parser)



```shell

```