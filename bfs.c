#include <stdio.h>
#include <stdbool.h>
#define MAX 100
int adj[MAX][MAX];
bool visited[MAX];
int n;
int queue[MAX], front = -1, rear = -1;
void enqueue(int vertex) {
if (rear == MAX - 1) return;
if (front == -1) front = 0;
rear++;
queue[rear] = vertex;
}
int dequeue() {
if (front == -1) return -1;
int item = queue[front];
front++;
if (front > rear) front = rear = -1;
return item;
}
void BFS(int v) {
enqueue(v);
visited[v] = true;
while (front != -1) {
int current = dequeue();
printf("%d "
, current);
for (int i = 0; i < n; i++) {
if (adj[current][i] && !visited[i]) {
enqueue(i);
visited[i] = true;
}
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
printf("BFS traversal order starting from vertex 0: ");
BFS(0);
return 0;
}