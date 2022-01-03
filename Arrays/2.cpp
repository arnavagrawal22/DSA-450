// reverse an array
#include <iostream>
using namespace std;

typedef struct
{
    int min;
    int max;
} ans;
// method1
// method2
ans divideMaxMin(int arr[], int low, int high)
{
    ans a;
    if (low == high)
    {
        a.min = arr[low];
        a.max = arr[low];
        return a;
    }
    else if (high - low == 1)
    {
        if (arr[low] >= arr[high])
        {
            a.min = arr[high];
            a.max = arr[low];
        }
        else
        {
            a.min = arr[low];
            a.max = arr[high];
        }
        return a;
    }
    int mid = (low + high) / 2;
    ans left = divideMaxMin(arr, low, mid);
    ans right = divideMaxMin(arr, mid + 1, high);
    if (left.min <= right.min)
        a.min = left.min;
    else
        a.min = right.min;

    if (left.max > right.max)
        a.max = left.max;
    else
        a.max = right.max;
    return a;
}

ans oddEven(int arr[], int size)
{
    ans a;
    int i;
    if (size % 2 == 0)
    {
        if (arr[0] >= arr[1])
        {
            a.min = arr[1];
            a.max = arr[0];
        }
        else
        {
            a.min = arr[0];
            a.max = arr[1];
        }
        i = 2;
    }
    else
    {
        a.min = arr[0];
        a.max = arr[0];
        i = 1;
    }
    for (; i < size; i = i + 2)
    {
        if (arr[i] >= arr[i + 1])
        {
            if (arr[i] > a.max)
            {
                a.max = arr[i];
            }
            if (arr[i + 1] < a.min)
            {
                a.min = arr[i + 1];
            }
        }
        else
        {
            if (arr[i + 1] > a.max)
            {
                a.max = arr[i + 1];
            }
            if (arr[i] < a.min)
            {
                a.min = arr[i];
            }
        }
    }
    return a;
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";

    cout << endl;
}
int main()
{
    int a[] = {3, 8, 6, 4, 9, 10};
    ans final = oddEven(a, 6);
    cout << final.min << " " << final.max << endl;
    printArray(a, 5);
}
