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

// ques link - https://leetcode.com/problems/remove-nth-node-from-end-of-list/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* ptr = head;
        int numberOfNodes = 0;
        int nodeNumber = 0;
        if(ptr->next == NULL) return NULL;
        while(ptr != NULL) {
            ptr = ptr->next;
            numberOfNodes++;
        }
        // cout<<"Number of nodes = "<<numberOfNodes<<endl;
        nodeNumber = numberOfNodes - n;
        // cout<<"Node to be deleted = "<<nodeNumber<<endl;
        ptr = head;
        if(nodeNumber == 0) {
            return head->next;
        }
        int i = 1;
        while(ptr->next != NULL && i != nodeNumber) {
            ptr = ptr->next;
            i++;
        }
        ptr->next = ptr->next->next;
        return head;
        
    }
};