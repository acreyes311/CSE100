#include <iostream>
using namespace std;

int binarySearch(int *arr,int size,int key)
{
// left and right of array
int left =0;
int right = size-1;


while(left <= right){
int mid = left+(right - left)/2;

//first check at middle
if (arr[mid] == key)
	return mid;
	
//if key greater than left, move left to mid+1
if (arr[mid] < key)
	left = mid+1;
//Key is in left half of array
if ( arr[mid]> key)
	right = mid-1;		
}

return -1;
}

int main(){

int size,key;

//get size
cin >> size;

//create array
int *arr = new int[size];

// get key to search
cin >> key;

// fill array
for(int i =0; i < size; i++){
	cin >> arr[i];
}


cout << binarySearch(arr,size,key);

return 0;
}
