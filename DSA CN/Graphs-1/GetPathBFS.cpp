#include <iostream>
#include <queue>
#include <map>
using namespace std;

void getPathBFS(int **edges, int v, int start, int end, bool *visited)
{
    queue<int> pendingVertices;
    map<int, int> m;
    pendingVertices.push(start);
    visited[start] = true;

    while (!pendingVertices.empty()){
        for (int i = 0; i < v; i++){

            if (visited[i]){
                continue;
            }

            if (i == pendingVertices.front()){
                continue;
            }

            if (edges[pendingVertices.front()][i]){
                pendingVertices.push(i);
                m[i] = pendingVertices.front();
                visited[i] = true;
            }
        }
        pendingVertices.pop();
    }

    if (!visited[end]){
        return;
    }
    int i = end;
    cout << end << " ";

    while (i != start){
        cout << m[i] << " ";
        i = m[i];
    }
}

int main(){
    int v, e;
    cin >> v >> e;

    int **edges = new int *[v];
    for(int i = 0; i < v; i++){
        edges[i] = new int[v];
        for (int j = 0; j < v; j++){
            edges[i][j] = false;
        }
    }

    for (int i = 0; i < e; i++){
        int f, s;
        cin >> f >> s;
        edges[f][s] = true;
        edges[s][f] = true;
    }

    bool *visited = new bool[v];
    for (int i = 0; i < v; i++){
        visited[i] = false;
    }

    int start, end;
    cin >> start >> end;
    getPathBFS(edges, v, start, end, visited);
    return 0;
}