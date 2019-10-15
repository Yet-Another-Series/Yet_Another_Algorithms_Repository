import java.util.*;
import java.lang.*;
import java.io.*;
 
public class minimumPath {

    // Function to find the vertex with the shortest distance value
    // of the vertex set that is not yet included in the tree
	
    static final int V=9;
    int shortestDistance(int dist[], Boolean sptSet[]) {
    
        // Initializing minimum value
        int min = Integer.MAX_VALUE, min_index=-1;
 
        for (int v = 0; v < V; v++)
            if (sptSet[v] == false && dist[v] <= min) {
            
                min = dist[v];
                min_index = v;
            }
 
        return min_index;
    }
 
    // Function to print the constructed distance array
    
    void printSolution(int dist[], int n) {
    
        System.out.println("Vertice    Distancia da origem");
        for (int i = 0; i < V; i++)
            System.out.println(i+" -------------> "+dist[i]);
    }
 
    // Function that implements the dijkstra algorithm 
    // for a graph represented using adjacency matrix

    void dijkstra(int graph[][], int src) {
    
    	// The output array dist[i] stores the shortest distance from origin to i
        int dist[] = new int[V];
 
        // sptSet[i] is true if vertex i is included in the shortest path tree
        // or when the shortest distance from origin to i is found
        Boolean sptSet[] = new Boolean[V];
 
        // Initializing all distances as infinite and sptSet [] as false
        for (int i = 0; i < V; i++) {
        
            dist[i] = Integer.MAX_VALUE;
            sptSet[i] = false;
        }
 
        // Distance from origin to itself is always 0
        dist[src] = 0;
 
        // Find the shortest path to all vertices
        for (int count = 0; count < V-1; count++) {
        
            // Chooses the shortest distance vertex from the unprocessed vertex set
            // u is always equal to origin in the first iteration
        	
            int u = shortestDistance(dist, sptSet);
 
            // Marks the selected vertex as processed
            sptSet[u] = true;
 
            // Updates the ajdacent vertices dist value to the chosen vertex
            for (int v = 0; v < V; v++)
 
                // Updates dist[v] if it is not in sptSet, theres an edge from u to v
                // and the total weight of the path from origin to v through u is
                // less than the current dist[v] value
                if (!sptSet[v] && graph[u][v]!=0 &&
                        dist[u] != Integer.MAX_VALUE &&
                        dist[u]+graph[u][v] < dist[v])
                    dist[v] = dist[u] + graph[u][v];
        }
 
        // Prints the constructed array
        printSolution(dist, V);
    }
 
    // Main
    public static void main (String[] args) {
    
        // graph adjacency matrix
       int graph[][] = new int[][]{{0, 4, 0, 0, 0, 0, 0, 8, 0},
                                  {4, 0, 8, 0, 0, 0, 0, 11, 0},
                                  {0, 8, 0, 7, 0, 4, 0, 0, 2},
                                  {0, 0, 7, 0, 9, 14, 0, 0, 0},
                                  {0, 0, 0, 9, 0, 10, 0, 0, 0},
                                  {0, 0, 4, 14, 10, 0, 2, 0, 0},
                                  {0, 0, 0, 0, 0, 2, 0, 1, 6},
                                  {8, 11, 0, 0, 0, 0, 1, 0, 7},
                                  {0, 0, 2, 0, 0, 0, 6, 7, 0}
                                 };
        minimumPath t = new minimumPath();
        t.dijkstra(graph, 0);
    }
}
