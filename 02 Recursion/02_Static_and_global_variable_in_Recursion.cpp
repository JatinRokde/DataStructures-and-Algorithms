#include <iostream>
using namespace std;

/*
Static and global variables have just their one copy maintained and so they will have just one activation record, which will keep on updating; instead of having individual activation records in each recursive call.
*/

int static_fun(int n)
{
    static int x = 0;
    if (n > 0)
    {
        x++;
        return static_fun(n - 1) + x;
    }
    return 0;
}

int main(void)
{
    int a = 5;
    cout << static_fun(a);
    return 0;
}