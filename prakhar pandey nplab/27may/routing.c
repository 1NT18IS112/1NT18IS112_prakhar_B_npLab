#include <stdio.h>
#include<string.h>
struct node
{
    unsigned dist[20];
    unsigned from[20];
} router[10];
int main()
{
    int nodes, e;
    printf("enter no of nodes and edges\n");
    scanf("%d%d", &nodes, &e);
    int costmat[nodes][nodes];
    memset(costmat, 999, sizeof(costmat));
    int count, i, j, k;
    printf("Enter all the edges with weight\n");
    while (e--)
    {
        int v1, v2, w;
        scanf("%d%d%d", &v1, &v2, &w);
        costmat[v1-1][v2-1] = w;
        costmat[v2-1][v1-1] = w;
    }
    for (i = 0; i < nodes; i++)
    {
        for (j = 0; j < nodes; j++)
        {
            costmat[i][i] = 0;
            router[i].dist[j] = costmat[i][j];
            router[i].from[j] = j;
        }
    }
    count = 0;
    for (i = 0; i < nodes; i++)
    for (j = 0; j < nodes; j++)
    for (k = 0; k < nodes; k++)
    if (router[i].dist[j] > costmat[i][k] + router[k].dist[j])
    {
        router[i].dist[j] = router[i].dist[k] + router[k].dist[j];
        router[i].from[j] = k;
        count++;
    }
    for (i = 0; i < nodes; i++)
    {
        printf("To reach router(node) %d\n", i + 1);
        printf("Source Distance Hop\n");
        for (j = 0; j < nodes; j++)
        {
            if (i != j)
            {
                printf("%d\t%d\t%d\n", j + 1, router[i].dist[j], router[i].from[j] + 1);
            }
        }
        printf("\n\n");
    }
}
