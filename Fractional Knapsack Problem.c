#include<stdio.h>
struct Item {
    int profit;
    int weight;
    float ratio;
};
int main() {
    int n, capacity;
    float totalProfit = 0;
    printf("Enter number of items: ");
    scanf("%d", &n);
    struct Item item[n];
    printf("Enter profit and weight of each item:\n");
    int i,j;
    for (i = 0; i < n; i++) {
        scanf("%d %d", &item[i].profit, &item[i].weight);
        item[i].ratio = (float)item[i].profit / item[i].weight;
    }
    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (item[i].ratio < item[j].ratio) {
                struct Item temp = item[i];
                item[i] = item[j];
                item[j] = temp;
            }
        }
    }
    printf("\nItems selected:\n");
    for ( i = 0; i < n; i++) {
        if (capacity >= item[i].weight) {
            printf("Item %d: profit %d, weight %d (full)\n",
                   i+1, item[i].profit, item[i].weight);
            totalProfit += item[i].profit;
            capacity -= item[i].weight;
        } else if (capacity > 0) {
            printf("Item %d: profit %.2f, weight %d (fraction %.2f)\n",
                   i+1, item[i].profit * ((float)capacity / item[i].weight),
                   capacity, (float)capacity / item[i].weight);
            totalProfit += item[i].profit * ((float)capacity / item[i].weight);
            capacity = 0;
        }
    }
    printf("\nMaximum Profit = %.2f\n", totalProfit);
    return 0;
}



