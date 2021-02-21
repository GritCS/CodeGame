//
// Created by doriswang on 2021/2/17.
//
/**
 * 题目：复杂链表的复制
 * 请实现函数 ComplexListNode* Clone(ComplexListNode* pHead);
 * 复制一个复杂链表。在复杂链表中，每个结点除了有一个m_pNext指针指向下一个结点外，还有一个
 * m_pSibling 指向链表中的任意结点或者NULL
 *
 * 测试样例：
 *  2----->4---->5
 *
 *  sibling:
 *  2->5
 *  5->4
 */
#include<iostream>

struct ComplexListNode{
    int m_nValue;
    ComplexListNode* m_pNext;
    ComplexListNode* m_pSibling;
};
 ComplexListNode* ConnectSiblingNodes(ComplexListNode* pHead){
    if(pHead==NULL){
        return NULL;
    }
    //1.添加结点
    ComplexListNode* pNode = pHead;
    while( pNode != NULL ){
        ComplexListNode* tempNode = new ComplexListNode();
        tempNode->m_nValue = pNode->m_nValue;
        tempNode->m_pNext=pNode->m_pNext;
        pNode->m_pNext = tempNode;
        pNode = tempNode->m_pNext;
    }

    //2.建立相邻结点
    ComplexListNode* pNodeOne = pHead;
    ComplexListNode* pNodeTow = pHead->m_pNext;
    while( pNodeOne!=NULL ){
        if(pNodeOne->m_pSibling != NULL){
            pNodeTow->m_pSibling = (pNodeOne->m_pSibling)->m_pNext;
        }
        pNodeOne = pNodeTow->m_pNext;
        if(pNodeOne!=NULL){
            pNodeTow = pNodeOne->m_pNext;
        }
    }

    //3.将两个链表拆开
    pNodeOne = pHead;
    pNodeTow = pHead->m_pNext;
    ComplexListNode* pRes = pHead->m_pNext;
    while(pNodeOne!=NULL){
        pNodeOne->m_pNext = pNodeTow->m_pNext;
        if(pNodeOne->m_pNext!=NULL){
            pNodeOne=pNodeOne->m_pNext;
            pNodeTow->m_pNext = pNodeOne->m_pNext;
            pNodeTow = pNodeTow->m_pNext;
        }else{
            break;
        }
    }

    return pRes;
}

int main(){
    ComplexListNode* node1 = new ComplexListNode();
    ComplexListNode* node2 = new ComplexListNode();
    ComplexListNode* node3 = new ComplexListNode();
    node1->m_nValue = 2;
    node2->m_nValue = 4;
    node3->m_nValue = 5;
    node1->m_pNext = node2;
    node2->m_pNext = node3;
    node3->m_pNext = NULL;
    node1->m_pSibling = node3;
    node2->m_pSibling =NULL;
    node3->m_pSibling = node2;
    ComplexListNode* pHead = node1;
    while(pHead!=NULL){
        std::cout<<"结点：    "<<pHead<< std::endl;
        std::cout<<"value:   "<<pHead->m_nValue<<std::endl;
        std::cout<<"Next:    "<<pHead->m_pNext<<std::endl;
        std::cout<<"Sibling: "<<pHead->m_pSibling<<std::endl;
        std::cout<<std::endl;
        pHead = pHead->m_pNext;
    }
    std::cout<<"====================="<<std::endl;
    pHead = ConnectSiblingNodes(node3);
    while(pHead!=NULL){
        std::cout<<"结点：    "<<pHead<< std::endl;
        std::cout<<"value:   "<<pHead->m_nValue<<std::endl;
        std::cout<<"Next:    "<<pHead->m_pNext<<std::endl;
        std::cout<<"Sibling: "<<pHead->m_pSibling<<std::endl;
        std::cout<<std::endl;
        pHead = pHead->m_pNext;
    }
}