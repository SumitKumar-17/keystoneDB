---
layout: default
---

<p align="center">
  <img src="./images/keystoneDB.png" alt="keystoneDB Logo" width="500">
</p>

<div align="center">
  <h1>keystoneDB</h1>
  <p><strong>A relational DBMS built upon persistent key-value storage</strong></p>
  <p><em>Database Management Systems Laboratory (CS39202) Term Project</em></p>
  
  <p>
    <a href="https://github.com/SumitKumar-17/keystoneDB">
      <img src="https://img.shields.io/badge/View%20on-GitHub-24292e?logo=github&logoColor=white" alt="View on GitHub">
    </a>
    <a href="https://github.com/SumitKumar-17/keystoneDB/stargazers">
      <img src="https://img.shields.io/github/stars/SumitKumar-17/keystoneDB?style=social" alt="GitHub stars">
    </a>
  </p>
</div>

<div class="demo-container">
  <img src="./images/keystoneDB_Demo.png" alt="keystoneDB Demo" class="demo-image">
</div>

## Key Features

<div class="features-grid">
  <div class="feature-item">
    <h3>Expression Evaluation</h3>
    <p>Support for nested expressions including arithmetic operations, logical operations, and more</p>
  </div>
  <div class="feature-item">
    <h3>Multiple Data Types</h3>
    <p>Support for INT, FLOAT, and CHAR(N) data types</p>
  </div>
  <div class="feature-item">
    <h3>Constraints</h3>
    <p>NOT NULL constraint, SQL comments, and more</p>
  </div>
  <div class="feature-item">
    <h3>Multi-line Support</h3>
    <p>Execute multi-line SQL statements with ease</p>
  </div>
  <div class="feature-item">
    <h3>File Execution</h3>
    <p>Run SQL scripts directly from files</p>
  </div>
  <div class="feature-item">
    <h3>Persistent Storage</h3>
    <p>Built upon LSM-Tree like MyRocks and TiDB</p>
  </div>
</div>

## Build Instructions

<div class="tabs">
  <button class="tablinks active" onclick="openTab(event, 'Ubuntu')">Ubuntu 22.04</button>
  <button class="tablinks" onclick="openTab(event, 'Arch')">Arch Linux</button>
</div>

<div id="Ubuntu" class="tabcontent" style="display:block;">
  <h3>Ubuntu 22.04</h3>
  
  <p>To get the third party dependencies (via source code), run:</p>
  
  ```shell
  git submodule init
  git submodule update
  ```
  
  <p>Install the following libraries on your computer:</p>
  
  ```shell
  # required by rocksdb
  sudo apt-get install libgflags-dev libzstd-dev libsnappy-dev zlib1g-dev libbz2-dev liblz4-dev
  # required by protobuf
  sudo apt-get install libprotobuf-dev protobuf-compiler
  # required by flex and bison
  sudo apt-get install flex bison
  ```
</div>

<div id="Arch" class="tabcontent">
  <h3>Arch Linux</h3>
  
  ```shell
  # Required by RocksDB
  sudo pacman -S gflags zstd snappy zlib bzip2 lz4 liburing-dev

  # Required by Protobuf
  sudo pacman -S protobuf

  # Required by flex and bison
  sudo pacman -S flex bison
  ```
  
  <p>If compiling the GRPC library gives an error, you need to recompile the db.proto with:</p>
  
  ```shell
  protoc --cpp_out=./ common/codec/db.proto
  ```
  
  <p>Then recompile the database again.</p>
  
  <p><strong>Note:</strong> This code was tested on <strong>Arch Linux</strong>. 
  If you are running on <strong>Ubuntu</strong> there can be an error that <strong>abseil error</strong> comes.
  For this you need to comment the line <strong>153 and 154</strong> in the CMakeLists.txt.</p>
</div>

### Building the Project

```shell
mkdir build
cd build
cmake ..
make -j4
```

## Supported SQL Examples

```sql
CREATE DATABASE example;
USE example;
CREATE TABLE user (id int, score float);
SHOW TABLES;
INSERT INTO user (id int NOT NULL) VALUES (1);
SELECT id from user WHERE id = 42;
UPDATE user SET id=1 WHERE id=42;
DELETE FROM user WHERE id=42;
SELECT * from user where id=(1+2*2+(id=id)+id^id+id) AND id = id%2 AND id IS NOT NULL;
select * from t1 where id is not null;
DROP TABLE user;
exit; -- keyword used to exit from the database
```

