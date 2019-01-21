#include <iostream>
using namespace std;


void maxHeapify(int *A,int heapSize, int i){

//formula for left and right
int l = 2*i+1;
int r = 2*i + 2;
int largest = i;
int temp;

// Left larger than root
if(l < heapSize && A[l] > A[largest])
	largest = l;
else
	largest = i;
	
// right larger than largest
if(r < heapSize && A[r] > A[largest])
	largest = r;

//largest not root	
if(largest != i){
	temp = A[i];
	A[i] = A[largest];
	A[largest] = temp;
	maxHeapify(A,heapSize,largest);
}
}

void buildMaxHeap(int *A, int size){
for(int i = size/2-1; i >= 0; i--) // 
	maxHeapify(A,size,i);

}


void heapSort(int *A, int size){
buildMaxHeap(A,size);  // Call to buildMaxheap
int temp;
for (int i = size-1; i >= 0; i--){
	temp = A[0];
	A[0] = A[i];
	A[i] = temp;	
	maxHeapify(A,i,0);
}	
}

int main(){

int size;
cin >> size;	// get size

//Create and build array
int *arr = new int[size];
for(int i = 0; i < size; i++)
	cin >> arr[i];

//Function Call	
heapSort(arr,size);	

//Print
for (int i = 0; i < size; i++)
	cout << arr[i] << ";";


return 0;
}
