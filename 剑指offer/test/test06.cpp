//
// Created by doriswang on 2021/2/1.
//
/**
 * 题目：输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树．假设
 * 输入的前序遍历和中序遍历的结果中不包含重复的数字．
 */
#include <iostream>
#include <exception>
struct BinaryTreeNode{
    int m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
};
/**
 *
 * @param prePtrH 前序遍历数组的头指针
 * @param prePtrE 前序遍历数组的尾指针
 * @param inPtrH 中序遍历数组的头指针
 * @param inPtrE 中序遍历数组的尾指针
 * @return　返回所建立树的根结点
 *
 * 注意函数要检查所给的中序遍历和前序遍历的正确性---c++异常机制
 */
BinaryTreeNode* ConstructCore(int* prePtrH , int* prePtrE,int* inPtrH,int* inPtrE){
    BinaryTreeNode* HeadNode = new BinaryTreeNode;
    HeadNode->m_nValue = *prePtrH;
    HeadNode->m_pLeft=NULL;
    HeadNode->m_pRight=NULL;
    if(prePtrH==prePtrE){//递归出口
        if(inPtrH==inPtrE&& *prePtrH==*inPtrH){
            return HeadNode;
        }else{
            throw "Invalid input．";
        }
    }
    else{
        int tempLength = inPtrE-inPtrH;
        int index=0;
        for(;index<tempLength;index++){
            if(*prePtrH == *(inPtrH+index)){
                break;
            }
        }
        if(*prePtrH!=*(inPtrH+index) && index==tempLength)//在中序遍历中没有找到根结点
            throw "Invalid input．";
        //建立左子树
        if(index>0){//左子树不为空
            HeadNode->m_pLeft=ConstructCore(prePtrH+1,prePtrH+index,inPtrH,inPtrH+index-1);

        }
        //建立右子树
        if(index!=tempLength){//右子树不为空
            HeadNode->m_pRight=ConstructCore(prePtrH+index+1,prePtrE,inPtrH+index+1,inPtrE);
        }
    }
    return HeadNode;
}
void PostOrder(BinaryTreeNode* root){
    if(root!=NULL){
        PostOrder(root->m_pLeft);
        PostOrder(root->m_pRight);
        std::cout<<root->m_nValue<<" ";
    }
}


/**
 *
 * @param preOrder 二叉树的前序遍历
 * @param inorder 　二叉树的中序遍历
 * @param length 二叉树的结点个数
 * @return 构造的二叉树的结点
 */
BinaryTreeNode* Construct(int* preOrder,int* inOrder, int length){
    if(preOrder==NULL || inOrder==NULL ||length==0){
        return NULL;
    }
    return ConstructCore(preOrder,preOrder+length-1,inOrder,inOrder+length-1);
}

int main(){
    int n;
    std::cout<<"输入所建二叉树的结点个数"<<std::endl;
    std::cin>>n;
    int* preOrder = new int[n];
    int* inOrder = new int[n];
    int* tempPtr=preOrder;
    std::cout<<"输入前序遍历"<<std::endl;
    for(int i=0;i<n;i++){
        std::cin>>*(tempPtr++);
    }

    tempPtr=inOrder;
    std::cout<<"输入中序遍历"<<std::endl;
    for(int i=0;i<n;i++){
        std::cin>>*(tempPtr++);
    }
    BinaryTreeNode* root = Construct(preOrder,inOrder,n);
    std::cout<<"后序遍历"<<std::endl;
    PostOrder(root);
};

