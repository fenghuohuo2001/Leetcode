
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(nullptr){}
};


// 即两个链表的结点相交之前是不一样，在相交结点之后均为一样的元素
// 注意交点不是数值相等，而是指针相等
// 找出并返回两个单链表相交的起始节点
class Solution{
public:
    template <typename T>
    void swap(T &a, T &b){
        T temp = a;
        a = b;
        b = temp;
    }

    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB){
        ListNode* curA = headA;
        ListNode* curB = headB;
        int lenA = 0, lenB = 0;
        // 求链表A长度
        while(curA != nullptr){
            lenA++;
            curA = curA->next;
        }
        // 求链表B长度
        while(curB != nullptr){
            lenB++;
            curB = curB->next;
        }
        // 建立指向头部的两个链表指针
        curA = headA;
        curB = headB;

        // 将curA设为长链表的指针，lenA为其长度
        if (lenB > lenA)
        {
            swap(lenA, lenB);
            swap(curA, curB);
        }

        // 求长短链表的长度差值
        int gap = lenA - lenB;

        while(gap--){
            curA = curA->next;
        }

        // 遍历curA和curB，遇到相同结点就直接返回
        while(curA != nullptr){
            if(curA == curB){
                return curA;
            }
            curA = curA->next;
            curB = curB->next;
        }

        return nullptr;
    }
};


class Solution{
public:
    template <typename T>
    void swap(T &a, T &b){
        T temp = a;
        a = b;
        b = temp;
    }

    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB){
        // 创建两个链表指针
        ListNode* curA = headA;
        ListNode* curB = headB;
        // 计算两个链表长度
        int lenA = 0, lenB = 0;
        while(curA!=nullptr){
            lenA++;
            curA = curA->next;
        }
        while(curB!=nullptr){
            lenB++;
            curB = curB->next;
        }

        // 注意 此时curA和curB都指向了链表末尾，为了实现遍历，需要重新赋值指向头结点
        curA = headA;
        curB = headB;

        // 将长链表赋值标注为A，短的为B
        if(lenB > lenA){
            swap(lenA, lenB);
            swap(curA, curB);
        }
        
        // 计算链表长度差值
        int gap = lenA - lenB;

        // 使curA和curB对齐
        while(gap--){       // 这里应该是gap--
            curA = curA->next;
        }

        // 开始寻找相交结点
        while(curA!=nullptr){
            if(curA == curB){
                return curA;
            }
            // 遍历
            curA = curA->next;
            curB = curB->next;
        }
        return nullptr;
    }
};