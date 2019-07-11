/*
 * @lc app=leetcode id=83 lang=cpp
 *
 * [83] Remove Duplicates from Sorted List
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
    // ListNode* deleteDuplicates(ListNode* head) {
    //     if(head == NULL) return nullptr;
        
    //     ListNode* dummy = head;
        
    //     while(head != NULL && head->next != NULL){
    //         if(head->next->val == head->val){
    //             ListNode* temp = head->next;
    //             head->next = head->next->next;
    //             delete temp;
    //         }else{
    //             head = head->next;
    //         }
            
    //     }
    //     return dummy;
    // }

    // 递归
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next==NULL) return head;
        
        while(head->next !=NULL && head->next->val == head->val){
            head->next = head->next->next;
        }
        
        head->next = deleteDuplicates(head->next);

        return head;
    }
};

