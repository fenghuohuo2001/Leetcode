#include <string>
using namespace std;

// 暴力解法
class Solution{
public:
    bool canConstruct(string ransomNote, string magazine){
        for(int i=0; i<magazine.length(); i++){
            for(int j=0; j<ransomNote.length(); j++){
                // 寻找相同字符
                if(magazine[i]==ransomNote[j]){
                    ransomNote.erase(ransomNote.begin() + j);   // 擦除
                    break;      // 跳出j循环
                }
            }
        }
        // 擦除到最后，如果ransomNote为空
        if(ransomNote.length()==0){
            return true;
        }
        return false;
    }
};


// 哈希法: 空间换时间
class Solution{
public:
    bool canConstruct(string ransomNote, string magazine){
        // 首先建立数组存储26个字母出现次数
        int record[26] = {0};
        
        // 超长return
        if(ransomNote.length() > magazine.length()){
            return false;
        }
        // 通过record记录magazine中元素出现次数
        for(int i=0; i<magazine.length(); i++){
            record[magazine[i] - 'a']++;
        }

        // 通过record判断ransomNote中元素出现次数
        for(int i=0; i<ransomNote.length(); i++){
            record[ransomNote[i] - 'a']--;
            // 为了节省时间，当首次出现小于0的数组元素时，就可以直接return
            if(record[ransomNote[i] - 'a'] < 0){
                return false;
            }
        }

        return true;
    }
};