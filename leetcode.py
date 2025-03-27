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