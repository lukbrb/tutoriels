""" 11. Container with most water: https://leetcode.com/problems/container-with-most-water/description/

Consigne :

You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
Find two lines that together with the x-axis form a container, such that the container contains the most water.
Return the maximum amount of water a container can store.
Notice that you may not slant the container.


Example 1:

Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

Example 2:

Input: height = [1,1]
Output: 1

"""

def maxArea(height):
    area_max = 0
    left = 0
    right = len(height) - 1

    while left < right:
        hleft = height[left]
        hright = height[right]
        area = ((hleft <= hright) * hleft + (hright < hleft) * hright) * (right - left)
        if area > area_max: area_max = area

        if hleft < hright: left += 1
        else: right -= 1

    return area_max


height = [1, 8 ,6, 2, 5, 4, 8, 3, 7]
print("Test 1: ", maxArea(height) == 49)
print("Test 2: ", maxArea([1, 1]) == 1)


"""
Résultats:
-----------
Runtime: 564ms
Beats 91.70%of users with Python3
------------
Memory: 29.33MB
Beats 36.88%of users with Python3
"""

def min(a, b):
    if a < b: return a # = (a <= b) * a
    if b < a: return b # (b < a) * b

# On réecrit donc min(a, b) = (a <= b) * a + (b < a) * b
