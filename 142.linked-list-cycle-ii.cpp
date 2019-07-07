/*
 * @lc app=leetcode id=142 lang=cpp
 *
 * [142] Linked List Cycle II
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
    // 两种解法
    // 解法一：使用hash_set记录节点，返回第一个出现的节点即可
    // 解法二：根据逻辑计算，
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL || head->next==NULL) return NULL;
        
        ListNode *fast=head->next, *slow=head;
        
        while(fast!=NULL && fast->next!=NULL){
            // 无环
            if(fast->next->next==NULL) return NULL;
            
            if(fast==slow){
                break;
            } 
            
            fast=fast->next->next;
            slow=slow->next;
        }
        
        if(fast==NULL || fast->next==NULL) return NULL;
        slow=head;
        fast=fast->next;
        while(slow!=fast){
            slow=slow->next;
            fast=fast->next;
        }
        
        return slow;
    }
};
