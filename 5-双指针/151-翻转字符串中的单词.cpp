#include <string>
#include <iostream>
using namespace std;

class Solution{
public:
    void reverse(string &s, int start, int end){
        for(int i=start, j=end; i<j; i++, j--){
            swap(s[i], s[j]);
        }
    }

    // 去除空格
    void removeExtraSpaces(string &s){
        int slow = 0;
        for(int i=0; i<s.size(); i++){
            // 遇到非空格就处理
            if(s[i] != ' '){
                // 在之后加入空格
                if(slow != 0){
                    s[slow++] = ' ';
                }
                // 对单个单词进行迭代
                while(i < s.size() && s[i] != ' '){
                    s[slow++] = s[i++];
                }
            }
        }
        s.resize(slow);
    }

    string reverseWords(string s){
        removeExtraSpaces(s);
        reverse(s, 0, s.size()-1);

        int start = 0;
        for(int i=0; i<=s.size(); i++){
            // 当遇到空格，或者检索到末尾时
            if(s[i] == ' ' || i==s.size()){
                reverse(s, start, i-1);
                start = i+1;
            }
        }
        return s;
    }
};