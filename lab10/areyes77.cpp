#include <iostream>
#include <list>
using namespace std;

class hashTable{

public:

hashTable(){
A = new int[size];
for(int i = 0; i < size; i++)
	A[i] = -1;
}

//Calculate hash function
int hashCalc(int k, int i){
int h1,h2;

//h1(k) = k%13
h1 = k % 13;	
//h2(k)=1+(k%11)
h2 = 1 + (k % 11);

//h(k,i) = (h1(k) + ih2(k))
return (h1 + (i * h2)) % 13;
}


void hashInsert(int key){
int i = 0;
int j;
bool flag = false;
//repeat
while(( i < size)&&!flag) {
	j = hashCalc(key,i);	// Calculate hash key
	if(A[j] == -1){
		flag = true;
		A[j] = key;
		//return j;
}
	else
		i++;
}	
}

int hashSearch(int key){
int i = 0;
//int j;
for(int j = 0; j < size; j++) {
	i = hashCalc(key,j);
	
	if(A[i] == key)
		return i;
}		
	if(A[i] != -1)
		return -1;
}			

//while(A[j] != -1 || i != size){
	//j = hashCalc(key,i);
	//if(A[j] == key)
	//	return i;
	//i++;
//}
//untill arr[j] == nil or i == m
//cout << "NOT_FOUND" << endl;
//return -1;



// DELETE FUNCTION
void hashDelete(int key){
int del;
del = hashSearch(key);
if(del != -1)
	A[del] = -1;
}

// PRINT FUNCTION
void hashPrint() {
for(int i = 0; i < size; i++){
	if(A[i] == -1)
		cout << endl;
	else	
		cout << A[i] << endl;
}
}

private:

int size = 13;
int *A;
};


int main(){

int input;
int index = 0;

hashTable table;

cin >> input;
while(input != -1){
	table.hashInsert(input);
	cin >> input;
}
//Print Table
table.hashPrint();

cin >> input;
while(input != -2) {	// PRINT INDEX
	index = table.hashSearch(input);
	if(index == -1)
		cout << "NOT_FOUND" << endl;
	else
		cout << index << endl;	
	
	cin >> input;
}



cin >> input;
while (input != -3) { // Delete
	table.hashDelete(input);
	cin >> input;
}

//Print htable
table.hashPrint();

return 0;
}
