#include <vector>
#include <unordered_map>
using namespace std;


// 其实相当于两两组合,在存在四个元素的情况下，随机选取两个元素，其剩余元素和与取出元素之和 其相加结果一定为0
class Solution{
public:
    int fourSumCount(vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &D){
        unordered_map<int, int> umap;   // key:a+b  val:a+b出现的次数
        // 遍历A和B，统计结果到umap中
        for(int a : A){
            for(int b: B){
                umap[a+b]++;
            }
        }
        int count = 0;      // 统计a+b+c+d=0出现的次数
        // 遍历C和D，如果0-(c+d)在map中出现过，就统计map中key对应的value出现次数
        for(int c: C){
            for(int d: D){
                if(umap.find(0-(c+d)) != umap.end()){
                    count += umap[0 - (c + d)];
                }
            }
        }
        return count;
    }
};


class Solution{
public:
    int fourSumCount(vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &D){
        unordered_map<int, int> umap;
        // 先取出两个元素统计到umap中
        for(int a: A){
            for(int b: B){
                umap[a+b]++;
            }
        }
        // 定义计数器
        int count = 0;

        // 判断umap中是否存在 c+d对应的差
        for(int c: C){
            for(int d: D){
                if(umap.find(0 - (c + d)) != umap.end()){
                    count += umap[0 - (c + d)];        // 注意是统计value出现的次数
                }
            }
        }
        return count;
    }
};