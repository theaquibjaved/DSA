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
        Node *orig = head, *copy = NULL;
        unordered_map<Node*, Node*> map;
        
        while(orig){
            copy = new Node(orig->val);
            map.insert(make_pair(orig, copy));
            orig = orig->next;
        }
        
        orig = head;
        
        while(orig){
            copy = map[orig];
            copy->next = map[orig->next];
            copy->random = map[orig->random];
            orig = orig->next;
        }        
        
        return map[head];
    }
};