#include <vector>
using namespace std;


// self-solution
class Solution{
public:
    void reverseString(vector<char> &s){
        
        for(int i=0; i<s.size()/2; i++){
            char temp;
            temp = s[i];
            s[i] = s[s.size()-i -1];
            s[s.size()-i-1] = temp;
        }
    }
};

// 代码随想录 使用两个指针
class Solution{
public:
    void reverseString(vector<char> &s){
        for(int i=0, j=s.size()-1; i<s.size()/2; i++, j--){
            swap(s[i], s[j]);
        }
    }
};
