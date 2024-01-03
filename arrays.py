"""Question 1282 Group the People Given the Group Size They Belong To
There are n people that are split into some unknown number of groups. Each person is labeled with a unique ID from 0 to n - 1.
Input: groupSizes = [3,3,3,3,3,1,3]
Output: [[5],[0,1,2],[3,4,6]]
"""
class Solution:
    def groupThePeople(self, groupSizes: List[int]) -> List[List[int]]:
        map = defaultdict(list)
        for i,g in enumerate(groupSizes):
            map[g].append(i)
        result = []
        # for i  in map.keys():
        #     result.append(map[i])
        # return result

        
        ans = []
        for g_key in map.keys():
            for div in range(len(map[g_key])//g_key):
                ans.append(map[g_key][g_key*div:g_key*(1+div)])
        return ans


"""Question 2610. 
You are given an integer array nums. You need to create a 2D array from nums satisfying the following conditions:
Input: nums = [1,3,4,1,2,3,1]
Output: [[1,3,4,2],[1,3],[1]]
"""
class Solution:
    def findMatrix(self, nums: List[int]) -> List[List[int]]:
        table = {}
        result = []
        for num in nums:
            if num not in table:
                table[num] = 0
            
                
            
            idx = table[num]
            
            if idx == len(result):
                result.append([])
            result[idx].append(num)
            table[num] += 1                 # done because of the indexing
        return result
    


"""Sliding Window"""

"""Question 1343 Given an array of integers arr and two integers k and threshold, return the number of sub-arrays of size k and average greater than or equal to threshold.

Input: arr = [2,2,2,2,5,5,5,8], k = 3, threshold = 4
Output: 3
"""
class Solution:
    def numOfSubarrays(self, arr: List[int], k: int, threshold: int) -> int:
        _sum = 0
        start_index = 0
        result = 0

        for idx, num in enumerate(arr):
            _sum += num

            while idx-start_index > k-1:
                _sum -= arr[start_index]
                start_index += 1
            if idx-start_index == k-1 and _sum//k >= threshold:
                result += 1
        return result
    


"""Question 2024
Input: answerKey = "TTFF", k = 2
Output: 4
Explanation: We can replace both the 'F's with 'T's to make answerKey = "TTTT".
There are four consecutive 'T's.

"""
#solution 1 (works, not in all cases)
class Solution:
    def maxConsecutiveAnswers(self, answerKey: str, k: int) -> int:
        sub_result = 1
        result = 0
        count = 0
        start_index = 0
        for i in range(1, len(answerKey)):
            if answerKey[i-1] == answerKey[i]:
                sub_result += 1
            elif count < k:
                sub_result += 1
                count += 1
            while sub_result > result:
                result = sub_result
                if answerKey[start_index] != answerKey[start_index + 1]:
                    count -= 1
                    sub_result -= 1
                    start_index += 1
        return result

#solution 2 (correct) uses double ended queue
    
class Solution:
    def maxConsecutiveAnswers(self, answerKey: str, k: int) -> int:
        f_positions = deque([-1]*(k+1))
        t_positions = deque([-1]*(k+1))
        ans = 0
        for i, n in enumerate(answerKey):
            if n == 'T':
                t_positions.popleft()
                t_positions.append(i)
            else:
                f_positions.popleft()
                f_positions.append(i)
            ans = max(ans, i-t_positions[0], i-f_positions[0])
        return ans