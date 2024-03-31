/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start

#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> map;
        for(auto s:strs){
            string tmp = s;
            sort(tmp.begin(), tmp.end());
            map[tmp].push_back(s);
        }
        for(auto iter:map){
            res.push_back(iter.second);
        }
        return res;
    }
};
// @lc code=end

