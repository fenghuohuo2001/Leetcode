#include <vector>
#include <unordered_map>
using namespace std;


// ��ʵ�൱���������
class Solution{
public:
    int fourSumCount(vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &D){
        unordered_map<int, int> umap;   // key:a+b  val:a+b���ֵĴ���
        // ����A��B��ͳ�ƽ����umap��
        for(int a : A){
            for(int b: B){
                umap[a+b]++;
            }
        }
        int count = 0;      // ͳ��a+b+c+d=0���ֵĴ���
        // ����C��D�����0-(c+d)��map�г��ֹ�����ͳ��map��key��Ӧ��value���ִ���
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