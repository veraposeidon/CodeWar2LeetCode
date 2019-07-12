/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
 *
 * https://leetcode.com/problems/reverse-linked-list/description/
 *
 * algorithms
 * Easy (52.74%)
 * Total Accepted:    524.4K
 * Total Submissions: 990.5K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * Reverse a singly linked list.
 * 
 * Example:
 * 
 * 
 * Input: 1->2->3->4->5->NULL
 * Output: 5->4->3->2->1->NULL
 * 
 * 
 * Follow up:
 * 
 * A linked list can be reversed either iteratively or recursively. Could you
 * implement both?
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
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // 0. 
        if (head ==NULL || head->next ==NULL) {
            return head;
        }

        ListNode* newHead = NULL;
        ListNode* iter = head;
        ListNode* prev = NULL;

        while(iter != NULL){
            ListNode* nex = iter->next;

            if(nex == NULL)
                newHead = iter;

            iter->next = prev;

            prev = iter;
            iter = nex;
        }
        
        return newHead;
    }

    // 递归解法
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        
        ListNode* prev = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        
        return prev;
    }
};

