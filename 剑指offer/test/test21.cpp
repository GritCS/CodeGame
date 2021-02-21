//
// Created by doriswang on 2021/2/6.
//
/**
 *  题目:定义栈的数据结构,请在该类型中实现一个能够得到栈的最小元素的min函数
 *  在该栈中,调用min,push以及pop的时间复杂度都是O(1)
 *  注意检查栈空异常
 */
#include<iostream>
#include<stack>
template<typename T> class StackWithMin{
public:
    StackWithMin();
    ~StackWithMin();
    void push(const T& value);
    void pop();
    const T& getMin();
private:
    std::stack<T> m_data;
    std::stack<T> m_min;
};
template<typename T> StackWithMin<T>::StackWithMin(){
    m_data = std::stack<T>();
    m_min = std::stack<T>();
}

template<typename T> StackWithMin<T>::~StackWithMin(){
}
 template<typename T> void StackWithMin<T>::push(const T& value){
    if(m_data.empty()||m_data.top()>value){
        m_min.push(value);
    }else{
        m_min.push(m_min.top());
    }
    m_data.push(value);
 }

template<typename T> void StackWithMin<T>:: pop(){
    if(!m_data.empty()){
        m_data.pop();
        m_min.pop();
    }else{
        throw new std::runtime_error("stack is empty");
    }
}

template<typename T> const T& StackWithMin<T>::getMin() {
    return m_min.top();
}

int main(){
    StackWithMin<int> datas =StackWithMin<int>();
    datas.push(10);
    std::cout<<datas.getMin()<<std::endl;
    datas.push(1);
    std::cout<<datas.getMin()<<std::endl;
    datas.push(9);
    std::cout<<datas.getMin()<<std::endl;
    datas.push(8);
    datas.push(1);
    std::cout<<datas.getMin()<<std::endl;
    datas.pop();

}