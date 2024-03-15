#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <unordered_map>


using namespace std;

class Solution {
private:
    // �Զ���ȽϺ���������pair�еĵڶ���Ԫ�ؽ�������
    static bool compareSecond(const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return a.second > b.second;
    }

public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<pair<int,int>> result_pair;
        vector<int> result;
        int count = 0;      // ����Ƶ��
        
        // ������
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
        
        // ȡǰ k ��Ԫ�صĵ�һ��Ԫ��
        for (int i = 0; i < k && i < result_pair.size(); ++i) {
            result.push_back(result_pair[i].first);
        }

        return result;
    }
};

// GPT��ϣ��ⷨ
class Solution {
private:
    // �Զ���ȽϺ���������pair�еĵڶ���Ԫ�ؽ�������
    static bool compareSecond(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second; // ��������
    }

public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;
        
        // ͳ��Ԫ�س���Ƶ��
        for (int num : nums) {
            freqMap[num]++;
        }
        
        // ��Ƶ����Ϣ����pair
        vector<pair<int, int>> freqPairs;
        for (auto it = freqMap.begin(); it != freqMap.end(); ++it) {
            freqPairs.push_back({it->first, it->second});
        }
        
        // ����Ƶ�ʽ�������
        sort(freqPairs.begin(), freqPairs.end(), compareSecond);
        
        // ȡ��ǰk��Ԫ��
        vector<int> result;
        for (int i = 0; i < k && i < freqPairs.size(); ++i) {
            result.push_back(freqPairs[i].first);
        }

        return result;
    }
};





class Solution{
public:
    // С����
    class mycomparsion{
    public:
        // ���ص��������
        bool operator()(const pair<int, int> &lhs, const pair<int, int> &rhs){
            return lhs.second > rhs.second;
        }
    };
    vector<int> topKFrequent(vector<int> &nums, int k){
        // ͳ��Ԫ�س��ֵ�Ƶ��
        unordered_map<int, int> map;    
        for(int i=0; i<nums.size(); i++){
            map[nums[i]]++;
        }
        // ��Ƶ������
        // ����һ��С����
        priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparsion> pri_que;
        // �ù̶���С��С����ɨ������Ƶ����ֵ
        for(unordered_map<int, int>::iterator it = map.begin(); it != map.end(); it++){
            pri_que.push(*it);
            if(pri_que.size() > k){
                pri_que.pop();
            }
        }
        // �ҳ�ǰk����ƵԪ��
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
    // С����
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

        // ����С����
        priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparsion> pri_que;

        for(unordered_map<int, int>::iterator it = map.begin(); it != map.end(); it++){
            pri_que.push(*it);
            if(pri_que.size() > k){
                pri_que.pop();
            }
        }

        // �ҳ�ǰk����ƵԪ��
        vector<int> result(k);
        for(int i=k-1; i>=0; i--){
            result[i] = pri_que.top().first;
            pri_que.pop();
        }
        return result; 
    }
};