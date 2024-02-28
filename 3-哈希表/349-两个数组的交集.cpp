#include <vector>
#include <unordered_set>
using namespace std;

// ������������ �������ǵĽ���

class Solution{
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2){
        unordered_set<int> result_set;
        // �� nums1 �����е�Ԫ�ظ��Ƶ� nums_set �С�������ʹ�õ�������Χ��ʼ����
        // ������� nums1 �е�����Ԫ�أ�����������һ���뵽 nums_set �С�
        // ���� unordered_set �е�Ԫ����Ψһ�ģ��ظ���Ԫ��ֻ�ᱻ����һ�Ρ�
        unordered_set<int> nums_set(nums1.begin(), nums1.end());
        for(int num: nums2){
            // ����nums2��Ԫ�� ��nums_set���ֳ��ֹ�
            if(nums_set.find(num) != nums_set.end()){   // ��δ�ҵ�ƥ��Ԫ�أ��򷵻�ָ�򼯺�ĩβ�ĵ�����unordered_set.end()
                result_set.insert(num);
            }
        }
        return vector<int>(result_set.begin(), result_set.end());
    }
};


class Solution{
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2){
        // ��������unordered_set()���ֱ�洢����1���ظ���Ԫ�أ���������������������2֮�䲻ͬ��Ԫ��
        unordered_set<int> result_set;
        unordered_set<int> nums_set;
        // ��nums1�е�Ԫ����unordered_set�洢
        nums_set.insert(nums1.begin(), nums1.end());
        // ѭ���Ƚ�
        for(int num: nums2){
            if(nums_set.find(num) != nums_set.end()){
                result_set.insert(num);
            }
        }
        // Ҫ���ص���vector����
        return vector<int> (result_set.begin(), result_set.end());
    }
};