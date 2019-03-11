/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
 *
 * https://leetcode.com/problems/palindrome-linked-list/description/
 *
 * algorithms
 * Easy (35.30%)
 * Total Accepted:    234.8K
 * Total Submissions: 663.6K
 * Testcase Example:  '[1,2]'
 *
 * Given a singly linked list, determine if it is a palindrome.
 * 
 * Example 1:
 * 
 * 
 * Input: 1->2
 * Output: false
 * 
 * Example 2:
 * 
 * 
 * Input: 1->2->2->1
 * Output: true
 * 
 * Follow up:
 * Could you do it in O(n) time and O(1) space?
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

// O(n)时间复杂度的话
// 一种简单地方案是，先O(n)翻转，再进行比较（不不，翻转了整个链表就变了，应该翻转后半部分。）
// 同时还需要判断奇数还是偶数(貌似不用判断)
// 关于后半部分，可以通过快慢指针来步进

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        // 0.
        if(head == NULL || head->next == NULL)
            return true;

        // 1.
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast->next != NULL && fast->next->next !=NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        
        slow = slow->next;

        // 2. 
        slow = reverseList(slow);

        // 3. 
        while(slow != NULL && head != NULL){
            if(slow->val != head->val)
                return false;
            
            slow = slow->next;
            head = head->next;
        }
        
        return true;
    }



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
};  

