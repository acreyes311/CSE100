#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INT_MAX 2147483647
typedef pair<int,int> vertex;
int pi[100];
vector<vertex> Adj[100];

// pseudocode
void mst(int size){
	priority_queue<vertex,vector<vertex>,greater<vertex>>Q;
	int key[100];
	bool flag[100];
	int u,v,w;	
	
	Q.push(pair<int,int>(0,0));
	
	for(int i = 0; i < size; i++) {
		key[i] = INT_MAX;
		pi[i] = 0;
	}
	
	do{
		u = Q.top().second;
		Q.pop();
		flag[u] = true;
		
		for (int i = 0 ; i < Adj[u].size(); i++) {
			v = Adj[u][i].first;
			w = Adj[u][i].second;
			
			if(!flag[v] && key[v] > w) {
				key[v] = Adj[u][i].second;
				Q.push(pair<int,int>(w,v));
				pi[v] = u;
			}
		}	
	
	}while(!Q.empty());

}

int main(){
int u,v,w, vertices, edges;
cin >> vertices;
cin >> edges;

for(int i = 0; i < edges; i++) {
	cin >> u;
	cin >> v;
	cin >> w;
	Adj[u].push_back(make_pair(v,w));
	Adj[v].push_back(make_pair(u,w));
}

mst(vertices);
//Print
for (int i = 1; i < vertices; i++)
	cout << pi[i] << endl;

return 0;
}
