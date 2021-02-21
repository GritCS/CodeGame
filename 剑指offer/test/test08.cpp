//
// Created by doriswang on 2021/2/2.
//

/**
 * 题目：　把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转
 *  输入一个递增排列的数组的一个旋转，输入旋转数组的最小元素．
*/

#include<iostream>
#include<exception>
/**
 * 递增排列的旋转数组可以分为两个小的递增数组（从左到右），
 *  利用双指针算法进行解答，
 *  startPtr   递增遍历第一个数组，
 *  endPtr  递减遍历第二个数组，
 *  而且第一个数组中的数　都大于第二个数组中的数
 * @param numbers　
 * @param length
 * @return　endPtr最后指向第一个数组的首部
 *
 * 样例测试：(注意特殊情况)
 * －－功能测试（输入的数组是升序排序数组的一个旋转，数组中有重复数字或者没有重复数数字
 * －－边界值测试：输入数组是一个升序排序的数组，只含有一个数字的数组
 * －－特殊输入测试：输入NULL指针
 *
 *
 * 如果数组中存在重复元素，可能会出现错误,因为指针会跳出自己所查找的范围,需要顺序查找
 * eg: 0 1 1 1 1
 *  [1 1 1][0 1]
 *  [1][0 1 1 1]
 */
int Min_v1(int* numbers , int length){
    if(numbers==NULL || length==0){
        throw new std::runtime_error("input error");
    }
    int startPtr= 0;
    int endPtr = length-1;
    int midPtr=0;
    while(numbers[startPtr]>=numbers[endPtr]){
        if(startPtr == endPtr-1){
            midPtr = endPtr;
            break;//循环出口
        }
        midPtr = (startPtr+endPtr)/2;
        //如果下标为index1，index2和indexMid指向的三个数字相等
        //只能顺序查找
        if(*(numbers+startPtr)==*(numbers+midPtr) && *(numbers+midPtr) == *(numbers+endPtr)){
            for(int i=startPtr;i<endPtr;i++){
                if(*(numbers+i)<*(numbers+startPtr)){
                    midPtr=i;
                    break;
                }
            }
        }
        if(*(numbers+midPtr)>=*(numbers+startPtr)){ //midPtr当前指向第一个数组
            startPtr=midPtr;
        }
        else if(*(numbers+midPtr)<=*(numbers+endPtr)) {//midPtr指向第二个数组
            endPtr = midPtr;
        }
    }
    return *(numbers+midPtr);
}
int main(){
    std::cout<<"输入数组的个数"<<std::endl;
    int n=0;
    std::cin>>n;
    int* numbers = new int[n];
    std::cout<<"依次输入数组中的元素"<<std::endl;

    for(int i=0;i<n;i++){
        std::cin>>numbers[i];
    }
    std::cout<<"数组中最小的元素"<<std::endl;
    std::cout<<Min_v1(numbers,n)<<std::endl;
}