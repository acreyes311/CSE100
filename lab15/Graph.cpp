#include <map>
#include <list>
#include <iostream>
#include <string>
#include <queue>

using namespace std;
#define INT_MAX 2147483647
struct Graph {
    list<string> vertices;
    map<pair<string,string>,int> edges;
    void PrintOut(void);
    void AddEdge(string,string,int);
    bool FindVertex(string);
    int FindEdgeCost(string vert1, string vert2);
    int IsReachable(string vert1, string vert2);
};

void Graph::PrintOut(void) {
    list<string>::iterator it;
    map<pair<string,string>,int>::iterator eit;
    
    for(it = vertices.begin(); it != vertices.end(); it++) {
        cout << *it << endl;
    }
    
    for(eit = edges.begin(); eit != edges.end(); eit++) {
        cout << (*eit).first.first << " " << (*eit).first.second << " " << (*eit).second << endl;
    }
}

void Graph::AddEdge(string vert1,string vert2,int weight) {

	if (FindVertex(vert1) && FindVertex(vert2))
		edges.insert(make_pair(make_pair(vert1,vert2),weight));
}

bool Graph::FindVertex(string vert1) {

	list<string>::iterator it;
	
	for(it = vertices.begin(); it != vertices.end(); it++) {
		if(*it == vert1)
			return true;
	}
	return false;
}

int Graph::FindEdgeCost(string vert1, string vert2) {

	map<pair<string,string>,int>::iterator eit;
	
	if(FindVertex(vert1) && FindVertex(vert2)) {
		for(eit = edges.begin(); eit != edges.end(); eit++) {
			if(((*eit).first.first == vert1) && ((*eit).first.second == vert2)) {
				return (*eit).second;
			}
		}
	}
	
	return -1;		
}

// * Pg. 595 BFS(G,s)
int Graph::IsReachable(string vert1, string vert2) {
	map<string,string> color;
	map<string,int> d;
	map<string, string> pi;
	queue<string> Q;
	list<string>::iterator vit;
	map<pair<string,string>,int>::iterator eit;
	string u, v;
	
	for(vit = vertices.begin(); vit != vertices.end(); vit++) {
		color[*vit] = "WHITE";	//undiscovered
		d[*vit] = INT_MAX;
		pi[*vit] = "";	// nil
	}
	
	color[vert1] = "GRAY";	//adjacent
	d[vert1] = 0;
	Q.push(vert1);
	
	while(!Q.empty()) {
		u = Q.front();
		Q.pop();
		
		for(eit = edges.begin(); eit != edges.end(); eit++) {
			if((*eit).first.first == u) {
				v = (*eit).first.second;
				
				if(color[v] == "WHITE") {
					color[v] = "GRAY";
					d[v] = d[u] + 1;
					pi[v] = u;
					Q.push(v);
				}
			}
		}
		
		color[u] = "BLACK";	//visited
	}
	if(d[vert2] != INT_MAX)
		return d[vert2];
		
	return -1;
}

int main() {
    Graph G;
    string in,start,end;
    int weight;
    cin >> in;
    
    while(in != "END") {
    	G.vertices.push_back(in);
    	cin >> in;
    }
    
    cin >> start;
    while(start != "END") {
    	cin >> end;
    	cin >> weight;
    	G.AddEdge(start,end,weight);
    	cin >> start;
    }
    
    G.PrintOut();
    int opcode;
    string A,B;
    do {
    	cin >> opcode;
       	switch(opcode) {
       		case 1:
       			cin >> A;
       			if(G.FindVertex(A))
       				cout << "1" << endl;
       			else
       				cout << "0" << endl;
       		break;
       		
       		case 2:
       			cin >> A;
       			cin >> B;
       			// Gives cross initialization error
       			//int ec = G.FindEdgeCost(A,B);
       			int ec;
       			ec = G.FindEdgeCost(A,B);
       			cout << ec << endl;
       		break;
       		       		
       		case 3:
       			cin >> A;
       			cin >> B;
       			int ecount = G.IsReachable(A,B);
       			cout << ecount << endl;
       		break;
       	}
   }while(opcode != 0);
    
}
