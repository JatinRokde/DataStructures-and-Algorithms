#include <iostream>
using namespace std;

struct Array
{
    int *arr;
    int length;
    int size;
};

void create(Array *a)
{
    cout << "Entet the max size of the array: ";
    cin >> a->size;
    cout << "Enter the number of elements you want to enter: ";
    cin >> a->length;

    a->arr =(int *)malloc(a->size * sizeof(int));
    // a->arr = new int[a->size];

    cout << "\nEnter " << a->length << " elements:\n";
    for (int i = 0; i < a->length; i++)
    {
        cin >> a->arr[i];
    }
}
/*
Time complexity: O(n) 
*/

void display(Array a)
{
    cout << "\n\nThe array is:\n";
    for (int i = 0; i < a.length; i++)
    {
        cout << a.arr[i] << " ";
    }
}
/*
Time complexity: O(n) 
*/


int main(void)
{
    Array a;
    create(&a);
    display(a);
    return 0;
}