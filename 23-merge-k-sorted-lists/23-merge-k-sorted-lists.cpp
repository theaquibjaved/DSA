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
        
        int n = lists.size();
        
        vector<int> vect;
        
        if(n == 0)
            return NULL;
        
        for(int i = 0; i < n; i++){
            ListNode* node = lists[i];
            
            while(node){
                vect.push_back(node->val);
                node = node->next;
            }
        }
        
        sort(vect.begin(), vect.end());
        int m = vect.size();
        
        ListNode *head = NULL, *tail = NULL;
        
        for(int i = 0; i < m; i++){
            ListNode* newNode = new ListNode(vect[i]);
            
            if(head == NULL){
                head = newNode;
                tail = newNode;
            }
            else{
                tail->next = newNode;
                tail = newNode;
            }
        }
        
        return head;
    }
};