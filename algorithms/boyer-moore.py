'''
  The Boyer-Moore voting method is one of the most often used optimum
algorithms for determining the majority element among elements with
more than N/2 occurrences. This works wonderfully for finding the
majority element, which requires two traversals over the provided 
items and is O(N) time and O(1) space complexity.
'''

def boyer-moore(arr):
    candidate = -1
    votes = 0
    for n in arr:
        if votes == 0:
            candidate = n
            votes = 1
        elif n == candidate:
            votes += 1
        else: 
            votes -= 1
    count = 0
    for n in arr:
        if n == candidate:
            count += 1
    if count > len(arr) // 2:
        return candidate
    else:
        return -1