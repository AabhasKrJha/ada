#include <stdio.h>
#include <string.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

void lcs(char *X, char *Y, int m, int n) {
    int dp[m + 1][n + 1];

    // Build the dp table using dynamic programming
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    // Find the LCS length
    int lcsLength = dp[m][n];

    // Create an array to store the LCS
    char lcsSequence[lcsLength + 1];
    lcsSequence[lcsLength] = '\0'; // Null-terminate the string

    // Backtrack to find the LCS
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcsSequence[--lcsLength] = X[i - 1];
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }

    // Print the LCS
    printf("Longest Common Subsequence: %s\n", lcsSequence);
}

int main() {
        printf("AABHAS KUMAR JHA - A2305221279\n\n");


    char X[100], Y[100];

    printf("Enter the first string: ");
    scanf("%s", X);

    printf("Enter the second string: ");
    scanf("%s", Y);

    int m = strlen(X);
    int n = strlen(Y);

    lcs(X, Y, m, n);

    return 0;
}
