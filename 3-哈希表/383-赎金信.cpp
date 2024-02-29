#include <string>
using namespace std;

// �����ⷨ
class Solution{
public:
    bool canConstruct(string ransomNote, string magazine){
        for(int i=0; i<magazine.length(); i++){
            for(int j=0; j<ransomNote.length(); j++){
                // Ѱ����ͬ�ַ�
                if(magazine[i]==ransomNote[j]){
                    ransomNote.erase(ransomNote.begin() + j);   // ����
                    break;      // ����jѭ��
                }
            }
        }
        // ������������ransomNoteΪ��
        if(ransomNote.length()==0){
            return true;
        }
        return false;
    }
};


// ��ϣ��: �ռ任ʱ��
class Solution{
public:
    bool canConstruct(string ransomNote, string magazine){
        // ���Ƚ�������洢26����ĸ���ִ���
        int record[26] = {0};
        
        // ����return
        if(ransomNote.length() > magazine.length()){
            return false;
        }
        // ͨ��record��¼magazine��Ԫ�س��ִ���
        for(int i=0; i<magazine.length(); i++){
            record[magazine[i] - 'a']++;
        }

        // ͨ��record�ж�ransomNote��Ԫ�س��ִ���
        for(int i=0; i<ransomNote.length(); i++){
            record[ransomNote[i] - 'a']--;
            // Ϊ�˽�ʡʱ�䣬���״γ���С��0������Ԫ��ʱ���Ϳ���ֱ��return
            if(record[ransomNote[i] - 'a'] < 0){
                return false;
            }
        }

        return true;
    }
};