#include <string>

using namespace std;

class Solution{
public:
    bool isAnagram(string s, string t){
        int record[26] = {0};   // ���峤��Ϊ26���������飬��������Ԫ�س�ʼ��Ϊ0
        for(int i=0; i<s.size(); i++){
            // ������Ҫ��ס�ַ�a��ASCII��ֻҪ���һ����Ե���ֵ����
            record[s[i] - 'a']++;
        }
        for(int i=0; i<t.size(); i++){
            record[t[i] - 'a']--;
        }
        for(int i=0; i<26; i++){
            if(record[i] != 0){
                // record��������е�Ԫ�ز�Ϊ0��˵���ַ���s��t һ����һ�����˻��������ַ�
                return false;
            }
        }
        // record��������Ԫ�ض�Ϊ0��˵���ַ�s��t����ĸ��λ��
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