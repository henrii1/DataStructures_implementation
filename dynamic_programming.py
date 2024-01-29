"""Question 22.
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
"""
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        ans=[]

        def backTracking(curr,openBrackets,closeBrackets):
            # Base Case
            if openBrackets==closeBrackets==n:
                ans.append("".join(curr)) # converts a list to a string
                return

            # closeBrackets is less than openBrackets
            if closeBrackets<openBrackets:
                curr.append(")")
                backTracking(curr,openBrackets,closeBrackets+1)
                curr.pop()
            
            # openBrackets is less than the input
            if openBrackets<n:
                curr.append("(")
                backTracking(curr,openBrackets+1,closeBrackets)
                curr.pop()

        backTracking(["("],1,0)
        
        return ans
    


"""Question 64 Minimum Path Sum
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
"""
class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
            
        
        m, n = len(grid), len(grid[0])
        
        for i in range(1, m):
            grid[i][0] += grid[i-1][0]
        
        for i in range(1, n):
            grid[0][i] += grid[0][i-1]
        
        for i in range(1, m):
            for j in range(1, n):
                grid[i][j] += min(grid[i-1][j], grid[i][j-1])
        
        return grid[-1][-1]

"""Intuition
-The intuition behind the dynamic programming approach is that the minimum path sum to reach a position (i, j) in the grid can be computed by considering the minimum path sum to reach the positions (i-1, j) and (i, j-1).

-This is because the only two possible ways to reach the position (i, j) are either by moving down from (i-1, j) or moving right from (i, j-1).

-By computing the minimum path sum to reach each position in the grid, the algorithm can find the minimum path sum to reach the bottom-right corner of the grid by simply looking at the last element of the array (grid[m-1][n-1]).

"""
