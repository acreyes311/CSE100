#include <iostream>
using namespace std;


void merge(int *arr, int left, int mid, int right){

int n1 = mid - left + 1;
int n2 = right - mid;
//temp L and R arrays
int L[n1];
int R[n2];

//copy arrays
for (int i = 0; i < n1; i++)
	L[i] = arr[left+i];

for (int j = 0; j < n2; j++)
	R[j] = arr[mid + 1 + j];
	
int i = 0;
int j = 0;
// index for merging array
int k = left;

while (i < n1 && j < n2){
	if(L[i] <= R[j]){
		arr[k] = L[i];
		i++;
	}
	else{
		arr[k] =R[j];
		j++;
	}
	k++;
}


//copy remaining elements
//Left array
while( i < n1){
	arr[k] = L[i];
	k++;
	i++;
}
//Right array
while( j < n2){
	arr[k] = R[j];
	k++;
	j++;
}

}

void mergeSort(int *arr, int left, int right){

if(left < right){
	int mid = left + (right - left)/2;
	
	//Sort first half
	mergeSort(arr,left,mid);
	//sort right half
	mergeSort(arr,mid+1,right);
	//merge arrays
	merge(arr,left,mid,right);
}	
}



int main(){
int size;

// get size
cin >> size;

//create and fill array
int *arr = new int[size];

for (int i =0; i < size; i++)
	cin >> arr[i];

//Call to mergesort
mergeSort(arr, 0, size-1);

// Print array
for (int i = 0; i < size; i++)
	cout << arr[i] << ";";
	
return 0;
}
