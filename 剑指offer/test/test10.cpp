//
// Created by doriswang on 2021/2/3.
//
#include<iostream>
#include <math.h>

/**
 *
 * 位运算－－考虑机器中编码方式
 * 题目：请实现一个函数，输入一个整数，输入该数二进制表示中１的个数
 * 要考虑负数，不能直接右移count，高位会补充１
 *
 * 测试用例：
 * int在本机器上占32bit
 * 正数(包括边界值 1,255）
 * 负数（包括边界值　-1,-256)
 * ０
 */
int NumberOf1_v1(int n){
    int count=0;
    unsigned int num=1;
    while(num!=0){
        if(n&num){
            ++count;
        }
        num=num<<1;
    }
    return count;
}

/**
 * 更快的解决方案
 * 把一个整数减去１，再和原整数，做运算，会把该整数最右边一个１变成０.
 * 一个整数的二进制表示中有多少个１，就可以进行多少次这样的操作
 * @param n
 * @return
 */
int NumberOf1_v2(int n){
    int count=0;
    while(n){
        count++;
        n=n&(n-1);
    }
    return count;
}
int main(){
    std::cout<<NumberOf1_v1(-pow(2,31));
}