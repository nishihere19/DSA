#include <bits/stdc++.h>
using namespace std;
 
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
 
int partition (int arr[], int low, int high)
{
    int pivot = arr[high]; // pivot
    cout<<"Initialised pivot: "<<pivot<<endl;
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far
    cout<<"Initialised i: "<<i<<endl;
 
    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (arr[j] < pivot)
        {
            cout<<"j: "<<j<<" i: "<<i<<" ,since arr[j]: "<<arr[j]<<" is less than pivot: "<<arr[pivot-1]<<", swap arr[i],arr[j]"<<endl;
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    cout<<"Swapping "<<arr[i+1]<<" "<<arr[high]<<endl;
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
 
/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quickSort(int arr[], int low, int high)
{
    cout<<"low: "<<low<<endl;
    cout<<"high: "<<high<<endl;
    for(int i=low;i<high;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = partition(arr, low, high);
 
        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
 
/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
 
// Driver Code
int main()
{
    int n;
    cout<<"Enter number of elements \n";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<"Enter element \t";
        cin>>arr[i];
    }
    quickSort(arr, 0, n-1);
    cout << "Sorted array: \n";
    printArray(arr, n);
    return 0;
}
 