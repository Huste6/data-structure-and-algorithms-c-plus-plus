/*
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};*/

class Solution {
public:
    int size(ListNode *list1) {
        int cnt = 0;
        while(list1 != nullptr) {
            list1 = list1->next;
            ++cnt;
        }
        return cnt;
    }

    ListNode* addElement(ListNode *&head, int x) {
        ListNode *newNode = new ListNode(x);
        if (head == nullptr) {
            head = newNode;
            return head;
        }
        ListNode *tmp = head;
        while (tmp->next != nullptr) {
            tmp = tmp->next;
        }
        tmp->next = newNode;
        return newNode;
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) {
            return list2;
        }
        if (list2 == nullptr) {
            return list1;
        }
        int n1 = size(list1);
        int n2 = size(list2);
        int i = 0, j = 0;
        ListNode *tmp = nullptr;
        ListNode *dummyHead = new ListNode(-1);
        tmp = dummyHead;

        while (i < n1 && j < n2) {
            if (list1->val < list2->val) {
                tmp->next = addElement(tmp->next, list1->val);
                list1 = list1->next;
                ++i;
            } else if (list1->val > list2->val) {
                tmp->next = addElement(tmp->next, list2->val);
                list2 = list2->next;
                ++j;
            } else if (list1->val == list2->val) {
                tmp->next = addElement(tmp->next, list1->val);
                list1 = list1->next;
                ++i;
            }
            tmp = tmp->next;
        }

        while (i < n1) {
            tmp->next = addElement(tmp->next, list1->val);
            list1 = list1->next;
            ++i;
            tmp = tmp->next;
        }

        while (j < n2) {
            tmp->next = addElement(tmp->next, list2->val);
            list2 = list2->next;
            ++j;
            tmp = tmp->next;
        }

        return dummyHead->next;
    }
};

