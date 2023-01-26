#include <iostream>
using namespace std;

// template <class T>
template <typename T>
class Arithmetic
{
private:
    T a;
    T b;

public:
    Arithmetic(T a, T b);
    T add();
    T sub();
};

template <class T>
Arithmetic<T>::Arithmetic(T a, T b)
{
    this->a = a;
    this->b = b;
}

template <class T>
T Arithmetic<T>::add()
{
    return a + b;
}

template <class T>
T Arithmetic<T>::sub()
{
    return a - b;
}

int main(void)
{
    Arithmetic<float> ar(10.2, 5.1);
    Arithmetic<int> arr(10, 5);

    cout << ar.add() << endl
         << ar.sub();

    cout << endl
         << arr.add() << endl
         << arr.sub();

    return 0;
}