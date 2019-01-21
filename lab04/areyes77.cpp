#include <iostream>
using namespace std;

#define INT_MAX  2147483647
#define INT_MIN  -2147483647 - 1

int maxCrossSubarray(int *A, int low, int mid, int high){
//sentinels
int leftsum = INT_MIN;
int rightsum = INT_MIN;

int sum = 0;
int maxleft, maxright;

//Max syb of A[i..mid]
for (int i = mid; i >= low; i--){
	sum += A[i];
	if(sum > leftsum){
		leftsum = sum;
		maxleft = i;
	}
}
sum = 0;

//Max sub of A[mid+1..j]
for(int j = mid+1; j <= high; j++){
	sum = sum + A[j];
	if(sum > rightsum){
		rightsum = sum;
		maxright = j;
	}
}
// returns indices and sum
return (maxleft, maxright, leftsum+rightsum);
}


int findMaxSubarray(int *A, int low, int high){
int mid = 0;
int leftlow, lefthigh, leftsum,
	rightlow, righthigh, rightsum,
	crosslow, crosshigh, crossSum = 0;
	
//base case 1 element
if (high == low)
	return(low,high,A[low]);
else
	mid = low+(high-low)/2;
	//mid = (low+high)/2;
	
(leftlow,lefthigh,leftsum) = findMaxSubarray(A,low,mid);
(rightlow, righthigh, rightsum) = findMaxSubarray(A,mid+1,high);
(crosslow, crosshigh, crossSum) = maxCrossSubarray(A,low,mid,high);

//combines
if (leftsum >= rightsum && leftsum >= crossSum)
	return (leftlow, lefthigh, leftsum);
else if (rightsum >= leftsum and rightsum >= crossSum)
	return (rightlow, righthigh, rightsum);
else
	return(crosslow, crosshigh, crossSum);
	
}

int main(){

int size;
//get size
cin >> size;

//create array
int *arr = new int[size];
//fill array
for(int i =0; i < size; i++)
	cin >> arr[i];
int a,b,sum;
(a,b,sum) = findMaxSubarray(arr,0,size-1);
cout << sum;
//cout << findMaxSubarray(arr,0,size-1);



return 0;
}
