#include <iostream>
using namespace std;

int main(void)
{
    char a[] = "How are you doing";
    int i, vcount;
    vcount = 0;

    for (i = 0; a[i] != '\0'; i++)
    {
        if (a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u' || a[i] == 'A' || a[i] == 'E' || a[i] == 'I' || a[i] == 'O' || a[i] == 'U')
        {
            vcount++;
        }
    }

    cout << " Vowels = " << vcount;

    return 0;
}