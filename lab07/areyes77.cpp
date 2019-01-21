#include <iostream>
#include <vector>

using namespace std;


void countingSort(vector<int> *V, int size,int k){
	vector<int> *newVect;
	newVect = new vector<int>[size];
	
	int count[10];
	for (int i = 0; i <10; i++)
		count[i]=0;
	
	for(int i = 0; i < size; i++)
		count[V[i][k]]++;
		
	for(int i = 1; i < 10; i++)
		count[i] += count[i-1];
		
	for(int i = size - 1; i >= 0; i--){
		newVect[count[V[i][k]] - 1] = V[i];
		count[V[i][k]]--;
	}
	
	for(int i = 0; i < size; i++)
		V[i] = newVect[i];		
}

void radixSort(vector<int> *V, int size){
	
	for(int i = 9; i>=0; i--)
	countingSort(V,size,i);
	//STABLE SORT
}

int main(){
	//get size
	int size;
	cin >> size;
	
	
	vector<int> *vect;
	vect = new vector<int>[size];
	
	for(int i = 0; i < size; i++){
		for(int j = 0; j < 10; j++){
		int temp;
		cin >> temp;
		vect[i].push_back(temp);
		}
	}
	
	radixSort(vect, size);
	

	
	
	for(int i = 0; i < size; i++){
		for(int j = 0; j < 10; j++){
		cout << vect[i][j] <<";";
		}
		cout << endl;
	}
	
	return 0;
}
