#include <stdio.h>

#define INF 9999
#define N 5   // number of vertices A B C D E

/*
   Prim's Algorithm
   Find Minimum Spanning Tree (MST)
   Vertices: 0=A, 1=B, 2=C, 3=D, 4=E
*/

int main()
{
    // weight matrix of the graph
    // 0 means no self edge, INF means no connection
    int graph[N][N] = {
        // A    B    C    D    E
        {  0,   2, INF,   6, INF }, // A
        {  2,   0,   3,   8,   5 }, // B
        {INF,   3,   0, INF,   7 }, // C
        {  6,   8, INF,   0,   9 }, // D
        {INF,   5,   7,   9,   0 }  // E
    };

    char name[] = {'A', 'B', 'C', 'D', 'E'};
    int visited[N] = {0, 0, 0, 0, 0};

    int edges_needed = N - 1;   // MST has V-1 edges
    int total_cost = 0;
    int count = 0;

    int i, j;
    int from, to, min_weight;

    // start from vertex A
    visited[0] = 1;

    printf("Edges in Minimum Spanning Tree:\n");

    while (count < edges_needed)
    {
        min_weight = INF;
        from = -1;
        to = -1;

        // find smallest edge from visited to not visited
        for (i = 0; i < N; i++)
        {
            if (visited[i] == 1)
            {
                for (j = 0; j < N; j++)
                {
                    if (visited[j] == 0 && graph[i][j] < min_weight)
                    {
                        min_weight = graph[i][j];
                        from = i;
                        to = j;
                    }
                }
            }
        }

        // add this edge to MST
        visited[to] = 1;
        total_cost = total_cost + min_weight;
        count++;

        printf("%c - %c : %d\n", name[from], name[to], min_weight);
    }

    printf("Total cost of MST: %d\n", total_cost);
    printf("Time Complexity: O(V^2)\n");
    printf("Space Complexity: O(V)\n");

    return 0;
}
