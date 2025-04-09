/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
*/
s
// for C, no hash map version, just a straight version
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;
    
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
    }
    return NULL;
}

/*
Given an integer x, return true if x is a palindrome, and false otherwise.

 

Example 1:

Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.
*/

#include <stdbool.h>
bool isPalindrome(int x) {
    if (x < 0) return false;
    char x_str[50];
    sprintf(x_str, "%d", x);
    int size = strlen(x_str);
    for(int i = 0; i < size / 2; i++){
        if (x_str[i] != x_str[size - 1 - i]) return false;
    }
    return true;
}


/*
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
Example 1:

Input: s = "III"
Output: 3
Explanation: III = 3.
*/

// inefficient version
int romanToInt(char* s) {
    typedef struct {
        char r;
        int n;
    } datatype;

    // Define Roman numeral mapping
    datatype dict[] = {
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
        {'C', 100}, {'D', 500}, {'M', 1000}
    };

    int struct_size = 7;
    int inp_size = strlen(s);
    int sum = 0;

    for (int i = 0; i < inp_size; i++) {
        for (int j = 0; j < struct_size; j++) {
            if (s[i] == dict[j].r) {
                // Check for subtractive cases (IX, IV, etc.)
                if ((s[i] == 'I') && (i < (inp_size-1)) && ((s[i+1] == 'V') || (s[i+1] == 'X'))) {
                    sum -= dict[j].n;
                } else if ((s[i] == 'X') && (i < (inp_size-1)) && ((s[i+1] == 'L') || (s[i+1] == 'C'))) {
                    sum -= dict[j].n;
                } else if ((s[i] == 'C') && (i < (inp_size-1)) && ((s[i+1] == 'D') || (s[i+1] == 'M'))) {
                    sum -= dict[j].n;
                } else {
                    sum += dict[j].n;
                }
            }
        }
    }

    return sum;
}

// more efficient version

// Note: we can use arrays instead of structs. just use the roman placeholders to understand better
int romanToInt(char* s) {
    // Use an array to store values instead of looping through a struct
    int dict[128] = {0};  // ASCII table size (0-127), all initialized to 0
    dict['I'] = 1;
    dict['V'] = 5;
    dict['X'] = 10;
    dict['L'] = 50;
    dict['C'] = 100;
    dict['D'] = 500;
    dict['M'] = 1000;

    int sum = 0;
    int inp_size = strlen(s);

    for (int i = 0; i < inp_size; i++) {
        // If next numeral is larger, subtract this one
        if (i + 1 < inp_size && dict[s[i]] < dict[s[i + 1]]) {
            sum -= dict[s[i]];
        } else {
            sum += dict[s[i]];
        }
    }

    return sum;
}


/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
*/

// we cannot return an array defined in the function, so we need to malloc it
// we must terminate the string with '\0' to avoid memory issues
#include <string.h>  //strlen
#include <stdlib.h>  //malloc

char* longestCommonPrefix(char** strs, int strsSize) {
    
    char* ans = (char*)malloc(strlen(strs[0] + 1));
    int size = strlen(strs[0]);
    int i;
    for (i = 0; i<size; i++){
        char s = strs[0][i];
        int j = 1;
        while (j < strsSize){
          if (strs[j][i] != s){
            ans[i] = '\0';
            return ans;
          } else {
            j += 1;
          }
        }
        ans[i] = s;
    }
    ans[i] = '\0';
    return ans;
}


/*
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

Output: true
*/

//simulate a stack with pointer arithmetic
bool isValid(char* s) {
    char stack [10000];
    int top = -1;
    
    for (int i=0; s[i] != '\0'; i++){
      char c = s[i];
      if (c =='[' || c == '{' || c == '('){
          stack[++top] = c;  // push (increment pointer before assigning)
      } else {
          if (top == -1) {return false;}
          char value = stack[top--];  // pop (take out value before decrementing)
          if ((c == ']' && value != '[') ||
              (c == '}' && value != '{') ||
              (c == ')' && value != '(')) {return false;}
  
      }
    }
    return top == -1;  //stack should be empty
  }

  