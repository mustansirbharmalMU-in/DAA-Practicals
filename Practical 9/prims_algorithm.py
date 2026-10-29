# Prim's Algorithm

graph = [
    ('A', 'B', 2),
    ('A', 'D', 6),
    ('B', 'C', 3),
    ('B', 'D', 8),
    ('B', 'E', 5),
    ('C', 'E', 7),
    ('D', 'E', 9)
]

# Set of vertices
vertices = {'A', 'B', 'C', 'D', 'E'}

# Start with vertex A
visited = {'A'}

mst = []
total_cost = 0

while len(visited) < len(vertices):

    minimum = None

    # Find the minimum edge connecting
    # a visited vertex to an unvisited vertex
    for u, v, weight in graph:

        if (u in visited and v not in visited) or \
           (v in visited and u not in visited):

            if minimum is None or weight < minimum[2]:
                minimum = (u, v, weight)

    # Add the minimum edge to MST
    u, v, weight = minimum

    mst.append(minimum)
    total_cost += weight

    # Add the new vertex to visited
    if u in visited:
        visited.add(v)
    else:
        visited.add(u)


# Display the Minimum Spanning Tree
print("Edges in Minimum Spanning Tree:")

for u, v, weight in mst:
    print(u, "-", v, ":", weight)

print("Total cost of MST:", total_cost)