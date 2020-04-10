/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;


void heapify(int a[], int n, int i)
{
    int largest = i;
    int left = (2*i)+1;
    int right = (2*i)+2;
    
    if(left<n && a[left]>a[i])
        largest = left;
    if(right<n && a[right]>a[largest])
        largest = right;
    
    if(largest!=i)
    {
        swap(a[largest],a[i]);
        heapify(a,n,largest);
    }
}

void build_heap(int a[], int n)
{
   int last_index = (n/2)-1;
   for(int i=last_index;i>=0;i--)
        heapify(a,n,i);
}

void printHeap(int a[], int n) 
{ 
    cout << "Array representation of Heap is:\n"; 
  
    for (int i = 0; i < n; ++i) 
        cout << a[i] << " "; 
    cout << "\n"; 
} 

int main()
{
    int arr[] = { 1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17 };
    int n = sizeof(arr)/sizeof(arr[0]);
    build_heap(arr,n);
    printHeap(arr, n);
    return 0;
}
