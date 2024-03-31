/*
 * @lc app=leetcode.cn id=71 lang=cpp
 *
 * [71] 简化路径
 */

// @lc code=start

#include<iostream>
#include<stack>
#include<cstring>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        string res = "";
        char *p = &path[0];
        stack<string> tmp;
        char *token = strtok(p, "/");
        while(token){
            string s = token;
            token = strtok(NULL, "/");
            if(s.compare(".")==0) continue;
            if(s.compare("..")==0){
                if(!tmp.empty()) tmp.pop();
                continue;
            }
            tmp.push(s);
        }
        while(!tmp.empty()){
            res = "/" + tmp.top() + res;
            tmp.pop();
        }
        return res;
    }
};
// @lc code=end

