#include <string>
#include <iostream>

using namespace std;

int main1(){
    string s;
    // cin >> s �������Ǵ��������ж�ȡһ�����벢����洢�ڱ��� s ��
    while(cin >> s){
        // ͳ�����ָ���
        int count = 0;
        int sOldSize = s.size();
        for(int i=0; i<s.size(); i++){
            if(s[i] >= '0' && s[i] <= '9'){
                count++;
            }
        }

        // �����ַ���s�Ĵ�С��Ҳ����ÿ���ո��滻�ɡ�number��֮��Ĵ�С
        s.resize(s.size() + count * 5); 
        int sNewSize = s.size();
        
        // �Ӻ���ǰ���ո��滻Ϊ��number��
        for(int i = sNewSize - 1, j = sOldSize - 1; j < i; i--, j--){
            if(s[j] > '9' || s[j] < '0'){
                s[i] = s[j];
            }else{
                s[i] = 'r';
                s[i-1] = 'e';
                s[i-2] = 'b';
                s[i-3] = 'm';
                s[i-4] = 'u';
                s[i-5] = 'n';
                i -= 5;
            }
        }
        cout << s << endl;
    }
    return 0;
}

int main(){
    // ����һ���ַ���
    string s;
    while(cin >> s){
        // ͳ���ַ��������ֵĸ���
        int count = 0;
        int OldSize = s.length();
        for(int i = 0; i < s.length(); i++){
            if(s[i] >= '0' && s[i] <= '9'){
                count ++;
            }
        }
        
        // ��ԭ�ַ�����������
        int NewSize = OldSize + count * 5;
        s.resize(NewSize);
        // �Ӻ���ǰ�������ַ����������
        for(int i = NewSize -1, j = OldSize - 1; j < i; i--, j--){
            // ����oldstring�еķ������ַ���ֱ����䵽Newstring��
            if(s[j] < '0' || s[j] > '9'){
                s[i] = s[j];
            }else{
                s[i] = 'r';
                s[i-1] = 'e';
                s[i-2] = 'b';
                s[i-3] = 'm';
                s[i-4] = 'u';   
                s[i-5] = 'n';   
                // ����number����
                i -= 5;
            }
        }
        cout << s << endl;
    }
    return 0;
}

int main(){
    string s;
    while(cin >> s){
        // ��ͳ��ԭ�ַ��������ֵĸ���
        int count = 0;
        int OldSize = s.length();
        for(int i=0; i<s.length(); i++){
            if(s[i]>='0' && s[i]<='9'){
                count ++;
            }
        }

        // ��ԭ�ַ�����������
        int NewSize = OldSize + count*5;
        s.resize(NewSize);

        for(int i=NewSize-1, j=OldSize-1; j<i; i--, j--){
            // ����ǰ��������Ϊ����
            if(s[j]<'0' || s[j]>'9'){
                s[i] = s[j];
            }else{
                s[i] = 'r';
                s[i-1] = 'e';
                s[i-2] = 'b';
                s[i-3] = 'm';
                s[i-4] = 'u';
                s[i-5] = 'n';
                i -= 5;
            }
        }
        cout << s << endl;
    }
    return 0;
}