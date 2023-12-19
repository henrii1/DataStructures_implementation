# recursion works as stacks, last in first out

'''backtracking general order with recursion: add or push, recursion, pop or remove'''
"""Order of python object implementation during recursion"""
## [5[4[3[2[1]]]]]                  #completes the innermost object recursively backwards until the outermost.
#NB: it is like forward and backward recursion. after the forward state is completed, it begins the backward process until it completely runs each object.
#> if the last object's state was n, the next backward will be n-1 continuously.

# Trie Data structure

# essentially maps by creating dictionaries as values of other dictionaries. each key has an attribute 'endofWords' that is boolean.

class TrieNode:
    def __init__(self):
        self.children = {}
        self.endofWord = False

class Trie:
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word: str) -> None:
        curr = self.root
        for c in word:
            if c not in curr.children:
                curr.children[c] = TrieNode()
            curr = curr.children[c]
        curr.endofWord = True
        return
    
    def search(self, word: str) -> bool:
        curr = self.root
        for c in word:
            if c not in curr.children:
                return False
            curr = curr.children[c]
        return curr.endofWord
    
    def startswith(self, prefix: str) -> bool:
        curr = self.root
        for c in prefix:
            if c not in curr.children:
                return False
            curr = curr.children[c]
        return True
    


# Example usage
trie = Trie()
words = ['apple', 'ape',  'adam', 'banana', 'codine']

for word in words:
    trie.insert(word)


print(trie.search('ape'))
print(trie.search('addit'))

print(trie.prefix('ap'))
print(trie.prefix('bak'))



# Memoization(top-down) and Tabulation(Bottom-up) approaches for fibonacci series

# Memoization (works with recursion), use for loop within example usage
cache = {}
def fib_one(val):
    if val in cache:
        return cache[val]

    if val == 0 or val == 1:
        value = 1
    else:
        value = fib_one(val - 2) + fib_one(val - 1)

    cache[val] = value
    print(val, ":", value)
    return value


# lru_cache()
from functools import lru_cache


@lru_cache(maxsize=1000)
def fibonacci(n):
    if n == 0 or n == 1:
        value = n
    else:
        value = fibonacci(n-2) + fibonacci(n-1)
    return value

# example usage
for n in range(1, 101):
    print(n, ":", fibonacci(n))
        


# fibonacci with tabulation (tabulation works with indexing list)


def fib_tab(n):
    result = []
    for i in range(0, n + 1):
        if i == 0 or i == 1:
            value = 1
        else:
            value = result[i - 2] + result[i - 1]
        result.append(value)
    return result[:]


# Greedy algorithm has a complexity of O(nlogn), when sorted, it will be O(n)


# backtracking
# all possible arrangement of 2 boys and 1 girl

def backtracking(chairs, arrangement):
    if len(chairs) == len(arrangement):
        print(arrangement)
        return
    for chair in chairs:
        if chair not in arrangement:
            arrangement.append(chair)
            backtracking(chairs, arrangement)
            arrangement.pop()

# example usage
chairs = ['boy1', 'boy2', 'girl']
arrangement = []
backtracking(chairs, arrangement)


#Nqueens problem (arranging 4 queens such that no two queens are in same row, same column or same diagonal) all possible arrangements that satisfy this.
#positive diagonal: (row-column) is constant
#negative diagonal: (row + column) is constant

# backtracking order: push or add, recursion, pop or remove
class Nqueens:
    def QueenNumber(self, n: int):
        column= set()
        positiveDiagonal = set()
        negativeDiagonal = set()
        result = 0

        def backtracking(r):
            if r == n:
                nonlocal result
                result += 1
                return
            for c in range(n):
                if c in column or (r + c) in positiveDiagonal or (r - c) in negativeDiagonal:
                    continue
                column.add(c)
                positiveDiagonal.add(r + c)
                negativeDiagonal.add(r - c)
                backtracking(r + 1)
                column.remove(c)
                positiveDiagonal.remove(r + c)
                negativeDiagonal.remove(r - c)
        backtracking(0)
        return result
