---
layout: default
---

<div class="hero-banner">
  <div class="hero-content">
    <h1>keystoneDB</h1>
    <p class="hero-description">A relational DBMS built upon persistent key-value storage</p>
    <p><em>Database Management Systems Laboratory (CS39202) Term Project</em></p>
    
    <div class="hero-buttons">
      <a href="https://github.com/SumitKumar-17/keystoneDB" class="btn primary-btn" target="_blank">View on GitHub</a>
      <a href="https://github.com/SumitKumar-17/keystoneDB/zipball/main" class="btn secondary-btn" target="_blank">Download .zip</a>
      <a href="https://github.com/SumitKumar-17/keystoneDB/tarball/main" class="btn secondary-btn" target="_blank">Download .tar.gz</a>
    </div>
  </div>
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
  
  <div class="code-container">
    <pre><code>git submodule init
git submodule update</code></pre>
    <button class="copy-button" onclick="copyCode(this)">Copy</button>
  </div>
  
  <p>Install the following libraries on your computer:</p>
  
  <div class="code-container">
    <pre><code># required by rocksdb
sudo apt-get install libgflags-dev libzstd-dev libsnappy-dev zlib1g-dev libbz2-dev liblz4-dev
# required by protobuf
sudo apt-get install libprotobuf-dev protobuf-compiler
# required by flex and bison
sudo apt-get install flex bison</code></pre>
    <button class="copy-button" onclick="copyCode(this)">Copy</button>
  </div>
</div>

<div id="Arch" class="tabcontent">
  <h3>Arch Linux</h3>
  
  <div class="code-container">
    <pre><code># Required by RocksDB
sudo pacman -S gflags zstd snappy zlib bzip2 lz4 liburing-dev

# Required by Protobuf
sudo pacman -S protobuf

# Required by flex and bison
sudo pacman -S flex bison</code></pre>
    <button class="copy-button" onclick="copyCode(this)">Copy</button>
  </div>
  
  <p>If compiling the GRPC library gives an error, you need to recompile the db.proto with:</p>
  
  <div class="code-container">
    <pre><code>protoc --cpp_out=./ common/codec/db.proto</code></pre>
    <button class="copy-button" onclick="copyCode(this)">Copy</button>
  </div>
</div>

<div class="note-container">
  <p><strong>Note:</strong> This code was tested on <strong>Arch Linux</strong>. 
  If you are running on <strong>Ubuntu</strong> there can be an error related to <strong>abseil</strong>.
  If you encounter this error, you need to comment lines <strong>153 and 154</strong> in the CMakeLists.txt file.</p>
</div>

### Building the Project

<div class="code-container">
  <pre><code>mkdir build
cd build
cmake ..
make -j4</code></pre>
  <button class="copy-button" onclick="copyCode(this)">Copy</button>
</div>

## Supported SQL Examples

<div class="code-container sql-code">
  <pre><code><span class="keyword">CREATE DATABASE</span> example;
<span class="keyword">USE</span> example;
<span class="keyword">CREATE TABLE</span> user (id <span class="type">int</span>, score <span class="type">float</span>);
<span class="keyword">SHOW TABLES</span>;
<span class="keyword">INSERT INTO</span> user (id <span class="type">int</span> <span class="keyword">NOT NULL</span>) <span class="keyword">VALUES</span> (1);
<span class="keyword">SELECT</span> id <span class="keyword">from</span> user <span class="keyword">WHERE</span> id = 42;
<span class="keyword">UPDATE</span> user <span class="keyword">SET</span> id=1 <span class="keyword">WHERE</span> id=42;
<span class="keyword">DELETE FROM</span> user <span class="keyword">WHERE</span> id=42;
<span class="keyword">SELECT</span> * <span class="keyword">from</span> user <span class="keyword">where</span> id=(1+2*2+(id=id)+id^id+id) <span class="keyword">AND</span> id = id%2 <span class="keyword">AND</span> id <span class="keyword">IS NOT NULL</span>;
<span class="keyword">select</span> * <span class="keyword">from</span> t1 <span class="keyword">where</span> id <span class="keyword">is not null</span>;
<span class="keyword">DROP TABLE</span> user;
exit; <span class="comment">-- keyword used to exit from the database</span></code></pre>
  <button class="copy-button" onclick="copyCode(this)">Copy</button>
