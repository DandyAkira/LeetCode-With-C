/*
 * @lc app=leetcode.cn id=1444 lang=cpp
 *
 * [1444] 切披萨的方案数
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
    int ways(vector<string>& pizza, int k) {
        int m = pizza.size();
        int n = pizza[0].length();
        long long modu = 1000000007LL;
        // sub为后缀和，表示以i,j为左上角，pizza右下角为右下角的矩阵中苹果的个数
        vector<vector<int>> sub(m+1, vector<int>(n+1));
        for(int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                sub[i][j] = sub[i+1][j] + sub[i][j+1] - sub[i+1][j+1] + (pizza[i][j] == 'A' ? 1 : 0);
            }
        }
        // 三维dp：dp[o][i][j]表示在以(i,j)为左上角的矩阵中切o刀的可能方案数，则需返回dp[k-1][0][0]
        vector<vector<vector<long long>>> dp(k, vector<vector<long long>>(m,vector<long long>(n)));
        // k = 0情况：不需要切割，只要pizza上有苹果就是可行的
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                dp[0][i][j] = sub[i][j] > 0 ? 1LL : 0LL;
            }
        }
        // i = m - 1：尾行的第j列到结尾的pizza切割o刀的可行方案数
        for (int o = 1; o < k; ++o) {
            for (int j = n-2; j >= 0; --j) {
                for (int h = 1; h + j < n; ++h) 
                    dp[o][m-1][j] += sub[m-1][j] - sub[m-1][j+h] > 0 ? dp[o-1][m-1][j+h] : 0LL;
            }
        }
        // j = n - 1：尾列的第i行到结尾的pizza切割o刀的可行方案数
        for (int o = 1; o < k; ++o) {
            for (int j = m-2; j >= 0; --j) {
                for (int h = 1; h + j < m; ++h) 
                    dp[o][j][n-1] += sub[j][n-1] - sub[j+h][n-1] > 0 ? dp[o-1][j+h][n-1] : 0LL;
            }
        }
        // 一般情况：dp[o][i][j]=横切一刀后dp[o-1][i+h][j]的总和 + 竖切一刀后dp[o-1][i][j+h]的总和
        for (int o = 1; o < k; ++o) {
            for (int i = m - 2; i >= 0; --i) {
                for (int j = n - 2; j >= 0; --j) {
                    for (int h = 1; h < m - i; ++h) {
                        dp[o][i][j] += sub[i][j] - sub[i+h][j] > 0 ? dp[o-1][i+h][j] : 0LL;
                    }
                    for (int h = 1; h < n - j; ++h) {
                        dp[o][i][j] += sub[i][j] - sub[i][j+h] > 0 ? dp[o-1][i][j+h] : 0LL;
                    }
                }
            }
        }
        return (int)(dp[k-1][0][0] % modu);
    }
};
// @lc code=end

