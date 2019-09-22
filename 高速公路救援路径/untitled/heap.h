#ifndef HEAP_H
#define HEAP_H
#include <iostream>
using namespace std;
const int maxsize=250;
template <class A>
class MinHeap{
    public:
        MinHeap(int sz=maxsize);
        MinHeap(A arr[],int n);
        ~MinHeap(){delete []heap;}
        bool Insert(A& x);
        bool Remove(A& x);
        bool IsEmpty(){return (currentsize==0)?true:false;}
        bool Full(){return (currentsize==maxHeapsize)?true:false;}
        void MakeEmpty(){currentsize=0;}
        void siftDown(int start,int m);
        void siftUp(int start);
        A *heap;
        int currentsize;
        int maxHeapsize;
};

template<class A>
MinHeap<A>::MinHeap(int sz){
    maxHeapsize=(maxsize<sz)?sz:maxsize;
    heap=new A[maxHeapsize];
    if(heap==NULL){
        cout<<"堆存储分配失败！"<<endl;
        //exit(1);
    }
    currentsize=0;
}

template<class A>
MinHeap<A>::MinHeap(A arr[],int n){
    if(maxsize<n)
        maxHeapsize=n;
    else
        maxHeapsize=maxsize;
    //maxHeapsize=(maxsize<n)?n:maxsize;
    heap=new A[maxHeapsize];
    if(heap==NULL){
        cout<<"堆存储分配失败！"<<endl;
        exit(1);
    }
    for(int i=0;i<n;i++) heap[i]=arr[i];
    currentsize=n;
    int currentPos=(currentsize-2)/2;
    while(currentPos>=0){
        siftDown(currentPos,currentsize-1);
        currentPos--;
    }
}

template<class A>
void MinHeap<A>::siftDown(int start,int m){
    int i=start,j=2*i+1;
    A temp=heap[i];
    while(j<=m){
        if(j<m&&heap[j]>heap[j+1]) j++;
        if(temp<=heap[j]) break;
        else{
            heap[i]=heap[j];
            i=j;j=2*j+1;
        }
        heap[i]=temp;
    }
}

template <class A>
void MinHeap<A>::siftUp(int start){
    int j=start,i=(j-1)/2;
    A temp=heap[j];
    while(j>0){
        if(heap[i]<=temp) break;
        else{
            heap[j]=heap[i];
            j=i;
            i=(i-1)/2;
        }
    }
    heap[j]=temp;
}

template<class A>
bool MinHeap<A>::Insert(A& x){
    if(currentsize==maxHeapsize){
        cout<<"Heap Full"<<endl;
        exit(1);
    }
    heap[currentsize]=x;
    siftUp(currentsize);
    currentsize++;
    return true;
}

template<class A>
bool MinHeap<A>::Remove(A& x){
    if(!currentsize){
        cout<<"Heap Empty"<<endl;
        exit(1);
    }
    x=heap[0];
    heap[0]=heap[currentsize-1];
    currentsize--;
    siftDown(0,currentsize-1);
    return true;
}
#endif // HEAP_H
