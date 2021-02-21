
//
// Created by doriswang on 2021/2/9.
//
/**
 * 题目：输入一个二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
 * 从树的根结点开始往下一直到 叶结点 所经过的结点 形成一条路径。
 *
 *
 *            ８
 *           /  \
 *          3 　７
 *         / \
 *       4　２
*/
#include<iostream>

#include<vector>
#include<algorithm>
struct BinaryTreeNode{
    int m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
};
void print(BinaryTreeNode* ptr){
    std::cout<<ptr->m_nValue <<" ";
}
void FindPath(BinaryTreeNode* pRoot,int exceptedSum,std::vector<BinaryTreeNode*> path,int& currentSum){
    if(pRoot!=NULL){
        currentSum+=pRoot->m_nValue;
        path.push_back(pRoot);
        //找到符合要求的路径
        if( pRoot->m_pLeft==NULL && pRoot->m_pRight==NULL &&exceptedSum == currentSum){
            std::cout<<"a path is"<<std::endl;
            std::for_each(path.begin(),path.end(),print);
            std::cout<<std::endl;
        }
        if(pRoot -> m_pLeft != NULL){
            FindPath(pRoot->m_pLeft,exceptedSum,path,currentSum);
        }
        if(pRoot -> m_pRight != NULL){
            FindPath(pRoot->m_pRight,exceptedSum,path,currentSum);
        }
        currentSum-=pRoot->m_nValue;
        path.pop_back();
    }
}
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

    bb->m_nValue = 3;
    bb->m_pRight= ee;
    bb->m_pLeft= dd;

    cc->m_nValue =7;
    cc->m_pRight=NULL;
    cc->m_pLeft =NULL;

    dd->m_nValue = 4;
    dd->m_pLeft=NULL;
    dd->m_pRight=NULL;

    ee->m_nValue=2;
    ee->m_pRight = NULL;
    ee->m_pLeft =NULL;

    ff->m_nValue =4;
    ff->m_pRight=NULL;
    ff->m_pLeft=NULL;
    std::vector<BinaryTreeNode*> path = std::vector<BinaryTreeNode*>();
    int num=0;
    FindPath(aa,15,path,num);
}