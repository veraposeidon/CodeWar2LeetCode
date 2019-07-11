/*
 * @lc app=leetcode id=82 lang=cpp
 *
 * [82] Remove Duplicates from Sorted List II
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
    // 递归
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) return NULL;
        
        if(head->next!=NULL && head->val == head->next->val){
            int val = head->val;
            while(head!=NULL && head->val == val){
                ListNode* tmp = head;
                head = head->next;
                delete tmp;
            }
            head = deleteDuplicates(head);
        }else{
            head->next = deleteDuplicates(head->next);
        }
        
        return head;
    }
};
