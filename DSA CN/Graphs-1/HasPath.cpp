#include <bits/stdc++.h>
using namespace std;

bool hasPath(int n, bool **edges, bool *visited, int start, int end){
    if(start >= n or end >= n){
        return false;
    }
    if(start == end){
        return true;
    }
    if (edges[start][end] or edges[end][start]){
        return true;
    }

    queue<int> pendingvertices;

    pendingvertices.push(start);
    visited[start] = true;

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

        if(visited[end]){
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
    int start, end;
    cin >> start >> end;

    if (hasPath(n, edges, visited, start, end)){
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