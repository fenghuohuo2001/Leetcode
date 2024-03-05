#include <string>
#include <iostream>

using namespace std;

void reverse(string &s, int start, int end){
    for(int i=start, j=end; i<j; i++, j--){
        swap(s[i], s[j]);
    }

}

int main(){
    string s;
    int n;
        cin >> n;
    cin >> s;



    cout << s << endl;
    // 整体先倒序，然后根据n来翻转
    reverse(s, 0, s.size()-1);
    reverse(s, 0, n-1);
    reverse(s, n, s.size()-1);

    cout << s << endl;

    return 0;
}
