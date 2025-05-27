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

int searchInsert(int* nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize-1;

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
int climbStairs(int n) {
    if (n <= 2) return n;
    int a = 1;
    int b = 2;

    for (int i=3; i<n+1; i++){
        int temp = b;
        b = a + b;
        a = temp;
    }

    return b;
}

/*
Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.

Input: head = [1,1,2]
Output: [1,2]
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* current = head;
    while (current && current->next){
        if (current->val == current->next->val){
            current->next = current->next->next;
        } else {
            current = current->next;
        }
    }
    return head;
    
}


/*
You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

 

Example 1:

Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
*/

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
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
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// Helper function to calculate the size of the tree
int countNodes(struct TreeNode* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Recursive helper for inorder traversal
void inorder(struct TreeNode* root, int* result, int* index) {
    if (!root) return;
    inorder(root->left, result, index);
    result[(*index)++] = root->val;
    inorder(root->right, result, index);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int totalNodes = countNodes(root);
    int* result = (int*)malloc(totalNodes * sizeof(int));
    *returnSize = 0;

    inorder(root, result, returnSize);

    return result;
}

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
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if (!p && !q) return true;
    if (!p || !q || p->val != q->val) return false;
    return (isSameTree(p->right, q->right) && isSameTree(p->left, q->left));
}

/*
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).
Input: root = [1,2,2,3,4,4,3]
Output: true
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool isMirror(struct TreeNode* t1, struct TreeNode* t2) {
    if (!t1 && !t2) return true;
    if (!t1 || !t2 || t1->val != t2->val) return false;
    return isMirror(t1->left, t2->right) && isMirror(t1->right, t2->left);
}

bool isSymmetric(struct TreeNode* root) {
    if (!root) return true;
    return isMirror(root->left, root->right);
}


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
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root) {
    if (!root) return 0;
    
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);

    return 1 + fmax(leftDepth, rightDepth);
}

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
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* buildtree(int* nums, int left, int right){
    if (left > right) return NULL;

    int mid = left + (right-left) / 2;
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = nums[mid];
    node->left = buildtree(nums, left, mid-1);
    node->right = buildtree(nums, mid+1, right);

    return node;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    return buildtree(nums, 0, numsSize-1);
}

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
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int checkbalance(struct TreeNode* root){
    if (!root) return 0;

    int left = checkbalance(root->left);
    if (left == -1) return -1;

    int right = checkbalance(root->right);
    if (right == -1) return -1;

    if (abs(left-right) > 1) return -1;

    return 1 + fmax(left, right);
}
bool isBalanced(struct TreeNode* root) {
    return checkbalance(root) != -1;
}


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
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 #define MIN(a, b) ((a) < (b) ? (a) : (b))
int minDepth(struct TreeNode* root) {
    if (!root) return 0;

    // If one of the children is NULL, you must go down the other side
    if (!root->left) return 1 + minDepth(root->right);
    if (!root->right) return 1 + minDepth(root->left);

    return 1 + MIN(minDepth(root->left), minDepth(root->right));
}

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

// Recursive DFS
bool hasPathSum(struct TreeNode* root, int targetSum) {
    if (!root) return false;
    
    if (!root->left && !root->right) return root->val == targetSum;

    return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
}

// DFS (manage stack)

typedef struct {
   struct TreeNode* node;
    int sum;
} NodePair;

#define MAX_SIZE 1000

int top = -1;
NodePair stack[MAX_SIZE];

void push(NodePair val) {
    if (top < MAX_SIZE - 1) stack[++top] = val;
}

NodePair pop(){
    return stack[top--];
}

int is_stack_empty(){
    return top == -1;
}

bool hasPathSum(struct TreeNode* root, int targetSum){
    if (!root) return false;
    
    top = -1;
    push((NodePair){root, root->val});

    while (!is_stack_empty()){
        NodePair curr = pop();
        struct TreeNode* node = curr.node;
        int sum = curr.sum;

        if (!node->left && !node->right && sum == targetSum) return true;

        if (node->right) push((NodePair){node->right, sum + node->right->val});
        if (node->left) push((NodePair){node->left, sum + node->left->val});
    }

    return false;
}
// BFS method


typedef struct {
   struct TreeNode* node;
    int sum;
} NodePair;
#define MAX_SIZE 1000
int front = 0, rear = 0;
NodePair queue[MAX_SIZE];

void enqueue(NodePair val){
    if ((rear + 1) % MAX_SIZE != front){
        queue[rear] = val;
        rear = (rear + 1 ) % MAX_SIZE;
    }
}

NodePair dequeue(){
    NodePair val = queue[front];
    front = (front + 1) % MAX_SIZE;
    return val;
}

int is_queue_empty(){
    return front == rear;
}


bool hasPathSum(struct TreeNode* root, int targetSum){
    if (!root) return 0;

    front = rear = 0;  // all variables can be updated inside functions
    enqueue((NodePair){root, root->val});

    while (!is_queue_empty()){
        NodePair curr = dequeue();
        struct TreeNode* node = curr.node;
        int sum = curr.sum;

        if (!node->left && !node->right && sum == targetSum) return true;

        if (node->left) enqueue((NodePair){node->left, node->left->val + sum});
        if (node->right) enqueue((NodePair){node->right, node->right->val + sum});

    }
    return false;
}