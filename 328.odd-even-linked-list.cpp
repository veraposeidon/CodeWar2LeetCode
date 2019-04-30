/*
 * @lc app=leetcode id=328 lang=cpp
 *
 * [328] Odd Even Linked List
 *
 * https://leetcode.com/problems/odd-even-linked-list/description/
 *
 * algorithms
 * Medium (47.89%)
 * Total Accepted:    142.7K
 * Total Submissions: 292.3K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * Given a singly linked list, group all odd nodes together followed by the
 * even nodes. Please note here we are talking about the node number and not
 * the value in the nodes.
 * 
 * You should try to do it in place. The program should run in O(1) space
 * complexity and O(nodes) time complexity.
 * 
 * Example 1:
 * 
 * 
 * Input: 1->2->3->4->5->NULL
 * Output: 1->3->5->2->4->NULL
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 2->1->3->5->6->4->7->NULL
 * Output: 2->3->6->7->1->5->4->NULL
 * 
 * 
 * Note:
 * 
 * 
 * The relative order inside both the even and odd groups should remain as it
 * was in the input.
 * The first node is considered odd, the second node even and so on ...
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
// 双指针
// 时间复杂度：O(N)
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        // 0. check
        if (head == NULL || head->next == NULL || head->next->next==NULL)
            return head;

        // 1. odd head and even head
        ListNode* even_first = head->next;  // 注意 head的next已经变了。
        ListNode* odd = head;
        ListNode* even = head->next;

        while(true){
            if(odd->next != NULL && odd->next->next != NULL)
            {
                odd->next=odd->next->next;
                odd = odd->next;
            }
            if(odd->next == NULL)
                break;
            if(even->next !=NULL && even->next->next !=NULL)
            {
                even->next=even->next->next;
                even=even->next;
            }
            if(even->next == NULL)
                break;
        }

        // odd end plus even head
        even->next=NULL;
        odd->next = even_first;

        // return head
        return head;
    }
};
