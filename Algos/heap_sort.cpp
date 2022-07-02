

  

#include<climits>
void heapSort(int arr[], int n)
{
    
    if(n == 0)
    {
        return;
    }
  
    int heap_size = 1;
    
    //build heap
    for(;heap_size <= n;heap_size++)
    {
        int size = heap_size;
        int * cbt = arr;
        
        
        int child_index = size-1;
        int parent_index = (child_index-1)/2;
    
        while((cbt[parent_index] > cbt[child_index])&&(child_index > 0))
        {
          int temp = cbt[parent_index];
          cbt[parent_index] = cbt[child_index];
          cbt[child_index] = temp;
        
          child_index = parent_index;
          parent_index = (child_index -1)/2;
        }
    }   
    heap_size--;
    
    //remove elements from the heap and for sorted array
    for(;heap_size > 1;)
    {
        int min =  arr[0];
        arr[0] = arr[heap_size -1];
        arr[--heap_size] = min;
        
        int parent_index = 0;
        int left_child = INT_MAX,right_child = INT_MAX;
        if(2*(parent_index)+1 < heap_size)
        {
            left_child = arr[2*(parent_index)+1];
        } 
        if(2*(parent_index)+2 < heap_size)
        {
            right_child = arr[2*(parent_index)+2];
        }    
        
        while(arr[parent_index] >  left_child || arr[parent_index] > right_child)      
        {
            if(left_child < right_child)
            {
                arr[2*(parent_index)+1] = arr[parent_index];
                arr[parent_index] = left_child;
                parent_index = 2*(parent_index)+1;
            }  
            else
            {
                arr[2*(parent_index)+2] = arr[parent_index];
                arr[parent_index] = right_child;
                parent_index = 2*(parent_index)+2;
            }  
            
            left_child = INT_MAX;
            right_child = INT_MAX;
            if(2*(parent_index)+1 < heap_size)
            {
                left_child = arr[2*(parent_index)+1];
            } 
            if(2*(parent_index)+2 < heap_size)
            {
                right_child = arr[2*(parent_index)+2];
            }   
        }    
    }    
        
}
