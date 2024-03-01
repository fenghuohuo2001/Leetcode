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
        // ������
        sort(nums.begin(), nums.end());
        // ��������a��ʼ����
        for(int i=0; i<nums.size(); i++){
            // ����һ����Ϊ��������target>0����ֱ���˳�ѭ�� Ҫ���ǣ�-4��-3��-2��-1��=-10�����
            if(nums[i]>target && nums[i]>0){
                break;
            }
            // ��aȥ��
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }

            // ��ʼ�ڶ���ѭ��
            for(int j=i+1; j<nums.size(); j++){
                // ͬ���ģ��ھ�Ϊ��������£����a+b�Ѿ�����target����ֱ�ӷ��أ�
                if((nums[i]+nums[j])>target && (nums[i]+nums[j])>=0){
                    break;
                }

                if(j>i+1 && nums[j]==nums[j-1]){
                    continue;
                }
                
                //��������˫ָ��
                int left = j+1;
                int right = nums.size()-1;

                while(left<right){
                    // ע������Ҫд��(long)nums[i] + nums[j] + nums[left] + nums[right] > target
                    // �ڽ����������ʱ��ֻҪ����һ���������ǳ����ͣ���ô����ͻ��Զ�����Ϊ�����ͣ�������������⡣
                    // ÿ������Ԫ�ض��ڽ�������ת��֮ǰ�ͱ�ת��Ϊ������
                    // ��д��(long)(nums[i] + nums[j] + nums[left] + nums[right]) > target ��Ͳ���������ת��֮�� ��������
                    //�����ڵ���Ͳ������Ƚ��ĸ�������ӵõ�һ�����������Ȼ���ٽ��г�����ת��������ĸ�������ӵĽ���Ѿ��������������͵ķ�Χ��
                    // ��ô�ڽ��г�����ת��֮ǰ���Ѿ����������������ܵ�����ת��Ϊ������֮��������ȷ��
                    if((long)nums[i] + nums[j] + nums[left] + nums[right] > target) right--;
                    else if((long)nums[i] + nums[j] + nums[left] + nums[right] < target) left++;
                    else{
                        result.push_back(vector<int> {nums[i], nums[j], nums[left], nums[right]});
                        // ����ָ��ȥ��
                        while(left<right && nums[left]==nums[left+1]) left++;
                        while(left<right && nums[right]==nums[right-1]) right--;
                        // �����ƶ�ָ��
                        left++;
                        right--;
                    }
                }

            }

        }
        return result;

    }
};