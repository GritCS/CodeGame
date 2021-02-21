//
// Created by doriswang on 2021/2/1.
//

#include<iostream>
/**
 *题目：在一个二维数组中，每一行都按照从左到右递增的顺序进行排列，每一列都按照从上到下递增的顺序排序．
 * 请完成一个函数，输入这样一个二维数组和一个整数，判断数组中是否含有该整数．如果含有，返回true，否则返回flase.
 *
 * 简单的数组查询问题，跟据它的大小判断下一个要查找的范围
 * 例如：
 * １　２　８　９
 * ２　４　９　12
 * ４　７　10　13
 * ６　８　11　15
 *要查找７
 * 算法思路：
 * 1. 如果从左上角开始查找，当要查找的数大于当前数组中的数，
 * 　   由于每行和每列都是递增排列，所以下一步查找范围不确定
 * ２．从右上方开始查找，如果要查找数小于当前值，列数小于１，查询左侧部分;
 *
 */

/*
 * matrix:二维数组
 * 　　rows:数组的行数
 *     columns:数组的列数
 * number:要查找的数
 */
bool Find(int* matrix,int rows ,int columns,int number)
{
    if(matrix != NULL && rows >0 && columns){
        int i=0;
        int j=columns-1;
        while(j>=0&&i<rows){
            if(matrix[i*columns+j]==number){
                return true;
            }else if(matrix[i*columns+j]<number){
                ++i;
            }else{
                --j;
            }
        }
    }
    return false;
}
int main(){
    int rows=0;
    int columns=0;
    std::cout<<"输出矩阵的行号和列号"<<std::endl;
    std::cin>> rows>>columns;
    int* Matrix = new int[rows*columns+1];
    for(int i=0;i<columns*rows;i++){
            std::cin>>Matrix[i];
    }
    std::cout<<"输入要查找的数";
    int number=0;
    std::cin>>number;
    std::cout<<Find(Matrix,rows,columns,number);
    return 0;
}