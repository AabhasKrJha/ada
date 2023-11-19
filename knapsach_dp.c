#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

void knapsack(int capacity, int weights[], int values[], int n) {
    int dp[n + 1][capacity + 1];
    int selected[n + 1];

    // Initialize the selected array
    for (int i = 0; i <= n; i++) {
        selected[i] = 0;
    }

    // Build the dp table using dynamic programming
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (weights[i - 1] <= w) {
                int withItem = values[i - 1] + dp[i - 1][w - weights[i - 1]];
                int withoutItem = dp[i - 1][w];
                if (withItem > withoutItem) {
                    dp[i][w] = withItem;
                    selected[i] = 1;
                } else {
                    dp[i][w] = withoutItem;
                    selected[i] = 0;
                }
            } else {
                dp[i][w] = dp[i - 1][w];
                selected[i] = 0;
            }
        }
    }

    printf("Maximum profit that can be obtained: %d\n", dp[n][capacity]);

    // Print the selected items
    printf("Items selected: ");
    int w = capacity;
    for (int i = n; i >= 1; i--) {
        if (selected[i] == 1) {
            printf("Item %d ", i);
            w -= weights[i - 1];
        }
    }
    printf("\n");
}

int main() {
    printf("AABHAS KUMAR JHA - A2305221279\n\n");
    int capacity, n;

    printf("Enter the knapsack capacity: ");
    scanf("%d", &capacity);

    printf("Enter the number of items: ");
    scanf("%d", &n);

    int weights[n], values[n];

    for (int i = 0; i < n; i++) {
        printf("Enter weight and value for item %d: ", i + 1);
        scanf("%d %d", &weights[i], &values[i]);
    }

    knapsack(capacity, weights, values, n);

    return 0;
}
