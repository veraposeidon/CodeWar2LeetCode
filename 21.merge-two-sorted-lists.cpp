/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
 *
 * https://leetcode.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (45.84%)
 * Total Accepted:    520.9K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * Merge two sorted linked lists and return it as a new list. The new list
 * should be made by splicing together the nodes of the first two lists.
 * 
 * Example:
 * 
 * Input: 1->2->4, 1->3->4
 * Output: 1->1->2->3->4->4
 * 
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 解法粗暴：两个指针
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL && l2 ==NULL) {
            return NULL;
        }
        if(l1 == NULL)
            return l2;
        
        if(l2 == NULL)
            return l1;

        ListNode newhead(0);
        ListNode* iter= &newhead;
        ListNode* l1Node = l1;
        ListNode* l2Node = l2;

        while(l1Node != NULL && l2Node != NULL){
            if (l1Node->val <= l2Node->val) {
                iter->next = l1Node;
                l1Node = l1Node->next;
            }else
            {
                iter->next = l2Node;
                l2Node = l2Node->next;
            }

            iter = iter->next;     
        }

        

        // while(l1Node != NULL){
        //     iter->next = l1Node;
        //     l1Node = l1Node->next;
        //     iter = iter->next; 
        // }

        // while(l2Node != NULL){
        //     iter->next = l2Node;
        //     l2Node = l2Node->next;
        //     iter = iter->next; 
        // }

        // 省去后续迭代，加速
        iter->next = l1Node==NULL?l2Node:l1Node;
        
        return newhead.next;
        
    }
};

