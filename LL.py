'''Question'''
#Between every pair of adjacent nodes, insert a new node with a value equal to the greatest common divisor of them.
Input: head = [18,6,10,3]
Output: [18,6,6,2,10,1,3]

'''Input'''
# # Create a sample linked list: 1 -> 2 -> 3 -> 4
# head = ListNode(1, ListNode(2, ListNode(3, ListNode(4))))

# # Create an instance of the Solution class
# solution = Solution()

# # Call the insertGreatestCommonDivisors method
# modified_head = solution.insertGreatestCommonDivisors(head)
# head represents the head node or reference.

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def insertGreatestCommonDivisors(self, head: Optional[ListNode]) -> Optional[ListNode]:
        pvs, nxt = head, head.next
        while nxt:
            new_val = math.gcd(pvs.val, nxt.val)
            new_node = ListNode(new_val)
            pvs.next, new_node.next = new_node, nxt
            pvs = nxt
            nxt = nxt.next
        return head
    


"""Question
For every two consecutive 0's, merge all the nodes lying in between them into a single node whose value is the sum of all the merged nodes. The modified list should not contain any 0's.

Input: head = [0,3,1,0,4,5,2,0]
Output: [4,11]
"""

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def mergeNodes(self, head: Optional[ListNode]) -> Optional[ListNode]:
        current_node = head.next
        result = new_node = ListNode(0)
        while current_node:
            current_sum = 0
            while current_node.val != 0:
                current_sum = current_sum + current_node.val
                current_node = current_node.next
            new_node.next = ListNode(current_sum)
            new_node = new_node.next

            current_node = current_node.next
        
        return result.next
    


"""Question
Input: head = [4,2,2,3]
Output: 7
Explanation:
The nodes with twins present in this linked list are:
- Node 0 is the twin of node 3 having a twin sum of 4 + 3 = 7.
- Node 1 is the twin of node 2 having a twin sum of 2 + 2 = 4.
Thus, the maximum twin sum of the linked list is max(7, 4) = 7.
"""



# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def pairSum(self, head: Optional[ListNode]) -> int:
        result = set()
        values = []
        current_node = head
        j = -1
        while current_node:
            values.append(current_node.val)
            current_node = current_node.next
        index = len(values) // 2
        mirror_one = values[:index]
        mirror_two = values[index:]
        for i in range(0, len(mirror_one)):
            result.add((mirror_one[i] + mirror_two[j]))
            j -= 1
        res = max(result)
        return res
    


'''Question
You are given the node to be deleted node. You will not be given access to the first node of head.

All the values of the linked list are unique, and it is guaranteed that the given node node is not the last node in the linked list.
'''


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteNode(self, node):
        """
        :type node: ListNode
        :rtype: void Do not return anything, modify node in-place instead.
        """
        node.val = node.next.val
        node.next = node.next.next

        """Question
You are given two linked lists: list1 and list2 of sizes n and m respectively.
Remove list1's nodes from the ath node to the bth node, and put list2 in their place
Input: list1 = [0,1,2,3,4,5], a = 3, b = 4, list2 = [1000000,1000001,1000002]
"""

'''Flawed solution'''
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeInBetween(self, list1: ListNode, a: int, b: int, list2: ListNode) -> ListNode:
        dummy = ListNode(-1, list1)
        second = list2
        head = current = dummy.next
        length = 0
        while current:
            if current.next.val == a:
                element_one = current
                while element_one.val != b:
                    break
                    current.next = current.next.next
                    current.val = current.next.val
                    element_one = element_one.next 
                    length += 1
            current = current.next
        current.next = current.next.next
        remaining = current.next
        while second:
            current.next = second
            current = current.next
            second = second.next
        while remaining:
            current.next = remaining
            current = current.next
            remaining = remaining.next
        return head