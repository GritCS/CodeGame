//
// Created by doriswang on 2021/2/7.
//
/**
 * 题目：输入两个整数序列，第一个序列表示栈的压入顺序，请判断第2个序列是否为该栈的弹出序列
 */
#include<iostream>
#include<stack>
bool IsPopOrder(const int* pPush,const int* pPop,int nLength){
    bool result=false;
    if(pPush!=NULL && pPop!=NULL && nLength>0){
        std::stack<int> sstack = std::stack<int>();
        const int* Ptr1 = pPush;
        const int* Ptr2 = pPop;
        while(Ptr2-pPop<nLength){
            while(sstack.empty()|| sstack.top()!=*Ptr2){
                sstack.push(*Ptr1);
                Ptr1++;
                if(Ptr1-pPush>nLength){
                    break;
                }
            }
            if(sstack.top()==*Ptr2){
                sstack.pop();
                Ptr2++;
            }
        }
        if(sstack.empty()){
            result =true;
        }
    }
    return result;
}
int main(){
    int num1[5]={1,2,3,4,5};
    int num2[5]={4,5,3,1,1};
    std::cout<<IsPopOrder(num1,num2,5);
}