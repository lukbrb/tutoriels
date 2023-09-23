""" 
4. Median of Two Sorted Arrays

Consigne : 

Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).
"""

from typing import List


def findMedianSortedArrays(nums1: List[int], nums2: List[int]) -> float:
        merged_array = nums1 + nums2
        merged_array.sort()
        N = len(merged_array)
        if N % 2 == 1:
            median = merged_array[N // 2]
        else:
            median = 0.5 * (merged_array[N//2 -1] + merged_array[N // 2])
        
        return median

"""
Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.

Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

"""

# Résolu en un essai, assez facilement avec Python. Réessayer en C
"""
Résultats : 
---------------
Runtime : 87ms
Beats 74.83% of users with Python3
---------------
Memory: 16.53MB
Beats 64.86% of users with Python3
"""