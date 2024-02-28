#include <unordered_set>
using namespace std;

class Solution{
public:
    // ȡ����ÿ����λ�ϵĵ�����
    int getSum(int n){
        int sum = 0;
        while(n){
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }
    // �жϿ�����
    bool isHappy(int n){
        unordered_set<int> set;
        while(1){
            int sum = getSum(n);
            if(sum == 1) return true;

            // ������sum�Ѿ����ֹ���˵���Ѿ���������ѭ���ˣ�����return false
            if(set.find(sum) != set.end()){
                return false;
            }else{
                set.insert(sum);
            }
            n = sum;
        }
    }
};


class Solution{
public:
    // ÿ��ȡ��λ�ϵ�����ƽ��
    int getSum(int n){
        int sum = 0;
        while(n){
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n){
        unordered_set<int> set;
        while(1){
            // �жϵ�ǰ���
            int sum = getSum(n);
            // ����ǰ���Ϊ1
            if (sum == 1){
                return true;
            }
            // ����ǰ�����֮ǰ�Ѿ����ֹ�
            if(set.find(sum) != set.end()){
                return false;
            }else{
                set.insert(sum);
            }
            // ���µ�ǰ��
            n = sum;
        }
    }
};


class Solution{
public:
    int getSum(int n){
        int sum = 0;
        while(n){
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n){
        // ���ȶ���һ��unordered_set���洢���������������ظ�ʱ���ͳ���������ѭ��
        unordered_set<int> set;
        while(1){
            // ����ÿλ���ֵ�ƽ����
            int sum = getSum(n);
            if (sum == 1){
                return true;
            }
            // �������Ϊ1�����жϵ�ǰ�������ǰ�Ƿ���ֹ�
            if (set.find(sum) != set.end()){
                return false;
            }else{
                set.insert(sum);
            }
            // ��������
            n = sum;
        }
    }
};