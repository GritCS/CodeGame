//
// Created by doriswang on 2021/2/8.
//
/**
 * 题目：输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果
 * 如果是则返回true,否则返回false。假设输入的数组的任意两个数字都互相不相同
 */
#include<iostream>

bool VerifySOBST(int nums[],int len){
    if(nums == NULL || len <0){
        return false;
    }
    int root=nums[len-1];
    int left =0;
    for(;left<len-1;left++){
        if(nums[left]>root){
            break;//找到左子树的边界
        }
    }
    int right = left;
    for(;right<len-1;right++){
        if(nums[right]<root){
            return false;//右子树中含有小于根结点的元素
        }
    }
    bool flag1=true;
    if(left>0){
        flag1=VerifySOBST(nums,left);
    }

    bool flag2 = true;
    if(right<len-1){
        flag2=VerifySOBST(nums+left,len-left-1);
    }
    return flag1&&flag2;
}

int main(){
    int nums[] ={5,7,6,9,11,8,10};
    int len = 7;
    std::cout<<VerifySOBST(nums,len);

}