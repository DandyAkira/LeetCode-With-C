/*
 * @lc app=leetcode.cn id=331 lang=cpp
 *
 * [331] 验证二叉树的前序序列化
 */

// @lc code=start

/* 思路：栈
我们可以定义一个概念，叫做槽位。
一个槽位可以被看作 「当前二叉树中正在等待被节点填充」 的那些位置。

二叉树的建立也伴随着槽位数量的变化。每当遇到一个节点时：

    if: 遇到了空节点，则要消耗一个槽位；
    if: 如果遇到了非空节点，则除了消耗一个槽位外，还要再补充两个槽位。

此外，还需要将根节点作为特殊情况处理。

我们使用栈来维护槽位的变化。栈中的每个元素，代表了对应节点处剩余槽位的数量，而栈顶元素就对应着下一步可用的槽位数量。
    当遇到空节点时，仅将栈顶元素减 1；
    当遇到非空节点时，将栈顶元素减 1 后，再向栈中压入一个 2。
无论何时，如果栈顶元素变为 0，就立刻将栈顶弹出。

遍历结束后，
若栈为空，说明没有待填充的槽位，因此是一个合法序列；
否则若栈不为空，则序列不合法。
此外，在遍历的过程中，若槽位数量不足，则序列不合法。
*/

#include<iostream>
#include<string>
#include<stack>
#include<string.h>
#include<vector>
using namespace std;

class Solution {
public:
    static vector<string> split(string preorder){
        vector<string> res;
        char * cpystr = new char[preorder.length() + 1];
        strcpy(cpystr, preorder.c_str());
        const char * p = ",";
        char * tmp = strtok(cpystr, p);
        while (tmp)
        {
            res.push_back(string(tmp));
            tmp = strtok(NULL, p);
        }
        return res;
    }

    static bool isValidSerialization(string preorder) {
        if(preorder[0] == '#' && preorder.length()>1) return false;
        if(preorder[0] == '#' && preorder.length()==1) return true;
        if(preorder.length() < 3){
            return false;
        }
        vector<string> data = split(preorder);
        stack<int> stk;
        stk.push(2);
        int i=1;
        for (auto &&each : data)
        {
            cout << each << " ";
        }
        cout << endl;
        
        while(!stk.empty() && i<data.size()){
            if(data[i] == "#"){
                stk.top()--;
                if(stk.top() == 0) stk.pop();
            } else {
                stk.top()--;
                if(stk.top() == 0) stk.pop();
                stk.push(2);
            }
            cout << "now ch: " << data[i];
            if(stk.empty()){
                cout << " empty" << endl;
            } else {
                cout << " top: " << stk.top() << endl;
            }
            i++;

        }
        if(i < data.size()){
            return false;
        }
        if(!stk.empty()){
            return false;
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    string a = "9,#,92,#,#";
    cout << Solution::isValidSerialization(a) << endl;
    return 0;
}

// @lc code=end

