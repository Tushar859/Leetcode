class Solution(object):
    def removeDuplicates(self, nums):
        arr = []
        cnt =0
        for i in range(len(nums)):
            if i == 0 or nums[i] != nums[i-1]:
                arr.append(nums[i])    

        for i in range(len(arr)):
                nums[i] = arr[i]      
        return len(arr)