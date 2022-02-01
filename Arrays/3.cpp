// reverse an array
#include <iostream>
using namespace std;
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";

    cout << endl;
}
int kthmax(int a[], int size, int k)
{
    for (int i = 0; i < k; i++)
    {
        int max = -35000;
        for (int j = 0; j < size; j++)
        {
            if (a[j] > max)
            {
                max = a[j];
            }
        }
        cout << max << endl;
        if (i == k - 1)
        {
            return max;
        }

        for (int j = 0; j < size; j++)
        {
            if (a[j] == max)
            {
                for (int k = j; k < size - 1; k++)
                {
                    a[k] = a[k + 1];
                }
                size--;
                printArray(a, size);
                break;
            }
        }
    }
    return 0;
}

int main()
{
    int a[] = {7, 6, 5, 4, 3, 2, 1};
    int ans = kthmax(a, 7, 5);
    cout << ans;
}
