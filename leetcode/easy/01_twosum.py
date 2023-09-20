""" Consigne :

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

"""

from typing import List


def twoSum(nums: List[int], target: int) -> List[int]:
    n = len(nums)
    # On veut générer des combinaisons uniques de (i, j)
    for i in range(n-1):
        for j in range(i+1, n):
            if (nums[i] + nums[j]) == target:
                return [i, j]

def twoSum_optim(nums, target):
    "Beats 98.71%of users with Python3"
    n = len(nums)
    return [[i, j] for i in range(n - 1) 
                    for j in range(i+1, n) 
                    if (nums[i] + nums[j]) == target][0]

if __name__ == '__main__':
    nums = [2,7,11,15]
    target = 9
    reponse = [0, 1]
    res = twoSum_optim(nums, target)
    print(res)
    # assert res == reponse, f"Expected {reponse}, got {res}]"
