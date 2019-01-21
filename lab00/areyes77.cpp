#include <iostream>
using namespace std;

void insertionSort(int* arr,int n){
int key;
int i;

for (int j = 1; j < n; j++){
	key = arr[j];
	i = j - 1;
	while((i >=0) && (arr[i] < key)){
		arr[i+1] = arr[i];
		i = i-1;
		arr[i+1] = key;
	}
}
}


int main(){

int size;

//get size of array
cin >> size;
//create array
int arr[size];

// fill array
for(int i = 0; i < size; i++){
	cin >> arr[i];
}

// Call insertionSort function
insertionSort(arr,size);

//Print array
for(int i = 0; i < size; i++){
	cout << arr[i] << ";";
}
return 0;
}
