#include "RamAllocator.h"
#include <iostream>
#include <memory>
#include <random>
#include <string>
#include <limits>

void clearInputStream() {
    std::cin.clear(); // clear the error flag
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
}

class RamAllocator {
public:
    void allocateMemory(size_t mb) {
        size_t bytes = mb * 1048576;
        buffer = std::make_unique<char[]>(bytes);
        if (!buffer) {
            throw std::runtime_error("Memory allocation failed.");
        }

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis('a', 'z');
        for (size_t i = 0; i < bytes; ++i) {
            buffer[i] = static_cast<char>(dis(gen));
        }
    }

    void displayMessage(size_t mb) {
        std::cout << mb << " MB allocated and filled with random data.\n";
    }

private:
    std::unique_ptr<char[]> buffer;
};

int main() {
    std::cout << "RAM Allocator\n";

    int mb = 0;
    std::cout << "How much MB do you want to allocate? ";
    while (!(std::cin >> mb) || mb <= 0) {
        clearInputStream();
        std::cout << "Invalid number. Please enter a positive integer: ";
    }

    try {
        RamAllocator allocator;
        allocator.allocateMemory(mb);
        allocator.displayMessage(mb);
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        return 1;
    }

    std::cout << "Press Enter to close the RAM Allocator...";
    clearInputStream();
    std::cin.get(); // wait for the Enter key

    return 0;
}
