#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for(int k=0; k<nums.size(); k++){
            if(nums[k]>target && nums[k]>0){
                break;
            }
            if(k>0 && nums[k]==nums[k-1]){
                continue;
            }
            for(int i=k+1; i<nums.size(); i++){
                if(nums[k] + nums[i] > target && nums[k] + nums[i] >= 0){
                    break;
                }
                if(i > k+1 && nums[i] == nums[i - 1]){
                    continue;
                }

                int left = i+1;
                int right = nums.size() - 1;
                while(right > left){
                    if((long) nums[k] + nums[i] + nums[left] + nums[right] > target){
                        right--;
                    } else if((long)nums[k] + nums[i] + nums[left] + nums[right] < target){
                        left++;
                    } else {
                        result.push_back(vector<int>{nums[k], nums[i], nums[left], nums[right]});

                        while(right > left && nums[right] == nums[right-1]) right--;
                        while(right > left && nums[left] == nums[left+1]) left++;

                        left++;
                        right--;
                    }

                }

            }

        }
        return result;
    }
};

class Solution{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target){
        vector<vector<int>> result;
        // 先排序
        sort(nums.begin(), nums.end());
        // 从最外层的a开始迭代
        for(int i=0; i<nums.size(); i++){
            // 若第一个数为正数，且target>0，则直接退出循环 要考虑（-4，-3，-2，-1）=-10的情况
            if(nums[i]>target && nums[i]>0){
                break;
            }
            // 对a去重
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }

            // 开始第二层循环
            for(int j=i+1; j<nums.size(); j++){
                // 同样的，在均为正的情况下，如果a+b已经大于target，就直接返回，
                if((nums[i]+nums[j])>target && (nums[i]+nums[j])>=0){
                    break;
                }

                if(j>i+1 && nums[j]==nums[j-1]){
                    continue;
                }
                
                //定义左右双指针
                int left = j+1;
                int right = nums.size()-1;

                while(left<right){
                    // 注意这里要写成(long)nums[i] + nums[j] + nums[left] + nums[right] > target
                    // 在进行整数相加时，只要其中一个操作数是长整型，那么结果就会自动提升为长整型，避免了溢出问题。
                    // 每个数组元素都在进行类型转换之前就被转换为长整型
                    // 若写成(long)(nums[i] + nums[j] + nums[left] + nums[right]) > target 求和操作发生在转换之后 会造成溢出
                    //括号内的求和操作首先将四个整数相加得到一个整数结果，然后再进行长整型转换。如果四个整数相加的结果已经超出了整数类型的范围，
                    // 那么在进行长整型转换之前就已经发生了溢出。这可能导致在转换为长整型之后结果不正确。
                    if((long)nums[i] + nums[j] + nums[left] + nums[right] > target) right--;
                    else if((long)nums[i] + nums[j] + nums[left] + nums[right] < target) left++;
                    else{
                        result.push_back(vector<int> {nums[i], nums[j], nums[left], nums[right]});
                        // 左右指针去重
                        while(left<right && nums[left]==nums[left+1]) left++;
                        while(left<right && nums[right]==nums[right-1]) right--;
                        // 继续移动指针
                        left++;
                        right--;
                    }
                }

            }

        }
        return result;

    }
};