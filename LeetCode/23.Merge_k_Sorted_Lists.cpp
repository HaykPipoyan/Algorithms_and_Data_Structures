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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode* a, ListNode* b){return a->val > b->val;};
        std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(cmp)> pq(cmp);
        int k = lists.size();
        if(k == 0){
            return nullptr;
        }
        for(int i = 0; i < k; ++i){
            if(lists[i] != nullptr){
                pq.push(lists[i]);
            }
        }
        ListNode* head = nullptr;
        ListNode* tmp = nullptr;

        while(!pq.empty()){
            ListNode* top = pq.top();
            pq.pop();
            if(top->next != nullptr){
                pq.push(top->next);
            }
            if(head == nullptr){
                head = tmp = top;
            } else {
                tmp->next = top;
                tmp = top;
            }
        }

        return head;
    }
};
