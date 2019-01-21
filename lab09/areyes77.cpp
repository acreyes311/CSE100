#include <iostream>
#include <list>
using namespace std;

// class for hashTable with insert, delete, search, and output functions
class hashTable{
	// key % size
	public:
	// Constructor with size input; create new list
	hashTable(int size) {h_Table = new list<int>[size];};
	
	// insert at front of list
	void hashInsert(int key, int size) {
		h_Table[key % size].push_front(key);
	}
	
	// search and delete key
	void hashDelete(int key, int size) {
		list<int> table = h_Table[key % size];
		list<int>::iterator t;
		
		// if empty failed
		if(table.empty()) {
			cout << key << " : DELETE FAILED" << endl;
			return; 
		}
		// iterate through list and search for key to delete
		for(t = table.begin(); t != table.end(); ++t){
			if(*t == key){
				table.erase(t);
				cout << key << " : DELETED" << endl;
				h_Table[key%size] = table;
				return; 
			}
		}
		// Key not found = fail
		cout << key << " : DELETE FAILED" << endl;
		return; 
	}
	
	// search list for key
	void hashSearch(int key, int size) {
		list <int> table = h_Table[key % size];
		list <int>::iterator t;
		int i=0; // index
		
		// empty = not found
		if(table.empty())
			cout << key << " : NOT FOUND" << endl;
		else {	// iterate through and search for key
			for(t = table.begin(); t != table.end(); ++t) {
				if(*t == key){
					cout << key << " : FOUND AT " << (key % size) 						<< "," << i << endl;
					return;
				}
				i++;
			}	
			cout << key << " : NOT FOUND" << endl;
		}
	}	
	
	// Print list
	void hashOutput(int size){
		list<int>table;
		list<int>::iterator t;
		
		// Populate table then iterate through printing.
		for(int i = 0; i < size; i++) {
			table = h_Table[i];
		
							
			cout << i << " : ";
			
			for(t = table.begin(); t != table.end(); ++t) {
				cout << *t;// << "->";
				
				if(++t != table.end())
					cout << "->";
					--t;
			}
			cout << endl;	
		}	
	}
	
	private:
	
	list<int> *h_Table;	
};	



int main(){
int size, key;
char ch;


cin >> size;
hashTable table(size);
cin >> ch;
//do (cin >> ch){
while (ch != 'e') {
	if(ch == 'i'){
		cin >> key;
		table.hashInsert(key,size);
	}
	if( ch == 'd') {
		cin >> key;
		table.hashDelete(key,size);
		cout << "++++++++++++++++++++" << endl;
		
	}
	if (ch == 's') {
		cin >> key;
		table.hashSearch(key,size);
		cout << "++++++++++++++++++++" << endl;
	}
	if (ch == 'o'){
		table.hashOutput(size);
		cout << "++++++++++++++++++++" << endl;
	}
	
	cin >> ch;
}//while (ch != 'e');
//cout << "++++++++++++++++++++" << endl;
return 0;
}
