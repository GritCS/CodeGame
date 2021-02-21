//
// Created by doriswang on 2021/2/3.
//

/**
 * 题目：写一个函数，输入n，求Fibomacci数列的第n项
 * 性能考虑：不能使用递归调用
 */
#include<iostream>
long long Fibonacci(unsigned int n){
    if(n<2){
        return n;
    }
    long long n1=0;
    long long n2=1;
    for(int i=1;i<n;i++){
        long long temp=n1+n2;
        n1=n2;
        n2=temp;
    }
    return n1;
}
int main(){
    std::cout<<Fibonacci(25);
}