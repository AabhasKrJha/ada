#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 100

typedef struct Edge {
    int source, destination, weight;
} Edge;

typedef struct Graph {
    int V, E;
    Edge* edges;
} Graph;

Graph* createGraph(int V, int E) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    graph->E = E;
    graph->edges = (Edge*)malloc(E * sizeof(Edge));
    return graph;
}

int minKey(int key[], int mstSet[], int V) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (mstSet[v] == 0 && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }

    return min_index;
}

void printMST(int parent[], int key[], int V) {
    printf("Edges in MST using Prim's Algorithm:\n");
    for (int i = 1; i < V; i++)
        printf("%d -- %d Weight: %d\n", parent[i], i, key[i]);

    int totalCost = 0;
    for (int i = 0; i < V; i++)
        totalCost += key[i];
    
    printf("Total cost of MST: %d\n", totalCost);
}

void primMST(Graph* graph, int startVertex) {
    int V = graph->V;
    int key[MAX_VERTICES];    // Key values used to pick minimum weight edge in cut
    int parent[MAX_VERTICES]; // Array to store constructed MST
    int mstSet[MAX_VERTICES]; // To represent set of vertices included in MST

    // Initialize all keys as INFINITE
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    // Make the key 0 so that this vertex is picked as the first vertex.
    key[startVertex] = 0;
    parent[startVertex] = -1; // First node is always the root of MST

    // The MST will have V vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum key vertex from the set of vertices not yet included in MST
        int u = minKey(key, mstSet, V);

        // Add the picked vertex to the MST Set
        mstSet[u] = 1;

        // Update key value and parent index of the adjacent vertices
        // of the picked vertex. Consider only those vertices which are not
        // yet included in the MST
        for (int v = 0; v < V; v++) {
            // Update the key only if graph[u][v] is smaller than key[v]
            if (graph->edges[u * V + v].weight && mstSet[v] == 0 && graph->edges[u * V + v].weight < key[v]) {
                parent[v] = u;
                key[v] = graph->edges[u * V + v].weight;
            }
        }
    }

    // print the constructed MST
    printMST(parent, key, V);
}

int main() {
    int V, E;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    printf("Enter the number of edges: ");
    scanf("%d", &E);

    Graph* graph = createGraph(V, E);

    printf("Enter the edges (source, destination, weight):\n");
    for (int i = 0; i < E; i++)
        scanf("%d %d %d", &(graph->edges[i].source), &(graph->edges[i].destination), &(graph->edges[i].weight));

    int startVertex;
    printf("Enter the starting vertex: ");
    scanf("%d", &startVertex);

    primMST(graph, startVertex);

    free(graph->edges);
    free(graph);

    return 0;
}
