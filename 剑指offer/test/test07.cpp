//
// Created by doriswang on 2021/2/2.
//
/**
 * 题目：用两个栈实现一个队列，队列的声明如下，请实现他的两个函数appendTail和deleteHead,
 * 分别完成在队列尾部插入结点和在队列头部删除结点的功能(先进先出）
 *  向stack1中插入结点
 *  从stack2中删除结点，如果stack1为空，则从stack1 pop相应的元素
 */
#include<iostream>
#include<stack>
template <typename T> class CQueue{
public:
        CQueue(void);
        ~CQueue(void);

        void appendTail(const T& node);
        T deleteHead();
private:
    std::stack<T> stack1;
    std::stack<T> stack2;
};

template<typename T> CQueue<T>::CQueue(void ) {
    stack1=std::stack<T>();
    stack2=std::stack<T>();
}
template<typename T> CQueue<T>::~CQueue(void){
}
template<typename T> void CQueue<T>::appendTail(const T &node) {
    stack1.push(node);
}

template<typename T> T CQueue<T>::deleteHead(){
    if(stack2.empty()){
        if(stack1.empty()){
            throw "queue is empty";
        }

        while(!stack1.empty()) {
            stack2.push(stack1.top());
            stack1.pop();//stack1栈顶的元素是最先插入元素
        }
    }
    T node = stack2.top();
    stack2.pop();
    return node;
}
int main(){
    CQueue<int> nodes = CQueue<int>();
    nodes.appendTail(2);
    nodes.appendTail(3);
    nodes.appendTail(4);
    std::cout<<nodes.deleteHead()<<std::endl;
    std::cout<<nodes.deleteHead()<<std::endl;
//    std::cout<<nodes.deleteHead();

}