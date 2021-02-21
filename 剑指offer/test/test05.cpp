//
// Created by doriswang on 2021/2/1.
//
/**
 * 题目:输入一个链表的头结点，从尾到头反过来打印出每个结点的值，要求不改变链表的结构
 */
#include<iostream>
#include <stack>

struct ListNode{
    int m_nKey;
    ListNode* m_pNext;
};
//思路１：利用栈,保存中间遍历的结点
void PrintListReverse(ListNode* pHead){
    std::stack<ListNode*> nodes;
    ListNode* pNode = pHead;

    while(pNode!=NULL){
        nodes.push(pNode);
        pNode=pNode->m_pNext;
    }
    while(!nodes.empty()){
        std::cout<<nodes.top()->m_nKey<<std::endl;
        nodes.pop();
    }
}
//递归函数，递归的本质就是栈结构，但是可能会有栈溢出问题，跟据题目的数量级考虑
void PrintListReverse_2(ListNode* pHead){
    if(pHead != NULL ){
        if(pHead->m_pNext != NULL){
            PrintListReverse_2(pHead->m_pNext);
        }
        std::cout<<pHead->m_nKey<<std::endl;
    }
    return;
}
int main(){
    ListNode* pHead= new ListNode;
    ListNode* node= pHead;
    pHead->m_nKey=23;
    int i=20;
    while(i>15){
        ListNode* tempNode = new ListNode;
        node->m_pNext = tempNode;
        node=tempNode;
        node->m_nKey = i--;
    }
    node->m_pNext=NULL;
//    ListNode* pHead=NULL;
//    PrintListReverse(pHead);
    PrintListReverse_2(pHead);
    return 0;
}
