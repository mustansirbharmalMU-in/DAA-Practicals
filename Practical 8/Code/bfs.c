#include <stdio.h>

#define MAX 20

/*
   BFS - Breadth First Search
   Visit vertices level by level using a queue
   Graph vertices: 0=A, 1=B, 2=C, 3=D, 4=E, 5=F
*/

int main()
{
    // adjacency list for the graph
    // A-B, A-C, B-D, B-E, C-F, E-F
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

    int queue[MAX];
    int front = 0, rear = 0;
    int start = 0;   // start from A
    int node, next;

    printf("BFS Traversal:\n");

    // put start node in queue and mark visited
    queue[rear++] = start;
    visited[start] = 1;

    while (front < rear)
    {
        // take one node from front of queue
        node = queue[front++];
        printf("%c ", name[node]);

        // add all unvisited neighbours to queue
        for (next = 0; next < 6; next++)
        {
            if (graph[node][next] == 1 && visited[next] == 0)
            {
                queue[rear++] = next;
                visited[next] = 1;
            }
        }
    }

    printf("\n");
    printf("Time Complexity: O(V + E)\n");
    printf("Space Complexity: O(V)\n");

    return 0;
}
