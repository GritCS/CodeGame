//
// Created by doriswang on 2021/2/5.
//
/**
 * 题目：请完成一个函数，输入一个二叉树，该函数计算出该二叉树的镜像
 *
 */
#include<iostream>
struct BinaryTreeNode{
    int m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
};

BinaryTreeNode* MirrorTree(BinaryTreeNode* pRoot){
    if(!pRoot|| (!(pRoot->m_pLeft) && ! (pRoot->m_pRight)) ){
        return NULL;
    }else{
        BinaryTreeNode* temp = pRoot->m_pLeft;
        pRoot->m_pLeft = pRoot->m_pRight;
        pRoot->m_pRight = temp;
        if(pRoot->m_pLeft)
            MirrorTree(pRoot->m_pLeft);
        if(pRoot->m_pRight)
            MirrorTree(pRoot->m_pRight);
    }
    return pRoot;
}
void PostOrder(BinaryTreeNode* root){
    if(root!=NULL){
        PostOrder(root->m_pLeft);
        PostOrder(root->m_pRight);
        std::cout<<root->m_nValue<<" ";
    }
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

    bb->m_nValue = 8;
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
    PostOrder(aa);
    std::cout<<std::endl;
    BinaryTreeNode* temp = MirrorTree(aa);
    PostOrder(temp);

}