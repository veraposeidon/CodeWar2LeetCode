/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


// 带环带链表
// 原理在此：https://blog.csdn.net/wuzhekai1985/article/details/6725263
class Solution1 {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // 0. check
        if(headA == NULL || headB == NULL)
            return NULL;

        // 1. 先构成带环单链表
        
    }
};

// 双指针解法
//这个思路就是，按照下面方式跑，必会出现交集，没有则就是空指针
//ListA + ListB = A + intersection + Bb + intersection
//ListB + ListA = Bb + intersection + A + intersection
//时间复杂度为O(n),且只做到了一遍遍历就OK。不错的算法。
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // 0. check
        if(headA == NULL || headB == NULL)
            return NULL;

        ListNode *cursorA = headA;
        ListNode *cursorB = headB;
        while(cursorA != cursorB){
            if(!cursorA){
                cursorA = headB;
            }else{
                cursorA = cursorA->next;
            }

            if(!cursorB){
                cursorB = headA;
            }else{
                cursorB = cursorB->next;
            }
        }

        return cursorA;
    }
};

