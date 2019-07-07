/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
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
    // 归并的思路
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return NULL;
         
        return merge(lists, 0, lists.size()-1);
    }
    
    ListNode* merge(vector<ListNode*>& lists, int left, int right){
        if(left==right) return lists[left];
        
        int mid = left + (right-left)/2;
        ListNode* lft = merge(lists, left, mid);
        ListNode* rht = merge(lists, mid+1, right);
        
        return mergeTwoLists(lft, rht);
    }
    
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

        // 省去后续迭代，加速
        iter->next = l1Node==NULL?l2Node:l1Node;
        
        return newhead.next;
        
    }
};

