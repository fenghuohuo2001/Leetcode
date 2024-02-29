#include <unordered_map>
#include <vector>
using namespace std;

// map�еĴ洢�ṹΪ {key������Ԫ�أ�value������Ԫ�ض�Ӧ���±�}��
// ��ϣ��
// ���ü������жϲ�ֵ�Ƿ���map�����г���

class Solution{
public:
    vector<int> twoSum(vector<int>& nums, int target){
        unordered_map <int, int> map;
        for(int i=0; i<nums.size(); i++){
            // ������ǰԪ�أ�����map��Ѱ���Ƿ���ƥ���key
            auto iter = map.find(target - nums[i]);
            if (iter != map.end()){
                return {iter->second, i};
            }
            // ���û�ҵ�ƥ��ԣ��Ͱѷ��ʹ���Ԫ�غ��±���뵽map��
            map.insert(pair<int, int> (nums[i], i));
        }
        return {};
    }
};

// Ϊʲô��map��Ѱ�ң�������ʣ��Ԫ����Ѱ��
// �о���map��Ѱ�ҵĻ���ʱ�临�ӶȽϸ�
/* 
�������鳤��Ϊ n������ÿ��Ԫ�أ�����Ҫ����һ���µĹ�ϣ��
Ȼ����в��Ҳ����������ܹ���Ҫ���� n �ν���Ͳ��Ҳ�����
ÿ�β�����ʱ�临�Ӷȶ�Ϊ O(n)������ܵ�ʱ�临�Ӷ�Ϊ O(n^2)���������㷨Ч�ʲ��ߡ�
*/
//
class Solution{
public:
    vector<int> twoSum(vector<int>& nums, int target){
        unordered_map <int, int> map;
        for(int i=0; i<nums.size(); i++){
            // �����ֵ�������Ƿ���ƥ����
            auto iter = map.find(target - nums[i]);
            if(iter != map.end()){
                return {iter->second, i};
            }
            // ��û��ƥ����Ŀ
            map.insert(pair<int, int>(nums[i], i));
        }
        return {};
    }
};


class Solution{
public:
    vector<int> twoSum(vector<int> &nums, int target){
        // �ȶ���map, <value, index>
        unordered_map <int, int> map;
        // ����ѭ��
        for(int i=0; i<nums.size(); i++){
            // ����Ԫ�أ���map��Ѱ���Ƿ���ڵ�ǰԪ�ض�Ӧ�Ĳ�ֵ
            std::unordered_map<int, int>::iterator iter = map.find(target - nums[i]);
            if(iter != map.end()){
                return {iter->second, i};
            }
            // ��û��ƥ����󣬾ͽ���ǰ����������뵽map�С�ע��������ṹΪ<value, index>
            map.insert(pair<int, int> (nums[i], i));
        }
        return {};
    }
};