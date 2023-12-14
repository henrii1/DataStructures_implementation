class solution:
    def __init__(self, s_length: int):
        self.s_length = s_length
        self.stack = []
    def push(self, value: list):
        if len(self.stack) == self.s_length:
            print("stack if full, cannot add elements")
        else:
            self.stack.append(value)
            self.stack.sort(key= lambda x: x[1], reverse=True)
            print(self.stack)

    def pop(self):
        if not self.stack:
            print("stack is empty, cannot remove any value")
        else:
            pop_value = self.stack.pop(0)
            print(pop_value)
            print(self.stack)

            


"""
Requirements:
        - takes in a stack length and prints fill when full
        - prints empty when empty
Analysis:  
        space: O(1), time O(1)

pseudocode:
        - define a push function: prints full if stack length equals length, append to stack otherwise and print stack.
        - define a pop function: prints empty if not stack, pops out of stack otherwise, returns pop and list.


"""



# Test
from collections import deque
n = int(input("Enter the length of stack"))
s = solution(n)
while True:
    print("Pick a number: 1. add a value | 2. remove a value | 3. quit:")
    reply = int(input())
    if reply == 1:
        number = input("Enter number or word")
        priority = input("Enter Priority")
        in_data = [number, priority]
        s.push(in_data)
    elif reply == 2:
        s.pop()
    elif reply == 3:
        break
    else:
        print("Enter a valid number")

#stacks are LIFO
#queues are FIFO
#priority queues are sorted or with priority score, still sort based on score.


from queue import Queue

q = Queue()

q.put(10)
q.put(45)
q.put(23)

q.get()  # 10
q.get()  # 23


q = []
q.append(12)
q.append(23)
q.sort
q.append(24)
q.sort


from collections import deque
q = deque()
q.appendleft(10)
q.appendleft(20)

q.pop()
q.pop()

import queue
stack = queue.LifoQueue
stack.put(12)
stack.put(23)
stack.get()   #pop method

stack = queue.LifoQueue(3)   #max size is set to three.
stack.put(5, timeout=3)   # set the timeout so that it can print 'queue is full'
stack.get(timeout=3)


#use these to construct any type of queue or stack.
