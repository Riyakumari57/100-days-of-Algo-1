// STL implementation of Prim's algorithm for MST 
#include<bits/stdc++.h> 
using namespace std; 
# define INF 0x3f3f3f3f 

// iPair ==> Integer Pair 
typedef pair<int, int> iPair; 


class Graph 
{ 
	int V; // No. of vertices 

	list< pair<int, int> > *adj; 
   

public: 
	Graph(int V); // Constructor 
     map<int, string> gValueMap; 

	// function to add an edge to graph 
	void addEdge(int u, int v, int w); 

	// Print MST using Prim's algorithm 
	void primMST(); 
}; 

// Allocates memory for adjacency list 
Graph::Graph(int V) 
{ 
	this->V = V; 
	adj = new list<iPair> [V]; 
} 

void Graph::addEdge(int u, int v, int w) 
{ 
	adj[u].push_back(make_pair(v, w)); 
	adj[v].push_back(make_pair(u, w)); 
} 

// Prints shortest paths from src to all other vertices 
void Graph::primMST() 
{ 

	priority_queue< iPair, vector <iPair> , greater<iPair> > pq; 

	int src = 0; // Taking vertex 0 as source 

	vector<int> key(V, INF); 

	vector<int> parent(V, -1); 


	vector<bool> inMST(V, false); 



	pq.push(make_pair(0, src)); 
	key[src] = 0; 

	while (!pq.empty()) 
	{ 
 
		int u = pq.top().second; 
		pq.pop(); 

		inMST[u] = true; // Include vertex in MST 

		// 'i' is used to get all adjacent vertices of a vertex 
		list< pair<int, int> >::iterator i; 
		for (i = adj[u].begin(); i != adj[u].end(); ++i) 
		{ 
            int v = (*i).first; 
			int weight = (*i).second; 
			if (inMST[v] == false && key[v] > weight) 
			{ 
				// Updating key of v 
				key[v] = weight; 
				pq.push(make_pair(key[v], v)); 
				parent[v] = u; 
			} 
		} 
	} 

	// Print edges of MST using parent array 
    long int mstWeight=0;
	for (int i = 1; i < V; ++i){ 
		cout<<gValueMap[parent[i]]<<" -- "<< gValueMap[i]<<endl;
    } 
} 

// Driver program to test methods of graph class 
int main() 
{    
	int n,d;
    cin>>n>>d;
    vector<string>vertices(n);
    for(int i=0;i<n;i++){
        string s="";
        int temp;
        for(int j=0;j<d;j++){
            cin>>temp;
            s+=to_string(temp);
        }
        vertices[i]= s;
    }
    map<int, string> ValueMap; 
	Graph g(n); 
     for(int i=0;i<n;i++){
         for(int j=i;j<n;j++){
              long int w=0;
              for(int smd=0;smd<d;smd++){
                  w+=abs(atoi((const char*)vertices[i][smd]) - atoi((const char*)vertices[j][smd]));
              }
              cout<<"w is "<<w<<endl;
              g.addEdge(i, j,w);
              ValueMap[i] = vertices[i];
              ValueMap[j] = vertices[j]; 
         }
     }
    g.gValueMap = ValueMap;
	g.primMST(); 

	return 0; 
} 
