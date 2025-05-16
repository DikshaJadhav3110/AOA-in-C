#include <stdio.h>
#include <stdlib.h>

struct Item
{
    int weight, value;
    int index;
};

int compare(const void *a, const void *b)
{
    double r1 = (double)((struct Item *)a)->value / ((struct Item *)a)->weight;
    double r2 = (double)((struct Item *)b)->value / ((struct Item *)b)->weight;
    return (r2 > r1) ? 1 : -1;
}

double fractionalKnapsack(int capacity, struct Item items[], int n)
{
    qsort(items, n, sizeof(struct Item), compare);

    double totalValue = 0.0;
    printf("Items taken (indexing from 0):\n");

    for (int i = 0; i < n && capacity > 0; i++)
    {
        if (items[i].weight <= capacity)
        {
            totalValue += items[i].value;
            capacity -= items[i].weight;
            printf("Item %d: 100%% (val=%d, wt=%d)\n", items[i].index, items[i].value, items[i].weight);
        }
        else
        {
            double fraction = (double)capacity / items[i].weight;
            totalValue += items[i].value * fraction;
            printf("Item %d: %.2f%% (val=%d, wt=%d)\n", items[i].index, fraction * 100, items[i].value, items[i].weight);
            break;
        }
    }

    return totalValue;
}

int main()
{
    struct Item items[] = {{10, 60}, {20, 100}, {30, 120}};
    int capacity = 50;
    int n = sizeof(items) / sizeof(items[0]);

    double maxVal = fractionalKnapsack(capacity, items, n);
    printf("Greedy Knapsack: Max value = %.2f\n", maxVal);
    return 0;
}
