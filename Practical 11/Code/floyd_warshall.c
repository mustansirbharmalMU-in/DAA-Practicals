#include <stdio.h>

#define N 4
#define INF 9999

/*
   Floyd-Warshall Algorithm
   Find shortest path between every pair of vertices
*/

int main()
{
    // graph with 4 vertices: 0=A, 1=B, 2=C, 3=D
    // INF means no direct edge
    int graph[N][N] = {
        // A    B    C    D
        {  0,   3, INF,   7 }, // A
        {  8,   0,   2, INF }, // B
        {  5, INF,   0,   1 }, // C
        {  2, INF, INF,   0 }  // D
    };

    int dist[N][N];
    char name[] = {'A', 'B', 'C', 'D'};
    int i, j, k;

    // copy graph into distance matrix
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            dist[i][j] = graph[i][j];

    // try every middle vertex k
    for (k = 0; k < N; k++)
    {
        for (i = 0; i < N; i++)
        {
            for (j = 0; j < N; j++)
            {
                // if path i->k->j is shorter, update
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    printf("Shortest distances between every pair:\n\n");
    printf("    ");
    for (j = 0; j < N; j++)
        printf("%4c", name[j]);
    printf("\n");

    for (i = 0; i < N; i++)
    {
        printf("%c   ", name[i]);
        for (j = 0; j < N; j++)
        {
            if (dist[i][j] == INF)
                printf("%4s", "INF");
            else
                printf("%4d", dist[i][j]);
        }
        printf("\n");
    }

    printf("\nTime Complexity: O(V^3)\n");
    printf("Space Complexity: O(V^2)\n");

    return 0;
}
