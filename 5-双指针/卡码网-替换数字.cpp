#include <iostream>
#include <string>
using namespace std;


int main(){
    string s;
    while(cin >> s){
        int Old_size = s.size();
        // 首先计算数字的个数
        int nums_count = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] >= '0' && s[i]<='9'){
                nums_count++;
            }
        }

        // 对字符串扩容
        int New_size = Old_size + nums_count * 5;
        s.resize(New_size);

        // 开始替换字符串
        for(int i=New_size-1, j=Old_size-1; j<i; i--, j--){
            // 如果不为数字就跳过
            if(s[j]<'0' || s[j]>'9'){       // 注意这里是j，对旧字符串进行扫描
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