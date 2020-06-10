#include "RamAllocator.h"

using namespace std;

int main()
{
    SetConsoleTitle(_T("RAM Allocater"));

    int i, n, mb, end;
    char* buffer;
    char buf[BUFSIZ];
 
    printf("How much MB do you want to allocate? ");

    while (fgets(buf, sizeof buf, stdin) == NULL || sscanf_s(buf, "%d%n", &i, &end) != 1 || !isspace(buf[end]))
    {
        printf("Invalid number. Please try again.\nHow much MB do you want to allocate? ");
        fflush(stdout);
    }

    mb = 1048576 * i;

    buffer = (char*)malloc(mb + 1);
    if (buffer == NULL) exit(1);

    for (n = 0; n < mb; n++)
        buffer[n] = rand() % 26 + 'a';
    buffer[mb] = '\0';

    printf("%iMB allocated!\n", i);

    printf("Press any key to close the Ram Allocator...");
    _getch();
    
    return 0;
}
