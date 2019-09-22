#ifndef QUEUE_H
#define QUEUE_H

#include <assert.h>
#include <iostream>
#include <iomanip>
using namespace std;
template <class T>
class SeqQueue{
    public:
        SeqQueue(int sz=10);
        ~SeqQueue(){
            delete[] elements;
        }
        bool EnQueue(T& x);
        bool DeQueue(T& x);
        bool getFront(T& x);
        void makeEmpty(){front=rear=0;}
        bool IsEmpty() const{
            return (front==rear)?true:false;
        }
        bool IsFull() const{
            return ((rear+1)%maxsize==front)?true:false;
        }
        int getSize() const{return (rear-front+maxsize)%maxsize;}
    protected:
        int rear,front;
        T *elements;
        int maxsize;
};


template <class T>
SeqQueue<T>::SeqQueue(int sz)
{
    front=0;
    rear=0;
    maxsize=sz;
    elements=new T[maxsize];
}


template<class T>
bool SeqQueue<T>::EnQueue(T& x){
    if(IsFull()==true) return false;
    elements[rear]=x;
    rear=(rear+1)%maxsize;
    return true;
}


template <class T>
bool SeqQueue<T>::DeQueue(T& x){
    if(IsEmpty()==true) return false;
    x=elements[front];
    front=(front+1)%maxsize;
    return true;
}



template<class T>
bool SeqQueue<T>::getFront(T& x){
    if(IsEmpty()==true) return false;
    x=elements[front];
    return false;
}
#endif // QUEUE_H
