#include <iostream>
using namespace std;

int main(void)
{
    char s[] = "WElCoMe";
    for (int i = 0; i != '\0'; i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            s[i] += 32;
        }
        else if (s[i] >= 'a' && s[i] <= 'z')
        {
            s[i] -= 32;
        }
    }
    cout << s;
    return 0;
}