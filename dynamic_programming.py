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
    


