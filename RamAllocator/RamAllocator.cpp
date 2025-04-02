#include "RamAllocator.h"
#include <iostream>
#include <memory>
#include <random>
#include <string>

int main() {
    std::cout << "RAM Allocator\n";

    // Prompt user for the amount of MB to allocate
    int mb = 0;
    std::cout << "How much MB do you want to allocate? ";
    while (!(std::cin >> mb) || mb <= 0) {
        std::cin.clear(); // clear the error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
        std::cout << "Invalid number. Please enter a positive integer: ";
    }

    // Calculate the number of bytes to allocate
    size_t bytes = static_cast<size_t>(mb) * 1048576;

    // Allocate memory using unique_ptr for automatic deallocation
    std::unique_ptr<char[]> buffer(new (std::nothrow) char[bytes + 1]);
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
    buffer[bytes] = '\0'; // Null-terminate the buffer

    std::cout << mb << " MB allocated and filled with random data.\n";

    // Wait for user input before closing
    std::cout << "Press Enter to close the RAM Allocator...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear the newline left in the buffer
    std::cin.get(); // wait for the Enter key

    return 0;
}
