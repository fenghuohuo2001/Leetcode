#include <unordered_map>
#include <vector>
using namespace std;

// map中的存储结构为 {key：数据元素，value：数组元素对应的下标}。
// 哈希法
// 采用减法，判断差值是否在map容器中出现

class Solution{
public:
    vector<int> twoSum(vector<int>& nums, int target){
        unordered_map <int, int> map;
        for(int i=0; i<nums.size(); i++){
            // 遍历当前元素，并在map中寻找是否有匹配的key
            auto iter = map.find(target - nums[i]);
            if (iter != map.end()){
                return {iter->second, i};
            }
            // 如果没找到匹配对，就把访问过的元素和下标加入到map中
            map.insert(pair<int, int> (nums[i], i));
        }
        return {};
    }
};

// 为什么在map中寻找，而不在剩余元素中寻找
// 感觉在map中寻找的话，时间复杂度较高
/* 
假设数组长度为 n，对于每个元素，都需要建立一个新的哈希表，
然后进行查找操作。这样总共需要进行 n 次建表和查找操作，
每次操作的时间复杂度都为 O(n)，因此总的时间复杂度为 O(n^2)，这样的算法效率不高。
*/
//
class Solution{
public:
    vector<int> twoSum(vector<int>& nums, int target){
        unordered_map <int, int> map;
        for(int i=0; i<nums.size(); i++){
            // 计算差值，查找是否有匹配项
            auto iter = map.find(target - nums[i]);
            if(iter != map.end()){
                return {iter->second, i};
            }
            // 若没有匹配项目
            map.insert(pair<int, int>(nums[i], i));
        }
        return {};
    }
};


class Solution{
public:
    vector<int> twoSum(vector<int> &nums, int target){
        // 先定义map, <value, index>
        unordered_map <int, int> map;
        // 建立循环
        for(int i=0; i<nums.size(); i++){
            // 遍历元素，在map中寻找是否存在当前元素对应的差值
            std::unordered_map<int, int>::iterator iter = map.find(target - nums[i]);
            if(iter != map.end()){
                return {iter->second, i};
            }
            // 若没有匹配对象，就将当前迭代对象插入到map中。注意插入对象结构为<value, index>
            map.insert(pair<int, int> (nums[i], i));
        }
        return {};
    }
};