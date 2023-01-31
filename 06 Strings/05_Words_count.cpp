#include <iostream>
using namespace std;

int main(void)
{
    string a = "How are you?";
    int word = 1;

    for (int i = 0; a[i] != '\0'; i++)
    {
        if (a[i] == ' ' and a[i - 1] != ' ')
        {
            word++;
        }
    }

    cout << word;
    return 0;
}