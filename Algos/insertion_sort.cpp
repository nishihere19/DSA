#include <iostream>
using namespace std;
void insertionSort(int arr[],int n)
{
	int i,temp,j;
	for(i=1;i<n;i++)
	{
		temp=arr[i];
		j=i-1;
		while(j>=0 && arr[j]>temp)
		{
			arr[j+1]=arr[j];
			j=j-1;
		}
		arr[j+1]=temp;
	}
}
int main()
{
	int n,i;
    cout<<"Enter number of elements in array"<<endl;
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++){
        cout<<"Enter element "<<i<<endl;
        cin>>arr[i];
    }
	insertionSort(arr,n);
    cout<<"The sorted array is : "<<endl;
    for (i=0;i<n;i++)
	cout<<arr[i]<< " ";
	return 0;
}
