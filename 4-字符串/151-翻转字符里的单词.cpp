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
                // slow��ɨ�����׸����ʺ���ÿ�����ʺ��һ���ո�
                if(slow !=0) s[slow++]=' ';
                // ɨ��һ���������ʣ��������s�У��������ո�ʱ��������һ��forѭ��
                while(i<s.size() && s[i] != ' '){
                    s[slow++] = s[i++];
                }
                //��ʱslow!=0
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
    // ��ת�ַ�
    void reverse(string &s, int start, int end){
        for(int i=start, j=end; i<j; i++, j--){
            swap(s[i], s[j]);
        }
    }

    // ɾ�����пո񣬲��ڵ���֮����ӿո�
    void removeExtraSpaces(string &s){
        int slow = 0;   // showΪˢ�º���ַ�������
        // ͨ��forѭ��ɨ����������
        for(int i=0; i<s.size(); i++){
            // ע������ɾ�����пո�Ȼ����ÿ�����ʺ󷽼���һ���ո񣬽��б�׼��
            if(s[i] != ' '){
                // ��Ҫ�����׸����ʺ��ٶԺ������ʺ󷽼���ո�
                if(slow!=0){
                    s[slow++] = ' ';
                }
                // ����Ϊ�ո�ĵ����ַ�����s��
                while(i<s.size() && s[i]!=' '){
                    s[slow++] = s[i++];
                }
            }
        }
        s.resize(slow);
    }


    string reverseWords(string s){
        // ����ȥ���ո񣬱�׼���ַ���
        removeExtraSpaces(s);
        // ���������ӵ�˳����з�ת������˳��Ҳ��ת��
        reverse(s, 0, s.size()-1);
        // �������еĵ������ʸ���ת����ԭÿ������˳��
        int start_word = 0;
        for(int i=0; i<=s.size(); i++){
            // ��⵽�ո���ߵ��ַ���ĩβ��ʱ�򣬾ͱ�ʾһ�����ʽ���
            if(s[i] == ' ' || i == s.size()){
                // �Ե��ʿ�ʼ�ͽ����ĵط����з�ת
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
            // �����ո�
            if(s[i] != ' '){
                // �ڼ�⵽���ʺ�ſ�ʼ��ӿո�
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
        // ��ΪҪ��⵽ĩβ�������Ҫ����s.size()
        for(int i=0; i<=s.size(); i++){
            // ��⵽�ո�ͼ�⵽ĩβʱ����ʾһ�����ʵĽ���
            if(s[i]==' ' || i == s.size()){
                reverse(s, start_word, i-1);
                start_word = i+1;
            }
        }
        return s;
    }
};