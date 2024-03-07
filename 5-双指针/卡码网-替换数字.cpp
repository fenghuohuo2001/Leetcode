#include <iostream>
#include <string>
using namespace std;


int main(){
    string s;
    while(cin >> s){
        int Old_size = s.size();
        // ���ȼ������ֵĸ���
        int nums_count = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] >= '0' && s[i]<='9'){
                nums_count++;
            }
        }

        // ���ַ�������
        int New_size = Old_size + nums_count * 5;
        s.resize(New_size);

        // ��ʼ�滻�ַ���
        for(int i=New_size-1, j=Old_size-1; j<i; i--, j--){
            // �����Ϊ���־�����
            if(s[j]<'0' || s[j]>'9'){       // ע��������j���Ծ��ַ�������ɨ��
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