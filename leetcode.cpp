/* Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
*/

// unordered map maps a number to another number: a hash map
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            // Declare an unordered map to store the numbers and their indices
            unordered_map<int, int> mp;
           
            // Loop through the array
            for(int i = 0; i < nums.size(); i++){
                // Check if the complement of the current number exists in the map
                if(mp.find(target - nums[i]) == mp.end())
                    // If not, add the current number and its index to the map
                    mp[nums[i]] = i;
                else
                    // If yes, return the indices of the current number and its complement
                    return {mp[target - nums[i]], i};
            }
     
            // If no pair is found, return {-1, -1} as a default value
            return {-1, -1};
        }
    };


/*
Given an integer x, return true if x is a palindrome, and false otherwise.

 

Example 1:

Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.
*/

#include <iostream>
#include <string>
class Solution {
    public:
        bool isPalindrome(int x) {
            if (x < 0) return false;  // negative numbers are never palindromes
    
            string x_str = to_string(x);
            int size = x_str.size();
            for (int x = 0; x < size / 2; x++){
                if (x_str[x] != x_str[size - 1 - x]) {return false;}
    
            }
            return true;
        }
    };


/*
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
Example 1:

Input: s = "III"
Output: 3
Explanation: III = 3.
*/

class Solution {
    public:
        int romanToInt(string s) {
            unordered_map<char, int> dict {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };
        int size = s.size();
        int sum = 0;
        for (int i=0; i<size; i++){
            if(i+1<size && dict[s[i]] < dict[s[i+1]]){
                sum -= dict[s[i]];
            } else{
                sum += dict[s[i]];
            }
        }
        return sum;
        }
    };




/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
*/

// sort the vector and compare the first and last elements
#include <vector>
#include <string>
#include <algorithm>    //contains sort
class Solution {
    public:
        string longestCommonPrefix(vector<string>& strs) {
            string ans = "";
            sort(strs.begin(), strs.end());
            int size = strs.size();
            for (auto i=0; i<min(strs[0].size(), strs[size-1].size()); i++){
                if (strs[0][i] != strs[size-1][i]){
                    return ans;
                } else {
                    ans += strs[0][i];
                }
            }
            return ans;
        }
    };


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

class Solution {
    public:
        bool isValid(string s) {
            stack<char> stk;
            unordered_map<char, char> pairs = {
                {']', '['},
                {'}', '{'},
                {')', '('}
            };
            for (auto c: s){
                if (pairs.count(c)){
                    if (stk.empty() || pairs[c] != stk.top()){ return false;}
                    stk.pop();
                } else {
                    stk.push(c);
                }
            }
            return stk.empty();
        }
    };


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
 * NOTE: we can actually initialize the LL using methods detailed in struct
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    public:
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);  // implicite malloc, value init. 
        ListNode* tail = &dummy;
    
        while (list1 && list2) {
            if (list1->val < list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }
    
        tail->next = list1 ? list1 : list2;
    
        return dummy.next;
    }
    };


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

// In-place solutions run through the array once, switching values
class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            if (nums.empty()){
                return 0;
            }
    
            int i = 0;
            for (int j=1; j<nums.size(); j++){
                if (nums[j] != nums[i]){
                    i += 1;
                    nums[i] = nums[j];
                }
            }
    
            return i + 1;
        }
    };


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
class Solution {
    public:
        int removeElement(vector<int>& nums, int val) {
            if (nums.empty()){
                return 0;
            }
            int i = 0;
            for (int j=0; j<nums.size(); j++){
                if (nums[j] != val){
                    nums[i] = nums[j];
                    i += 1;
                }
            }
            return i;
        }
    };


/*
Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

 

Example 1:

Input: haystack = "sadbutsad", needle = "sad"
Output: 0
*/

// Use .find method returns a size_t or int
class Solution {
    public:
        int strStr(string haystack, string needle) {
            size_t index = haystack.find(needle);      // can also return no position (npos)
            if (index != string::npos) {
                return index;
            }
            return -1;
        }
    };
        