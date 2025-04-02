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

int main() {
    std::cout << "RAM Allocator\n";

    // Prompt user for the amount of MB to allocate
    int mb = 0;
    std::cout << "How much MB do you want to allocate? ";
    while (!(std::cin >> mb) || mb <= 0) {
        clearInputStream();
        std::cout << "Invalid number. Please enter a positive integer: ";
    }

    // Calculate the number of bytes to allocate
    size_t bytes = static_cast<size_t>(mb) * 1048576;

    // Allocate memory using unique_ptr for automatic deallocation
    auto buffer = std::make_unique<char[]>(bytes);
    if (!buffer) {
        std::cerr << "Memory allocation failed.\n";
        return 1;
    }

    // Fill the allocated memory with random lowercase letters
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis('a', 'z');
    for (size_t i = 0; i < bytes; ++i) {
        buffer[i] = static_cast<char>(dis(gen));
    }

    std::cout << mb << " MB allocated and filled with random data.\n";

    // Wait for user input before closing
    std::cout << "Press Enter to close the RAM Allocator...";
    clearInputStream();
    std::cin.get(); // wait for the Enter key

    return 0;
}
