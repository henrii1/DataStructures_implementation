# defining a BST. lower values are in left sub tree, higher values are in right sub tree

#deletion
#> if no children, key is none
#> if only one child, key is none return child
#> if contains two children, replace with highest value in left sub tree, then recursion on that rchild to delete and update.


class BST:
    def __init__(self, key: int | None = None):
        self.key = key
        self.rchild = None
        self.lchild = None

    def insert(self, data):
        if self.key is None:
            BST(data)
            return
        if self.key > data:
            if self.lchild:
                self.lchild.insert(data)
            else:
                self.lchild = BST(data)
        else:
            if self.rchild:
                self.rchild.insert(data)
            else:
                self.rchild = BST(data)


    def search(self, data):
        if self.key is None:
            print("There is no data within this BST")
            return
        if self.key == data:
            print(f"Node: {data} found within the BST")
            return
        if self.key > data:
            if self.lchild:
                self.lchild.search(data)
            else:
                print(f"Value: {data} not present in BST")
        else:
            if self.rchild:
                self.rchild.search(data)
            else: 
                print(f"Value: {data} not present in BST")

    def pre_order(self):
        print(self.key, end=" ")
        if self.lchild:
            self.lchild.pre_order()
        if self.rchild:
            self.rchild.pre_order()

    def in_order(self):
        if self.lchild:
            self.lchild.in_order()
        print(self.key, end=" ")
        if self.rchild:
            self.rchild.in_order()

    def post_order(self):
        if self.lchild:
            self.lchild.post_order()
        if self.rchild:
            self.rchild.post_order()
        print(self.key, end=" ")

    def delete(self, data):
        if self.key is None:
            print(f"value {data} is not present in BST")
            return
        if self.key > data:
            if self.lchild:
               self.lchild = self.lchild.delete(data)
            else:
                print(f"value {data} is not present in BST")
        elif self.key < data:
            if self.rchild:
                self.rchild = self.rchild.delete(data)
            else:
                print(f"value {data} is not present in BST")
        else:
            if self.lchild:
                if not self.rchild:
                    temp = self.lchild
                    self.key = None
                    return temp
                temp = self.lchild
                while temp.rchild:
                    temp = temp.rchild
                self.key = temp.key
                self.lchild = self.lchild.delete(temp.key)
            else:
                temp = self.rchild
                self.key = None
                return temp
        return self              # this is important to preserve the structure of the bst.


# this works but it constantly updates the self reference
    def find_max(self):
        if self.rchild:
            self.rchild = self.rchild.find_max()
            return
        print(self.key)


# this can be used too. if you want to refer to the first self, save the recursive child to a temp variable and use it for recursion.
    def find_min(self):
        if self.lchild:
            return self.lchild.find_min()
        print(self.key)
        return self.key



    
def count(class_instance):
    if class_instance is None:                               # i'm using the class reference instead because a node can be initialized with 1
        return 0
    return 1 + count(class_instance.rchild) + count(class_instance.lchild)     # for each recursion, it return is 1, + plus the recursion of its child, that yeilds 1, plus that of its child ...




# max heapify function

def max_heapify(arr, n, i):
    largest = i
    left = (2 * i) + 1
    right = (2 * i) + 2

    if left < n and arr[largest] < arr[left]:
        arr[largest], arr[left] = arr[left], arr[largest]
        largest = left
        max_heapify(arr, n, largest)
        return
    if right < n and arr[largest] < arr[right]:
        arr[largest], arr[right] = arr[right], arr[largest]
        largest = right
        max_heapify(arr, n, largest)




arr = [2,3,54,50,12,3]

n = len(arr)

# Building max heap from a list              
for i in range(n // 2 - 1, -1, -1):                 # n//2-1 will consider only the non leaf nodes, in reverse order till index 0
                                                    #> leaf nodes will remain as is.
    max_heapify(arr, n, i)

# Printing the max heap
for i in range(n):
    print(arr[i])




"""Adjacency Matrix"""

nodes = []
graph = []
node_count = 0

def add_node(v):
    global node_count
    if v in nodes:
        print(f"node {v} already present in graph")
    else:
        node_count += 1
        nodes.append(v)
        v_list = [0] * node_count
        graph.append(v_list)


def add_edge(v1, v2):
    if v1 not in nodes:
        print(v1, 'not in the graph')
    elif v2 not in nodes:
        print(v2, 'not in the graph')
    else:
        index_one = nodes.index(v1)
        index_two = nodes.index(v2)
        graph[index_one][index_two] == 1
        graph[index_two][index_one] == 1


def print_graph():
    node_count = len(nodes)
    for i in node_count:
        for j in node_count:
            print(format(graph[i][j], end=" "))        #format method makes the print appear alligned regardless of digit number.


def del_node(v):
    if v not in nodes:
        print(v, 'is not available in node')
    else:
        index = nodes.index(v)
        nodes.pop(index)
        graph.pop(index)
        for i in graph:
            i.pop(index)

def del_edge(v1, v2):
    if v1 not in nodes:
        print(v1, 'is not present in the graph')
    elif v2 not in nodes:
        print(v2, 'is not present in the graph')
    else:
        index1 = nodes.index(v1)
        index2 = nodes.index(v2)
        graph[index1][index2] == 0
        graph[index2][index1] == 0



"""Adjacency List representation"""

graph = {}

def add_node(v):
    if v in graph:
        print(v, 'is present in graph')
    else:
        graph[v] = []


def add_edge(v1, v2):
    if v1 not in graph:
        print(v1, 'not available in the graph')
    elif v2 not in graph:
        print(v2, "not present in the graph")
    else:
        graph[v2].append(v1)
        graph[v1].append(v2)


# for printing, we can print out the dictionary and its key and values.

def del_node(v):
    if v not in graph:
        print(v, "is not present in graph")
    else:
        graph.pop(v)
        for i in graph:
            if v in graph[i]:
                graph[i].remove(v)

def del_edge(v1, v2):
    if v1 not in graph:
        print(v1, 'is not present in graph')
    elif v2 not in graph:
        print(v2, 'is not present in graph')
    else:
        graph[v2].remove(v1)
        graph[v1].remove(v2)


visited = set()
graph = {
    "A": ["B", "D"],
    "B": ["A", "V"],
    "C": ["A", "E", "F"],
    "D": ["A", "E", "F"]
}

node = input()

# recursive approach

def DFS_recursive(node, visited, graph):
    if node not in graph:
        print(node, 'is not present in the graph')
    else:
        if node not in visited:
            visited.add(node)
            print(node)
            for i in graph[node]:
                DFS_recursive(i, visited, graph)


#iterative approach

def DFS_iterative(node, visited, graph):
    stack = []
    if node not in graph:
        print(node, 'is not present in the graph')
    else:
        stack.append(node)
        while stack:
            value = stack.pop()
            if value not in visited:
                visited.add(value)
                print (node)
                for i in graph[value]:
                    stack.append(i)



# Breadth for search approach
from queue import Queue

queue_ob = Queue()

def BFS(node, graph):
    if node not in graph:
        print(node, 'is not present in the graph')
    else:
        parent = {}
        level = {}
        parent[node] = None
        level[node] = 0
        queue_ob.put(node)
        while not queue_ob.empty():
            item = queue_ob.get()
            if item not in visited:
                visited.add(item)
                print(item)
                for i in graph[item]:
                    queue_ob.put(i)
                    level[i] = level[item] + 1
                    parent[i] = item
