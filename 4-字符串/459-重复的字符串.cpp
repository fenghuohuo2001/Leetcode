#include <string>
#include <iostream>
using namespace std;


/*
所以判断字符串s是否由重复子串组成，只要两个s拼接在一起，
里面还出现一个s的话，就说明是由重复子串组成。

当然，我们在判断 s + s 拼接的字符串里是否出现一个s的的时候，
要刨除 s + s 的首字符和尾字符，这样避免在s+s中搜索出原来的s，我们要搜索的是中间拼接出来的s。
*/
class Solution1{
public:
    bool repeatedSubstringPattern(string s){
        string t = s + s;
        t.erase(t.begin());     // 这里只移除了第一个字符，而不是移除字符串
        t.erase(t.end()-1);

        if (t.find(s) != string::npos){
            return true;
        }
        return false;
    }
};


// int main(){
//     string s = "hello world";
//     s.erase(s.begin());
//     s.erase(s.end())-1;

//     cout << s << endl;
// };


// kmp
// 若可重复，即总字符串减去最长相等前后缀后，剩余的一定是最小重复字符串。
// 若不可重复，即总字符串减去最长相等前后缀的结果，不为最小重复字符串，也就是len说不能整除len-next[len-1]
class Solution{
public:
    void getNext(int* next, const string s){
        // 先初始化
        int j = 0;
        next[0] = 0;
        // for循环求解next
        for(int i=1; i<s.size(); i++){
            // 不相等的情况，持续回退
            while(j>0 && s[i]!=s[j]){
                j = next[j - 1];
            }
            if(s[i] == s[j]){
                j++;
            }
            next[i] = j;
        }
    }

    bool repeatedSubstringPattern(string s){
        int next[s.size()];
        getNext(next, s);
        std::cout << "Array next: ";
        for (int i = 0; i < s.size(); ++i) {
            std::cout << next[i] << " ";
        }
        std::cout << std::endl;

        // 获取最小重复子串长度
        int len_min_repeat = s.size() - next[s.size() - 1];
        
        if(s.size() % len_min_repeat == 0 && len_min_repeat!=s.size()){
            return true;
        }
        return false;
    }
};

int main(){
    string s = "abcabcabcabcabcq";
    Solution sol;
    cout << sol.repeatedSubstringPattern(s) << endl;
    return 0;
};