#include<iostream>
#include <vector>
#include<list> 
#define INF 2147483647;
using namespace std;  

int count = 0;

class Graph {
    private:
        int V;    
        list<int> *adj; 
        void AllPathsUtil (int v1, int v2, bool visited [], int path [], int index); 
    public: 
        Graph(int V);   
        bool pathExist; 
        void addEdge (int v, int w); 
        void AllPaths (int v1, int v2);
    
}; 
  
Graph::Graph(int V) { 
    this->V = V; 
    adj = new list<int> [V]; 
} 
  
void Graph::addEdge (int v, int w) { 
    adj[v].push_back(w);
    adj[w].push_back(v); 
} 

void Graph::AllPathsUtil (int v1, int v2, bool visited[], int path[], int index) { 
    visited[v1] = true;
    path[index] = v1;
    index++;

    if (v1 == v2) {
        int i;

        pathExist = true;
        for(i = 0; i < index-1; i++)
            cout << path[i] << "->";
        cout << path[i] << endl;
        count++;
    }
    else { 
        for (list<int>::iterator i = adj[v1].begin(); i != adj[v1].end(); ++i) 
            if (!visited[*i]) 
                AllPathsUtil(*i, v2, visited, path, index); 
    }

    index--;
    visited[v1] = false;
} 
  
void Graph::AllPaths (int v1, int v2) { 
    bool *visited = new bool [V]; 
    for (int i = 0; i < V; i++) 
        visited[i] = false;
    int *path = new int [V];
    int index = 0;
    count = 0;
    pathExist=false;
    
    AllPathsUtil(v1,v2,visited,path,index);
} 
  
int main () 
{
    int v;
    vector<vector<int>> matrix;
    cout << "Input the number of vertices: "; cin >> v; 
    Graph g(v);
    
    for (int i = 0; i < v; i++) {
        vector<int> temp;
        for (int j = 0; j < v; j++) {
            int number; cin >> number;
            temp.push_back(number);
        }
        matrix.push_back(temp);
    }
    for (int i = 0; i < v; i++)
        for (int j = 0; j < v; j++)
            if (matrix[i][j] == 1)
                g.addEdge(i, j);

    int ans = INF;
    for (int i = 0; i < v; i++)
        for (int j = 0; j < v; j++) {
            cout << "   Path between " << i << " and " << j << endl;
            if (i != j) {
                g.AllPaths(i, j);
                if (ans > count)
                    ans = count;
            }
            if (!g.pathExist)
                cout << "There is no path exist between " << i << " and " << j << endl;
        }
    
    cout << "Edge connectivity: " << ans << endl;

    return 0; 
} 