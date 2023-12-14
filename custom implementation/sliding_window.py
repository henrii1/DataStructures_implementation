"""For sliding window, we do not create a result dictionary, we compute and return a slice of the original list"""


#E.G1: Given a array of positive integers, find the subarrays of integers that add up to a given number.
from typing import List
import time
class Solution:
    def __init__(self, example_input: List, desired_sum: int) -> List[List]:
        self.example = example_input
        self.sum = desired_sum
        self.result = []
    def brute_force(self):
        for i in range(len(self.example)):
            sum_counter = 0
            for j in range(i, len(self.example)):
                sum_counter += self.example[j]
                if sum_counter == self.sum:
                    self.result.append(self.example[i:j+1])
        return self.result
    
    def sliding_window(self):
        sum_counter = 0
        start_index = 0
        for index, value in enumerate(self.example):
            sum_counter += value
            while sum_counter > self.sum:
                sum_counter -= self.example[start_index]
                start_index += 1
            if sum_counter == self.sum:
                self.result.append(self.example[start_index:index + 1])
        return self.result






"""
Requirements:
            -sub arrays are contiguous hence should be considered, as well as the order. 
            -nested list of result should be printed.
Analysis:
        -brute force approach: sums all possible combination of values and stores in a table or hashmap. time and space complexity is O(n2)
        -sliding window technique: slides through, storing only first and last index each time. time complexity O(n), space complexity O(1)

Algorithm:
    Brute force: 
        create result list, 
        first loop for each index, 
        create a sum counter, 
        second for loop for each item in first loop, 
        add element into sum counter,
        if sum is equal to desired_sum, append into result
    Sliding window:
        create a result list,
        initialize starting index,
        initialize sum counter
        for loop with enumerate to get index and value
            sum counter += list[index]
            if sum counter > desired_sum
                sum counter -= list[starting_sum]
                starting sum += 1
            result.append(starting_sum: i+1)

        



"""





# Tests
# case 1 sliding window

example_input1 = [1, 7, 9, 4, 3, 2, 2]
desired_sum1 = 7
solution1 = [[7], [4, 3], [3, 2, 2]]

start_sliding = time.time()
obtained_solution1_sliding = Solution(example_input1, desired_sum1).sliding_window()
end_sliding = time.time()
print(obtained_solution1_sliding)
print(f"Sliding Window: {(end_sliding - start_sliding):.2f} seconds")
assert solution1 == obtained_solution1_sliding
# case 1 brute force
start_brute = time.time()
obtained_solution1_brute = Solution(example_input1, desired_sum1).brute_force()
end_brute = time.time()
print(obtained_solution1_brute)
print(f"Brute Force: {(end_brute - start_brute):.2f} seconds")
assert solution1 == obtained_solution1_brute

# case 2
example_input2 = [-1, -4, 0, 5, 3, 2, 1]
desired_sum2 = 5
solution2 = [[-1, -4, 0, 5, 3, 2], [5], [3, 2]]
obtained_solution2 = Solution(example_input2, desired_sum2).sliding_window()
assert solution2 != obtained_solution2





#E.G2: Given an array of 0's and 1's, find the maximum sequence of continuous 1's that can be formed by flipping at-most k 0's to 1's.
from typing import List
import time
class Solution:
    def __init__(self, example_input: List, max_flips: int) -> List:
        self.example = example_input
        self.flip = max_flips
        self.result = []
    def brute_force(self):
        self.result = []
        for i in range(len(self.example)):
            zeros = []
            for j in range(i, len(self.example)):
                if self.example[j] == 0:
                    zeros.append(0)
                    if len(zeros) == self.flip:
                        self.result.append(self.example[i:j+1])
        self.result.sort()
        return self.result[-1]
    def sliding_window(self):
        result_list = []
        zero_count = 0
        for value in self.example:
            result_list.append(value)
            if value == 0:
                zero_count += 1
            while zero_count > self.flip:
                if result_list[0] == 0:
                    zero_count -= 1
                result_list.pop(0)
            if zero_count == self.flip:
                self.result = result_list.copy()
        return self.result








