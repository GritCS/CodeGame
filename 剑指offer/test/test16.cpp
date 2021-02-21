//
// Created by doriswang on 2021/2/4.
//
/**
 * 题目：　定义一个函数，输入一个链表的头结点．
 * 反转该链表，并输出反转链表的头结点
 */
#include<iostream>
struct ListNode{
    int m_nKey;
    ListNode* m_pNext;
};
ListNode* ReverseList(ListNode* pHead){
    ListNode* pre = pHead;
    if(!pre){//链表为空
        return NULL;
    }
    ListNode* mid = pHead->m_pNext;
    if(!mid){//链表只包含一个结点
        return pHead;
    }
    pHead->m_pNext=NULL;
    ListNode* later = NULL;
    if(mid->m_pNext){//如果链表包含３个以上的结点
        later = mid->m_pNext;
    }
    while(later){//later并未直到最后一个结点的下一个结点
        mid->m_pNext = pre;
        pre = mid;
        mid = later;
        later = later->m_pNext;
    }
    mid->m_pNext=pre;
    pHead = mid;
    return pHead;
}
int main(){
    ListNode* aa =new ListNode();
    ListNode* bb =new ListNode();
    ListNode* cc =new  ListNode();
    aa->m_nKey=1;
    bb->m_nKey=2;
    cc->m_nKey=3;
    aa->m_pNext=bb;
    bb->m_pNext=cc;
    cc->m_pNext=NULL;
    ListNode* temp = aa;
    while(temp){
        std::cout<<temp->m_nKey<<std::endl;
        temp=temp->m_pNext;
    }

    temp = ReverseList(cc);
    std::cout<<std::endl;
    while(temp){
        std::cout<<temp->m_nKey<<std::endl;
        temp=temp->m_pNext;
    }
    return 0;
}