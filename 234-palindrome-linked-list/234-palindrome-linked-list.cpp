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
    
    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while(fast->next && fast->next->next){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return slow;
    }
    
    bool isPalindrome(ListNode* head) {
        
        if(head == NULL || head->next == NULL)
            return true;
        
        ListNode *slow = middleNode(head);
        
        slow->next = reverseList(slow->next);
        slow = slow->next;
        
        while(slow){
            if(head->val != slow->val)
                return false;
            slow = slow->next;
            head = head->next;
            
        }
        
        return true;
    }
    
    ListNode* reverseList(ListNode *head){
        ListNode *dummy = NULL;
        ListNode *nex = NULL;
        
        while(head){
            nex = head->next;
            head->next = dummy;
            dummy = head;
            head = nex;
        }
        
        return dummy;
    }
};