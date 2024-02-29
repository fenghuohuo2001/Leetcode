#include <vector>
#include <unordered_map>
using namespace std;


// 其实相当于两两组合
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