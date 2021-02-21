//
// Created by doriswang on 2021/2/4.
//
/**
 * 题目：给定单向链表的头指针和一个结点指针(指向单向链表中的某个结点)，定义一个函数在O(1)时间删除该结点．
 * 注意区别之前的删除指定内容的结点
 *
 * 链表结点与函数的定义如下
 *
 * 拓展：删除结点有两种方式：
 *  －找到该结点的前驱结点，前驱结点的指针指向要删除结点的下一个结点
 *  释放要删除结点的内存
 *  －删除结点的内容被覆盖为下一个要删除结点的内容，
 *  释放要删除结点的下一个结点的内容
 *
 *
 *  测试用例
 *  功能测试：
 *       删除中间结点，头节点，尾部结点
 *       从只有一个
 *
 *  */
#include<iostream>
struct ListNode{
    int m_nValue;
    ListNode* m_pNext;
};
void DeleteNode(ListNode** pListHead,ListNode* pToBeDeleted){
    if( pListHead==NULL || pToBeDeleted ==NULL){
        return;//异常输入
    }
    if(*pListHead==pToBeDeleted){//删除头结点
        ListNode* temp = *pListHead;
        *pListHead = (*pListHead)->m_pNext;
        delete temp;
    }
    else if(pToBeDeleted->m_pNext!=NULL){//删除中间结点
        pToBeDeleted->m_nValue=(pToBeDeleted->m_pNext)->m_nValue;
        ListNode* mp=pToBeDeleted->m_pNext;
        pToBeDeleted->m_pNext=(pToBeDeleted->m_pNext)->m_pNext;
        delete mp;
    }
    else{//删除尾结点
        for(ListNode* temp= *pListHead;temp;temp=temp->m_pNext){
            if(temp->m_pNext==pToBeDeleted){//找到要删除的结点
                temp->m_pNext=NULL;
                delete pToBeDeleted;
            }
        }
    }
}
int main(){
    ListNode* head = NULL;
    ListNode* aa =new ListNode();
    ListNode* bb =new ListNode();
    ListNode* cc =new  ListNode();
    aa->m_nValue=1;
    bb->m_nValue=2;
    cc->m_nValue=3;
    aa->m_pNext=bb;
    bb->m_pNext=cc;
    cc->m_pNext=NULL;
    DeleteNode(&cc,cc);
    ListNode* temp =cc;
    while(temp){
        std::cout<<temp->m_nValue<<std::endl;
        temp=temp->m_pNext;
    }
    return 0;
}