#include <string>
#include <iostream>
using namespace std;


// 思考：
// needle.size()-- if(needle.size()==0) 即为匹配成功
class Solution1{
public:
    int strStr(string haystack, string needle){
        // 定义两个指针分别扫描两个字符
        int index1 = 0;
        int index2 = 0;
        int count = needle.size();
        // if(haystack == needle) return 0;
        for(int i=0; i < haystack.size(); i++){
            if(haystack[i] == needle[index2] && count != 0){
                index2++;
                count--;
            }else if(count != needle.size()){
                // 一旦后续出现不相同的字符，将count刷新并将i返回到开始时刻
                i = i - (needle.size() - count);
                index2 = 0;
                count = needle.size();
            }
            if(count == 0){
                return i-needle.size()+1;
            }
        }
        return -1;
    }
};


int main1() {
    Solution1 sol;
    std::string haystack = "mississippi";
    std::string needle = "issip";
    int result = sol.strStr(haystack, needle);
    cout << "Result: " << result << endl;
    return 0;
}



// 代码随想录解法
class Solution{
public:
    // 计算前缀表
    void getNext(int* next, const string& s){
        int j = 0;          // j是前缀末尾，这里只是初始化为0，方便以后回退，两个元素时，前缀末尾索引为0
        next[0] = 0;        // 0的时候回退到0
        for(int i = 1; i<s.size(); i++){        // i是后缀末尾，因此i应该从1开始
            while(j>0 && s[i] != s[j]){
                j = next[j - 1];
            }
            if(s[i] == s[j]){   // 直到找到相等的j才+1
                j++;
            }
            next[i] = j;
        }
    }

    int strStr(string haystack, string needle){
        if(needle.size() == 0){
            return 0;
        }
        int next[needle.size()];
        getNext(next, needle);
        int j = 0;
        for(int i = 0; i<haystack.size(); i++){
            while(j > 0 && haystack[i] != needle[j]){
                j = next[j - 1];
            }
            if (haystack[i] == needle[j]){
                j++;
            }
            if(j == needle.size()){
                return (i - needle.size() + 1);
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;
    std::string haystack = "aabaaabaaaf";
    std::string needle = "aaabaaaf";
    int result = sol.strStr(haystack, needle);
    cout << "Result: " << result << endl;
    return 0;
}


// kmp解法
class Solution{
public:
    // 获取next数组
    void getNext(const string s, int* next){
        // 初始化
        int j = 0;  // 前缀末尾
        next[0] = 0;    // next第一个元素为0
        // 采用for循环迭代
        for(int i=1; i < s.size(); i++){
            // 当不相等，进行回退，回退到不相等
            while(j>0 && s[i]!=s[j]){
                j = next[j-1];
            }
            // 将前缀末尾，也就是公共前后缀长度，或者最小偏移量，也是偏移索引增加1个
            if(s[i]==s[j]){
                j++;
            }
            // 将前缀末尾，也就是公共前后缀长度，或者最小偏移量，也是偏移索引存入
            next[i] = j;
        }
    }

    int strStr(string haystack, string needle){
        if(needle.size() == 0){
            return 0;
        }
        // 获取next数组
        int next[needle.size()];
        getNext(needle, next);

        int j = 0;  // 模式串指针
        // 开始匹配
        for(int i=0; i<haystack.size(); i++){
            // 当不相等时，要回退直到相等为止
            while(j>0 && haystack[i]!=needle[j]){
                j = next[j - 1];
            }
            // 当相等时
            if(haystack[i] == needle[j]){
                j++;
            }
            if(j == needle.size()){
                return i - needle.size() + 1;
            }
        }
        return -1;
    }
};