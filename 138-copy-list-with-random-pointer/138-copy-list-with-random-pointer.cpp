/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        Node* curr = head, *temp = head;
        
        //insert copy nodes after each node
        while(curr){
            temp = curr->next;
            
            curr->next = new Node(curr->val);
            curr->next->next = temp;
            curr = temp;
        }
        
        curr = head;
        
        //connecting the random pointers of copy nodes
        while(curr){
            if(curr->random != NULL)
                curr->next->random = curr->random->next;
            curr = curr->next->next;
        }
        
        //restore the original list and extract the copied list
        curr = head;
        Node *original = new Node(0);
        Node *copy = original;
        
        while(curr){
            temp = curr->next->next;
            
            //extract the copy
            copy->next = curr->next;
            
            //restore the original
            curr->next = temp;
            
            copy = copy->next;
            curr = temp;
        }
        
        return original->next;
    }
};











