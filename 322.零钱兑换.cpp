/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
#include<iostream>
#include<stack>
#include<cstring>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;


class Solution {
public:
    int coinChange(vector<int>& sizes, int requirement) {
        vector<int> dp(requirement+1);
        dp[0] = 0;
        for(int req=1; req <= requirement; req++){
            int min_num = INT_MAX-1;
            for(auto each : sizes){
                if(each <= req){
                    min_num = min_num < dp[req - each] ? min_num : dp[req - each];
                }
            }
            dp[req] = min_num + 1;
        }
        return dp[requirement] == INT_MAX ? -1 : dp[requirement];
    }
};
// @lc code=end

