#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
bool isSafe(int board[], int row, int col, int N) {
for (int i = 0; i < col; i++) {
if (board[i] == row || board[i] - i == row - col || board[i] + i == row + col)
return false;
}
return true;
}
bool solveNQueens(int board[], int col, int N) {
if (col >= N) {
for (int i = 0; i < N; i++) {
for (int j = 0; j < N; j++) {
printf("%d ", (board[i] == j) ? 1 : 0);
}
printf("\n");
}
return true;
}
for (int i = 0; i < N; i++) {
if (isSafe(board, i, col, N)) {
board[col] = i;
if (solveNQueens(board, col + 1, N)) return true;
board[col] = -1; // backtrack
}
}
return false;
}
int main() {
int N;
printf("Rishita Chaubey A2305221265\n");
printf("Enter the number of queens (board size): ");
scanf("%d"
, &N);
int* board = (int*)malloc(N * sizeof(int));
for (int i = 0; i < N; i++) {
board[i] = -1;
}
if (!solveNQueens(board, 0, N)) {
printf("Solution does not exist.");
}
free(board);
return 0;
}