"""
@Name: 1.两数之和.py
@Auth: Huohuo
@Date: 2023/2/23-19:37
@Desc: 
@Ver : 
code_idea
"""
from typing import List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        n = len(nums)
        for i in range(n):
            for j in range(i+1, n):
                if nums[i] + nums[j] == target:
                    return [i, j]
        return []


nums = [2, 7, 11, 15]
target = 9
a = Solution()
a.twoSum(nums, target)