Additional examples can be found in [test.sql](https://github.com/SumitKumar-17/keystoneDB/blob/main/test/test.sql).

## Project Structure

| File                 | Description                                         |
|----------------------|-----------------------------------------------------|
| include/*            | all the header files                                |
| sql/*                | intermediate representation(IR) for SQL             |
| executor/*           | execute SQL IR                                      |
| executor/processor/* | processor for SQL expression(visitor pattern)       |
| parser/sql.l         | lexical analysis for SQL(flex)                      |
| parser/sql.y         | syntax analysis for SQL(bison)                      |
| third_party/*        | third party dependencies, e.g., googletest, rocksdb |
| test/*               | unit test                                           |
| docs/*               | documentation for the project                       |

## How to Run

Start keystoneDB interactive shell (interactive mode):

```shell
# Assuming you are in build directory
./build/keystoneDB
```

## Architecture

<div class="architecture-gallery">
  {% for i in (1..10) %}
    <div class="architecture-item">
      <img src="./images/{{ i }}.png" alt="Architecture Diagram {{ i }}" onclick="enlargeImage(this)">
    </div>
  {% endfor %}
</div>

<div id="imageModal" class="modal">
  <span class="close">&times;</span>
  <img class="modal-content" id="enlargedImage">
</div>

## Demo Screenshots

<div class="demo-gallery">
  {% for i in (11..18) %}
    <div class="demo-item">
      <img src="./images/{{ i }}.png" alt="Demo Screenshot {{ i }}" onclick="enlargeImage(this)">
    </div>
  {% endfor %}
</div>

<style>
  .features-grid {
    display: grid;
    grid-template-columns: repeat(auto-fit, minmax(300px, 1fr));
    gap: 20px;
    margin: 30px 0;
  }
  
  .feature-item {
    background-color: rgba(255, 255, 255, 0.8);
    border-radius: 8px;
    padding: 20px;
    box-shadow: 0 4px 6px rgba(0, 0, 0, 0.1);
    transition: transform 0.3s ease;
  }
  
  .feature-item:hover {
    transform: translateY(-5px);
  }
  
  .demo-container {
    margin: 40px 0;
    text-align: center;
  }
  
  .demo-image {
    max-width: 100%;
    border-radius: 8px;
    box-shadow: 0 5px 15px rgba(0, 0, 0, 0.2);
  }
  
  .architecture-gallery, .demo-gallery {
    display: grid;
    grid-template-columns: repeat(auto-fit, minmax(250px, 1fr));
    gap: 15px;
    margin: 30px 0;
  }
  
  .architecture-item img, .demo-item img {
    width: 100%;
    border-radius: 6px;
    cursor: pointer;
    transition: opacity 0.3s ease;
  }
  
  .architecture-item img:hover, .demo-item img:hover {
    opacity: 0.9;
  }
  
  .modal {
    display: none;
    position: fixed;
    z-index: 1000;
    left: 0;
    top: 0;
    width: 100%;
    height: 100%;
    overflow: auto;
    background-color: rgba(0, 0, 0, 0.9);
  }
  
  .modal-content {
    margin: auto;
    display: block;
    max-width: 90%;
    max-height: 90%;
  }
  
  .close {
    position: absolute;
    top: 15px;
    right: 35px;
    color: #f1f1f1;
    font-size: 40px;
    font-weight: bold;
    transition: 0.3s;
    cursor: pointer;
  }
  
  .tabs {
    overflow: hidden;
    border: 1px solid #ccc;
    background-color: #f1f1f1;
    border-radius: 5px 5px 0 0;
  }
  
  .tabs button {
    background-color: inherit;
    float: left;
    border: none;
    outline: none;
    cursor: pointer;
    padding: 14px 16px;
    transition: 0.3s;
    font-size: 17px;
  }
  
  .tabs button:hover {
    background-color: #ddd;
  }
  
  .tabs button.active {
    background-color: #4CAF50;
    color: white;
  }
  
  .tabcontent {
    display: none;
    padding: 6px 12px;
    border: 1px solid #ccc;
    border-top: none;
    border-radius: 0 0 5px 5px;
    animation: fadeEffect 1s;
  }
  
  @keyframes fadeEffect {
    from {opacity: 0;}
    to {opacity: 1;}
  }
</style>

<script>
  function openTab(evt, tabName) {
    var i, tabcontent, tablinks;
    tabcontent = document.getElementsByClassName("tabcontent");
    for (i = 0; i < tabcontent.length; i++) {
      tabcontent[i].style.display = "none";
    }
    tablinks = document.getElementsByClassName("tablinks");
    for (i = 0; i < tablinks.length; i++) {
      tablinks[i].className = tablinks[i].className.replace(" active", "");
    }
    document.getElementById(tabName).style.display = "block";
    evt.currentTarget.className += " active";
  }
  
  function enlargeImage(img) {
    var modal = document.getElementById("imageModal");
    var modalImg = document.getElementById("enlargedImage");
    modal.style.display = "block";
    modalImg.src = img.src;
    
    var span = document.getElementsByClassName("close")[0];
    span.onclick = function() { 
      modal.style.display = "none";
    }
    
    window.onclick = function(event) {
      if (event.target == modal) {
        modal.style.display = "none";
      }
    }
  }
</script>