//
// Created by doriswang on 2021/2/4.
//
/**
 * 题目：输入一个链表，删除该链表中倒数第k个结点．
 */
#include<iostream>
 struct ListNode{
     int m_nValue;
     ListNode* m_pNext;
 };
 ListNode* FindKthToTail(ListNode* pListHead,unsigned int k){
     //异常处理
     if(pListHead==NULL || !k){
         throw new std::runtime_error("input error");
     }

     ListNode* pre=pListHead;
     ListNode* later=pListHead;
     ListNode* Ptr=later->m_pNext;//later的后继结点，Ptr是要删除的结点
     //删除尾结点（遍历，利用前结点索引删除）
     if(k==1) {
         if (!Ptr) {//只包含一个结点
             delete later;
             return NULL;
         } else {
             while (Ptr->m_pNext) { //
                 later = Ptr;
                 Ptr = Ptr->m_pNext;
             }
             later->m_pNext = Ptr->m_pNext;
             delete Ptr;//删除尾结点
             return pListHead;
         }
     }
     //删除非尾结点,
     // 初始化，pre所指结点是头结点，later指的结点为第k-1个结点
     // 当later指到尾结点，pre所指的结点是要删除的倒数第k个结点
     for(int i=0;i<k;i++){
         if(later){
             later=later->m_pNext;
         }else{//k>结点的个数
             throw new std::runtime_error("input error");
         }
     }
     if(!later){//如果删除的是头结点
         ListNode* temp = pListHead;
         pListHead = pListHead->m_pNext;
         delete temp;
         return pListHead;
     }
     else{//删除的是非头节点，pListHead不需要修改
         while(later){
             later=later->m_pNext;
             pre=pre->m_pNext;
         }
         ListNode* tempPtr = pre->m_pNext;
         pre->m_nValue=(pre->m_pNext)->m_nValue;
         pre->m_pNext= tempPtr->m_pNext;
         delete tempPtr;
         return pListHead;
     }
 }
 int main(){

     ListNode* aa =new ListNode();
     ListNode* bb =new ListNode();
     ListNode* cc =new  ListNode();
     aa->m_nValue=1;
     bb->m_nValue=2;
     cc->m_nValue=3;
     aa->m_pNext=bb;
     bb->m_pNext=cc;
     cc->m_pNext=NULL;


     ListNode* temp = FindKthToTail(aa,2);
     while(temp){
         std::cout<<temp->m_nValue<<std::endl;
         temp=temp->m_pNext;
     }
     return 0;
 }