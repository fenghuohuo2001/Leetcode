"""
@Name: 704-二分查找.py
@Auth: Huohuo
@Date: 2023/4/6-20:28
@Desc: 
@Ver : 
code_idea

1. right减一的影响：
    由于是向下取整的，right是否减一对取值结果无影响
    若减一，则在数组元素个数为偶数时，会少一次循环；在奇数时，无影响
2. left加一的影响?
    由于是向下去噪，left是否减一至关重要
    在判断条件取等于号时，说明取值区间是右闭的：
        若加一，则在判断条件取等于时，能够取到最后一位元素
        若不加一，则在target取最后一位元素时，会陷入无限循环，即一直取[-2]的元素，无法到达[-1]
    在判断条件不取等于号时，说明取值区间是右开的：
        此时加一与不加一对结果无影响
        但是在不论偶数还是奇数个的时侯，会少一次循环?
"""
from typing import List

# # 循环解题
# class Solution:
#     def search(self, nums: List[int], target: int) -> int:
#         temp = 0
#         for i, num in enumerate(nums):
#             if num == target:
#                 print(i)
#                 return i
#             else:
#                 temp += 1
#             if temp == len(nums):
#                 print(-1)
#                 return -1
#             else:
#                 continue

# 二分查找
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        left, right = 0, len(nums)-1
        while left <= right:
            mid = (left + right) // 2
            if nums[mid] == target:
                print(mid)
                return mid
            if nums[mid] < target:    # 若target在中位数右边
                left = mid+1            # 若是mid或者-1，则在偶数个序列中，最后一步永远不会收敛
            elif nums[mid] > target:    # 若target在中位数左边
                right = mid
        print(-1)
        return -1



Solve = Solution()


nums = [-1,0,3,5,9,12]
target = 12

Solve.search(nums, target)