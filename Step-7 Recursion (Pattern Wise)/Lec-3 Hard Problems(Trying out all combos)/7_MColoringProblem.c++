// M - Coloring Problem



/*// Problem Link-> https://www.naukri.com/code360/problems/m-coloring-problem_981273


bool isSafe(int v, int color[], vector<vector<int>>& mat, int c, int n) {
    for (int i = 0; i < n; i++) {
        // Check if adjacent vertex has the same color
        if (mat[v][i] == 1 && color[i] == c) {
            return false;
        }
    }
    return true;
}

// Backtracking function to assign colors to vertices
bool graphColoringUtil(vector<vector<int>>& mat, int m, int color[], int v, int n) {
    // If all vertices are assigned a color then return true
    if (v == n) {
        return true;
    }

    // Try different colors for vertex `v`
    for (int c = 1; c <= m; c++) {
        // Check if this color can be assigned to vertex `v`
        if (isSafe(v, color, mat, c, n)) {
            color[v] = c;  // Assign color `c` to vertex `v`

            // Recur to assign colors to the next vertex
            if (graphColoringUtil(mat, m, color, v + 1, n)) {
                return true;
            }

            // If assigning color `c` doesn't lead to a solution, remove it (backtrack)
            color[v] = 0;
        }
    }
    return false;
}


string graphColoring(vector<vector<int>>& mat, int m) {
    int n = mat.size();  // Number of vertices
    int color[n] = {0};  // Array to store the colors assigned to vertices

    if (graphColoringUtil(mat, m, color, 0, n)) {
        return "YES";
    } else {
        return "NO";
    }
}

*/





#include<bits/stdc++.h>
using namespace std;

bool isSafeToColor(int node, int color[], bool graph[101][101], int N, int col) {
    for(int j = 0; j < N; j++) {
        if(j != node && graph[j][node] == 1 && color[j] == col) {
            return false;
        }
    }
    return true;
}

bool solveGFG(int node, int color[], int m, int N, bool graph[101][101]) {
    // Base Case
    if(node == N) return true;

    for(int i = 1; i <= m; i++) {
        if(isSafeToColor(node, color, graph, N, i)) {
            color[node] = i;
            if(solveGFG(node + 1, color, m, N, graph)) return true;

            //BackTrack
            color[node] = 0;
        }
    }
    return false;
}

bool graphColoringGFG(bool graph[101][101], int m, int N) {
    int color[N] = {0};
    if(solveGFG(0, color, m, N, graph)) return true;

    return false;
}






// Helper function to check if it's safe to color vertex `v` with color `c`
bool isSafe(int v, int color[], vector<vector<int>>& mat, int c, int n) {
    for (int i = 0; i < n; i++) {
        // Check if adjacent vertex has the same color
        if (mat[v][i] == 1 && color[i] == c) {
            return false;
        }
    }
    return true;
}

// Backtracking function to assign colors to vertices
bool graphColoringUtil(vector<vector<int>>& mat, int m, int color[], int v, int n) {
    // If all vertices are assigned a color then return true
    if (v == n) {
        return true;
    }

    // Try different colors for vertex `v`
    for (int c = 1; c <= m; c++) {
        // Check if this color can be assigned to vertex `v`
        if (isSafe(v, color, mat, c, n)) {
            color[v] = c;  // Assign color `c` to vertex `v`

            // Recur to assign colors to the next vertex
            if (graphColoringUtil(mat, m, color, v + 1, n)) {
                return true;
            }

            // If assigning color `c` doesn't lead to a solution, remove it (backtrack)
            color[v] = 0;
        }
    }
    return false;
}

// Function to check if the graph can be colored with `m` colors
string graphColoring(vector<vector<int>>& mat, int m) {
    int n = mat.size();  // Number of vertices
    int color[n] = {0};  // Array to store the colors assigned to vertices

    // Start from the first vertex
    if (graphColoringUtil(mat, m, color, 0, n)) {
        return "YES";
    } else {
        return "NO";
    }
}



int main() {

// GFG
    int N = 4;
    int m = 3;

    bool graph[101][101];
    memset(graph, false, sizeof graph);

    // Edges are (0, 1), (1, 2), (2, 3), (3, 0), (0, 2)
    graph[0][1] = 1; graph[1][0] = 1;
    graph[1][2] = 1; graph[2][1] = 1;
    graph[2][3] = 1; graph[3][2] = 1;
    graph[3][0] = 1; graph[0][3] = 1;
    graph[0][2] = 1; graph[2][0] = 1;

    cout << "The output is: " << graphColoringGFG(graph, m, N);


cout << endl << endl;


// Coding NInjas
    vector<vector<int>> mat = {
        {0, 1, 1, 0},
        {1, 0, 1, 1},
        {1, 1, 0, 1},
        {0, 1, 1, 0}
    };
    int M = 3;  // Number of colors

    cout << graphColoring(mat, M) << endl;  // Output: "YES" or "NO"

    return 0;
}
