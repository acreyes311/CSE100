#include <iostream>
#include <cstdlib>
using namespace std;


int partition(int *A, int p, int r){
int x = A[r];
int i = p - 1;
int temp;

for(int j = p; j <= r-1; j++){
	if(A[j] <= x){
		i = i+1;
		temp = A[i];
		A[i] = A[j];
		A[j] = temp;
	}
}

temp = A[i+1];
A[i+1] = A[r];
A[r] = temp;

return i+1;	
}


int randomizedPart(int *A, int p, int r){

int i = p + rand()% (r-p);
int temp;
temp = A[r];
A[r] = A[i];
A[i] = temp;
return partition(A,p,r);

}

void randomizedQuicksort(int *A, int p, int r){
if( p < r){
	int q = randomizedPart(A,p,r);
	randomizedQuicksort(A,p,q-1);
	randomizedQuicksort(A,q+1,r);
	}

}


int main(){

int size;
cin >> size;

int *arr = new int[size];
for(int i = 0; i < size; i++)
	cin >> arr[i];
	
	
randomizedQuicksort(arr,0,size-1);

for(int i = 0; i < size; i++)
	cout << arr[i] << ";";

return 0;
}
