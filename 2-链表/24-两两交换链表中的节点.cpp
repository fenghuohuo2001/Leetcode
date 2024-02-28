
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(nullptr){}
};


// 其实就是连续的四个元素视为一组，将其中相邻两个结点交换
class Solution{
public:
    ListNode* swapPairs(ListNode* head){
        // 创建虚拟头结点
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* cur = dummyHead;
        while(cur->next != nullptr && cur->next->next != nullptr){
            ListNode* tmp = cur->next;
            ListNode* tmp1= cur->next->next->next;

            cur->next = cur->next->next;        // 更新虚拟头结点指向
            cur->next->next = tmp;              // 更新第二个结点（2）指向（1）
            cur->next->next->next = tmp1;       // 更新第一个结点（1）指向（3）

            cur = cur->next->next;              // 更新第cur指向下一个交换区域
        }

        return dummyHead->next;
    }

};