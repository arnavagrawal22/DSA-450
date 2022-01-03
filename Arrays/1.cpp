// reverse an array
#include <iostream>
using namespace std;

void reverse(int arr[], int size)
{
    int i = 0;
    int j = size - 1;
    while (i < j)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }
}

void reverseR(int arr[], int start, int end)
{
    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        return reverseR(arr, start + 1, end - 1);
    }
}
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";

    cout << endl;
}
int main()
{
    int a[] = {1, 2, 3, 4, 5};
    reverseR(a, 0, 4);
    printArray(a, 5);
}
