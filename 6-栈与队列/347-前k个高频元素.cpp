#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <unordered_map>


using namespace std;

class Solution {
private:
    // 自定义比较函数，按照pair中的第二个元素进行排序
    static bool compareSecond(const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return a.second > b.second;
    }

public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<pair<int,int>> result_pair;
        vector<int> result;
        int count = 0;      // 出现频率
        
        // 先排序
        sort(nums.begin(), nums.end());
        
        stack<int> st;
        for(int i=0; i<nums.size(); i++){
            if(!st.empty()){
                if(st.top() == nums[i]){
                    count++;
                }else{
                    result_pair.push_back({st.top(), count});
                    count = 0;
                }
            }else{
                st.push(nums[i]);
            }
        }
        sort(result_pair.begin(), result_pair.end(), compareSecond);
        
        // 取前 k 个元素的第一个元素
        for (int i = 0; i < k && i < result_pair.size(); ++i) {
            result.push_back(result_pair[i].first);
        }

        return result;
    }
};

// GPT哈希表解法
class Solution {
private:
    // 自定义比较函数，按照pair中的第二个元素进行排序
    static bool compareSecond(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second; // 降序排列
    }

public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;
        
        // 统计元素出现频率
        for (int num : nums) {
            freqMap[num]++;
        }
        
        // 将频率信息存入pair
        vector<pair<int, int>> freqPairs;
        for (auto it = freqMap.begin(); it != freqMap.end(); ++it) {
            freqPairs.push_back({it->first, it->second});
        }
        
        // 按照频率降序排列
        sort(freqPairs.begin(), freqPairs.end(), compareSecond);
        
        // 取出前k个元素
        vector<int> result;
        for (int i = 0; i < k && i < freqPairs.size(); ++i) {
            result.push_back(freqPairs[i].first);
        }

        return result;
    }
};





class Solution{
public:
    // 小顶堆
    class mycomparsion{
    public:
        // 重载调用运算符
        bool operator()(const pair<int, int> &lhs, const pair<int, int> &rhs){
            return lhs.second > rhs.second;
        }
    };
    vector<int> topKFrequent(vector<int> &nums, int k){
        // 统计元素出现的频率
        unordered_map<int, int> map;    
        for(int i=0; i<nums.size(); i++){
            map[nums[i]]++;
        }
        // 对频率排序
        // 定义一个小顶堆
        priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparsion> pri_que;
        // 用固定大小的小顶堆扫描所有频率数值
        for(unordered_map<int, int>::iterator it = map.begin(); it != map.end(); it++){
            pri_que.push(*it);
            if(pri_que.size() > k){
                pri_que.pop();
            }
        }
        // 找出前k个高频元素
        vector<int> result(k);
        for(int i = k-1; i>=0; i--){
            result[i] = pri_que.top().first;
            pri_que.pop();
        }
        return result;
    }
};

class Solution{
public:
    // 小顶堆
    class mycomparsion{
    public:
        bool operator()(const pair<int, int> &lhs, const pair<int, int> &rhs){
            return lhs.second > rhs.second;
        }
    };

    vector<int> topKFrequent(vector<int> &nums, int k){
        unordered_map<int, int> map;
        for(int i=0; i<nums.size(); i++){
            map[nums[i]]++;
        }

        // 定义小顶堆
        priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparsion> pri_que;

        for(unordered_map<int, int>::iterator it = map.begin(); it != map.end(); it++){
            pri_que.push(*it);
            if(pri_que.size() > k){
                pri_que.pop();
            }
        }

        // 找出前k个高频元素
        vector<int> result(k);
        for(int i=k-1; i>=0; i--){
            result[i] = pri_que.top().first;
            pri_que.pop();
        }
        return result; 
    }
};