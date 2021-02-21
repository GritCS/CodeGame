//
// Created by doriswang on 2021/2/7.
//
/**
 * 题目：从上往下打印出二叉树的每个结点，同一层的结点按照从左到右的顺序打印
 * 样例　 A:
 *
 *            ８
 *           /  \
 *          9 　７
 *         / \
 *       ９　２
 *
 */
#include<queue>
#include<iostream>
 struct BinaryTreeNode{
     int m_nValue;
     BinaryTreeNode* m_pLeft;
     BinaryTreeNode* m_pRight;
 };

 void PrintTopToBottom(BinaryTreeNode* pRoot){
    if(!pRoot){
        return ;
    }else{
        std::queue<BinaryTreeNode*> nodes = std::queue<BinaryTreeNode*>();
        nodes.push(pRoot);
        while(!nodes.empty()){
            BinaryTreeNode* Ptr = nodes.front();
            nodes.pop();
            std::cout<<Ptr->m_nValue<<std::endl;//打印出相应的值
            if(Ptr->m_pLeft){
                nodes.push(Ptr->m_pLeft);
            }
            if(Ptr->m_pRight){
                nodes.push(Ptr->m_pRight);
            }
        }
    }
 }
/**
 *
 * @return
 */
 int main(){


     BinaryTreeNode* aa = new BinaryTreeNode();
     BinaryTreeNode* bb = new BinaryTreeNode();
     BinaryTreeNode* cc = new BinaryTreeNode();
     BinaryTreeNode* dd = new BinaryTreeNode();
     BinaryTreeNode* ee = new BinaryTreeNode();
     BinaryTreeNode* ff = new BinaryTreeNode();


     aa->m_nValue = 8;
     aa->m_pLeft = bb;
     aa->m_pRight = cc;

     bb->m_nValue = 9;
     bb->m_pRight= ee;
     bb->m_pLeft= dd;

     cc->m_nValue =7;
     cc->m_pRight=NULL;
     cc->m_pLeft =NULL;

     dd->m_nValue = 9;
     dd->m_pLeft=NULL;
     dd->m_pRight=NULL;

     ee->m_nValue=2;
     ee->m_pRight = NULL;
     ee->m_pLeft =NULL;

     ff->m_nValue =4;
     ff->m_pRight=NULL;
     ff->m_pLeft=NULL;


     PrintTopToBottom(aa);
 }