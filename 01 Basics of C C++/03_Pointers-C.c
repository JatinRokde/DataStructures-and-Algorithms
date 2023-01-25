#include <stdio.h>

int main(void)
{
    int a = 10;
    int *p;
    p = &a;

    printf("%d\n", a); // 10
    printf("%d\n", p); // address of a
    printf("%d\n", &a); // address of a
    printf("%d\n", &p); // address of p
    printf("%d\n", *p); // value of p (= a) = 10

    free(p);
    return 0;
}