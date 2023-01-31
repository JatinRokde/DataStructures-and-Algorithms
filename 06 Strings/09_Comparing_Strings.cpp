#include <iostream>
using namespace std;

int main(void)
{
    char A[] = "Painter";
    char B[] = "Painting";
    int i, j;

    for (i = 0, j = 0; A[i] != '\0' and B[j] != '\0'; i++, j++)
    {
        if (A[i] != B[j])
        {
            break;
        }
    }

    if (A[i] == B[j])
    {
        cout << "Strings are Equal";
    }
    else if (A[i] < B[j])
    {
        cout << "String 1 is smaller";
    }
    else
    {
        cout << "String 1 is bigger";
    }
    return 0;
}