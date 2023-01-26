#include <bits/stdc++.h>
using namespace std;

bool hasPath(int n, bool **edges, bool *visited, int v1, int v2){
    if(v1 >= n or v2 >= n){
        return false;
    }
    if(v1 == v2){
        return true;
    }
    if (edges[v1][v2] or edges[v2][v1]){
        return true;
    }
    queue<int> pendingvertices;

    pendingvertices.push(v1);
    visited[v1] = true;

    while(!pendingvertices.empty()){
        int currentVertex = pendingvertices.front();
        pendingvertices.pop();
        for(int i = 0; i < n; i++){
            if(i == currentVertex){
                continue;
            }
            if(visited[i] == true){
                continue;
            }
            if(edges[currentVertex][i]){
                pendingvertices.push(i);
                visited[i] = true;
            }
        }    
        if(visited[v2]){
            return true;
        }
    }
    return false;
}

int main() {
    // Write your code here
    int n; // no. of vertices
    int e; // no. of edges
    cin >> n >> e;

    bool **edges = new bool *[n];
    for (int i = 0; i < n; i++) {
      edges[i] = new bool[n];
      for (int j = 0; j < n; j++) {
        edges[i][j] = false;
      }
    }
    for (int i = 0; i < e; i++) {
      int f, s;
      cin >> f >> s;
      edges[f][s] = true;
      edges[s][f] = true;
    }

    bool *visited = new bool[n];
    for(int i = 0; i < n; i++){
        visited[i] = false;
    }
    int v1, v2;
    cin >> v1 >> v2;

    if (hasPath(n, edges, visited, v1, v2)){
        cout << "true";
    }
    else{
        cout << "false";
    }

    for (int i = 0; i < n; i++) {
      delete[] edges[i];
    }
    delete[] edges;

}