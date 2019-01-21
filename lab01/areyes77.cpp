#include <iostream>
using namespace std;


int linearSearch(int *a, int N,int key){

// search for key. return index if found
for (int i = 0; i < N; i++){
	if (a[i] == key)	
		return i;
}
// key not found return -1
return -1;
}

int main(){

int N, key;

//get size of array
cin >> N;

// get key
cin >> key;

//create array
int *arr = new int[N];

//fill array
for (int i = 0; i < N; i++){
	cin >> arr[i];
}

// call to linear search. display index or -1
cout << linearSearch(arr,N,key) << endl;

return 0;
}
