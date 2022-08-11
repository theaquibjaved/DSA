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
class compare{
    public:
    bool operator()(ListNode* first, ListNode* second){
        return (first->val > second->val);
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        
        if(k == 0)
            return NULL;
        
        priority_queue<ListNode*, vector<ListNode*>, compare> minheap;
        
        for(int i = 0; i < k; i++){
            if(lists[i] != NULL)
                minheap.push(lists[i]);
        }
        
        ListNode* head = NULL;
        ListNode* tail = NULL;
        
        while(!minheap.empty()){
            ListNode* cur = minheap.top();
            minheap.pop();
            
            if(cur->next != NULL){
                minheap.push(cur->next);
                cur->next = NULL;
            }
            
            // bool firstNode = head == NULL;
            if(head == NULL){
                head = cur;
                tail = cur;
            }
            else{
                tail->next = cur;
                tail = tail->next;
            }
        }
        
        return head;
    }
};









