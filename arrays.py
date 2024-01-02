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