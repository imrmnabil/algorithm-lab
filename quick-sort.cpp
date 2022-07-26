#include <iostream>
using namespace std;
 
void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 
   

int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high];
    int i = (low - 1);   
   
    for (int j = low; j <= high- 1; j++) 
    { 
        
        if (arr[j] <= pivot) 
        { 
            i++; 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 
   

void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        int pivot = partition(arr, low, high); 
   
        quickSort(arr, low, pivot - 1); 
        quickSort(arr, pivot + 1, high); 
    } 
} 
   
void printResult(int *array, int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << array[i] << " ";
    }
    cout<<endl;

}
   
int main() 
{ 
    int arr[] = {95, 56, 48, 92, 13, 484, 623, 448, 1, 256};
    int n = sizeof(arr)/sizeof(arr[0]); 
    cout<<"Before Sorting :"<<endl;
    printResult(arr,n);
    cout<<endl;
    quickSort(arr, 0, n-1); 
    cout<<"After Sorting :"<<endl; 
    printResult(arr,n); 
    return 0; 
}