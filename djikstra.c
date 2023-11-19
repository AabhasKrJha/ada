#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V 100 // Maximum number of vertices

void dijkstra(int graph[V][V], int source, int vertices) {
    int distance[vertices];  // To store the minimum distance from the source to each vertex
    int visited[vertices];  // To keep track of visited vertices
    int i, j, min_distance, u;

    // Initialize distance[] and visited[]
    for (i = 0; i < vertices; i++) {
        distance[i] = INT_MAX; // Set distance to infinity for all vertices
        visited[i] = 0; // Mark all vertices as not visited
    }

    distance[source] = 0; // Distance from source to itself is always 0

    // Find the shortest path for all vertices
    for (i = 0; i < vertices - 1; i++) {
        // Find the vertex with the minimum distance value among the unvisited vertices
        min_distance = INT_MAX;
        for (j = 0; j < vertices; j++) {
            if (!visited[j] && distance[j] < min_distance) {
                min_distance = distance[j];
                u = j;
            }
        }

        // Mark the selected vertex as visited
        visited[u] = 1;

        // Update distance values of adjacent vertices of the selected vertex
        for (j = 0; j < vertices; j++) {
            if (!visited[j] && graph[u][j] && (distance[u] + graph[u][j] < distance[j])) {
                distance[j] = distance[u] + graph[u][j];
            }
        }
    }

    // Print the shortest distances from the source vertex to all other vertices
    printf("Shortest distances from source vertex %d:\n", source);
    for (i = 0; i < vertices; i++) {
        printf("Vertex %d: %d\n", i, distance[i]);
    }
}

int main() {
    printf("AABHAS KUMAR JHA - A2305221279\n\n");
    
    int graph[V][V];
    int vertices, source;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter the adjacency matrix of the graph (0 for no edge, positive values for edge weights):\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the source vertex: ");
    scanf("%d", &source);

    dijkstra(graph, source, vertices);

    return 0;
}
