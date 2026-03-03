#include <stdio.h>
int matrix[25][25], visited_cities[25];
int limit, cost = 0;
int tsp(int c)
{
    int count;
    int nearest_city =-1;
    int minimum = 999;
    for(count = 0; count < limit; count++)
    {
        if((matrix[c][count] != 0) && (visited_cities[count] == 0))
        {
            if(matrix[c][count] < minimum)
            {
                minimum = matrix[c][count];
                nearest_city = count;
            }
        }
    }
    if(nearest_city != -1)
    {
        cost += minimum;
    }
    return nearest_city;
}
void minimum_cost(int city)
{
    int nearest_city;
    visited_cities[city] = 1;
    printf("%d ", city + 1);
    nearest_city = tsp(city);
    if(nearest_city == -1)
    {
        printf("1 ");
        cost += matrix[city][0];
        return;
    }
    minimum_cost(nearest_city);
}
int main()
{
    int i, j;
    printf("Enter Total Number of Cities: ");
    scanf("%d", &limit);
    printf("\nEnter Cost Matrix:\n");
    for(i = 0; i < limit; i++)
    {
        for(j = 0; j < limit; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
        visited_cities[i] = 0;
    }
    printf("\nEntered Cost Matrix:\n");
    for(i = 0; i < limit; i++)
    {
        for(j = 0; j < limit; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\nPath: ");
    minimum_cost(0);
    printf("\nMinimum Cost: %d\n", cost);
    return 0;
}
