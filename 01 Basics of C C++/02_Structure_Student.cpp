#include <iostream>
using namespace std;

struct Student
{
    int rollno;
    char name[10];
    char department[10];
    char address[15];
};

int main(void)
{
    Student s[15]; // array of structure
    cout << "Size of the stucture array variable is: " << sizeof(s); // 15 * 40 = 600
    cout << "\nSize of the structure is: " << sizeof(Student); // 40
    return 0;
}