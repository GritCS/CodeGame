//
// Created by doriswang on 2021/2/13.
//
#include<iostream>

#include<vector>
#include<algorithm>

void print(const int& temp){
    std::cout<< temp<<" ";
}
bool cmp(int a,int b){
    return (a>b);//升序排列
}
int main(){
    int nums[] = {34,1,89,0,3,5,11};
    std::vector<int> ptr = std::vector<int>(nums,nums+sizeof(nums)/sizeof(int));
    //遍历方法
    std::for_each(ptr.begin(),ptr.end(),print);

    //sort两个参数
    std::sort(ptr.begin(),ptr.end(),cmp);
    std::cout<<std::endl;
    std::for_each(ptr.begin(),ptr.end(),print);
}
