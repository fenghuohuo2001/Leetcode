struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(nullptr){}
};

class Solution{
public: 
    ListNode* reverseList(ListNode* head){
        ListNode* temp;
        ListNode* cur = head;
        ListNode* pre = nullptr;

        while(cur){
            // ÔÝ´æ
            temp = cur->next;
            cur->next = pre;
            // update
            pre = cur;
            cur = temp;
        }

        return pre;
    }
};