</div>

Additional examples can be found in <a href="https://github.com/SumitKumar-17/keystoneDB/blob/main/test/test.sql" target="_blank">test.sql</a>.

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

<div class="code-container">
  <pre><code># Assuming you are in build directory
./build/keystoneDB</code></pre>
  <button class="copy-button" onclick="copyCode(this)">Copy</button>
</div>

## Architecture

<div class="vertical-gallery">
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

<div class="vertical-gallery">
  {% for i in (11..18) %}
    <div class="demo-item">
      <img src="./images/{{ i }}.png" alt="Demo Screenshot {{ i }}" onclick="enlargeImage(this)">
    </div>
  {% endfor %}
</div>

<style>
  /* Main layout and typography */
  body {
    font-family: -apple-system, BlinkMacSystemFont, "Segoe UI", Roboto, Oxygen, Ubuntu, Cantarell, "Fira Sans", "Droid Sans", "Helvetica Neue", Arial, sans-serif;
    line-height: 1.6;
    color: #24292e;
    background-color: #f6f8fa;
  }
  
  /* Hero Banner */
  .hero-banner {
    background-image: linear-gradient(120deg, #155799, #159957);
    color: white;
    padding: 3rem 1rem;
    text-align: center;
    margin-bottom: 40px;
    border-radius: 0 0 8px 8px;
  }
  
  .hero-content {
    max-width: 800px;
    margin: 0 auto;
  }
  
  .hero-content h1 {
    font-size: 3rem;
    margin-bottom: 1rem;
    color: white;
  }
  
  .hero-description {
    font-size: 1.5rem;
    opacity: 0.9;
    margin-bottom: 2rem;
  }
  
  .hero-buttons {
    display: flex;
    justify-content: center;
    gap: 20px;
    margin-top: 30px;
  }
  
  .btn {
    padding: 12px 24px;
    border-radius: 4px;
    text-decoration: none;
    text-align: center;
    font-weight: 600;
    transition: all 0.3s ease;
    display: inline-block;
    border: none;
    cursor: pointer;
  }
  
  .primary-btn {
    background-color: #0366d6;
    color: white;
  }
  
  .primary-btn:hover {
    background-color: #0459c4;
    transform: translateY(-2px);
  }
  
  .secondary-btn {
    background-color: rgba(255, 255, 255, 0.2);
    color: white;
  }
  
  .secondary-btn:hover {
    background-color: rgba(255, 255, 255, 0.3);
    transform: translateY(-2px);
  }
  
  /* Features Grid */
  .features-grid {
    display: grid;
    grid-template-columns: repeat(auto-fit, minmax(300px, 1fr));
    gap: 20px;
    margin: 30px 0;
  }
  
  .feature-item {
    background-color: white;
    border-radius: 8px;
    padding: 20px;
    box-shadow: 0 4px 6px rgba(0, 0, 0, 0.1);
    transition: transform 0.3s ease;
  }
  
  .feature-item:hover {
    transform: translateY(-5px);
  }
  
  .feature-item h3 {
    color: #155799;
    margin-top: 0;
    margin-bottom: 10px;
  }
  
  /* Demo container */
  .demo-container {
    margin: 40px 0;
    text-align: center;
  }
  
  .demo-image {
    max-width: 100%;
    border-radius: 8px;
    box-shadow: 0 5px 15px rgba(0, 0, 0, 0.2);
  }
  
  /* Image Gallery */
  .vertical-gallery {
    display: flex;
    flex-direction: column;
    gap: 30px;
    margin: 30px 0;
  }
  
  .architecture-item img, .demo-item img {
    width: 100%;
    border-radius: 6px;
    cursor: pointer;
    transition: opacity 0.3s ease;
    box-shadow: 0 3px 10px rgba(0, 0, 0, 0.15);
  }
  
  .architecture-item img:hover, .demo-item img:hover {
    opacity: 0.9;
  }
  
  /* Modal for image zoom */
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
  
  /* Tabs */
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
    background-color: #159957;
    color: white;
  }
  
  .tabcontent {
    display: none;
    padding: 6px 12px;
    border: 1px solid #ccc;
    border-top: none;
    border-radius: 0 0 5px 5px;
    animation: fadeEffect 1s;
    background-color: white;
  }
  
  /* Notes */
  .note-container {
    background-color: #fffde7;
    border-left: 4px solid #fdd835;
    padding: 15px;
    margin: 20px 0;
    border-radius: 0 4px 4px 0;
  }
  
  /* Code Containers */
  .code-container {
    position: relative;
    margin: 20px 0;
  }
  
  .code-container pre {
    background-color: #f6f8fa;
    border-radius: 6px;
    padding: 16px;
    padding-right: 60px;
    overflow: auto;
    margin: 0;
    border: 1px solid #e1e4e8;
  }
  
  .sql-code pre {
    background-color: #282c34;
    color: #abb2bf;
  }
  
  /* SQL Syntax Highlighting */
  .sql-code .keyword {
    color: #c678dd;
    font-weight: bold;
  }
  
  .sql-code .type {
    color: #98c379;
  }
  
  .sql-code .comment {
    color: #5c6370;
    font-style: italic;
  }
  
  .copy-button {
    position: absolute;
    top: 8px;
    right: 8px;
    background-color: #e9ecef;
    border: none;
    border-radius: 4px;
    padding: 5px 10px;
    cursor: pointer;
    font-size: 12px;
    transition: all 0.2s ease;
  }
  
  .copy-button:hover {
    background-color: #dee2e6;
  }
  
  .copy-button.copied {
    background-color: #159957;
    color: white;
  }
  
  /* Tables */
  table {
    border-collapse: collapse;
    width: 100%;
    margin: 2rem 0;
    background-color: white;
    border-radius: 6px;
    overflow: hidden;
    box-shadow: 0 0 20px rgba(0, 0, 0, 0.1);
  }
  
  th, td {
    padding: 12px 15px;
    text-align: left;
    border-bottom: 1px solid #ddd;
  }
  
  th {
    background-color: #f6f8fa;
    font-weight: 600;
    color: #24292e;
  }
  
  tr:hover {
    background-color: #f5f5f5;
  }
  
  /* Headings */
  h1, h2, h3, h4, h5, h6 {
    margin-top: 2rem;
    margin-bottom: 1rem;
    font-weight: 600;
    color: #155799;
  }
  
  h2 {
    padding-bottom: 0.3em;
    border-bottom: 1px solid #eaecef;
  }
  
  /* Responsive adjustments */
  @media screen and (max-width: 768px) {
    .hero-buttons {
      flex-direction: column;
      gap: 10px;
    }
    
    .features-grid {
      grid-template-columns: 1fr;
    }
    
    .hero-content h1 {
      font-size: 2.5rem;
    }
    
    .hero-description {
      font-size: 1.2rem;
    }
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
  
  function copyCode(button) {
    const codeBlock = button.previousElementSibling;
    const code = codeBlock.textContent;
    
    navigator.clipboard.writeText(code).then(() => {
      // Visual feedback
      button.textContent = "Copied!";
      button.classList.add("copied");
      
      // Reset after 2 seconds
      setTimeout(() => {
        button.textContent = "Copy";
        button.classList.remove("copied");
      }, 2000);
    });
  }
  
  // Make all external links open in new tabs
  document.addEventListener('DOMContentLoaded', function() {
    var links = document.getElementsByTagName('a');
    for (var i = 0; i < links.length; i++) {
      if (links[i].hostname != window.location.hostname) {
        links[i].target = '_blank';
        links[i].rel = 'noopener noreferrer';
      }
    }
  });
</script>