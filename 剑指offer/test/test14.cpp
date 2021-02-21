//
// Created by doriswang on 2021/2/4.
//
/**
 * 题目：输入一个整数数组，实现一个函数来调整该数组中数字的顺序
 * 使得所有奇数位于数组的前半部分，所有偶数位于数组的后半部分
 * 双指针解法
 */
#include<iostream>
void ReorderOddEven(int* pData,unsigned int length){
    int* pre = pData;
    int* later = (pData+length-1);
    while(pre<later){
        while((*pre&1)&&(pre-pData<length)){//为偶数
            pre++;
        }
        while(!(*later&1)&&(later>pData)){
            later--;
        }
        if(pre<later){
            int tempNum = *pre;
            *pre = *later;
            *later = tempNum;
        }
    }
}
int main(){
    int pData[] ={2,4,6,8,10};
    ReorderOddEven(pData,5);
    for(int i=0;i<5;i++) {
        std::cout << pData[i] << std::endl;
    }
}
