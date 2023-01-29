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

    a->arr = (int *)malloc(a->size * sizeof(int));
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

int linearSearch(Array a, int key)
{
    for (int i = 0; i < a.length; i++)
    {
        if (a.arr[i] == key)
        {
            return i;
        }
    }
    return -1;
}
/*
Time complexity:
Best case: O(1) - element found at first position
Worst case: O(n) - element found at last index or element not found
*/

/*
Improvising Linear Search
i) Transposition - we swap the key element with its previous element; doing so it takes (n-1) comparisons in the next same element search.
ii) Moce to Head - In this, we swap the key element with the first element; doing so, upon next search it takes constant time.
*/

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

// Transposition
int transpositionLinearSearch(Array *a, int key)
{
    for (int i = 0; i < a->length; i++)
    {
        if (a->arr[i] == key)
        {
            swap(&a->arr[i], &a->arr[i - 1]);
            return i;
        }
    }
    return -1;
}

// Move to Head
int moveHeadLinearSearch(Array *a, int key)
{
    for (int i = 0; i < a->length; i++)
    {
        if (a->arr[i] == key)
        {
            swap(&a->arr[i], &a->arr[0]);
            return i;
        }
    }
    return -1;
}

int iterativeBinarySearch(Array a, int key)
{
    int low, high, mid;
    low = 0;
    high = a.length - 1;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (a.arr[mid] == key)
            return mid;
        else if (a.arr[mid] > key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}
/*
Time complexity:
Best case: O(1) - key is found at the mid of the array
Worst case: O(log n)
*/

int recursiveBinarySearch(Array a, int low, int high, int key)
{
    if (low <= high)
    {
        int mid = (low + high) / 2;

        if (a.arr[mid] == key)
            return mid;
        else if (a.arr[mid] > key)
            return recursiveBinarySearch(a, low, mid - 1, key);
        else
            return recursiveBinarySearch(a, mid + 1, high, key);
    }
    return -1;
}
/*
Time complexity:
Best case: O(1) - Key is found in the mid of the array
Worst case: O(n)
*/

int getElement(struct Array a, int index)
{
    if (index >= 0 && index < a.length)
    {
        return a.arr[index];
    }
    return -1;
}
/*
Time complexity: O(1) - always constant
*/

void setElement(struct Array *a, int index, int value)
{
    if (index >= 0 && index < a->length)
    {
        a->arr[index] = value;
    }
}
/*
Time complexity: O(1) - always constant time
*/

int maxElement(struct Array a)
{
    int max = a.arr[0];
    for (int i = 0; i < a.length; i++)
    {
        if (a.arr[i] > max)
        {
            max = a.arr[i];
        }
    }
    return max;
}
/*
Time complexity: O(n)
*/

int minElement(struct Array a)
{
    int min = a.arr[0];
    for (int i = 0; i < a.length; i++)
    {
        if (a.arr[i] < min)
        {
            min = a.arr[i];
        }
    }
    return min;
}
/*
Time complexity: O(n)
*/

int sumElement(struct Array a)
{
    int sum = 0;
    for (int i = 0; i < a.length; i++)
    {
        sum += a.arr[i];
    }
    return sum;
}
/*
Time complexity: O(n)
*/

float averageElement(struct Array a)
{
    int sum = 0;
    float average;
    for (int i = 0; i < a.length; i++)
    {
        sum += a.arr[i];
    }
    average = (float)sum / a.length;
    return average;
}
/*
Time complexity: O(n)
*/

int *arrayReverse1(Array a)
{
    int *B;
    B = new int[a.length];

    for (int i = a.length - 1, j = 0; i >= 0; i--, j++)
    {
        B[j] = a.arr[i];
    }
    return B;
}
/*
Time complexity: O(n)
*/

void displayReversedArray(int *a, int n)
{
    cout << "\n\nThe Reversed array is:\n";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

void arrayReverse2(struct Array *a)
{
    for (int i = 0, j = a->length - 1; i < j; i++, j--)
    {
        swap(&a->arr[i], &a->arr[j]);
    }
}
/*
Time complexity: O(n)
*/

void leftShift(struct Array a)
{
    for (int i = 0; i < a.length - 1; i++)
    {
        a.arr[i] = a.arr[i + 1];
    }
    a.arr[a.length - 1] = 0;

    for (int i = 0; i < a.length; i++)
    {
        cout << a.arr[i] << " ";
    }
}
/*
Time complexity: O(n)
*/

void rightShift(struct Array a)
{
    for (int i = a.length - 1; i > 0; i--)
    {
        a.arr[i] = a.arr[i - 1];
    }
    a.arr[0] = 0;

    for (int i = 0; i < a.length; i++)
    {
        cout << a.arr[i] << " ";
    }
}
/*
Time complexity: O(n)
*/

void leftRotate(struct Array a)
{
    int temp = a.arr[0];
    for (int i = 0; i < a.length - 1; i++)
    {
        a.arr[i] = a.arr[i + 1];
    }
    a.arr[a.length - 1] = temp;

    for (int i = 0; i < a.length; i++)
    {
        cout << a.arr[i] << " ";
    }
}
/*
Time complexity: O(n)
*/

void rightRotate(struct Array a)
{
    int temp = a.arr[a.length - 1];
    for (int i = a.length - 1; i > 0; i--)
    {
        a.arr[i] = a.arr[i - 1];
    }
    a.arr[0] = temp;

    for (int i = 0; i < a.length; i++)
    {
        cout << a.arr[i] << " ";
    }
}
/*
Time complexity: O(n)
*/

void sortedElementInsert(Array *a, int element)
{
    if (a->length < a->size)
    {
        int i;
        for (i = a->length - 1; i >= 0 && a->arr[i] > element; i--)
        {
            a->arr[i + 1] = a->arr[i];
        }
        a->arr[i + 1] = element;
        a->length++;
    }
}
/*
Time complexity:
Best case: O(1) - Element is largest
Worst case: O(n) - Element is smallest
*/

bool isSorted(Array a)
{
    for (int i = 0; i < (a.length - 1); i++)
    {
        if (a.arr[i] > a.arr[i + 1])
        {
            return false;
        }
    }
    return true;
}
/*
Time complexity: O(n)
*/

// Rearranges negatives to the left and positives to the right
void rearrange(Array *a)
{
    int i = 0, j = a->length - 1;

    while (i < j)
    {
        while (a->arr[i] < 0)
        {
            i++;
        }

        while (a->arr[j] >= 0)
        {
            j--;
        }

        if (i < j)
        {
            swap(&a->arr[i], &a->arr[j]);
        }
    }
}
/*
Time complexity: O(n)
Comparison = n + 2
*/

struct Array *merge(struct Array a, struct Array b)
{
    int i, j, k;
    i = j = k = 0;

    struct Array *c = (struct Array *)malloc(sizeof(struct Array));
    // struct Array *c = new struct Array;

    while ((i < a.length) && (j < b.length))
    {
        if (a.arr[i] < b.arr[j])
        {
            c->arr[k] = a.arr[i];
            i++;
            k++;
        }
        else
        {
            c->arr[k] = b.arr[j];
            j++;
            k++;
        }
    }

    while (i < a.length)
    {
        c->arr[k] = a.arr[i];
        i++;
        k++;
    }

    while (j < b.length)
    {
        c->arr[k] = b.arr[j];
        j++;
        k++;
    }

    c->length = a.length + b.length;
    c->size = a.size + b.size;

    return c;
}
/*
Time complexity: theta(m + n) - Linear
*/



int main(void)
{
    Array a;
    Array b;
    Array *c;
    create(&a);
    create(&b);
    display(a);
    display(b);
    // append(&a, 11);
    // insert(&a, 30, 2);
    // deleteElement(&a, 3);
    // cout << endl
    //      << linearSearch(a, 4);
    // cout << endl
    //      << moveHeadLinearSearch(&a, 4);
    // cout << endl
    //      << iterativeBinarySearch(a, 4);
    // cout << endl
    //      << recursiveBinarySearch(a, 0, a.length - 1, 3);
    // cout << endl
    //      << getElement(a, 2);
    // setElement(&a, 2, 55);
    // cout << endl << minElement(a);
    // cout << endl << sumElement(a);
    // cout << endl << averageElement(a);

    // int *revarr = arrayReverse1(a);
    // displayReversedArray(revarr, a.length);

    // arrayReverse2(&a);

    // cout << endl;
    // leftShift(a);
    // cout << endl;
    // rightShift(a);

    // cout << endl;
    // leftRotate(a);
    // cout << endl;
    // rightRotate(a);

    // cout << endl << isSorted(a);

    // sortedElementInsert(&a, 6);

    // rearrange(&a);

    c = merge(a, b);

    display(*c);

    return 0;
}