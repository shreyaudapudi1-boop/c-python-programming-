
import heapq

def dijkstra(graph, source):
    distances = {node: float("inf") for node in graph}
    parents = {node: None for node in graph}
    distances[source] = 0
    queue = [(0, source)]

    while queue:
        distance, node = heapq.heappop(queue)

        if distance != distances[node]:
            continue

        for neighbor, weight in graph[node]:
            new_distance = distance + weight

            if new_distance < distances[neighbor]:
                distances[neighbor] = new_distance
                parents[neighbor] = node
                heapq.heappush(queue, (new_distance, neighbor))

    return distances, parents


graph = {
    0: [(1, 10), (3, 30), (4, 100)],
    1: [(0, 10), (2, 50)],
    2: [(1, 50), (3, 20), (4, 10)],
    3: [(0, 30), (2, 20), (4, 60)],
    4: [(0, 100), (2, 10), (3, 60)]
}

distances, parents = dijkstra(graph, 0)

for node, distance in distances.items():
    print(f"Node {node}: {distance}")

target = 4
if distances[target] == float("inf"):
    print("Target is unreachable")
else:
    path = []
    current = target

    while current is not None:
        path.append(current)
        current = parents[current]

    print("Shortest path:", " -> ".join(map(str, path[::-1])))
