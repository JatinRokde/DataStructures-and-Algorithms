#include <iostream>
using namespace std;

int validation(string name)
{
    for (int i = 0; name[i] != '\0'; i++)
    {
        if (!(name[i] >= 65 and name[i] <= 90) and !(name[i] >= 97 and name[i] <= 122) and !(name[i] >= 48 and name[i] <= 57))
        {
            return 0;
        }
    }
    return 1;
}

int main(void)
{
    string name = "ak4hi35@hjkaf";

    int result = validation(name);
    if (result)
    {
        cout << "String is valid";
    }
    else 
    {
        cout << "String is invalid";
    }

    return 0;
}