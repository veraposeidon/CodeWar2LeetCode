/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
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
    // 直接遍历
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head==NULL || head->next==NULL) return head;

        ListNode* cur=head,*prev=NULL;
        while (m>1)
        {
            prev = cur;
            cur = cur->next;
            m--;
            n--;
        }

        ListNode *con=prev,*tail=cur;

        while (n>0)
        {
            ListNode *temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
            n--;
        }
        
        if(con!=NULL){
            con->next = prev;
        }else{
            head = prev;
        }

        tail->next = cur;
        
        return head;
    }
};

