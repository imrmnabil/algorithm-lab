#include <iostream>
using namespace std;

void printResult(int *array, int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << array[i] << " ";
    }
    cout<<endl;

}

void merge(int *array, int low, int mid, int high)
{
    int temp[high + 1];
    int i = low;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= high)
    {
        if (array[i] <= array[j])
            temp[k++] = array[i++];
        else
            temp[k++] = array[j++];
    }
    while (i <= mid)
        temp[k++] = array[i++];
    while (j <= high)
        temp[k++] = array[j++];
    k--;
    while (k >= 0)
    {
        array[k + low] = temp[k];
        k--;
    }
}

void mSort(int *array, int low, int high)
{
    int mid;

    if (low < high)
    {
        mid = (low + high) / 2;
        mSort(array, low, mid);
        mSort(array, mid + 1, high);
        merge(array, low, mid, high);
    }
}

int main()
{
    int arr[] = {95, 56, 48, 92, 13, 484, 623, 448, 1, 256};
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Before Sorting :" << std::endl;
    printResult(arr, n);

    mSort(arr, 0, n - 1);

    std::cout << "After Merge Sort :" << std::endl;
    printResult(arr, n);
    return (0);
}
