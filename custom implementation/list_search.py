list = [2, 8, 3, 6, 4]

#remember
list[1:4]         # is non inclusive of index 4

def linear_search(value: int, list: List):
    i = 0
    while i <= len(list)-1:
        if list[i] == value:
            print(f'{value} found at index {i}')
            i += 1
            return True
        else:
            print(f"number {value} is not in the list")
    return False


# Binary Search: works only on sorted lists. complexity is O (logn)

from typing import List

def binary_search(value, lst: List):
    L = 0
    U = len(lst) - 1

    while L <= U:
        mid = (L + U) // 2

        if lst[mid] == value:
            print(f"Value found at index {mid}")
            return True
        elif lst[mid] < value:
            L = mid + 1
        else:
            U = mid - 1

    print("Value not found in list")
    return False

# Example usage:
my_list = [2, 4, 6, 8, 10, 12, 14, 16]
result = binary_search(10, my_list)
print(result)
