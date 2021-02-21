//
// Created by doriswang on 2021/2/5.
//

/**
 * 题目：输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每个数字
 *
 */
#include<iostream>
void PrintCircle(int** numbers,int columns,int rows,int start){
    //先打印上方
    int colPtr=0;
    int rowPtr=0;
    while(colPtr<columns){
        std::cout<<numbers[rowPtr+start][colPtr+start]<<std::endl;
        colPtr++;
    }
    colPtr--;//columns-1
    //右侧
    rowPtr++;//row=1;
    while(rowPtr<rows){
        std::cout<< numbers[rowPtr+start][colPtr+start]<<std::endl;
        rowPtr++;
    }
    rowPtr--;//rowPtr=rows-1;
    colPtr--;//colPtr = columns-2;
    //再打印下方
    if(rowPtr>0&&colPtr>0){
        while(colPtr>0){
            std::cout<< numbers[rowPtr+start][colPtr+start]<<std::endl;
            colPtr--;
        }
    }
    //再打印左侧
    //colPtr=0,rowPtr-2
    colPtr++;//colPtr=0;
    rowPtr--;//rows-2
    if(colPtr>0&&rowPtr>0){
        while(rowPtr>1){
            std::cout<< numbers[rowPtr+start][colPtr+start]<<std::endl;
            rowPtr--;
        }
    }
}
void PrintMatrix(int** numbers,int columns,int rows){
    if(!numbers||columns<=0||rows<=0){
        return;
    }
    int Ptr=0;
    int min = (columns<rows?columns:rows +1 )/2;
    int col=columns;
    int row=rows;
    while( Ptr < min){
        PrintCircle(numbers,col,row,Ptr);
        col-=2;
        row-=2;
        Ptr++;
    }
}
int main(){

    //方式一:单独声明指针数组用于传参
    //c++中 二维数组int numbers[row][col]实质是数组的数组
    // 变量名numbers可以看作是指向row-1维数组的指针,该数组的每个元素是int*/数组
    int numbers[2][4] = {{1,2,3,4},{5,6,7,8}};
    std::cout<< typeid(numbers[0]).name();
    int * ptr[2] = {numbers[0],numbers[1]};
    PrintMatrix(ptr, 4, 2);

    //错误示范:这里ptr实质还是一维数组,ptr[1][1]内存访问异常
    //int* ptr = &number[0];
    //PrintMatrix(ptr, 4, 2);

    //方式2:直接声明指针数组,初始化方式复杂,但可以动态申请内存
    int rows=2;
    int columns=4;
    int** nums = new int*[rows];
    for(int i=0;i<rows;i++){
        nums[i]=new int[columns];
    }
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            nums[i][j]=i+j;
        }
    }
    PrintMatrix(nums,columns,rows);

}