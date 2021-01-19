/*
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
Follow up: Could you implement a solution with a linear runtime complexity and without using extra memory?
Example 1:

Input: nums = [2,2,1]
Output: 1

Example 2:
Input: nums = [4,1,2,1,2]
Output: 4

Example 3:
Input: nums = [1]
Output: 1
*/

int singleNumber(int* nums, int numsSize){
    int num = 0;
    // XORing all the numbers will cancel out the repeated number and the result is the solution.
    // XOR of a number with itself is 0.
    // 4 ^ 1 ^ 2 ^ 1 ^ 2 = 4
    for(int i = 0; i < numsSize; i++){
        num ^= nums[i];
    }
    return num;
}
