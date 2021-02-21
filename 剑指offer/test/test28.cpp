//
// Created by doriswang on 2021/2/17.
//
#include<iostream>
/**
 * 题目：输入一个字符串，打印出该字符串中字符的所有排序。
 *  例如 输入字符串 abc,则打印出由字符 a,b,c 所能排列出来的所有字符串
 *
 *  abc,acb,bac,bca,cab,cba
 */
#include<algorithm>
void Print(char pStr[],int begin){
    if(pStr==NULL||begin<0){
        return;
    }
    else if(pStr[begin] == '\0'){
        std::cout<<pStr<<std::endl;
    }
    else{
        int ptr= begin;
        while( pStr[ptr]!='\0'){
            if(begin!=ptr)
                std::swap(pStr[begin],pStr[ptr]);
            Print(pStr,begin+1);
            if(begin!=ptr)
                std::swap(pStr[begin],pStr[ptr]);
            ptr++;
        }
    }
}
int main(){
    char str[] = "abcd";
    Print(str,0);
}