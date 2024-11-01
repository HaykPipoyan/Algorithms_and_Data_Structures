/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverse(ListNode* node){
        ListNode* current = node;
        ListNode* parent = nullptr;
        ListNode* tmp = nullptr;
        while(current!= nullptr){
            tmp = current->next;
            current->next = parent;
            parent = current;
            current = tmp;
        } 
        return parent;
    }
    ListNode* split(ListNode* node){
        ListNode* fast = node->next;
        ListNode* slow = node;
        while(fast){
            fast = fast->next;
            if(fast != nullptr){
                fast = fast->next;
                slow = slow->next;
            }
        }
        ListNode* tmp = slow->next;
        slow->next = nullptr;
        return tmp;

    }
    void reorderList(ListNode* head) {
        ListNode* newHead = split(head);
        newHead = reverse(newHead);
        ListNode* current = head;
        while(current != nullptr && newHead != nullptr){
            ListNode* tmp1 = current->next;
            ListNode* tmp2 = newHead->next;
            current->next = newHead;
            current = tmp1;
            newHead->next = current;
            newHead = tmp2;
        }

    }
};
