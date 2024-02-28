#include <vector>
#include <unordered_set>
using namespace std;

// 给定两个数组 计算它们的交集

class Solution{
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2){
        unordered_set<int> result_set;
        // 将 nums1 容器中的元素复制到 nums_set 中。由于是使用迭代器范围初始化，
        // 它会遍历 nums1 中的所有元素，并将它们逐一插入到 nums_set 中。
        // 由于 unordered_set 中的元素是唯一的，重复的元素只会被插入一次。
        unordered_set<int> nums_set(nums1.begin(), nums1.end());
        for(int num: nums2){
            // 发现nums2的元素 在nums_set中又出现过
            if(nums_set.find(num) != nums_set.end()){   // 若未找到匹配元素，则返回指向集合末尾的迭代器unordered_set.end()
                result_set.insert(num);
            }
        }
        return vector<int>(result_set.begin(), result_set.end());
    }
};


class Solution{
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2){
        // 定义两个unordered_set()，分别存储数组1不重复的元素，和最终输出结果即与数组2之间不同的元素
        unordered_set<int> result_set;
        unordered_set<int> nums_set;
        // 将nums1中的元素用unordered_set存储
        nums_set.insert(nums1.begin(), nums1.end());
        // 循环比较
        for(int num: nums2){
            if(nums_set.find(num) != nums_set.end()){
                result_set.insert(num);
            }
        }
        // 要返回的是vector类型
        return vector<int> (result_set.begin(), result_set.end());
    }
};