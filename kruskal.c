#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 100

typedef struct Edge {
    int source, destination, weight;
} Edge;

typedef struct Graph {
    int V, E;
    Edge* edges;
} Graph;

typedef struct Subset {
    int parent;
    int rank;
} Subset;

Graph* createGraph(int V, int E) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    graph->E = E;
    graph->edges = (Edge*)malloc(E * sizeof(Edge));
    return graph;
}

int find(Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);

    return subsets[i].parent;
}

void Union(Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

int compareEdges(const void* a, const void* b) {
    return ((Edge*)a)->weight - ((Edge*)b)->weight;
}

void kruskalMST(Graph* graph) {
    int V = graph->V;
    Edge result[V]; // Store the resultant MST
    int e = 0;       // An index variable, used for the result[]
    int i = 0;       // An index variable, used for the sorted edges

    qsort(graph->edges, graph->E, sizeof(graph->edges[0]), compareEdges);

    Subset* subsets = (Subset*)malloc(V * sizeof(Subset));

    for (int v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    while (e < V - 1 && i < graph->E) {
        Edge next_edge = graph->edges[i++];

        int x = find(subsets, next_edge.source);
        int y = find(subsets, next_edge.destination);

        if (x != y) {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }

    printf("Edges in MST using Kruskal's Algorithm:\n");
    for (int j = 0; j < e; j++)
        printf("%d -- %d Weight: %d\n", result[j].source, result[j].destination, result[j].weight);

    free(subsets);
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

    kruskalMST(graph);

    free(graph->edges);
    free(graph);

    return 0;
}
