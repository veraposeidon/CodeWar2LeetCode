/*
 * @lc app=leetcode id=148 lang=cpp
 *
 * [148] Sort List
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
    // 由于时间复杂度要求为nlogn,所以考虑使用快速排序和归并排序。
    // 这里使用归并排序
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        
        ListNode* mid = getMiddle(head);
        ListNode* secdPrt = NULL;
        if(mid!=NULL){
            secdPrt = mid->next;
            mid->next = NULL;
        }
        
        // 递归 进行归并
        return merge(sortList(head), sortList(secdPrt));
    }
    
    // 获取中间节点
    ListNode* getMiddle(ListNode* head){
        if(head==NULL || head->next==NULL) return head;
        ListNode *fast=head->next,*slow=head;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
    
    // 归并
    ListNode* merge(ListNode* first, ListNode* second){
        if(first==NULL) return second;
        if(second==NULL) return first;
        
        ListNode* dummy = new ListNode(0);
        ListNode* node = dummy;
        
        while(first!=NULL&&second!=NULL){
            if(first->val <= second->val){
                node->next = first;
                first=first->next;
            }else{
                node->next = second;
                second=second->next;
            }
            node = node->next;
        }

        
        if(first!=NULL) node->next=first;
        if(second!=NULL) node->next=second;
        
        ListNode* ret = dummy->next;
        delete dummy;   // 删除dummy节点
        return ret;
    }
    
};

