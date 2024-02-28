#include <iostream>

// ��������ڵ�ṹ��
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// �����ֵ����ڵ�
void assignList(ListNode* head, int* arr, int n) {
    if (n == 0) 
        return;
    head->val = *arr;
    if (n > 1) {
        head->next = new ListNode(0);
        // ���������������洢�ı���������ڵ�ַ��+1����ָ����һ������Ԫ��
        assignList(head->next, arr + 1, n - 1);
    }
}

// ��ӡ����
void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    // ��������ͷ�ڵ�
    ListNode* head = new ListNode(0);

    // �����ֵ����ڵ�
    assignList(head, arr, n);

    // ��ӡ����
    std::cout << "�����ʼֵ��" << std::endl;
    printList(head);

    return 0;
}
