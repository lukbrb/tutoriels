""" 14. Longest Common Prefix : https://leetcode.com/problems/longest-common-prefix/description/

Consigne :

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"

Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.

"""


from typing import List


def longestCommonPrefix(strs: List[str]):
    prefix = ""
    max_len = len(min(strs, key=len))
    if len(strs) == 1: return strs[0]

    for index in range(max_len):
        if all(mot[index] == strs[0][index] for mot in strs[1:]):
            prefix += strs[0][index]
        else: break
    return prefix

strs1 = ["flower","flow","flight"]
print(longestCommonPrefix(strs1) == "fl")
strs2 = ["dog","racecar","car"]
print(longestCommonPrefix(strs2) == "")
strs3 = ["a"]

print(longestCommonPrefix(strs3) == "a")

"""
Résultats:
---------------
Runtime 51ms
Beats 8.37%of users with Python3
---------------
Memory 16.25MB
Beats 87.10%of users with Python3
"""