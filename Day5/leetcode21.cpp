// 21. Merge Two Sorted Lists
// Easy

// 6224

// 734

// Add to List

// Share
// Merge two sorted linked lists and return it as a sorted list. The list should be made by splicing together the nodes of the first two lists.

 

// Example 1:


// Input: l1 = [1,2,4], l2 = [1,3,4]
// Output: [1,1,2,3,4,4]
// Example 2:

// Input: l1 = [], l2 = []
// Output: []
// Example 3:

// Input: l1 = [], l2 = [0]
// Output: [0]
 

// Constraints:

// The number of nodes in both lists is in the range [0, 50].
// -100 <= Node.val <= 100
// Both l1 and l2 are sorted in non-decreasing order.

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* p = l1;
        ListNode* q = l2;
        ListNode* r = NULL;
        ListNode* head = r;
        if (!p && !q) return r;
        else if (!p) return l2;
        else if (!q) return l1;
        while(p && q){
            if (p->val < q->val){
                // cout<<p->val<<" ";
                ListNode* temp = new ListNode();
                temp->val = p->val;
                p = p->next;
                if (!head){
                    r = temp;
                    head = r;
                }
                else {
                    r->next = temp;
                    r = r->next;
                }
            }
            else{
                // cout<<q->val<<" ";
                ListNode* temp = new ListNode();
                temp->val = q->val;
                q = q->next;
                if (!head){
                    r = temp;
                    head = r;
                }
                else {
                    r->next = temp;
                    r = r->next;
                }
            }
        }
        if (p){
            r->next = p;
            // cout<<p->val;
        }
        if (q){
            r->next = q;
        }
        return head;
    }
};