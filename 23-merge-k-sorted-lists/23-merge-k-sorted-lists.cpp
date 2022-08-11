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

class compare
{
public:
    bool operator()(const ListNode *first, const ListNode *second)
    {
        return (first->val > second->val);
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& listArray) {
        int k = listArray.size();

    if (k == 0)
    {
        return NULL;
    }

    priority_queue<ListNode*, vector<ListNode*>, compare> helperPQ;

    // Push into the queue.
    for (int i = 0; i < k; i++)
    {
        if (listArray[i] != NULL)
        {
            helperPQ.push(listArray[i]);
        }
    }

    ListNode *head = NULL, *tail = NULL;

    // Add nodes while queue is non empty.
    while (helperPQ.size() > 0)
    {
        ListNode *minNode = helperPQ.top();
        helperPQ.pop();

        if (minNode->next != NULL)
        {
            helperPQ.push(minNode->next);
            minNode->next = NULL;
        }

        if (head == NULL)
        {
            head = minNode;
            tail = minNode;
        }
        else
        {
            tail->next = minNode;
            tail = tail->next;
        }
    }

    return head;
    }
};