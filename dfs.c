#include <stdio.h>
#include <stdbool.h>
#define MAX 100
int adj[MAX][MAX];
bool visited[MAX];
int n;
void DFS(int v) {
visited[v] = true;
printf("%d "
, v);
for (int i = 0; i < n; i++) {
if (adj[v][i] && !visited[i]) {
DFS(i);
}
}
}
int main() {
int edges, x, y;
printf("Rishita Chaubey A2305221265\n");
printf("Enter the number of vertices and edges: ");
scanf("%d %d"
, &n, &edges);
printf("Enter the edges (format: vertex1 vertex2):\n");
for (int i = 0; i < edges; i++) {
scanf("%d %d"
, &x, &y);
adj[x][y] = 1;
adj[y][x] = 1;
}
for (int i = 0; i < n; i++) {
visited[i] = false;
}
printf("DFS traversal order starting from vertex 0: ");
DFS(0);
return 0;
}