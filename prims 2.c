//prims

#include <stdio.h>
#include <stdlib.h>

#define MAX_EDGES 50
#define MAX_VERTICES 30
#define INF 1000000  // Define a large value for infinity

struct Edge {
    int source, destination, weight;
};

struct Graph {
    int numVertices, numEdges;
    struct Edge edges[MAX_EDGES];
};

int minKey(int key[], int mstSet[], int numVertices) {
    int min = INF, min_index;
    for (int v = 0; v < numVertices; v++)
        if (!mstSet[v] && key[v] < min)
            min = key[v], min_index = v;
    return min_index;
}

void prims(struct Graph graph) {
    int parent[MAX_VERTICES];
    int key[MAX_VERTICES];
    int mstSet[MAX_VERTICES];

    for (int i = 0; i < graph.numVertices; i++) {
        key[i] = INF;
        mstSet[i] = 0;
    }

    printf("Enter the starting vertex: ");
    int startVertex;
    scanf("%d", &startVertex);

    key[startVertex] = 0;
    parent[startVertex] = -1;

    for (int count = 0; count < graph.numVertices - 1; count++) {
        int u = minKey(key, mstSet, graph.numVertices);
        mstSet[u] = 1;

        for (int v = 0; v < graph.numVertices; v++) {
            if (graph.edges[v].weight && !mstSet[v] && graph.edges[v].weight < key[v]) {
                parent[v] = u;
                key[v] = graph.edges[v].weight;
            }
        }
    }

    printf("\nEdges in MST using Prim's Algorithm:\n");
    int totalCost = 0;
    for (int i = 1; i < graph.numVertices; i++) {
        printf("%d -- %d Weight: %d\n", parent[i], i, graph.edges[i].weight);
        totalCost += graph.edges[i].weight;
    }
    printf("Total cost of MST: %d\n", totalCost);
}

int main() {
    printf("Rishita Chaubey - A2305221265\n\n");
    int numVertices, numEdges;
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    struct Graph graph;
    graph.numVertices = numVertices;
    graph.numEdges = 0;

    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    printf("Enter the edges (source, destination, weight):\n");
    for (int i = 0; i < numEdges; i++) {
        int source, destination, weight;
        scanf("%d %d %d", &source, &destination, &weight);
        graph.edges[graph.numEdges].source = source;
        graph.edges[graph.numEdges].destination = destination;
        graph.edges[graph.numEdges].weight = weight;
        graph.numEdges++;
    }

    prims(graph);

    return 0;
}

