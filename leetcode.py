"""Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
"""
from typing import List
# Using a hash map
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        num_map = {}  # Hash table to store number and its index
        for i, num in enumerate(nums):
            complement = target - num  # Find the complement
            if complement in num_map:
                return [num_map[complement], i]  # Return indices of complement and current number
            num_map[num] = i  # Store the number with its indexs



"""
Given an integer x, return true if x is a palindrome, and false otherwise.

 

Example 1:

Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.
"""
class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0:
            return False
        x_str = str(x)
        size = len(x_str)
        for i in range(size // 2):
            if (x_str[i] != x_str[size - 1 - i]):
                return False
        return True


"""
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
Example 1:

Input: s = "III"
Output: 3
Explanation: III = 3."
"""
class Solution:
    def romanToInt(self, s: str) -> int:
        dic = {}
        dic['I'] = 1
        dic['V'] = 5
        dic['X'] = 10
        dic['L'] = 50
        dic['C'] = 100
        dic['D'] = 500
        dic['M'] = 1000
        sum = 0
        length = len(s)
        for i in range(length):
            if (i + 1 < length and dic[s[i]] < dic[s[i + 1]]):
                sum -= dic[s[i]]
            else:
                sum += dic[s[i]]
        return sum



"""
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
"""

#lexicographically sort the list and compare only first and last
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        ans = ""
        sorted_list = sorted(strs)
        first, last = sorted_list[0], sorted_list[-1]
        for i in zip(first, last):
            if i[0] != i[1]:
                return ans
            else:
                ans += i[0]
        return ans
    

"""
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 

Example 1:

Input: s = "()"

Output: true

Example 2:

Input: s = "()[]{}"

Output: true"""

class Solution:
    def isValid(self, s: str) -> bool:
      stk = []
      pairs = dict([(']','['), ('}','{'), (')','(')])

      for i in s:
        if i in pairs:
            if (len(stk)==0 or pairs[i] != stk[-1]):
                return False
            stk.pop()
        else:
            stk.append(i)

      return not stk
    
"""
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.
Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:

Input: list1 = [], list2 = []
Output: []
"""
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode()
        tail = dummy      #pass by value by default, for python

        while list1 and list2:
            if list1.val < list2.val:
                tail.next = list1
                list1 = list1.next
            else:
                tail.next = list2
                list2 = list2.next
            tail = tail.next

        tail.next = list1 or list2   #notice the use of or

        return dummy.next
        