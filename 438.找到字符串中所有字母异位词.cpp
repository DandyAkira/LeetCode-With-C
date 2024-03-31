/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start

#include<iostream>
#include<vector>
#include<string>
#include<set>
using namespace std;

class Solution {
public:
    // ! 用 multiset 超时
    vector<int> findAnagrams_multiset(string s, string p) {
        multiset<char> s_set;
        multiset<char> p_set;
        vector<int> res;
        int i = 0;
        for(char each:p){
            p_set.insert(each);
        }
        
        for(int j = p.length()-1; j < s.length(); j++){
            if(i==0){
                for(int k = i; k <= j; k++){
                    s_set.insert(s.at(k));
                }
            } else {
                s_set.erase(s_set.find(s.at(i-1)));
                s_set.insert(s.at(j));
            }
            if(s_set == p_set){
                res.push_back(i);
            }
            i++;
        }
        return res;
    }

    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        if(s.length() < p.length()) {
            return res;
        }
        int pivet = 0;
        int p_arr[26] = {0};
        int s_arr[26] = {0};
        bool same;
        for(char each:p){
            p_arr[each-'a']++;
        }
        for(int j = p.length() - 1; j < s.length(); j++){
            same = true;
            if(pivet == 0){
                for(int i=0; i<=j; i++){
                    s_arr[s[i]-'a']++;
                }
            } else {
                s_arr[s[pivet - 1] - 'a']--;
                s_arr[s[j] - 'a']++;
            }
            for(int i=0; i<26; i++){
                if(s_arr[i] != p_arr[i]){
                    same = false;
                    break;
                }
            }
            if(same){
                res.push_back(pivet);
            }
            pivet++;
        }
        return res;
    }
};

// @lc code=end

