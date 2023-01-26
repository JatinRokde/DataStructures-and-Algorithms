#include <iostream>
using namespace std;

struct Test
{
    int A[5];
    int n;
};

// Array here being passed as call by value method, any changes made to the array here won't be reflecting in the main array.
void display(Test t1)
{
    for (int i = 0; i < t1.n; i++)
    {
        cout << t1.A[i] << " ";
    }
    t1.A[2] = 22;
}

int main(void)
{
    Test t = {{1, 2, 3, 4, 5}, 5};
    display(t);
    cout << endl;
    display(t);
    return 0;
}