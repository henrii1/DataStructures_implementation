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

/*
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.
Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:

Input: list1 = [], list2 = []
Output: []
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode dummy;        // this copies hence must allocate memory
    struct ListNode* tail = &dummy;
    dummy.next = NULL;

    while (list1 && list2) {  //we can test the conditions using the list pointer
        if (list1->val < list2->val) {
            tail->next = list1;     //assigning the list struct instead of malloc
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }

    // Append the remaining nodes
    if (list1) tail->next = list1;
    if (list2) tail->next = list2;

    return dummy.next;
}


/*
Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. Then return the number of unique elements in nums.

Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things:

Change the array nums such that the first k elements of nums contain the unique elements in the order they were present in nums initially. The remaining elements of nums are not important as well as the size of nums.
Return k.
Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
*/

// In-place solution
int removeDuplicates(int* nums, int numsSize) {
    if (numsSize == 0){
        return 0;
    }
    int i = 0;

    for (int j=1; j<numsSize; j++){
        if (nums[j] != nums[i]){
            i += 1;
            nums[i] = nums[j];
        }
    }
    return i + 1;
}

/*
Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.

Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things:

Change the array nums such that the first k elements of nums contain the elements which are not equal to val. The remaining elements of nums are not important as well as the size of nums.
Return k.
Example 2:

Input: nums = [0,1,2,2,3,0,4,2], val = 2
Output: 5, nums = [0,1,4,0,3,_,_,_]

*/
// In-place solution
int removeElement(int* nums, int numsSize, int val) {
    if (numsSize == 0){
        return 0;
    }

    int i = 0;

    for (int j=0; j<numsSize; j++){
        if (nums[j] != val){
            nums[i] = nums[j];
            i += 1;
        }
    }
    return i;
}

/*
Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

 

Example 1:

Input: haystack = "sadbutsad", needle = "sad"
Output: 0
*/

// Uses the strstr func. returns a char pointer.
int strStr(char* haystack, char* needle) {
    if (! *needle) return -1;
    
    char* pos = strstr(haystack, needle); //returns a pointer to needles 1st element
    if (pos){
        return pos - haystack; // both are pointers hence we need to substract
    } 
    return -1;

}