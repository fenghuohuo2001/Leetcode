#include <string>

using namespace std;

class Solution{
public:
    bool isAnagram(string s, string t){
        int record[26] = {0};   // 定义长度为26的整型数组，并将所有元素初始化为0
        for(int i=0; i<s.size(); i++){
            // 并不需要记住字符a的ASCII，只要求出一个相对的数值即可
            record[s[i] - 'a']++;
        }
        for(int i=0; i<t.size(); i++){
            record[t[i] - 'a']--;
        }
        for(int i=0; i<26; i++){
            if(record[i] != 0){
                // record数组如果有的元素不为0，说明字符串s和t 一定有一个多了或者少了字符
                return false;
            }
        }
        // record数组所有元素都为0，说明字符s和t是字母异位词
        return true;
    }
};


class Solution{
public:
    bool isAnagram(string s, string t){
        int record[26] = {0};
        for(int i=0; i<s.size(); i++){
            record[s[i] - 'a']++;
        }
        for(int i=0; i<t.size(); i++){
            record[t[i] - 'a']--;
        }
        for(int i=0; i<26; i++){
            if(record[i]!=0){
                return false;
            }
        }
        return true;
    }
};


class Solution{
public:
    bool isAnagram(string s, string t){
        int record[26] = {0};
        for(int i=0; i<s.size(); i++){
            record[s[i]-'a']++;
        }
        for(int i=0; i<t.size(); i++){
            record[t[i]-'a']--;
        }
        for(int i=0; i<26; i++){
            if(record[i]!=0){
                return false;
            }
        }
        return true;
    }
};