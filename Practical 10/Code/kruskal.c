#include <stdio.h>

#define MAX 20

/*
   Kruskal's Algorithm
   Find Minimum Spanning Tree (MST)
   Pick cheapest edges that do not form a cycle
*/

// Edge structure: from, to, weight
struct Edge
{
    int u, v, w;
};

char name[] = {'A', 'B', 'C', 'D', 'E'};
int parent[MAX];

// find root of a vertex (for cycle check)
int find(int x)
{
    if (parent[x] == x)
        return x;
    return find(parent[x]);
}

// join two sets
void unite(int a, int b)
{
    int rootA = find(a);
    int rootB = find(b);
    parent[rootA] = rootB;
}

int main()
{
    // same graph used in Prim's practical
    // A-B:2, A-D:6, B-C:3, B-D:8, B-E:5, C-E:7, D-E:9
    struct Edge edges[7] = {
        {0, 1, 2}, // A-B
        {0, 3, 6}, // A-D
        {1, 2, 3}, // B-C
        {1, 3, 8}, // B-D
        {1, 4, 5}, // B-E
        {2, 4, 7}, // C-E
        {3, 4, 9}  // D-E
    };

    int n = 5;          // number of vertices
    int e = 7;          // number of edges
    int i, j;
    int total_cost = 0;
    int mst_edges = 0;

    // sort edges by weight (simple bubble sort)
    for (i = 0; i < e - 1; i++)
    {
        for (j = 0; j < e - i - 1; j++)
        {
            if (edges[j].w > edges[j + 1].w)
            {
                struct Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }

    // each vertex is its own parent at start
    for (i = 0; i < n; i++)
        parent[i] = i;

    printf("Edges in Minimum Spanning Tree:\n");

    // pick edges one by one (cheapest first)
    for (i = 0; i < e; i++)
    {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;

        // if u and v are in different sets, no cycle
        if (find(u) != find(v))
        {
            printf("%c - %c : %d\n", name[u], name[v], w);
            unite(u, v);
            total_cost = total_cost + w;
            mst_edges++;
        }

        // MST is complete when we have n-1 edges
        if (mst_edges == n - 1)
            break;
    }

    printf("Total cost of MST: %d\n", total_cost);
    printf("Time Complexity: O(E log E)\n");
    printf("Space Complexity: O(V)\n");

    return 0;
}
