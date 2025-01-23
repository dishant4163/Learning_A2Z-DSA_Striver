// Graph Representation in C++



#include<bits/stdc++.h>
using namespace std;


int main() {

cout << "Adjacency Matrix" << endl;

// Matrix / Adjacency Matrix
    int n, m;
    cin >> n >> m;
    //graph here

    // adjacency matrix for undirected graph
    // time complexity: O(n)
    int adj[n+1][m+1]; // for 1-based indexing Graph
    for(int i=0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;  // this statement will be removed in case of directed graph
    }






cout << "Adjacency Lists " << endl << endl;

// Lists / Adjacency Lists
    int N, M;
    cin >> N >> M;
    //graph

    // adjacency list for undirected graph
    // time complexity: O(2E) this is for undirected graph
    // time complexity: O(E) this is for directed graph
    vector<int> Adj[N+1];
    for(int i=0; i < M; i++) {
        int U, V;
        // U ----> V // directed graph
        cin >> U >> V;
        // on u-th index store v
        Adj[U].push_back(V); 
        // on v-th index store u
        // Adj[V].push_back(U);  // this statement will be removed in case of directed graph
    }





    return 0;
}
