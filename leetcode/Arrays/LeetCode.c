#include <stdio.h>
#include <stdlib.h>


int* twoSum(int* nums, int numsSize, int target, int* returnSize) {

    *returnSize = 2;

    // init array to zero
    int* map = malloc(numsSize * sizeof(int));

    int curr = 0;
    int* p_retval = malloc(2 * sizeof(int));

    for (int i = 0; i < numsSize; i++) {

        curr = target - nums[i];

        for (int j = 0; j <= i; j++)
        {
            if (map[j] == curr)
            {
                p_retval[0] = i;
                p_retval[1] = j;

                *returnSize = 2;
                return p_retval;
            }
        }

        map[i] = nums[i];
    }

    *returnSize = 0;
    return p_retval;
}

void merge(int* nums1, int nums1Size, int* nums2, int nums2Size) {

    int m = nums1Size;
    int n = nums2Size;
    int i = m + n - 1;

    for (; i >= m; i--)
    {
        nums1[i] = nums2[i - m];
    }

    for (i = 0; i < m + n; i++)
    {
        for (int j = i + 1; j < m + n; j++)
        {
            if (nums1[i] > nums1[j])
            {
                nums1[i] = nums1[i] ^ nums1[j];
                nums1[j] = nums1[i] ^ nums1[j];
                nums1[i] = nums1[i] ^ nums1[j];
            }
        }
    }
}

int* shuffle(int* nums, int numsSize, int* returnSize) {

    int n = numsSize;

    int* results = malloc(sizeof(int) * n * 2);
    *returnSize = n * 2;

    for (int i = 0; i < n; i++)
    {
        results[2 * i] = nums[i];
        results[2 * i + 1] = nums[i + n];
    }

    return results;
    *returnSize = 0;
    return NULL;
}

int singleNumber(int* nums, int numsSize) {

    // unique number placeholder
    int uniqueNumber = 0;

    for (int i = 0; i < numsSize; i++)
    {
        uniqueNumber = uniqueNumber ^ nums[i];
    }

    return uniqueNumber;
}

double average(int* salary, int salarySize) {

    if (salarySize > 2)
    {
        int minVal = salary[0], maxVal = 0; // minVal has to start from value. Can't be 0
        double totalSum = 0;

        for (int i = 0; i < salarySize; i++)
        {
            if (salary[i] > maxVal)
                maxVal = salary[i];

            if (salary[i] < minVal)
                minVal = salary[i];

            totalSum += salary[i];
        }

        totalSum -= maxVal;
        totalSum -= minVal;

        return totalSum / (salarySize - 2);
    }

    return 0;
}

int* getConcatenation(int* nums, int numsSize, int* returnSize) {

    int* ans = malloc(sizeof(int) * numsSize * 2);
    *returnSize = 2 * numsSize;

    for (int j = 0; j < numsSize; j++)
    {
        ans[j] = nums[j];
        ans[j + numsSize] = nums[j];
    }

    // Return ans and free the pointer returnSize.
    return ans;
    *returnSize = 0;
    return NULL;
}

int main() {


    /*  Concatenation of Array
        Given an integer array nums of length n, you want to create an array ans of length 2n where ans[i] == nums[i] and ans[i + n] == nums[i] for 0 <= i < n (0-indexed).
        Specifically, ans is the concatenation of two nums arrays.
        Return the array ans.
    */
    int cA_data[] = { 1,3,2,1 };
    int* cA_ret;
    cA_ret = getConcatenation(cA_data, 4, 8);


    /*  Average Salary Excluding the Minimum and Maximum Salary
        You are given an array of unique integers salary where salary[i] is the salary of the ith employee.
        Return the average salary of employees excluding the minimum and maximum salary. Answers within 10-5 of the actual answer will be accepted.
    */
    int s_data[] = { 4000,3000,1000,2000 };
    double s_ret = average(s_data, 4);


    /*  Single Number
        Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
        You must implement a solution with a linear runtime complexity and use only constant extra space.
    */
    int sN_data[] = { 1,1,2,2,3,4,4,5 };
    int sN_ret = singleNumber(sN_data, 8);


    /*  Shuffle the Array
        Given the array nums consisting of 2n elements in the form [x1,x2,...,xn,y1,y2,...,yn].
        Return the array in the form [x1,y1,x2,y2,...,xn,yn].
    */
    int sA_data[] = { 1,2,3,4,5,1,2,3,4,5 };
    shuffle(sA_data, 10, 10);


    /*  Merge Sorted Array
        You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.
        Merge nums1 and nums2 into a single array sorted in non-decreasing order.
        The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.
    */
    int mSA_data1[] = { 1,3,5,0,0,0 };
    int mSA_data2[] = { 2,4,6 };
    merge(mSA_data1, 3, mSA_data2, 3);


    /*  Two Sums
        Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
        You may assume that each input would have exactly one solution, and you may not use the same element twice.
    */
    int* tS_ret;
    int tS_data[] = { 0, 2, 3, 3, 2, 4, 0 };

    tS_ret = twoSum(tS_data, 6, 6, 2);
    tS_ret = twoSum(tS_data, 6, 4, 2);
    tS_ret = twoSum(tS_data, 6, 0, 2);

}