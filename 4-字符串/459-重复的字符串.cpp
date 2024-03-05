#include <string>
#include <iostream>
using namespace std;


/*
�����ж��ַ���s�Ƿ����ظ��Ӵ���ɣ�ֻҪ����sƴ����һ��
���滹����һ��s�Ļ�����˵�������ظ��Ӵ���ɡ�

��Ȼ���������ж� s + s ƴ�ӵ��ַ������Ƿ����һ��s�ĵ�ʱ��
Ҫ�ٳ� s + s �����ַ���β�ַ�������������s+s��������ԭ����s������Ҫ���������м�ƴ�ӳ�����s��
*/
class Solution1{
public:
    bool repeatedSubstringPattern(string s){
        string t = s + s;
        t.erase(t.begin());     // ����ֻ�Ƴ��˵�һ���ַ����������Ƴ��ַ���
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
// �����ظ��������ַ�����ȥ����ǰ��׺��ʣ���һ������С�ظ��ַ�����
// �������ظ��������ַ�����ȥ����ǰ��׺�Ľ������Ϊ��С�ظ��ַ�����Ҳ����len˵��������len-next[len-1]
class Solution{
public:
    void getNext(int* next, const string s){
        // �ȳ�ʼ��
        int j = 0;
        next[0] = 0;
        // forѭ�����next
        for(int i=1; i<s.size(); i++){
            // ����ȵ��������������
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

        // ��ȡ��С�ظ��Ӵ�����
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