/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <limits.h>
using namespace std;

#define V 6     // Number of vertices in the graph

void dijkstra(int graph[V][V], int s, float avgDist[V]);
int minDist(int dist[], bool visited[]);
void printDist(int dist[], int s);


int main()
{
    int graph[V][V] = {{0,10,0,0,15,5},
                    {10,0,10,30,0,0},
                    {0,10,0,12,5,0},
                    {0,30,12,0,0,20},
                    {15,0,5,0,0,0},
                    {5,0,0,20,0,0}};
    
    float avgDist[V];
    
    for(int s=0; s<V; s++){
        dijkstra(graph, s, avgDist);
    }
    
    for(int s=0; s<V; s++){
        cout<< "average distance from city "<< s<<"\t\t"<<avgDist[s]<<endl;
    }
}




void dijkstra(int graph[V][V], int s, float avgDist[V])
{
    int dist[V]; //upper bound to the minimum distance from the source
    int prev[V]; //previous vertex in discovered shortest path
  
    bool visited[V]; // true if visited
  
    for (int i = 0; i < V; i++){
        dist[i] = INT_MAX;
        visited[i] = false;
    }
  
    // Distance of source vertex from itself is always 0
    dist[s] = 0;
  
    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum distance vertex from unvisited vertices
        int u = minDist(dist, visited);
        visited[u] = true;
  
        // Update dist value of the adjacent vertices of the
        // picked vertex.
        
        for (int v = 0; v < V; v++){
  
            // relax the edge (u,v)
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
            {
                   dist[v] = dist[u] + graph[u][v];
                   prev[v] = u;
            }
        }
    }
  
    // print the distances
    printDist(dist, s);
    
    // calculate the average distance from source
    int ttl_dist = 0;
    for(int v=0 ; v<V; v++){
        ttl_dist += dist[v];
    }
    avgDist[s] = ttl_dist/V; 
}




int minDist(int dist[], bool visited[])
{
  
    // Initialize min value
    int min = INT_MAX, min_index;
  
    for (int v = 0; v < V; v++)
        if (visited[v] == false && dist[v] <= min){
            min = dist[v];
            min_index = v;
        }
  
    return min_index;
}



void printDist(int dist[], int s)
{
    cout << "Vertex \t Distance from " << s << endl;
    for (int i = 0; i < V; i++){
        cout << i << " \t\t\t\t" << dist[i] << endl;
    }
    cout << endl;
}
