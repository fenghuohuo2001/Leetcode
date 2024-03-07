#include <string>
#include <stack>
using namespace std;


class Solution {
public:
    bool isValid(string s) {
        if(s.size() % 2 != 0) return false;
        stack<char> st;
        for (int i=0; i < s.size(); i++){
            // 入栈
            if(s[i] == '(') {
                st.push(')');
            }else if(s[i] == '['){
                st.push(']');
            }else if(s[i] == '{'){
                st.push('}');
            }
            // 出栈
            else if(st.empty() || s[i] != st.top()){
                return false;
            }else{
                st.pop();
            }

        }
    return st.empty();
    }
};

class Solution {
public:
    bool isValid(string s) {
        // 首先判断奇数偶数
        if(s.size() % 2 != 0) return false;

        stack<char> st;
        for (int i=0; i < s.size(); i++){
            if(s[i] == '('){
                st.push(')');
            }else if(s[i] == '['){
                st.push(']');
            }else if(s[i] == '{'){
                st.push('}');
            }
            // 出栈
            else if(st.empty() || s[i] != st.top()){
                return false;
            }else{
                st.pop();
            }
        }
        return st.empty();
    }
};