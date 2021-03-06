//
//  CSortDemo.c
//  LearnAlgorithmOnMac
//
//  Created by panwei on 2019/11/13.
//  Copyright © 2019 WeirdPan. All rights reserved.
//

#include "CSortDemo.h"
#include <limits.h>
//求一个字符串里面的最长回文字符串（两遍对称的字符串，比如bab、bb）
//思路，比如一个字符串string=iambabygirl，回文字符串是bab，那么可以用i循环每个字符，假设它是中心的那个字符串a，那么string[i-1]和string[i+1]应该相等（a左右两遍的字符串相等），如果不等那就break跳出循环，如果相等，那么就继续比较string[i-2]和string[i+2]是否相等，直到string[i-j]和string[i+j]这轮小循环全部结束，此时回文字符串长度是j*2+1,
int LongestPalindrome(const char *s, int n)
{
    int i, j, max,c;
    c = 0;
    if (s == 0 || n < 1)
        return 0;
    max = 0;//回文字符串长度最大值，非空字符串至少是1

    for (i = 0; i < n; ++i) { // i is the middle point of the palindrome
        for (j = 1; (i - j >= 0) && (i + j < n); ++j){ // 如果回文的长度是奇数 if the length of the palindrome is odd
            if (s[i - j] != s[i + j])
                break;
            c = j * 2 + 1;
        }
        if (c > max)
            max = c;
        for (j = 1; (i - j >= 0) && (i + j + 1 < n); ++j){ //如果回文的长度是偶数 for the even case
            if (s[i - j] != s[i + j + 1])
                break;
            c = j * 2 + 2;
        }
        if (c > max)
            max = c;
    }
    return max;
}
//测试用例:
//const char *testStr = "iambabygirl";
//LongestPalindrome(testStr, strlen(testStr));

//LeetCode152-C
//https://leetcode-cn.com/problems/maximum-product-subarray/comments/401259
int MAX_NUM(int a, int b)
{
    return (a > b ? a : b);
}

int MIN_NUM(int a, int b)
{
    return (a < b ? a : b);
}

int maxProduct(int* nums, int numsSize){
    int max_number = INT_MIN;
    int max_tmp = 1, min_tmp = 1;
    int tmp;  // 在这个数小于0的时候，将最大值和最小值互相交换
    int i;
    for (i = 0; i < numsSize; ++i)
    {
        if (nums[i] < 0)
        {
            tmp = max_tmp;
            max_tmp = min_tmp;
            min_tmp = tmp;
        }
        max_tmp = MAX_NUM(max_tmp * nums[i], nums[i]);
        min_tmp = MIN_NUM(min_tmp * nums[i], nums[i]);
        
        max_number = MAX_NUM(max_number, max_tmp);
    }
    return max_number;
}
