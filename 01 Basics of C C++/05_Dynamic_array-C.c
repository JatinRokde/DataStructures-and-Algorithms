#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *p;
    p = malloc(3 * sizeof(int));

    p[0] = 2;
    p[1] = 3;
    p[2] = 5;

    for (int i = 0; i < 3; i++)
        printf("%d ", p[i]);

    free(p);
    return 0;
}