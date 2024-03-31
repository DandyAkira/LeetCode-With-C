/*
 * @lc app=leetcode.cn id=188 lang=c
 *
 * [188] 买卖股票的最佳时机 IV
 */

// @lc code=start

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int maxProfit(int k, int* prices, int pricesSize){
    if(pricesSize == 0){
        return 0;
    }
    int buy[pricesSize][k+1];
    int sell[pricesSize][k+1];
    memset(buy, 0, sizeof(buy));
    memset(sell, 0, sizeof(sell));

    buy[0][0] = -prices[0];
    sell[0][0] = 0;

    for(int i=1; i<=k; i++){
        buy[0][i] = INT_MIN / 2;
        sell[0][i] = INT_MIN / 2;
    }

    for(int i = 1; i<pricesSize; i++){
        buy[i][0] = fmax(buy[i - 1][0], sell[i - 1][0] - prices[i]);
        for (int j = 1; j <= k; ++j) {
            buy[i][j] = fmax(buy[i - 1][j], sell[i - 1][j] - prices[i]);
            sell[i][j] = fmax(sell[i - 1][j], buy[i - 1][j - 1] + prices[i]);
        }
    }
    
    int ret = 0;
    for (int i = 0; i <= k; i++) {
        ret = fmax(ret, sell[pricesSize - 1][i]);
    }

    return ret;

}
// @lc code=end

