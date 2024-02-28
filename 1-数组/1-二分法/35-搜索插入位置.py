"""
@Name: 35-搜索插入位置.py
@Auth: Huohuo
@Date: 2023/4/9-20:35
@Desc: 
@Ver : 
code_idea
"""
from typing import List

# 自解
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        left, right = 0, len(nums)-1
        while left <= right:
            temp = (left + right)//2
            if target == nums[temp]:
                print(temp)
                return temp
            elif target > nums[temp]:
                left = temp + 1
            elif target < nums[temp]:
                right = temp - 1
        print(left, right)
        # 分为情况讨论
        if target < nums[right]:
            print(max(right, 0))
            print("left", left)
            return(max(right, 0))
        elif nums[right] < target:
            print(left)
            return(left)

# 标准解
# class Solution:
#     def searchInsert(self, nums: List[int], target: int) -> int:
#         left, right = 0, len(nums)
#
#         while left < right:
#             mid = (left + right) // 2
#             if nums[mid] < target:    # 若target在右边，则mid及mid左边必不可能是目标索引，因此+1
#                 left = mid + 1
#             else:
#                 right = mid
#         print(left)       # 返回大于等于target的索引
#         return left





Solve = Solution()


nums = [1, 3, 5, 6]
target = 3

Solve.searchInsert(nums, target)

