// Breadth First Search (BFS): Level Order Traversal
// Pre-req: Graph Representation, Queue STL



/* // Problem-Link->
// https://www.naukri.com/code360/problems/bfs-in-graph_973002


vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
    // Write your code here.
    int vis[n] = {0};
    vis[0] = 1;
    queue<int> q;
    q.push(0);
    vector<int> bfsAns;

    while(!q.empty()) {
        int node = q.front(); q.pop();
        bfsAns.push_back(node);

        for(auto it : adj[node]) {
            if(!vis[it]) {
                vis[it] = 1;
                q.push(it);
            }
        }
    }
    return bfsAns;
}


*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;


// Function to return Breadth First Traversal of given graph.
vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    int vis[V] = {0};
    vis[0] = 1;
    queue<int> q;
    q.push(0); // push the initial starting node
    vector<int> bfs;

    while(!q.empty()) {
        int node = q.front(); // get the topmost element in the queue
        q.pop();
        bfs.push_back(node);
        // traverse for all its neighbours 
        for(auto it : adj[node]) {
        // if the neighbour has previously not been visited, 
        // store in Q and mark as visited 
            if(!vis[it]) {
                vis[it] = 1;
                q.push(it);
            }
        }
    }
    return bfs;
}




void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printAns(vector<int>& ans) {
    for(int i=0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
}


int main() {

    vector<int> adj[6];

    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 0, 4);

    vector<int> ans = bfsOfGraph(5, adj);
    cout << "Traversing the Graph using Breadth-First Search (BFS): " ;
    printAns(ans);


    return 0;
}
