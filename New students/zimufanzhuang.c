#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

struct node {
    struct ads {
        int x, y;
    } sdfe;
};

struct node a;

int main()
{
    a.sdfe.x = 0;
    a.sdfe.y = 0;
    printf("%d %d\n", a.sdfe.x, a.sdfe.y);
    system("pause");
    return 0;
}