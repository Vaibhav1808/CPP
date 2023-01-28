#include <bits/stdc++.h>
using namespace std;

vector<int> getPath(int v, int **edges, bool *visited, int start, int end){
    vector<int> path;

    if(start == end){
        path.push_back(start);
        return path;
    }

    for(int i = 0; i < v; i++){
        if(i == start){
            continue;
        }
        if(visited[i]){
            continue;
        }
        if(edges[start][i]){
            visited[i] = true;
            path = getPath(v,edges,visited,i,end);
            if(path.size()){
                path.push_back(start);
                return path;
            }
        }
    }
}

int main(){
    int v, e;
    cin >> v >> e;

    int **edges = new int*[v];
    for(int i = 0; i < v; i++){
        edges[i] = new int[v];
        for(int j = 0; j < v; j++){
            edges[i][j] = 0;
        }
    }

    for (int i = 0; i < e; i++){
        int f, s;
        cin >> f >> s;

        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    bool *visited = new bool[v];
    for(int i = 0; i < v; i++){
        visited[i] = false;
    }

    int start, end;
    cin >> start >> end;
    visited[start] = true;

    vector<int> path = getPath(v, edges, visited, start, end);

    if(path.size() != 0){
      for (int i = 0; i < path.size(); i++) {
        cout << path[i] << " ";
      }
    }

    for(int i = 0; i < v; i++){
        delete[] edges[i];
    }
    delete[] edges;
}