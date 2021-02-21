//
// Created by doriswang on 2021/2/1.
//
/**
 * 题目：请实现一个函数，把字符串中的每个空格替换成"%20"．
 * 例: "We are happy." 则输出"We%20are%20happy"
 *  要求复杂度是O(n)
 *
 * 题目陷阱：　原来是一个空格字符，替换之后字符串的长度有变化
 * 题目有两种情况
 * １．创建新的字符串并在新的字符串上做替换，那么自己可以分配足够多的内存
 * ２．在原来的字符串上做替换，并保证输入的字符串后面有足够多的空余内存
 *
 *  该函数利用双指针　解决情况２下的问题
 *  首先先计算出替换后所需要的内存空间，从后向前进行替换
 */

#include <iostream>

/*length为字符数组string的总容量*/
void ReplaceBlank(char string[],int length){
    int num=0;
    int ptr1=0;
    int ptr2=0;
    while(string[ptr1]!='\0'){
        if(string[ptr1]==' '){
            num++;//对空格进行计数
        }
        ++ptr1;
    }
    if(ptr1+num*2>length){
        std::cout<<"内存不够，转换失败";
    }else{
        ptr2=ptr1+num*2;
        while(ptr1>=0){
            if(string[ptr1]==' '){
                string[ptr2--]='0';
                string[ptr2--]='2';
                string[ptr2--]='%';
            }else{
                string[ptr2--]=string[ptr1];
            }
            --ptr1;
        }
    }
}
int main(){
    char string[] = "000000000000000000";
    int length=27;
    string[0]='\0';
    std::cout<<string<<std::endl;
    ReplaceBlank(string,length);
    std::cout<<string<<std::endl;
}