"""
Requirements:
            -sub arrays are contiguous hence should be considered, as well as the order. 
            -nested list of result should be printed.
Analysis:
        -brute force approach: sums all possible combination of values and stores in a table or hashmap. time and space complexity is O(n2)
        -sliding window technique: slides through, storing only first and last index each time. time complexity O(n), space complexity O(1)

Algorithm:
    Brute force: 
        create result list, 
        first loop for each index,
        create a list to store number of zeros
        create the second loop from i to len(list)
        if j is zero, append to zero list
        if len(zero) == 2, append nested list to result
        result.sort()
        return result[-1]

    Sliding window:
        create a count list
        initialize a counter of zeros
        loop over the values in the list
        count_list.append(value)
        if value is 0, increment counter
        while counter > flip amount
        if count_list[0] is 0, decrement counter, pop first index
        if counter == flip value
        self.result = count.list.copy
        return self.result




        



"""





# Tests
# case 1 sliding window

# Test case #1
example_input1 = [1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 0]
max_flips1 = 2
solution1 = [0, 1, 1, 0, 1, 1]


calculated_solution1 = Solution(example_input1, max_flips1).brute_force()
calculated_solution2 = Solution(example_input1, max_flips1).sliding_window()

print(f"Example Input #1: {example_input1}, Maximum Flips: {max_flips1}, Solution: {calculated_solution1} (Length: {len(calculated_solution1)})")
print(f"Example Input #1: {example_input1}, Maximum Flips: {max_flips1}, Solution: {calculated_solution2} (Length: {len(calculated_solution2)})")
# assert calculated_solution1 == solution1




#E.G3: Given an array of integers, find maximum sum subarray of the required size.

#write the code for the brute force approach

def sliding_window(input_arr, subarray_size):
    # Validate input
    assert subarray_size > 0, 'Subarray size must be positive.'

    current_sum = 0
    max_sum = 0
    max_sum_start_index = 0

    # Iterate entire array from left to right
    for index, number in enumerate(input_arr):
        # Increase the window size by one from the right
        current_sum += number

        if index < subarray_size:
            # Continue to accumulate until we reach the desired subarray size (= max window size)
            max_sum = current_sum
        else:
            # We are over the max window size, so remove one element from the left
            current_sum -= input_arr[index - subarray_size]

            if current_sum > max_sum:
                # We have a new maximum sum window, so record its starting index
                max_sum = current_sum
                max_sum_start_index = index - subarray_size + 1

    return input_arr[max_sum_start_index:max_sum_start_index + subarray_size]




'''
Requirements:
            -sub arrays are contiguous hence should be considered, as well as the order. 
            -result is a list
Analysis:
        -brute force approach: sums all possible combination of values and stores in a table or hashmap. time and space complexity is O(n2)
        -sliding window technique: slides through, storing only first and last index each time. time complexity O(n), space complexity O(1)

Algorithm:
    brute-force:                  if more than one list contains same sum, retain only one of them
        create a result dictionary, key should be count and value should be list of desired size
        initialize a sum counter
        initialize a increment_counter
        for i in range(len(list))
        create a list for results
        for j in range(i, len(list))
        sub result list.append(j)
        counter += j
        incrementer += 1
        if incrementer == required size?
        result_dic.update({counter: sub result list})
        result_dic.sort()
        list(result_dic.popitem()[1])
    sliding_window:                      #don't create a result list, just use slicing to return the right index
        initialize current sum
        initialize max sum
        initialize start index  # will be used later for assignment
        for index, value in enumerate(example list)
        current sum += value
        if index < required size
        max sum = curr sum
        else:current sum -= example list[index-required size]
        if curr sum > max sum
        max sum = cur sum
        max start index = index - required size + 1
        return example list[max start index: index + 1]
'''

# Tests
# Test case #1
example_input1 = [-1, 2, 3, 0, -3, 9]
subarray_size1 = 2
solution1 = [-3, 9]

calculated_solution1 = get_max_subarray(example_input1, subarray_size1)

print(f"Example Input #1: {example_input1}, Subarray Size: {subarray_size1}, Solution: {calculated_solution1}")
assert calculated_solution1 == solution1