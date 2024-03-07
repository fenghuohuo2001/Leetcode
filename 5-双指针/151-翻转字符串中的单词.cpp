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

    // ȥ���ո�
    void removeExtraSpaces(string &s){
        int slow = 0;
        for(int i=0; i<s.size(); i++){
            // �����ǿո�ʹ���
            if(s[i] != ' '){
                // ��֮�����ո�
                if(slow != 0){
                    s[slow++] = ' ';
                }
                // �Ե������ʽ��е���
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
            // �������ո񣬻��߼�����ĩβʱ
            if(s[i] == ' ' || i==s.size()){
                reverse(s, start, i-1);
                start = i+1;
            }
        }
        return s;
    }
};