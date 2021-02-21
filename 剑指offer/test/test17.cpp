//
// Created by doriswang on 2021/2/5.
//
/**
 * 题目：输入两个递增排序的链表，合并这两个链表并使新链表中的结点仍然是按照
 *  递增排序的．
 */
#include<iostream>
struct ListNode{
    int m_nValue;
    ListNode* m_pNext;
};

ListNode* Merge(ListNode* pHead1,ListNode* pHead2){
    if(!pHead1){
        return pHead2;//链表１为空
    }else if(!pHead2){
        return pHead1;//链表２为空
    }
    ListNode* pNewHead = NULL;
    if(pHead1->m_nValue <pHead2->m_nValue){
        pNewHead = pHead1;
        pNewHead->m_pNext = Merge(pHead1->m_pNext,pHead2);//采用递归算法
    }else{
        pNewHead = pHead2;
        pNewHead->m_pNext = Merge(pHead1,pHead2->m_pNext);
    }
    return pNewHead;
}

int main(){

    ListNode* aa =new ListNode();
    ListNode* bb =new ListNode();
    ListNode* cc =new  ListNode();
    ListNode* dd = new ListNode();
    ListNode* ee = new ListNode();
    aa->m_nValue=1;
    bb->m_nValue=3;
    cc->m_nValue=5;
    aa->m_pNext=bb;
    bb->m_pNext=cc;
    cc->m_pNext=NULL;

    dd->m_nValue =6;
    dd->m_pNext =ee;
    ee->m_nValue =7;
    ee->m_pNext=NULL;
    ListNode* temp = Merge(aa,dd);
    while(temp){
        std::cout<<temp->m_nValue<<std::endl;
        temp=temp->m_pNext;
    }
    return 0;
}