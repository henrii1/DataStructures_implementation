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
        

/*
Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [1,3,5,6], target = 5
Output: 2
Example 2:

Input: nums = [1,3,5,6], target = 2
Output: 1
*/

class Solution {
    public:
        int searchInsert(vector<int>& nums, int target) {
            int left = 0;
            int right = (nums.size() - 1);
    
            while (left <= right){
               int mid = (left + right) / 2;
    
               if (nums[mid] == target){
                return mid;
               } else if (nums[mid] < target){
                left = mid + 1;
               } else {
                right = mid - 1;
               }
            }
            return left;
        }
    };


/*
You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

 

Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
*/
class Solution {
    public:
        int climbStairs(int n) {
            if (n <= 2) return n;
            int a = 1;
            int b = 2;
            for (int i=3; i<n+1; i++){
                int temp = b;
                b = a+b;
                a = temp;
            }
            return b;
        }
    };

/*
Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.

Input: head = [1,1,2]
Output: [1,2]
*/

/*
Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.

Input: head = [1,1,2]
Output: [1,2]
*/

class Solution {
    public:
        ListNode* deleteDuplicates(ListNode* head) {
            ListNode* current = head;
            while (current && current->next){
                if (current->val == current->next->val){
                    current->next = current->next->next;
                } else {
                    current = current->next;
                }
            }
            return head;
        }
    };


    /*
    You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

 

Example 1:

Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
    */

    class Solution {
        public:
            void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
                int i = m - 1;
                int j = n - 1;
                int k = n + m - 1;
                while (j >= 0){
                    if (i >= 0 && nums1[i] > nums2[j]){
                        nums1[k--] = nums1[i--];
        
                    } else{
                        nums1[k--] = nums2[j--];
                    }
                }
            }
        };


/*
Given the root of a binary tree, return the inorder traversal of its nodes' values.

 

Example 1:

Input: root = [1,null,2,3]

Output: [1,3,2]
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 class Solution {
    public:
        vector<int> inorderTraversal(TreeNode* root) {
            vector<int> result;
            inorder(root, result);
            return result;

        }
    private:
        void inorder(TreeNode* node, vector<int>& result){
            if (!node) return;
            inorder(node->left, result);
            result.push_back(node->val);
            inorder(node->right, result);
        }
    };


/*
Given the roots of two binary trees p and q, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

(regardless of if the children arrangement are different, i.e., val1 in lst in tree1 and val1 in rst in tree2)
Input: p = [1,2,3], q = [1,2,3]
Output: true
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 class Solution {
    public:
        bool isSameTree(TreeNode* p, TreeNode* q) {
            if (!p && !q) return true;
            if (!p || !q || p->val != q->val) return false;
            return (isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
        }
    };



/*
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).
Input: root = [1,2,2,3,4,4,3]
Output: true
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return isMirror(root->left, root->right);
        
    }

private:
    bool isMirror(TreeNode* left, TreeNode* right){
        if (!left && !right) return true;
        if (!left || !right || left->val != right->val) return false;
        return(isMirror(left->left, right->right) && isMirror(left->right, right->left));
    }
};

/*
Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
Input: root = [3,9,20,null,null,15,7]
Output: 3
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        
        return 1 + std::max(leftDepth, rightDepth);
    }
};


/*
Q108: Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.

Input: nums = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: [0,-10,5,null,-3,null,9] is also accepted:
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildtree(nums, 0, nums.size()-1);
    }
private:
    TreeNode* buildtree(vector<int>& nums, int left, int right){
       if (left > right) return nullptr;
        
       int mid = left + (right-left) / 2;
       TreeNode* node = new TreeNode(nums[mid]);
       node->left = buildtree(nums, left, mid-1);
       node->right = buildtree(nums, mid+1, right);
       return node;
    }
};

/*
Q110: Given a binary tree, determine if it is height-balanced.
A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.

Input: root = [3,9,20,null,null,15,7]
Output: true
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return checkbalance(root) != -1;
    }
private:
    int checkbalance(TreeNode* node){
        if (!node) return 0;

        int left = checkbalance(node->left);
        if (left == -1) return -1;

        int right = checkbalance(node->right);
        if (right == -1) return -1;

        if (abs(left - right) > 1) return -1;

        return 1 + std::max(left, right);
    }
};


/*
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.

Example 2:

Input: root = [2,null,3,null,4,null,5,null,6]
Output: 5
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 // Using BFS
 
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;

        std::queue<std::pair<TreeNode*, int>> queue;
        queue.push({root, 1});

        while (!queue.empty()){
            TreeNode* node = queue.front().first;
            int depth = queue.front().second;

            queue.pop();

            if (!node->left && !node->right) return depth;

            if (node->left) queue.push({node->left, depth + 1});
            if (node->right) queue.push({node->right, depth + 1});
        }
            return 0;
    }
};


/*
Q112: Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.

A leaf is a node with no children.

Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
Output: true
Explanation: The root-to-leaf path with the target sum is shown.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

 /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


 // DFS recursive
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;

        if(!root->left && !root->right) return root->val == targetSum;
        return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
    }
};


// DFS iterative
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;

        std::stack<std::pair<TreeNode*, int>> stack;
        stack.push({root, root->val});

        while(! stack.empty()){
            auto [node, sum] = stack.top();
            stack.pop();

            if (!node->left && !node->right && sum == targetSum) return true;

            if (node->left) stack.push({node->left, node->left->val + sum});
            if (node->right) stack.push({node->right, node->right->val + sum});
        }
        return false;
    }
};


// BFS iterative
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;

        std::queue<std::pair<TreeNode*, int>> queue;
        queue.push({root, root->val});

        while(! queue.empty()){
            auto [node, sum] = queue.front();
            queue.pop();

            if (!node->left && !node->right && sum == targetSum) return true;

            if (node->left) queue.push({node->left, node->left->val + sum});
            if (node->right) queue.push({node->right, node->right->val + sum});
        }
        return false;
    }
};