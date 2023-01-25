#include <stdio.h>
#include <stdlib.h>

struct Rectangle
{
    int length;
    int breadth;
};


int main(void)
{
    struct Rectangle *p;
    p = (struct Rectangle *)malloc(sizeof(struct Rectangle));

    p->length = 15;
    p->breadth = 5;

    printf("Length: %d\n", p->length);
    printf("Breadth: %d", p->breadth);

    free(p);
    return 0;
}