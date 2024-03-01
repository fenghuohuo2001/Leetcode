#include <string>
#include <algorithm>
using namespace std;

class Solution{
public:
    string reverseStr(string s, int k){
        for(int i=0; i<s.length(); i+=(2*k)){
            if(i < s.length()){
                reverse(s.begin()+i, s.begin()+i+k-1);
            }else{
                if(i + k < s.length()){
                    reverse(s.begin()+ i, s.end());
                }else{
                    reverse(s.begin()+ i, s.end());
                }
            }
        }
        return s;
    }
};


class Solution{
public:
    string reverseStr(string s, int k){
        for(int i=0; i<s.length(); i+=(2*k)){
            if(i+k <= s.length()){
                reverse(s.begin()+i, s.begin()+i+k);
            }else{
                reverse(s.begin()+ i, s.end());
            }
        }
        return s;
    }
};

class Solution{
public:
    string reverseStr(string s, int k){
        for(int i=0; i<s.size(); i+=(2*k)){
            if(i + k <= s.length()){
                reverse(s.begin()+i, s.begin() + i + k);
            }else{
                reverse(s.begin() + i, s.end());
            }
        }
        return s;
    }
};