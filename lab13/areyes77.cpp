#include <iostream>
using namespace std;
#define INT_MAX 2147483647



// P.377 Print-Optimal-Parens pseudocode				
void print(int *s, int i, int j, int size) {

if(i == j) {
	cout << "A" << i-1;	
	//return;
}

else {
	cout << "(";
	
	// s,i,s[i][j]
	print(s,i,*((s+i*size)+j),size);
	
	cout << ".";
	
	// s,s[i][j]+1,j
	print(s,*((s+i*size)+j)+1,j,size);
	
	cout << ")";
}

}


//p375 Matrix-Chain-Order pseudocode
void matrixChainOrder(int *p, int size) {
int n = size;// - 1;
int m[n][n];
int s[n][n];

for(int i = 1; i < n; i++) 
	m[i][i] = 0;
	
for (int l = 2; l < n; l++) { // Chain length
	for(int i =1; i < n - l + 1; i++) {
		int j = i + l - 1;
		m[i][j] = INT_MAX;
		
		for(int k = i; k <= j - 1; k++) {
			int q = m[i][k] + m[k+1][j] + p[i-1] * p[k] * p[j];
			if(q < m[i][j]) {
				m[i][j] = q;
				s[i][j] = k;
			}
		}
	}

}

// Printing

cout  << m[1][size-1] << endl;

print(*s,1,size-1,size);

cout << endl;

}
		



int main() {

int size;
cin >> size;

int *arr = new int[size];

for(int i = 0; i <= size; i++)
	cin >> arr[i];

matrixChainOrder(arr,size+1);

return 0;
}
