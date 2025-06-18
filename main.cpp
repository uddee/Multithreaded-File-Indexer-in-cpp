#include <iostream>
#include <filesystem>
#include <vector>
#include <thread>
#include <mutex>

namespace fs = std::filesystem;

std::vector<std::string> indexed_files;
std::mutex index_mutex;

void index_directory(const fs::path& path) {
    for (const auto& entry : fs::recursive_directory_iterator(path)) {
        if (entry.is_regular_file()) {
            std::lock_guard<std::mutex> lock(index_mutex);
            indexed_files.push_back(entry.path().string());
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <dir1> <dir2> ..." << std::endl;
        return 1;
    }

    std::vector<std::thread> workers;
    for (int i = 1; i < argc; ++i) {
        fs::path dir(argv[i]);
        if (fs::exists(dir) && fs::is_directory(dir)) {
            workers.emplace_back(index_directory, dir);
        } else {
            std::cerr << "Skipping invalid directory: " << dir << std::endl;
        }
    }

    for (auto& thread : workers) {
        thread.join();
    }

    std::cout << "Indexed " << indexed_files.size() << " files:" << std::endl;
    for (const auto& file : indexed_files) {
        std::cout << file << std::endl;
    }

    return 0;
}
