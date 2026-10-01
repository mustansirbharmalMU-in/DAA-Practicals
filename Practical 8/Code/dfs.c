#include <stdio.h>

/*
   DFS - Depth First Search
   Go deep along one path, then backtrack
   Graph vertices: 0=A, 1=B, 2=C, 3=D, 4=E, 5=F
*/

int graph[6][6] = {
    {0, 1, 1, 0, 0, 0}, // A connected to B, C
    {1, 0, 0, 1, 1, 0}, // B connected to A, D, E
    {1, 0, 0, 0, 0, 1}, // C connected to A, F
    {0, 1, 0, 0, 0, 0}, // D connected to B
    {0, 1, 0, 0, 0, 1}, // E connected to B, F
    {0, 0, 1, 0, 1, 0}  // F connected to C, E
};

char name[] = {'A', 'B', 'C', 'D', 'E', 'F'};
int visited[6] = {0, 0, 0, 0, 0, 0};

void dfs(int node)
{
    int next;

    // visit current node
    printf("%c ", name[node]);
    visited[node] = 1;

    // visit all unvisited neighbours
    for (next = 0; next < 6; next++)
    {
        if (graph[node][next] == 1 && visited[next] == 0)
            dfs(next);
    }
}

int main()
{
    int start = 0;   // start from A

    printf("DFS Traversal:\n");
    dfs(start);

    printf("\n");
    printf("Time Complexity: O(V + E)\n");
    printf("Space Complexity: O(V)\n");

    return 0;
}
