#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution{
public:
    vector<vector<int>> threeSum(vector<int> &nums){
        vector<vector<int>> result;
        // ��������Ԫ�ش�С˳��
        sort(nums.begin(), nums.end());
        // �ҳ�a + b + c = 0
        // a = nums[i], b = nums[j], c = -(a+b)
        for(int i=0; i<nums.size(); i++){
            // ����֮�������һ��Ԫ���Ѿ������㣬��ô�����ܴճ���Ԫ��
            if(nums[i] > 0){
                break;
            }

            // ��Ԫ��Ԫ��aȥ��
            if(i>0 && nums[i]==nums[i-1]){
                continue;           // ��ת����һ��ѭ��
            }

            unordered_set<int> set;

            for (int j = i+1; j<nums.size(); j++){
                // ��Ԫ��Ԫ��bȥ��
                if(j>i+2 && nums[j]==nums[j-1] && nums[j-1]==nums[j-2]){
                    continue;
                }
                int c = 0 - (nums[i] + nums[j]);
                if(set.find(c) != set.end()){
                    result.push_back({nums[i], nums[j], c});
                    set.erase(c);       // ��Ԫ��cȥ��
                }else{
                    set.insert(nums[j]);
                }
            }
        }
        return result;
    }
};


// ˫ָ�뷨���һЩ
class Solution{
public:
    vector<vector<int>> threeSum(vector<int>& nums){
        vector<vector<int>> result;
        // ������
        sort(nums.begin(), nums.end());
        // ����
        for(int i=0; i<nums.size(); i++){
            // ��������ĵ�һ��Ԫ�ؼ�����0�����������������Ԫ��
            if(nums[i] > 0) return result;
            
            // �ڿ�ʼ��b����ʱ��Ҫ�ж�a��û���ظ� ͬʱ��һ��Ԫ�ز�Ӧ�ò������
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }

            // ����˫ָ��
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
        // ���ȶ�ԭ�����������
        sort(nums.begin(), nums.end());

        // ��ʼ����
        for(int i=0; i<nums.size(); i++){
            // �������������һ��Ԫ�ش���0ʱ��ֱ��return
            if(nums[i]>0) return result;

            // ��aȥ��
            if(i>0 && nums[i] == nums[i-1]){
                continue;
            }

            // a������ϣ�����������˫ָ���bc���д���
            int left = i + 1;
            int right = nums.size() - 1;
            while(left < right){
                if ((nums[i] + nums[left] + nums[right]) > 0) right--;
                else if ((nums[i] + nums[left] + nums[right]) < 0) left++;
                else{
                    result.push_back(vector<int> {nums[i], nums[left], nums[right]});
                    // ��b��c����ȥ��
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