//
//  main.cpp
//  GraphTraversal
//
//  Created by Alok PS on 7/30/16.
//  Copyright © 2016 AlokPS. All rights reserved.
//


//DEPTH FIRST TRAVERSAL USES STACK-RECUSRION APPROACH WHERE AS THE THE BREADTH FIRST TRAVERSAL USES THE QUEUE APPROACH.

#include <iostream>
#include <list>

using namespace std;


//DFS uses a Stack and BFS uses Queue
class Graph{
    
private:
    int NumVertices;
    list<int> *Ptr2Adjlist;
    
public:
    Graph(int V);//Constructor
    void addEdge(int vertices, int edge);//Add edge to graph
    void DFS(int vertices); //DFS traversal of vertices reachable from v
    void DFSUtil(int vertex, bool visited[]);
    void BFS(int s); //prints BFS traversal
    bool Search(Graph g, int sVertex, int eVertex);
    
};


Graph::Graph(int vertices){
    
    this->NumVertices = vertices;
    Ptr2Adjlist = new list<int>[vertices];
}

void Graph::addEdge(int vertex, int edge){
    
    Ptr2Adjlist[vertex].push_back(edge);
}

void Graph::DFSUtil(int vertex, bool *visited){
 
    //Mark the current Node as Visited and print it
    visited[vertex] = true;
    cout << vertex << " ";
    
    for(auto k=Ptr2Adjlist[vertex].begin();k!=Ptr2Adjlist[vertex].end();k++){
        
        if(!visited[*k]){
            DFSUtil(*k, visited);
        }
    }
    
}

//DFS traversal of vertices reachable from the parameter
void Graph::DFS(int vertices){
    
    //Mark all the nodes as not visited
    bool *visited = new bool[vertices];
    
    for(int i=0;i<vertices;i++){
        visited[i] = false;
    }
    
    DFSUtil(vertices, visited);
    
}

void Graph::BFS(int s){
    
    //Mark all the Vertices as Not Visited
    bool *visited = new bool[NumVertices];
    for(int i=0;i<NumVertices;i++){
        visited[i] = false;
    }
    
    list<int> queue;
    
    visited[s] = true;
    queue.push_back(s);
    
    while (!queue.empty()) {
        
        s = queue.front();
        cout << s << " ";
        queue.pop_front();
        
        //Get all the adjacent vertices of the dequeues vertex s
        //If a adjacent has not been visited, then mark as visited and
        //enqueue it
        for(auto i= Ptr2Adjlist[s].begin();i!=Ptr2Adjlist[s].end();i++){
            
            if(!visited[*i]){
                visited[*i] = true;
                queue.push_back(*i);
            }
            
        }
    }
    
}

/*Given a directed graph, design an algorithm to find out whether there is a route
 between two nodes.*/
bool Graph::Search(Graph g, int sVertex, int eVertex){
    
    list<int> queue;

    bool *visited = new bool[NumVertices];
    for(int i=0;i<NumVertices;i++){
        visited[i] = false;
    }
    int j;
    queue.push_back(sVertex);
    while(!queue.empty()){
        j= queue.front();
        queue.pop_front();
        
        for(auto i=Ptr2Adjlist[j].begin();i!=Ptr2Adjlist[j].end();i++){
            
            if(!visited[*i]){
                if(*i == eVertex){
                    cout << "There is a edge between 2 vertices" << endl;
                    return true;
                }
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
    return false;
}


int main(int argc, const char * argv[]) {
   
    Graph mygraph(4);
    mygraph.addEdge(0, 1);
    mygraph.addEdge(0, 2);
    mygraph.addEdge(1, 2);
    mygraph.addEdge(2, 0);
    mygraph.addEdge(2, 3);
    mygraph.addEdge(3, 3);
    mygraph.addEdge(0, 3);

    cout << "The Following is the DFS Traversal (starting from vertex 2)" << endl;
    mygraph.DFS(2);
    cout << endl;
    cout << "The Following is the BFS Traversal (starting from vertex 2)" << endl;
    mygraph.BFS(2);
    cout << endl;
    mygraph.Search(mygraph, 0, 3);
    
    
    
    return 0;
}
