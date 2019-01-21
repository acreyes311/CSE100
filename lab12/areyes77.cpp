#include <iostream>
using namespace std;
#define INT_MIN -2147483648

//p.369 Extended-Bottom-Up-Cut-Rod
void extendedCutRod(int *p, int size) {
int *r = new int [size+1];
int *s = new int [size+1];
int q;
r[0] = 0;
for(int j = 1; j <= size;j++) {
	q = INT_MIN;
	for(int i = 1; i <= j; i++) {
		if(q < p[i] + r[j-i]) {
			q = p[i] + r[j-i];
			s[j] = i;
		}
	
	}
	r[j] = q;
}

cout << r[size] << endl;

//p.369 Print-Cut-Rod-Solution
int n = size;

while(n > 0) {
	cout << s[n] << " ";
	n = n - s[n];
}
cout << "-1";  // space gives error
cout << endl;
}




int main() {
int size;
cin >> size;

int *arr = new int[size+1];

for(int i = 1; i <= size; i++)
	cin >> arr[i];
	
extendedCutRod(arr,size);

return 0;
}
