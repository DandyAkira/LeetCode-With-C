/*
 * @lc app=leetcode.cn id=2272 lang=cpp
 *
 * [2272] 最大波动的子字符串
 */

#include<iostream>
#include<unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
    int largestVariance(string s) {
        unordered_map<char, int> mp;
        int shake = 0;
        for (int i = 0; i < s.length(); i++)
        {   
            mp.clear();
            char minchar = s[i];
            mp[s[i]] = 1;
            for (int j = i+1; j < s.length(); j++)
            {
                mp[s[j]]++;
                if(mp[s[j]] < mp[minchar]) minchar = s[j];
                shake = shake > (mp[s[j]] - mp[minchar]) ? shake : (mp[s[j]] - mp[minchar]);
            }
        }
        return shake;
        
    }
};
// @lc code=end

