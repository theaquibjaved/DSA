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
    int lengthOfLL(ListNode* head){
        int len = 0;
        while(head){
            ++len;
            head = head->next;
        }
        return len;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        int length = lengthOfLL(head);
        
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode *pre = dummy;
        ListNode *cur;
        ListNode *nex;
        
        while(length >= k){
            cur = pre->next;
            nex = cur->next;
            
            for(int i = 1; i < k; i++){
                cur->next = nex->next;
                nex->next = pre->next;
                pre->next = nex;
                nex = cur->next;
            }
            pre = cur;
            length -= k;
        }
        
        return dummy->next;
    }
};