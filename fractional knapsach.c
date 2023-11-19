#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int weight;
    int value;
    double ratio;
} Item;

// Function to compare items based on their ratios
int compareItems(const void* a, const void* b) {
    Item* itemA = (Item*)a;
    Item* itemB = (Item*)b;
    return itemB->ratio - itemA->ratio;
}

void fractionalKnapsack(int capacity, Item items[], int n) {
    qsort(items, n, sizeof(Item), compareItems); // Sort items based on ratios
    
    double totalValue = 0.0;
    
    printf("Selected Items and Fractions:\n");

    for (int i = 0; i < n; i++) {
        if (capacity == 0) {
            break;
        }
        int quantity = (capacity < items[i].weight) ? capacity : items[i].weight;
        double fraction = (double)quantity / items[i].weight;
        totalValue += fraction * items[i].value;
        capacity -= quantity;
        printf("Item %d: %.2lf of weight, Profit: %.2lf\n", i + 1, fraction, fraction * items[i].value);
    }

    printf("Maximum value that can be obtained: %.2lf\n", totalValue);
}

int main() {
    printf("Rishita Chaubey - A2305221265\n\n");
    int capacity;
    printf("Enter the knapsack capacity: ");
    scanf("%d", &capacity);

    int n;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    Item items[n];
    for (int i = 0; i < n; i++) {
        printf("Enter the weight and value of item %d: ", i + 1);
        scanf("%d %d", &items[i].weight, &items[i].value);
        items[i].ratio = (double)items[i].value / items[i].weight;
    }

    fractionalKnapsack(capacity, items, n);

    return 0;
}
