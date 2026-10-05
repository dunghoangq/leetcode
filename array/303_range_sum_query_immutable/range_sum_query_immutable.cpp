/*
RANGE SUM QUERY - IMMUTATBLE

Given int array nums, handle multiple queries of the following type:

1. Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.

Implement NumArray class:

- NumArray(int[] nums) Initializes the object with the integer array nums.
- int sumRange(int left, int right) Returns the sum of the elements of nums between indices left and right inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).

e.g.1,

Input
["NumArray", "sumRange", "sumRange", "sumRange"]
[[[-2, 0, 3, -5, 2, -1]], [0, 2], [2, 5], [0, 5]]
Output
[null, 1, -1, -3]

Explanation
NumArray numArray = new NumArray([-2, 0, 3, -5, 2, -1]);
numArray.sumRange(0, 2); // return (-2) + 0 + 3 = 1
numArray.sumRange(2, 5); // return 3 + (-5) + 2 + (-1) = -1
numArray.sumRange(0, 5); // return (-2) + 0 + 3 + (-5) + 2 + (-1) = -3

-------------------------------

Algorithim

Prefix sum
- Time: O(1)
- Space: O(n)

NUM-ARRAY(nums)
    n = nums.length
    nums

SUM-RANGE(left, right)
    if left or right not in range (0, n)
        return error
    if left > right
        return error

    sum = 0

    for i = left..right + 1
        sum += nums[i]

    return sum
*/

#include <iostream>
#include <vector>

class NumArray {
private:
    std::vector<int> prefix;

public:
    NumArray(std::vector<int>& nums) {
        int n = nums.size();
        prefix.resize(n+1, 0);

        for (int i = 0; i < n; i++) 
            prefix[i+1] = prefix[i] + nums[i];
    }

    int sumRange(int left, int right) {
        return prefix[right + 1] - prefix[left];
    }
};