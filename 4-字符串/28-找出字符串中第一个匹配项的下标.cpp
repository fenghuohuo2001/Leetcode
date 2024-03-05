#include <string>
#include <iostream>
using namespace std;


// ˼����
// needle.size()-- if(needle.size()==0) ��Ϊƥ��ɹ�
class Solution1{
public:
    int strStr(string haystack, string needle){
        // ��������ָ��ֱ�ɨ�������ַ�
        int index1 = 0;
        int index2 = 0;
        int count = needle.size();
        // if(haystack == needle) return 0;
        for(int i=0; i < haystack.size(); i++){
            if(haystack[i] == needle[index2] && count != 0){
                index2++;
                count--;
            }else if(count != needle.size()){
                // һ���������ֲ���ͬ���ַ�����countˢ�²���i���ص���ʼʱ��
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



// ��������¼�ⷨ
class Solution{
public:
    // ����ǰ׺��
    void getNext(int* next, const string& s){
        int j = 0;          // j��ǰ׺ĩβ������ֻ�ǳ�ʼ��Ϊ0�������Ժ���ˣ�����Ԫ��ʱ��ǰ׺ĩβ����Ϊ0
        next[0] = 0;        // 0��ʱ����˵�0
        for(int i = 1; i<s.size(); i++){        // i�Ǻ�׺ĩβ�����iӦ�ô�1��ʼ
            while(j>0 && s[i] != s[j]){
                j = next[j - 1];
            }
            if(s[i] == s[j]){   // ֱ���ҵ���ȵ�j��+1
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


// kmp�ⷨ
class Solution{
public:
    // ��ȡnext����
    void getNext(const string s, int* next){
        // ��ʼ��
        int j = 0;  // ǰ׺ĩβ
        next[0] = 0;    // next��һ��Ԫ��Ϊ0
        // ����forѭ������
        for(int i=1; i < s.size(); i++){
            // ������ȣ����л��ˣ����˵������
            while(j>0 && s[i]!=s[j]){
                j = next[j-1];
            }
            // ��ǰ׺ĩβ��Ҳ���ǹ���ǰ��׺���ȣ�������Сƫ������Ҳ��ƫ����������1��
            if(s[i]==s[j]){
                j++;
            }
            // ��ǰ׺ĩβ��Ҳ���ǹ���ǰ��׺���ȣ�������Сƫ������Ҳ��ƫ����������
            next[i] = j;
        }
    }

    int strStr(string haystack, string needle){
        if(needle.size() == 0){
            return 0;
        }
        // ��ȡnext����
        int next[needle.size()];
        getNext(needle, next);

        int j = 0;  // ģʽ��ָ��
        // ��ʼƥ��
        for(int i=0; i<haystack.size(); i++){
            // �������ʱ��Ҫ����ֱ�����Ϊֹ
            while(j>0 && haystack[i]!=needle[j]){
                j = next[j - 1];
            }
            // �����ʱ
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