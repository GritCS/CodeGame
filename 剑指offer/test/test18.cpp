//
// Created by doriswang on 2021/2/5.
//
/**
 * 题目：输入两棵二叉树Ａ和Ｂ，判断Ｂ是不是Ａ的子结构
 *　树的问题，多用递归解决
 *      １．先找到与Ｂ根结点相同内容的结点
 *      ２．判断之后两个树的子结构是不是相同
 * 测试用例：
 *      两颗二叉树的一个或者两个根结点为NULL指针
 *      二叉树的所有结点都没有左子树或者右子树
 *
 */
#include<iostream>
struct BinaryTreeNode{
    int m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
};
/**
 * 判断以pRootA为根结点的树　是否包含　以pRootB为根结点的子树
 * @param pRootA
 * @param pRootB
 * @return
 */
bool ifContain(BinaryTreeNode* pRootA,BinaryTreeNode* pRootB){
    if(!pRootB){
        return true;
    }else if(!pRootA){
        return false;
    }else{
        if(pRootA->m_nValue == pRootB->m_nValue)
            return ifContain(pRootA->m_pRight,pRootB->m_pRight)&&ifContain(pRootA->m_pLeft,pRootB->m_pLeft);
    }
    return false;
}

bool HasSubTree(BinaryTreeNode* pRootA,BinaryTreeNode* pRootB){
    bool result=false;
    if(pRootB==NULL) {
        return true;
    }
    else if(pRootA==NULL){
            return result;
    }else{
        if(pRootA->m_nValue == pRootB->m_nValue){ //如果根结点相同，继续判断相同根结点的子结构是否相同
            result= ifContain(pRootA,pRootB);
        }
        if(!result){
            result= HasSubTree(pRootA->m_pRight,pRootB);
        }
        if(!result){
            result= HasSubTree(pRootA->m_pLeft,pRootB);
        }
    }
    return result;
}
/**
 * 样例　 A:                    B：
 *
 *            ８                 ８
 *           /  \              /  \
 *          ８　７             9   2
 *         / \
 *       ９　２
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


    BinaryTreeNode* ii = new BinaryTreeNode();
    BinaryTreeNode* jj = new BinaryTreeNode();
    BinaryTreeNode* kk = new BinaryTreeNode();
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


    ii->m_nValue=8;
    ii->m_pLeft = jj;
    ii->m_pRight =kk;

    jj->m_nValue=9;
    jj->m_pRight=NULL;
    jj->m_pLeft=NULL;

    kk->m_nValue = 2;
    kk->m_pLeft=NULL;
    kk->m_pRight=NULL;
    std::cout<<HasSubTree(aa,ii);
}
