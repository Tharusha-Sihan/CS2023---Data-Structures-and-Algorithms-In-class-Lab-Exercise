#include <iostream>
using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   // build heapify
   int largest = root;
   int left = 2*root+1;
   int right = 2*root +2;
   
   if(left < n && arr[left]>arr[largest]){
       largest = left;
   }
   
   if (right < n && arr[right]>arr[largest]){
       largest = right;
   }
   
   if (largest != root){
       int temp = arr[root];
       arr[root] = arr[largest];
       arr[largest] = temp;
       heapify( arr, n, largest);
   }
}

  
// implementing heap sort
void heapSort(int arr[], int n)
{
   // build heap
   int begin = n/2 -1;
   for (int i = begin; i>=0; i--){
       heapify(arr,n,i);
   }
   for (int k=n-1; k>=0; k--){
       int temp = arr[0];
       arr[0] = arr[k];
       arr[k] = temp;
       heapify(arr,k,0);
   }
   // extracting elements from heap one by one
}
  
/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
  
// main program
int main()
{
  // int heap_arr[] = {4,17,3,12,9,6};
  // int n = sizeof(heap_arr)/sizeof(heap_arr[0]);
  int n;
  cout<< "Enter the length of the array :";
  cin >> n;
  cout<< "Enter array: ";
  int heap_arr[n];
  for(int j = 0; j<n; j++){
      cin >> heap_arr[j];
  }
   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);
  
   heapSort(heap_arr, n);
  
   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
}