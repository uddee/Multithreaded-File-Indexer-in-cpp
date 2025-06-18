# Multithreaded File Indexer in C++

This project is a simple multithreaded file indexer written in modern C++17 using `std::filesystem` and `std::thread`.

## 🔧 Features
- Recursively scans directories
- Uses multiple threads for parallel directory traversal
- Thread-safe collection of file paths

## 🚀 Usage

```bash
./indexer /path/to/dir1 /path/to/dir2 ...
🛠️ Build Instructions
bash
Copy
Edit
g++ -std=c++17 -pthread main.cpp -o indexer
📦 Dependencies
GCC 9+ or Clang 10+

C++17 or later

📄 Example Output
bash
Copy
Edit
Indexed 1625 files:
/home/user/code/main.cpp
/home/user/code/utils/helper.hpp
...
🧠 Concepts Used
STL containers and iterators

C++17 std::filesystem

std::thread and std::mutex

RAII for thread-safety (std::lock_guard)

