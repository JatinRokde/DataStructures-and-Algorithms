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

void append(struct Array *a, int value)
{
    if (a->length < a->size)
    {
        a->arr[a->length] = value;
        a->length++;
    }
}
/*
Time complexity: O(1) - always constant
*/

void insert(Array *a, int value, int index)
{
    if (a->length < a->size)
    {
        if (index >= 0 and index < a->length)
        {
            for (int i = a->length; i > index; i--)
            {
                a->arr[i] = a->arr[i - 1];
            }
            a->arr[index] = value;
            a->length++;
        }
    }
}
/*
Time complexity:
Best case: O(1) - when element is inserted at the last
Worst case: O(n) - when element is inserted at index 0
*/

int deleteElement(Array *a, int index)
{
    if (index >= 0 && index < a->length)
    {
        int x;
        x = a->arr[index];

        for (int i = index; i < (a->length - 1); i++)
        {
            a->arr[i] = a->arr[i + 1];
        }
        a->length--;
        return x;
    }
    return -1;
}
/*
Time complexity:
Best case: O(1) - when the last element is deleted
Worst case: O(n) - when element present on index 0 is deleted
*/


int main(void)
{
    Array a;
    create(&a);
    display(a);
    // append(&a, 11);
    // insert(&a, 30, 2);
    deleteElement(&a, 3);
    display(a);
    return 0;
}