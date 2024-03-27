//
//  main.cpp
//  StackandQueue
//
//  Created by Atabay on 2024/3/18.
//

#include <iostream>
#include <cassert>
#define MAX 100
#define SIZE 100

using namespace std;

class Stack {
public:
    int a[MAX];
    int top;
    
    Stack(){ top = -1; }
    bool push(int x);
    int pop();
    bool isStackEmpty();
};

bool Stack::push(int x){
    if (top >= (MAX-1)) {
        cout<<"Stack Overflow"<<endl;
        return false;
    }else{
        a[++top] = x;
        cout<<x<<" pushed into stack"<<endl;
        return true;
    }
};

int Stack::pop(){
    if(top < 0){
        cout<<"Stack Underflow";
        return 0;
    }else{
        int x = a[top--];
        return x;
    }
};

bool Stack::isStackEmpty(){
    return (top < 0);
}

class Queue {
public:
    int front, rear;
    int arr[SIZE];
    
    Queue(){ front = -1; rear = -1; }
    bool enqueue(int x);
    int dequeue();
    bool isQueueEmpty();
};

bool Queue::enqueue(int x){
    if(rear == SIZE - 1){
        cout<<"Queue Overflow"<<endl;
        return false;
    }else{
        if(front == -1) front = 0;
        arr[++rear] = x;
        cout<<x<<" enqueued into queue"<<endl;
        return true;
    }
};

int Queue::dequeue(){
    if(front == -1 || front > rear){
        cout<<"Queue Underflow."<<endl;
        return 0;
    }else{
        int x = arr[front++];
        return x;
    }
};

bool Queue::isQueueEmpty(){
    if(front == -1 || front > rear){
        return true;
    }else{
        return false;
    }
};

void testStack(){
    Stack s;
    
    //Test Cases for stack
    assert(s.isStackEmpty() == true);
    s.push(1);
    assert(s.a[s.top] == 1);
    s.push(2);
    assert(s.a[s.top] == 2);
    s.push(3);
    assert(s.a[s.top] == 3);
    s.pop();
    assert(s.a[s.top] == 2);
    s.pop();
    assert(s.a[s.top] == 1);
    assert(s.isStackEmpty() == false);
    s.pop();
    assert(s.isStackEmpty() == true);
};

void testQueue(){
    Queue q;

    assert(q.isQueueEmpty() == true);
    q.enqueue(10);
    assert(q.isQueueEmpty() == false);
    int dequeuedValue = q.dequeue();
    assert(dequeuedValue == 10);
    assert(q.isQueueEmpty() == true);
    dequeuedValue = q.dequeue();
    assert(dequeuedValue == 0);
    for(int i = 0; i < SIZE; i++) {
        q.enqueue(i);
    }
    bool enqueueResult = q.enqueue(100);
    assert(enqueueResult == false);
};

int main() {
    testStack();
    cout << "All test cases for stack passed."<<endl;
    
    testQueue();
    cout << "All test cases for queue passed."<<endl;
    
    return 0;
}
