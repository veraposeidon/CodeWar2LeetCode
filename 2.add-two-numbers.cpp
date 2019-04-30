/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 *
 * https://leetcode.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (30.74%)
 * Total Accepted:    819.7K
 * Total Submissions: 2.7M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 *
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 *
 * Example:
 *
 *
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Explanation: 342 + 465 = 807.
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
// 直接指针遍历即可，注意进位
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // 1. 判空
        if (l1==NULL && l2 == NULL) {
            return NULL;
        }

        // 2. 创建头指针
        ListNode dummynode(0);
        ListNode* node = &dummynode;    // 创建一个遍历指针
        int carry = 0; // 进位
        // 遍历计算
        while(l1 || l2 || carry){
            int sum = (l1?l1->val:0) + (l2?l2->val:0) + carry;    // 累加
            carry = sum / 10;   // 是否进位
            int digit = sum % 10;   // 本位
            node->next = new ListNode(digit);
            node = node->next;
            l1 = l1?l1->next:l1;    // 先判空
            l2 = l2?l2->next:l2;
        }
        // 返回dummynode下一个
        return dummynode.next;
    }
};

