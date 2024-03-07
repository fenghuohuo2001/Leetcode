#include <string>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        for(int i=0; i<s.size(); i++){
            if(!st.empty()){
                if(s[i] != st.top()){
                    st.push(s[i]);
                }else{
                    st.pop();
                }
            }else{
                st.push(s[i]);
            }
        }

        string result = "";
        while(!st.empty()){
            result += st.top();
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};