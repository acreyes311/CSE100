#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;



void bucketSort(float *A, int size){
//float *B = new float [size];
vector <float> B [size];
int s = 0;


for(int i = 0; i < size; i++){
	int k = size*A[i]; // 
	B[k].push_back(A[i]);
}
//Sort	

for (int i = 0; i < size-1; i++){
	
	sort(B[i].begin(), B[i].end());	
	
}	
//Concatenate lists
	
for (int i = 0; i < size; i++)
	for(int j = 0; j < B[i].size(); j++){
		A[s] = B[i][j];
		s++;
	}

}




/*
void bucketSort(float *A, int size){
//float *B = new float [size];
vector <float> B [size];



for(int i = 0; i < size; i++){
	int k = size*A[i];
	B[k].push_back(A[i]);
}
//Sort	

for (int i = 0; i < size-1; i++){
	
	//insertionSort(B,i);
}	
//Concatenate lists
int s = 0;	
for (int i = 0; i < size; i++)
	for(int j = 0; j < B[i].size(); j++)
		A[s++] = B[i][j];
//for (int i = 0; i < size; i++){
	//int bsize = B[i].size();
	//if(bsize > 0){
		//for(int j = 0; j < bsize; j++){
			//A[k] = B[i][j];	
		//	k++;
		//}
	//}
//}		
}
*/

int main(){

int size;
cin >> size;


float *arr = new float [size];

for(int i =0; i < size; i++)
	cin >>arr[i];

bucketSort(arr,size);

for(int i = 0; i < size; i++)
	cout << arr[i] << endl;

return 0;
}
