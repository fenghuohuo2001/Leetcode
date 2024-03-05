#include <string>

using namespace std;

class Solution{
public:
    void reverse(string &s, int start, int end){
        for(int i=start, j=end; i<j; i++, j--){
            swap(s[i], s[j]);
        }
    }

    void removeExtraSpaces(string &s){
        int slow=0;
        for(int i=0; i<s.size(); i++){
            if(s[i] != ' '){
                // slow在扫描完首个单词后，在每个单词后加一个空格
                if(slow !=0) s[slow++]=' ';
                // 扫描一个完整单词，将其放入s中，当遇到空格时，进行下一次for循环
                while(i<s.size() && s[i] != ' '){
                    s[slow++] = s[i++];
                }
                //此时slow!=0
            }
        }
        s.resize(slow);
    }

    string reverseWords(string s){
        removeExtraSpaces(s);
        reverse(s, 0, s.size()-1);
        int start = 0;
        for(int i=0; i<= s.size(); ++i){
            if(i == s.size() || s[i] == ' '){
                reverse(s, start, i-1);
                start = i+1;
            }
        }
        return s;
    }
};


class Solution{
public:
    // 翻转字符
    void reverse(string &s, int start, int end){
        for(int i=start, j=end; i<j; i++, j--){
            swap(s[i], s[j]);
        }
    }

    // 删除所有空格，并在单词之间添加空格
    void removeExtraSpaces(string &s){
        int slow = 0;   // show为刷新后的字符串长度
        // 通过for循环扫描整个句子
        for(int i=0; i<s.size(); i++){
            // 注意是先删除所有空格，然后在每个单词后方加入一个空格，进行标准化
            if(s[i] != ' '){
                // 需要经过首个单词后，再对后续单词后方加入空格
                if(slow!=0){
                    s[slow++] = ' ';
                }
                // 将不为空格的单词字符存入s中
                while(i<s.size() && s[i]!=' '){
                    s[slow++] = s[i++];
                }
            }
        }
        s.resize(slow);
    }


    string reverseWords(string s){
        // 首先去除空格，标准化字符串
        removeExtraSpaces(s);
        // 对整个句子的顺序进行翻转（单词顺序也翻转）
        reverse(s, 0, s.size()-1);
        // 将句子中的单个单词给翻转，还原每个单词顺序
        int start_word = 0;
        for(int i=0; i<=s.size(); i++){
            // 检测到空格或者到字符串末尾的时候，就表示一个单词结束
            if(s[i] == ' ' || i == s.size()){
                // 对单词开始和结束的地方进行翻转
                reverse(s, start_word, i-1);
                start_word = i + 1;
            }
        }
        return s;
    }
};




class Solution{
public:
    void reverse(string &s, int start, int end){
        for(int i=start, j=end; i<j; i++, j--){
            swap(s[i], s[j]);
        }
    }

    void removeExtraSpaces(string &s){
        int slow = 0;
        for(int i=0; i<s.size(); i++){
            // 跳过空格
            if(s[i] != ' '){
                // 在检测到单词后才开始添加空格
                if(slow!=0) s[slow++] = ' ';
                while(s[i]!= ' ' && i<s.size()){
                    s[slow++] = s[i++];
                }
            }
        }
        s.resize(slow);
    }

    string reverseWords(string s){
        removeExtraSpaces(s);
        reverse(s, 0, s.size()-1);
        
        int start_word = 0;
        // 因为要检测到末尾，因此需要等于s.size()
        for(int i=0; i<=s.size(); i++){
            // 检测到空格和检测到末尾时，表示一个单词的结束
            if(s[i]==' ' || i == s.size()){
                reverse(s, start_word, i-1);
                start_word = i+1;
            }
        }
        return s;
    }
};