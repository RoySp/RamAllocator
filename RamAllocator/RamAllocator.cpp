#include "RamAllocator.h"
#include <iostream>
#include <cstdlib>
#include <cstring>

int main()
{
    SetConsoleTitle(_T("RAM Allocater"));

    int i = 0, n = 0, mb = 0;
    char* buffer = nullptr;
    char buf[BUFSIZ];

    std::cout << "How much MB do you want to allocate? ";

    while (fgets(buf, sizeof buf, stdin) == NULL || sscanf_s(buf, "%d", &i) != 1)
    {
        std::cout << "Invalid number. Please try again.\nHow much MB do you want to allocate? ";
        fflush(stdout);
    }

    mb = 1048576 * i;

    buffer = static_cast<char*>(malloc(mb + 1));
    if (buffer == NULL) 
    {
        std::cerr << "Memory allocation failed.\n";
        return 1;
    }

    for (n = 0; n < mb; n++)
    {
        buffer[n] = rand() % 26 + 'a';
    }
    buffer[mb] = '\0';

    std::cout << i << "MB allocated!\n";

    std::cout << "Press any key to close the Ram Allocator...";
    _getch();

    free(buffer);

    return 0;
}
