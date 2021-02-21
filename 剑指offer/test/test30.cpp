//
// Created by doriswang on 2021/2/19.
//
/**
 * 最小的k个数
 * 题目： 输入n个整数，找出其中最小的k个数。
 */
/**思路1：
//可以参考题目29中所提到的快排类似的思路，
//用O(n)复杂度，找到top(k)和k_ed的数字
 只有当我们可以修改输入的数组时，可以使用
 */


/**
 *思路2：O(nlogk)的算法，适合处理海量数据
 *  我们可以先创建一个大小为k的小根堆存储最小的k个数字
 *  之后依次读取n个整数中的一个数。
 *  如果容器中已经有的数字少于k个，把读取的数放入容器中
 *  如果容器中数字中多于k个，
 *          如果比堆中的最大数 小，则删除堆中的最大值，并把该数插入堆中
 *          如果比堆中的最大数 大，则维持不变，读取下一个整数
 */
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
void MinTopK(const std::vector<int>& data,int k){
    std::priority_queue<int> dataK;//大根堆
    int len = data.size();
    for(int i=0;i<len;i++){
        if(dataK.size()<k){
            dataK.push(data[i]);
        }
        else{
            int MaxD = dataK.top();
            if(data[i]<MaxD){
                dataK.pop();
                dataK.push(data[i]);
            }
        }
    }
    while(!dataK.empty()){
        std::cout<<dataK.top()<<" ";
        dataK.pop();
    }
}
int main(){
    int data[] ={213,34,12,1,2,66,342,64,21,3,0};
    std::vector<int> datas(data,data+sizeof(data)/sizeof(int));
    MinTopK(datas,4);
}
