//
// Created by doriswang on 2021/2/18.
//
/**
 * 题目：数组中有一个数字出现的次数超过数组长度的一半，
 *  请找出这个数字
 *
 */
 /**
  * 思路1：如果数组中有一个数字出现的次数超过了数组长度的一半
  *  排序之后，该数字一定位于数组中间的数字，即中位数,
  *  即需要计算第n/2大的数字
  *
  * 基于快排的思想，《Partition》可以在O(n)下，计算得到数字中第k大的数组
  */
#include<iostream>
#include<algorithm>
int Partition(int numbers[], int length,int start,int end){
    //我们这里默认numbers[0]作为中枢轴
    int temp = numbers[start];
    int left=start;
    int right=end;
    while(right>left){
        while(numbers[left]<=temp){
            left++;
        }//left指向左边第一个大于轴的数字
        while(numbers[right]>temp){
            right--;
        }//right指向右边第一个小于轴的数字
        if(right>left){
            std::swap(numbers[right],numbers[left]);
        }
    }//0-right =(小于轴的数字) | = left-n (大于轴的数字)
    std::swap(numbers[start],numbers[right]);
    return right;//right为轴元素 在排序后的数组的正确位置
}

//
int MoreThanHalfNum(int numbers[],int length){
    if(numbers==NULL || length<=0){
        std::cout<<"输入错误"<<std::endl;
        return 0;//
    }
    int middle=length>>1;
    int start=0;
    int end = length-1;
    int index = Partition(numbers,length,start,end);
    while(index != middle){
        if(index>middle){
            end=index-1;
            index = Partition(numbers,length,start,end);
        }
        else{
            start = index+1;
            index = Partition(numbers,length,start,end);
        }
    }
    int result=numbers[middle];
    return result;
}
/**
 * 解法2：跟据数组特点找出O(n)算法
 *  只需要保存两个值：一个是数组中的一个数字，一个是次数
 *  当我们遍历到下一个数字时，如果下一个数字和我们之前保存的数字相同，则次数加1
 *  如果和之前保存的数字不同时，则次数减1
 *
 *  数字出现次数最多的数字一定是最后保存的数字，
 * @return
 */
int MoreThanHalfNum2(int numbers[] ,int length){
    if(numbers==NULL || length<=0){
        std::cout<<"输入错误"<<std::endl;
        return 0;//
    }
    int temp = numbers[0];
    int nums = 1;
    for(int i=1;i<length-1;i++){
        if(temp==numbers[i]){
            nums++;
        }
        else{
            if(--nums<=0){
                temp=numbers[i];
                nums=1;
            }
        }
    }
    return temp;
}
int main(){
    int nums[] ={3,2,4,10,10,10,4};
//    std::cout<<MoreThanHalfNum(nums,7);
    std::cout<<MoreThanHalfNum2(nums,7);
}