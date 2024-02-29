#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution{
public:
    vector<vector<int>> threeSum(vector<int> &nums){
        vector<vector<int>> result;
        // 整理数组元素大小顺序
        sort(nums.begin(), nums.end());
        // 找出a + b + c = 0
        // a = nums[i], b = nums[j], c = -(a+b)
        for(int i=0; i<nums.size(); i++){
            // 排序之后如果第一个元素已经大于零，那么不可能凑成三元组
            if(nums[i] > 0){
                break;
            }

            // 三元组元素a去重
            if(i>0 && nums[i]==nums[i-1]){
                continue;           // 跳转到下一次循环
            }

            unordered_set<int> set;

            for (int j = i+1; j<nums.size(); j++){
                // 三元组元素b去重
                if(j>i+2 && nums[j]==nums[j-1] && nums[j-1]==nums[j-2]){
                    continue;
                }
                int c = 0 - (nums[i] + nums[j]);
                if(set.find(c) != set.end()){
                    result.push_back({nums[i], nums[j], c});
                    set.erase(c);       // 三元组c去重
                }else{
                    set.insert(nums[j]);
                }
            }
        }
        return result;
    }
};


// 双指针法会简单一些
class Solution{
public:
    vector<vector<int>> threeSum(vector<int>& nums){
        vector<vector<int>> result;
        // 先排序
        sort(nums.begin(), nums.end());
        // 遍历
        for(int i=0; i<nums.size(); i++){
            // 如果排序后的第一个元素即大于0，后续不可能组成三元组
            if(nums[i] > 0) return result;
            
            // 在开始对b迭代时，要判断a有没有重复 同时第一个元素不应该参与迭代
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }

            // 定义双指针
            int left = i + 1;
            int right = nums.size() - 1;
            while(left<right){
                if (nums[i] + nums[left] + nums[right] > 0) right--;
                else if (nums[i] + nums[left] + nums[right] < 0) left++;
                else {
                    result.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    while(right > left && nums[right] == nums[right-1]) right--;
                    while(right > left && nums[left] == nums[left+1]) left++;

                    right--;
                    left++;
                }
            }
        }
        return result;
    }
};

class Solution{
public:
    vector<vector<int>> threeSum(vector<int>& nums){
        vector<vector<int>> result;
        // 首先对原数组进行排序
        sort(nums.begin(), nums.end());

        // 开始遍历
        for(int i=0; i<nums.size(); i++){
            // 当排序后的数组第一个元素大于0时，直接return
            if(nums[i]>0) return result;

            // 对a去重
            if(i>0 && nums[i] == nums[i-1]){
                continue;
            }

            // a处理完毕，接下来采用双指针对bc进行处理
            int left = i + 1;
            int right = nums.size() - 1;
            while(left < right){
                if ((nums[i] + nums[left] + nums[right]) > 0) right--;
                else if ((nums[i] + nums[left] + nums[right]) < 0) left++;
                else{
                    result.push_back(vector<int> {nums[i], nums[left], nums[right]});
                    // 对b，c进行去重
                    while(left < right && (nums[i] + nums[left+1] + nums[right]) == 0) left++; 
                    while(left < right && (nums[i] + nums[left] + nums[right-1]) == 0) right--;

                    // while(left < right && nums[left] == nums[left+1]) left++; 
                    // while(left < right && nums[right] == nums[right-1]) right--;
                    left++;
                    right--; 
                }

            }

        }
        return result;
    }
};