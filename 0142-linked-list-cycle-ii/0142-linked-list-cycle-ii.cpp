/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
//using hashmap
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode *,bool>visited;
        ListNode*node=head;
        while(node!=NULL){
            if(visited[node])return node;
            visited[node]=true;
            node=node->next;
        }
        return NULL;

    }
};