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