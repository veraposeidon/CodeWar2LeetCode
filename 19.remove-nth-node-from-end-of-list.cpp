/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
 *
 * https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
 *
 * algorithms
 * Medium (33.99%)
 * Total Accepted:    359K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given a linked list, remove the n-th node from the end of list and return
 * its head.
 * 
 * Example:
 * 
 * 
 * Given linked list: 1->2->3->4->5, and n = 2.
 * 
 * After removing the second node from the end, the linked list becomes
 * 1->2->3->5.
 * 
 * 
 * Note:
 * 
 * Given n will always be valid.
 * 
 * Follow up:
 * 
 * Could you do this in one pass?
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

// 思路：
// 首先双指针，找到要删除的节点的上一个节点
// 然后再 删除要删除的节点
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 0. 倒数第零个没有意义
        if (head == NULL || n == 0) {
            return NULL;
        }
        
        ListNode* prior = head;
        ListNode* behind = head;

        // 1. 先走几步(第二个指针需要)
        for(int i = 1; i <= n-1; i++)
        {
            if(prior->next != NULL)
            {
                prior = prior->next;
            }else
            {
                return NULL; //根本就没那么多步
            }
            
        }

        // 1.1 要是走到头了，就说明删除的是头节点
        if(prior->next == NULL)
        {
            ListNode* newHead = head->next;
            delete head;
            head = newHead;
            return head;
        }

        prior = prior->next;


        // 2. 一起走
        while(prior->next != NULL){
            prior = prior->next;
            behind = behind->next;
        }
        
        // 3. 删除下一个节点
        // 如果要删的是尾节点的话
        if (behind->next->next == NULL) {
           delete behind->next;
           behind->next = NULL;
        }else
        {
            ListNode* copy = behind->next;
            behind->next = behind->next->next;
            delete copy;
            copy = NULL;
        }
        
        return head;

    }
};

