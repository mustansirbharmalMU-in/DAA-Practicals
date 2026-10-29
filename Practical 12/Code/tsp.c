#include <stdio.h>

#define N 4
#define INF 9999

/*
   Travelling Salesman Problem (TSP)
   Find minimum cost to visit all cities exactly once
   and return to the starting city
   Method: try all possible paths (brute force / backtracking)
*/

int graph[N][N] = {
    // A  B  C  D
    { 0, 10, 15, 20 }, // A
    {10,  0, 35, 25 }, // B
    {15, 35,  0, 30 }, // C
    {20, 25, 30,  0 }  // D
};

char name[] = {'A', 'B', 'C', 'D'};
int visited[N];
int min_cost = INF;

// path stores the current route
int path[N + 1];
int best_path[N + 1];

void tsp(int city, int count, int cost)
{
    int next;

    // if all cities visited, return to start
    if (count == N)
    {
        if (graph[city][0] != 0)
        {
            int total = cost + graph[city][0];
            if (total < min_cost)
            {
                min_cost = total;

                // save best path
                int i;
                for (i = 0; i < N; i++)
                    best_path[i] = path[i];
                best_path[N] = 0; // back to A
            }
        }
        return;
    }

    // try every unvisited city
    for (next = 0; next < N; next++)
    {
        if (visited[next] == 0 && graph[city][next] != 0)
        {
            visited[next] = 1;
            path[count] = next;

            tsp(next, count + 1, cost + graph[city][next]);

            visited[next] = 0; // backtrack
        }
    }
}

int main()
{
    int i;

    for (i = 0; i < N; i++)
        visited[i] = 0;

    // start from city A (0)
    visited[0] = 1;
    path[0] = 0;

    tsp(0, 1, 0);

    printf("Travelling Salesman Problem\n");
    printf("---------------------------\n");
    printf("Best path: ");
    for (i = 0; i <= N; i++)
    {
        printf("%c", name[best_path[i]]);
        if (i < N)
            printf(" -> ");
    }
    printf("\nMinimum cost: %d\n", min_cost);
    printf("Time Complexity: O(N!)\n");
    printf("Space Complexity: O(N)\n");

    return 0;
}
