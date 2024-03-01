#include <string>
#include <iostream>

using namespace std;

int main1(){
    string s;
    // cin >> s 的作用是从输入流中读取一个输入并将其存储在变量 s 中
    while(cin >> s){
        // 统计数字个数
        int count = 0;
        int sOldSize = s.size();
        for(int i=0; i<s.size(); i++){
            if(s[i] >= '0' && s[i] <= '9'){
                count++;
            }
        }

        // 扩充字符串s的大小，也就是每个空格替换成‘number’之后的大小
        s.resize(s.size() + count * 5); 
        int sNewSize = s.size();
        
        // 从后往前将空格替换为“number”
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
    // 定义一个字符串
    string s;
    while(cin >> s){
        // 统计字符串中数字的个数
        int count = 0;
        int OldSize = s.length();
        for(int i = 0; i < s.length(); i++){
            if(s[i] >= '0' && s[i] <= '9'){
                count ++;
            }
        }
        
        // 对原字符串进行扩容
        int NewSize = OldSize + count * 5;
        s.resize(NewSize);
        // 从后往前，对新字符串进行填充
        for(int i = NewSize -1, j = OldSize - 1; j < i; i--, j--){
            // 对于oldstring中的非数字字符，直接填充到Newstring中
            if(s[j] < '0' || s[j] > '9'){
                s[i] = s[j];
            }else{
                s[i] = 'r';
                s[i-1] = 'e';
                s[i-2] = 'b';
                s[i-3] = 'm';
                s[i-4] = 'u';   
                s[i-5] = 'n';   
                // 跳过number区域
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
        // 先统计原字符串中数字的个数
        int count = 0;
        int OldSize = s.length();
        for(int i=0; i<s.length(); i++){
            if(s[i]>='0' && s[i]<='9'){
                count ++;
            }
        }

        // 对原字符串进行扩容
        int NewSize = OldSize + count*5;
        s.resize(NewSize);

        for(int i=NewSize-1, j=OldSize-1; j<i; i--, j--){
            // 若当前迭代对象不为数字
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