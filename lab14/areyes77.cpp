#include <iostream>
#include <queue>
#include <vector>

using namespace std;

string garr[26];

struct minHeap {
char value;
int freq;
minHeap *left;
minHeap *right;

minHeap(char v, int num) {
	//minHeap *left, *right;
	left = NULL;
	right = NULL;
	value = v;
	freq = num;
}
};

struct compare {
bool operator()(minHeap* left, minHeap* right) {
	return (left->freq > right->freq);
}
};



void printHuff(minHeap* r, string s, char set[], int size) {
if (r == NULL)
	return;
	
if(r->value == '\n') {
	printHuff(r->left, s + "0", set, size);
	printHuff(r->right, s + "1", set, size);
}
	
else if(r->value != '\n') {
	for(int i = 0; i < size; ++i) {
		if(r->value == set[i])
			garr[i] = s;
	}
}

}

void print(minHeap* r, string s) {
if(r == NULL)
	return;
	
if( r->value != '\n')
	cout << s << endl;
	
print(r->left, s + "0");
print(r->right, s + "1");


}

//P. 431 HUFFMAN(C) pseudocode
void huffman(int num[], char set[], int size) {
minHeap *x;
minHeap *y;
minHeap *z;

priority_queue <minHeap*, vector <minHeap*>, compare > Q;

for(int i = 0; i < size; ++i) {
	minHeap *temp = new minHeap(set[i], num[i]);
	Q.push(temp);
}

while (Q.size() != 1) {
	x = Q.top();
	Q.pop();
	
	y = Q.top();
	Q.pop();
	
	z = new minHeap('\n', x->freq + y->freq);
	z->left = x;
	z->right = y;
	
	Q.push(z);
}

string s = "";
//print(Q.top(), s);
printHuff(Q.top(),s,set,size);

}


int main() {

int num;
cin >> num;
int arr[num];

for(int i = 0; i < num; i++)
	cin >> arr[i];

char set[] = {'A', 'B', 'C', 'D', 'E','F'};
huffman(arr,set,num);

for(int i = 0; i < num; i++)
	cout << garr[i] << endl;
	
return 0;
}
