//
// Created by doriswang on 2021/2/3.
//
/**
 * 题目：输入数字n,按顺序打印出从１最大的n位十进制，
 * 比如输入３,则打印出１，２，３一直到最大的999
 * n可能很大，所以这里我们用字符数组模拟加法
 *
 *
 */
#include<iostream>
#include <cstring>
bool increase(char* numbers,int length) {
    int c = 0;//进位
    if (numbers[length - 1] == '9') {
        numbers[length - 1] = '0';
        c = 1;
        int i = length - 2;
        for (; i >= 0; i--) {
            if (numbers[i]=='9') {//number[i]+进位为０,为继续向前进１
                numbers[i] ='0';
                c = 1;
            } else {
                numbers[i] = numbers[i] + c ;
                c = 0;//没有进位，跳出循环
                break;
            }
        }
        if(i==-1){
            return false;//向前number[-1]进位
        }
    }
    else{
        numbers[length-1]+=1;
    }
    return true;
}
void printN(char*numbers,int length){
    int i=0;
    for(;i<length;i++){
        if(numbers[i]!='0'){
            break;
        }
    }
    for(;i<length;i++){
        std::cout<<numbers[i];
    }
    std::cout<<'\t'<<std::endl;
}

void PrintToMaxOfN(int n){
    if(n<=0){
        throw new std::runtime_error("input error");
    }
    char* number = new char[n+1];
    memset(number,'0',n);
    number[n]='\0';
    while(increase(number,n)){
        printN(number,n);
    }
}

int main(){
    PrintToMaxOfN(100);
}

