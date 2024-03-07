#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> st;
        int result;
        for(int i=0; i<tokens.size(); i++){
            // 若当前字符为运算符
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/" ){
                long long num1 = st.top();
                st.pop();
                long long num2 = st.top();
                st.pop();
                if(tokens[i] == "+") st.push(num2 + num1);
                if(tokens[i] == "-") st.push(num2 - num1);
                if(tokens[i] == "*") st.push(num2 * num1);
                if(tokens[i] == "/") st.push(num2 / num1);
            }else{
                long long number = stoll(tokens[i]);
                st.push(number);
            }
        }
        result = st.top();
        st.pop();
        return result;
    }
};