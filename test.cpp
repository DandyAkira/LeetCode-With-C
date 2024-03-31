#include<iostream>
#include<string>
#include<stack>

using namespace std;

int main(int argc, char const *argv[])
{
    stack<int> stk;
    stk.push(2);
    cout << stk.top() << endl;
    stk.top()--;
    cout << stk.top();
    return 0;
}
