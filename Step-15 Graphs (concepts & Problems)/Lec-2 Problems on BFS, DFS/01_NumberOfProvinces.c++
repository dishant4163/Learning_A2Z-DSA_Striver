// Number of Provinces (using DFS/BFS)

// Pre-req: Connected Components, Graph traversal techniques


/* // PRoblem Link-> https://www.naukri.com/code360/problems/find-the-number-of-states_1377943


void dfs(int node, vector<int> adjLt[], int vis[]) {
    vis[node] = 1;
    for(auto it : adjLt[node]) {
        if(!vis[it]) {
            dfs(it, adjLt, vis);
        }
    }
}

int findNumOfProvinces(vector<vector<int>>& roads, int n) {
    // Write your code here.
    vector<int> adjLt[n];

    for(int i=0; i < n; i++) {
        for(int j=0; j < n; j++) {
            if (roads[i][j] == 1 && i != j) {
                adjLt[i].push_back(j);
                adjLt[j].push_back(i);
            }
        }
    }

    int vis[n] = {0}, cnt = 0;
    for(int i=0; i < n; i++) {
        if (!vis[i]) {
            cnt++;
            dfs(i, adjLt, vis);
        }
    }
    return cnt;
}

*/


#include<iostream>
#include<vector>
using namespace std;


void dfsHelper(int node, vector<int> adjList[], int vis[]) {
    vis[node] = 1;

    for(auto it : adjList[node]) {
        if(!vis[it]) {
            dfsHelper(it, adjList, vis);
        }
    }
}

int numProvinces(vector<vector<int>> adj, int V) {
    vector<int> adjList[V];

    for(int i=0; i < V; i++) {
        for(int j=0; j < V; j++) {
            if(adj[i][j] == 1 && i != j) {
                adjList[i].push_back(j);
                adjList[j].push_back(i);
            }
        }
    }

    int vis[V] = {0}, cnt = 0;
    for(int i=0; i < V; i++) {
        if(!vis[i]) {
            cnt++;
            dfsHelper(i, adjList, vis);
        }
    }

    return cnt;
}


int main() {

    vector<vector<int>> adj =
    {
        {1, 0, 1},
        {0, 1, 0},
        {1, 0, 1}
    };

    int V = 3;

    cout << "Number of Provinces is: " << numProvinces(adj, V) << endl;


    return 0;
}
