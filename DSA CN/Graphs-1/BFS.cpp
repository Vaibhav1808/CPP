#include <bits/stdc++.h>
using namespace std;

void printBFS(int **edges, int n, int sv){
    queue<int> pendingvertices;

    bool *visited = new bool[n];
    for(int i = 0; i < n; i++){
        visited[i] = false;
    }

    pendingvertices.push(sv);
    visited[sv] = true;

    while(!pendingvertices.empty()){
        int currentVertex = pendingvertices.front();
        cout << currentVertex << endl;
        pendingvertices.pop();
        
        for(int i = 0; i < n; i++){
            if(i == currentVertex){
                continue;
            }
            if(edges[currentVertex][i] == 1 and !visited[i]){
                pendingvertices.push(i);
                visited[i] = true;
            }
        }
    }
    delete[] visited;
}

int main(){
    int n; // no. of vertices
    int e; // no. of edges
    cin >> n >> e;

    int **edges = new int*[n];
    for(int i = 0; i < n; i++){
        edges[i] = new int[n];
        for(int j = 0; j < n; j++){
            edges[i][j] = 0;
        }
    }
    for(int i = 0; i < e; i++){
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    bool *visited = new bool[n];
    for(int i = 0; i < n; i++){
        visited[i] = false;
    }

    printBFS(edges, n, 0);
    delete[] visited;
    for(int i = 0; i < n; i++){
        delete[] edges[i];
    }
    delete[] edges;
}