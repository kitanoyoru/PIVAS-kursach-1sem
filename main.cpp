# // C++ program to print the paths between two vertices
#include<iostream> 
#include<list> 
using namespace std;  

class Graph {
    private: 
        int V;    
        list<int> *adj; 
        void printAllPathsUtil(int v1, int v2, bool visited[], int path[], int index); 
    public: 
        Graph(int V);   
        bool pathExist; 
        void addEdge(int v, int w); 
        void printAllPaths(int v1, int v2);
    
}; 
  
Graph::Graph(int V) { 
    this->V = V; 
    adj = new list<int>[V]; 
} 
  
void Graph::addEdge(int v, int w) { 
    adj[v].push_back(w);
    adj[w].push_back(v); 
} 

void Graph::printAllPathsUtil(int v1, int v2, bool visited[], int path[], int index) { 

    visited[v1] = true;
    path[index]=v1;
    index++;

    if(v1==v2){
        int i;
        if(!pathExist)
            cout<<"Following are the paths between "<<path[0]<<" and "<<path[index-1] << endl;
        pathExist=true;
        for(i=0;i<index-1;i++)
            cout<<path[i]<<"->";
        cout<<path[i]<<endl;
    }
    else { 
        list<int>::iterator i; 
        for (i = adj[v1].begin(); i != adj[v1].end(); ++i) 
            if (!visited[*i]) 
                printAllPathsUtil(*i, v2, visited, path, index); 
    }

    index--;
    visited[v1]=false;
} 
  
void Graph::printAllPaths(int v1, int v2) { 
    bool *visited = new bool[V]; 
    for (int i = 0; i < V; i++) 
        visited[i] = false;
        
    int *path = new int[V];
    
    int index = 0;
    
    pathExist=false;
    
    printAllPathsUtil(v1,v2,visited,path,index);
} 
  
int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
	
    int v1=0, v2=3;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++) {
            cout << "   Path between " << i << " and " << j << endl;
            if (i != j)
                g.printAllPaths(i, j);
            if (!g.pathExist)
                cout << "There is no path exist between " << i << " and " << j << endl;
        }

    return 0; 
} 