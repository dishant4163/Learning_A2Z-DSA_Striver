// Depth First Search (DFS) Graph Traversal

// Pre-req: Recursion, Graph Representation



#include<iostream>
#include<vector>
using namespace std;



void dfsHelper(int node, vector<int> adj[], int vis[], vector<int> &dfs) {
    vis[node] = 1;
    dfs.push_back(node);
    // traverse all its neighbours
    for(auto it : adj[node]) {
        // if the neighbour is not visited
        if(!vis[it]) {
            dfsHelper(it, adj, vis, dfs);
        }
    }
}

// Function to return a list containing the DFS traversal of the graph
vector<int> dfsOfGraph(int V, vector<int> adj[]) {
    int vis[V] = {0}, startindex = 0;
    vector<int> dfsAns;
    dfsHelper(startindex, adj, vis, dfsAns);

    return dfsAns;
}




void addEdge(vector <int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printAns(vector <int> &ans) {
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
}


int main() {

    vector <int> adj[5];

    addEdge(adj, 0, 2);
    addEdge(adj, 2, 4);
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 3);

    vector <int> ans = dfsOfGraph(5, adj);
    cout << "Traversing the Graph using Depth First Search (DFS) is: " ;
    printAns(ans);

    return 0;
}
