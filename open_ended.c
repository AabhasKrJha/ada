#include <stdio.h>

#define MAX_COURSES 100
#define MAX_CREDITS 1000

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack_brute_force(int credits[], int grades[], int n, int credit_limit) {
    int i, j;
    int max_gpa = 0;
    int max_combination = 0;

    for (i = 0; i < (1 << n); i++) {
        int total_credits = 0;
        int total_gpa = 0;

        for (j = 0; j < n; j++) {
            if (i & (1 << j)) {
                total_credits += credits[j];
                total_gpa += grades[j];
            }
        }

        if (total_credits <= credit_limit && total_gpa > max_gpa) {
            max_gpa = total_gpa;
            max_combination = i;
        }
    }

    printf("Solution vector (brute force): [");
    for (i = 0; i < n; i++) {
        if (max_combination & (1 << i)) {
            printf("1");
        } else {
            printf("0");
        }
        if (i < n - 1) {
            printf(", ");
        }
    }
    printf("]\n");

    return (int) (max_gpa/40);
}


int knapsack_dynamic_programming(int credits[], int grades[], int n, int credit_limit) {
    int i, j;
    int table[MAX_COURSES + 1][MAX_CREDITS + 1];

    for (i = 0; i <= n; i++) {
        for (j = 0; j <= credit_limit; j++) {
            if (i == 0 || j == 0) {
                table[i][j] = 0;
            } else if (credits[i - 1] <= j) {
                table[i][j] = max(grades[i - 1] + table[i - 1][j - credits[i - 1]], table[i - 1][j]);
            } else {
                table[i][j] = table[i - 1][j];
            }
        }
    }

    printf("Solution vector (dynamic programming): [");
    i = n;
    j = credit_limit;
    while (i > 0 && j > 0) {
        if (table[i][j] != table[i - 1][j]) {
            printf("1");
            j -= credits[i - 1];
        } else {
            printf("0");
        }
        i--;
        if (i > 0 && j > 0) {
            printf(", ");
        }
    }
    printf("]\n");

    return (int) (table[n][credit_limit] / 40);
}


int knapsack_greedy(int credits[], int grades[], int n, int credit_limit) {
    int i, j;
    int max_gpa = 0;
    int solution[MAX_COURSES] = {0};

    // Sort the courses by GPA in descending order
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (grades[i] < grades[j]) {
                int temp = grades[i];
                grades[i] = grades[j];
                grades[j] = temp;
                temp = credits[i];
                credits[i] = credits[j];
                credits[j] = temp;
            }
        }
    }

    // Select the courses with the highest GPA until the credit limit is reached
    for (i = 0; i < n; i++) {
        if (credits[i] <= credit_limit) {
            solution[i] = 1;
            max_gpa += grades[i];
            credit_limit -= credits[i];
        }
    }

    printf("Solution vector (greedy): [");
    for (i = 0; i < n; i++) {
        printf("%d", solution[i]);
        if (i < n - 1) {
            printf(", ");
        }
    }
    printf("]\n");

    return (int) (max_gpa/40);
}



int main() {

    int credits[MAX_COURSES];
    int grades[MAX_COURSES];
    int n, i;

    printf("Enter the number of courses: ");
    scanf("%d", &n);

    printf("Enter the credits and grades for each course:\n");
    for (i = 0; i < n; i++) {
        printf("Course %d: ", i + 1);
        scanf("%d %d", &credits[i], &grades[i]);
    }

    float prev_gpa;
    int credit_limit;

    printf("Enter your previous semester GPA: ");
    scanf("%f", &prev_gpa);

    credit_limit = (int) (prev_gpa * 4);

    printf("Your credit limit for this semester is: %d\n", credit_limit);

    knapsack_brute_force(credits, grades, n, credit_limit);

    knapsack_dynamic_programming(credits, grades, n, credit_limit);

    knapsack_greedy(credits, grades, n, credit_limit);

    return 0;

}


