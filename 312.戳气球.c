/*
 * @lc app=leetcode.cn id=312 lang=c
 *
 * [312] 戳气球
 */

// @lc code=start

int DP(int s, int e, int* nums){

    if(s==e){return nums[s];}
    if(e==s+1){
        int bigger = nums[s] > nums[e] ? nums[s] : nums[e];
        return (nums[s]*nums[e] + bigger);
    }

    int total = 0;
    int sum;
    for(int k = s+1; k < e; k++){
        sum = DP(s, k, nums) + DP(k, e, nums) + nums[s]*nums[k]*nums[e];
        if(sum > total){
            total = sum;
            printf("%d\n", k);
        }
    }
    int bigger = nums[s] > nums[e] ? nums[s] : nums[e];
    return (total + nums[s]*nums[e] + bigger);
}

int maxCoins(int* nums, int numsSize){
    return DP(0, numsSize-1, nums);
}

int main(int argc, char const *argv[])
{
    int nums[] = {3,1,5,8};
    printf("%d\n", maxCoins(nums, 4));
    return 0;
}

// @lc code=end

