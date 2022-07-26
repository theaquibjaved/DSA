/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        Node* start = root;
        
        while(start){
            Node* ptr = start;
            Node* prev = NULL;
            start = NULL;
            
            while(ptr){
                
                if(ptr->left){
                    if(prev)
                        prev->next = ptr->left;
                    if(start == NULL)
                        start = ptr->left;
                    prev = ptr->left;
                }
                
                if(ptr->right){
                    if(prev)
                        prev->next = ptr->right;
                    if(start == NULL)
                        start = ptr->right;
                    prev = ptr->right;
                }
                
                ptr = ptr->next;
            }
        }
        
        return root;
    }
};