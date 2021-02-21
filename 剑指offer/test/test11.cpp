//
// Created by doriswang on 2021/2/3.
//
/**
 * 题目：实现函数double Power(double base, int exponent),
 *      求base的exponent次方，不得使用库函数，同时不需要考虑大数问题
 * exponent为
 * 正数
 * 负数
 * ０
 */
#include<iostream>
double Power(double base, int exponent){
    double min=0.0000001;
    if(base<min && base>-min){
        return 0;//如果base=0,0的0次幂为0
    }
    if(exponent==0)
        return 0;
    else if(exponent==1){
        return base;//递归出口
    }
    else if(exponent<0){
        return 1/Power(base,-exponent);
    }else{
        double result=Power(base,exponent>>1);
        result*=result;
        if(exponent&1){
            result*=base;
        }
        return result;
    }
}
int main(){
    std::cout<<Power(2,-4)<<std::endl;
}
