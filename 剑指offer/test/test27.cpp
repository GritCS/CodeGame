//
// Created by doriswang on 2021/2/17.
//
/**
 * 题目：输入一颗二叉搜索树，将该二叉搜索树转换成一个排序的双向链表
 * 要求不能创建任何新的结点，只能调整树中结点指针的指向。
 *
 *中根遍历顺序            转为 2 = 3 = 4 = 7 = 8
 *            7
 *           /  \
 *          3 　 8
 *         / \
 *        2　 4
*/
#include <iostream>

struct BinaryTreeNode{
    int m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
};


/**
 * 将二叉搜索树构建成一个排序的双向链表，返回链表的尾结点(指向最大元素结点)
 * @param pNode
 * @return
 */
BinaryTreeNode* ConvertNode(BinaryTreeNode* pNode){
    if(pNode == NULL) {
        return NULL;
    }
    BinaryTreeNode* pCurrent = pNode;
    if(pCurrent->m_pLeft != NULL){
        BinaryTreeNode* pLastNodeInList = ConvertNode(pCurrent->m_pLeft);
        pCurrent->m_pLeft = pLastNodeInList;
        pLastNodeInList->m_pRight = pCurrent;
    }

    //右子树
    if(pCurrent->m_pRight != NULL){
        BinaryTreeNode* pHead = ConvertNode(pCurrent->m_pRight);
        pNode = pHead;
        while(pHead->m_pLeft!=NULL){
            pHead=pHead->m_pLeft;//双向链表，找到链表的最前端
        }
        pCurrent->m_pRight=pHead;
        pHead->m_pLeft = pCurrent;
    }
    return pNode;

}

int main(){

    BinaryTreeNode* aa = new BinaryTreeNode();
    BinaryTreeNode* bb = new BinaryTreeNode();
    BinaryTreeNode* cc = new BinaryTreeNode();
    BinaryTreeNode* dd = new BinaryTreeNode();
    BinaryTreeNode* ee = new BinaryTreeNode();



    aa->m_nValue = 7;
    aa->m_pLeft = bb;
    aa->m_pRight = cc;

    bb->m_nValue = 3;
    bb->m_pRight= ee;
    bb->m_pLeft= dd;

    cc->m_nValue =8;
    cc->m_pRight=NULL;
    cc->m_pLeft =NULL;

    dd->m_nValue = 2;
    dd->m_pLeft=NULL;
    dd->m_pRight=NULL;

    ee->m_nValue= 4;
    ee->m_pRight = NULL;
    ee->m_pLeft =NULL;

    //
    BinaryTreeNode* ListNode=ConvertNode(aa);
    while(ListNode->m_pLeft!=NULL){
        std::cout<<ListNode->m_nValue<<std::endl;
        ListNode = ListNode->m_pLeft;
    }

}