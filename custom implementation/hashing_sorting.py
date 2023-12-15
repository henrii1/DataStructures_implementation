# Hashing  
#E.g. Given an array of strings, group the anagrams together, anagrams are words containing the same letters.
from typing import List
def anagram(str: List[str]):
    anagram_dic = {}
    result = []

    for s in str:
        sorted_s = sorted(s)
        if sorted_s not in anagram_dic:
            anagram_dic[sorted_s] = [s]
        else:
            anagram_dic[sorted_s].append(s)
    for a in anagram_dic.values():
        result.append(a)
    return result

# in this example, the hashing is done using the Anagram dictionary.

"""Sorting Algorthms"""
#SELECTIONSORT: finds the smallest element in the list, swaps with zero index, finds the smallest from index 1, swaps with index 1
#BUBBLESORT: goes from first to last element in the list, swaps adjacent element from first to last multiple times until sorted

#MERGESORT: divides lists until only one element remain: recursively merge all sublists into one main list, sorting as you go
    
#INSERTIONSORT: goes from left to right, for each new element, compares with all the elements to its left to find a perfect position. 
#> goes over the list just once.

#QUICKSORT: selects a mid value, swaps item left that are larger with those right that are smaller, recursively.



#implementation of insertion sort
def insertion_sort(list):
    for i in range(1, len(list)):
        for j in range(i-1, -1, -1):
            if list[j] > list[j + 1]:
                list[j], list[j + 1] = list[j + 1], list[j]
    return list


# selection sort

def selection_sort(list):
    for i in range(0, len(list)):
        for j in range(i+1, len(list)):
            if list[j-1] < list[j]:
                list[j-1], list[j] = list[j], list[j-1]
        list[i], list[-1] = list[-1], list[i]
    return list
            

# bubble sort

def bubble_sort(list):
    for i in range(0, len(list)-1):    #last element is already sorted
        for j in range(0, len(list)-1):
            if list[j] > list[j + 1]:
                list[j], list[j + 1] = list[j + 1], list[j]
    return list
            

#NB: recursion adds up again by calling itself multiple times eg(merg(a), merge(a/2), merge(a/4), merge(a/6))

# merge sort

def merge_sort(arr):
    if len(arr) > 1:
        mid = len(arr) // 2 
        left_half = arr[:mid]  
        right_half = arr[mid:]  

        merge_sort(left_half)  
        merge_sort(right_half)  # perform recursion on both till only 1 value in list

        i = j = k = 0           

        # Merge the two halves
        while i < len(left_half) and j < len(right_half):    # join recursively by comparing one element in one with all in the other, append to main list
            if left_half[i] < right_half[j]:
                arr[k] = left_half[i]
                i += 1
            else:
                arr[k] = right_half[j]
                j += 1
            k += 1

        # Check for any remaining elements in both halves
        while i < len(left_half):                           #check if some elements still remains that haven't been appended in left half
            arr[k] = left_half[i]
            i += 1
            k += 1

        while j < len(right_half):                          #check if some elements still remains that haven't been appended in left half
            arr[k] = right_half[j]
            j += 1
            k += 1
    return arr


    
# Quick Sort

def quick_sort(list):
    if len(list) <= 1:
        return list
    else:
        pivot = list[0]
        less_than_pivot = [x for x in list[1:] if x <= pivot]
        greater_than_pivot = [x for x in list[1:] if x > pivot]

        return quick_sort(less_than_pivot) + [pivot] + quick_sort(greater_than_pivot)