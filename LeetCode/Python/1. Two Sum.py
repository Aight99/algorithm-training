from typing import List


def twoSum(nums: List[int], target: int) -> List[int]:
    hash_map = dict()
    for i, num in enumerate(nums):
        hash_code = target - num
        if hash_code in hash_map.keys():
            return [hash_map[hash_code], i]
        hash_map[num] = i
    return [0, 0]


nums = list(map(int, input().split()))
target = int(input())
print(nums)
print(target)
print(twoSum(nums, target))
