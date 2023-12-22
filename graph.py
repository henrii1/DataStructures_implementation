""" Question 797
Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1, find all possible paths from node 0 to node n - 1 and return them in any order.
"""
# recursive solution

class Solution:
    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        def dfs(node, path):            # termination condition
            if node == n - 1:
                overall_result.append(path.copy())  # use copy so that changing path won't change the value in overall_result
                return

            visited.add(node)                # mandatory of traversal
            for neighbor in graph[node]:
                if neighbor not in visited:
                    path.append(neighbor)            #order: append, recurse, pop
                    dfs(neighbor, path)
                    path.pop()

            visited.remove(node)               #remove allows it to explore other possible arrangements.

        n = len(graph)
        overall_result = []
        visited = set()
        dfs(0, [0])

        return overall_result
    



"""Question: Minimum Vertexes to reach all nodes in a graph"""
class Solution:
    def findSmallestSetOfVertices(self, n: int, edges: List[List[int]]) -> List[int]:
        def dfs(node, path):
            if node == l:
                overall_result.append(path.copy())
                return
            visited.add(node)
            for neighbor in edges[node]:
                if neighbor not in visited:
                    path.append(neighbor)
                    dfs(neighbor, path)
                    path.pop()
            visited.remove(node)

        l = n - 1
        overall_result = []
        visited = set()
        dfs(0, [0])
        return min(overall_result)
    
"""Question 1557. Minimum Number of Vertices to Reach All Nodes
Input: n = 6, edges = [[0,1],[0,2],[2,5],[3,4],[4,2]]
Output: [0,3]
"""
#NB: range(n) == 0, 5
#> list(range(n)) == [0, 1, 2, 3, 4, 5]
class Solution:
    def findSmallestSetOfVertices(self, n: int, edges: List[List[int]]) -> List[int]:
        connected = set(map(lambda e: e[1], edges))                                    # set of all 2nd index values
        return list(filter(lambda x: x not in connected, range(n)))                    # values in range n that are not in connected.
    



"""Question 841 Keys and Rooms
There are n rooms labeled from 0 to n - 1 and all the rooms are locked except for room 0. Your goal is to visit all the rooms. However, you cannot enter a locked room without having its key.
"""

#DFs approach: didn't pass all test cases
class Solution:
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        def dfs(node, path):
            if len(path) == l:
                result.append(path.copy())
                return
            
            visited.add(node)
            for key in rooms[node]:
                if key not in visited:
                    path.append(key)
                    dfs(key, path)
                    path.pop()
            visited.remove(node)

        l = len(rooms)
        result = []
        visited = set()
        dfs(0, [0])
        if result:
            return True
        else:
            return False
        



"""Question 841 Keys and Rooms
There are n rooms labeled from 0 to n - 1 and all the rooms are locked except for room 0. Your goal is to visit all the rooms. However, you cannot enter a locked room without having its key.
"""
# Base solution. takes in all keys in a room, provided the room is within set

class Solution:
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        n = len(rooms)
        keys = set()
        keys.add(0)

        k = 1
        while k != 0:
            k = len(keys)
            for i in range(n):
                if i in keys:
                    keys.update(rooms[i])   # add all keys within room, if it is in set
            k = len(keys) - k  # will equal zero when keys doesn't increase
        return len(keys) == n  # evaluates to true or false
    


""" Question 1584 Min Cost to Connect All Points
Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.

cost for two connection = |xi - xj| + |yi - yj|

Input: points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
Output: 20
"""


class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        n = len(points)
        min_cost = 0
        visited = set()
        heap = [(0,0)]           # cost, node

        while heap:
            cost, node = heapq.heappop(heap)    # node changes based on our min distanc point, after pop

            if node not in visited:
                visited.add(node)
                min_cost += cost

                for neighbors, neighbor_cost in self.get_neighbors(node, points, visited):
                    heapq.heappush(heap, (neighbor_cost, neighbors))
        return min_cost


    def get_neighbors(self, node, points: List[List[int]], visited):
        neighbors = []
        x1, y1 = points[node]

        for i, (x2, y2) in enumerate(points):    # i is index
            if i not in visited:
                cost = abs(x1 - x2) + abs(y1 - y2)
                neighbors.append((i, cost))
        return neighbors                           # neighors contains the index and cost for all other nodes compared to one node, (node)            
    



"""Question 547 Numer of Provinces
A province is a group of directly or indirectly connected cities and no other cities outside of the group.

Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3
"""

class Solution:
    def findCircleNum(self, is_connected: List[List[int]]) -> int:
        def visit_from(x: int, seen: set[int]) -> bool:
            return seen.add(x) or all(visit_from(y, seen) for y, c in enumerate(is_connected[x]) if y not in seen and c)

        seen = set()
        return sum((x not in seen) and visit_from(x, seen) for x in range(len(is_connected)))