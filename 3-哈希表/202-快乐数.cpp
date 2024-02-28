#include <unordered_set>
using namespace std;

class Solution{
public:
    // 取数字每个个位上的单数和
    int getSum(int n){
        int sum = 0;
        while(n){
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }
    // 判断快乐数
    bool isHappy(int n){
        unordered_set<int> set;
        while(1){
            int sum = getSum(n);
            if(sum == 1) return true;

            // 如果这个sum已经出现过，说明已经陷入无限循环了，立刻return false
            if(set.find(sum) != set.end()){
                return false;
            }else{
                set.insert(sum);
            }
            n = sum;
        }
    }
};


class Solution{
public:
    // 每次取个位上的数的平方
    int getSum(int n){
        int sum = 0;
        while(n){
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n){
        unordered_set<int> set;
        while(1){
            // 判断当前结果
            int sum = getSum(n);
            // 若当前结果为1
            if (sum == 1){
                return true;
            }
            // 若当前结果在之前已经出现过
            if(set.find(sum) != set.end()){
                return false;
            }else{
                set.insert(sum);
            }
            // 更新当前数
            n = sum;
        }
    }
};


class Solution{
public:
    int getSum(int n){
        int sum = 0;
        while(n){
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n){
        // 首先定义一个unordered_set来存储结果，当结果出现重复时，就出现问下你循环
        unordered_set<int> set;
        while(1){
            // 计算每位数字的平方和
            int sum = getSum(n);
            if (sum == 1){
                return true;
            }
            // 若结果不为1，则判断当前结果在以前是否出现过
            if (set.find(sum) != set.end()){
                return false;
            }else{
                set.insert(sum);
            }
            // 更新输入
            n = sum;
        }
    }
};