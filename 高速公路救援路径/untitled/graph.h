#ifndef GRAPH_H
#define GRAPH_H
#include "qlist.h"
#include <qfile.h>
#include <qtextstream.h>
#include <iostream>
#include<string.h>
#include <fstream>
#include "queue.h"
#include "Heap.h"
using namespace std;
const int maxvertices=70;
template<class T>
class Vertex{
    public:
    int x,y;
        int flag;
        T name;
        Vertex()
        {
            flag=-1;
            name=0;
        }
};


template <class T,class E>
class Graphmtx{
    public:
        int maxWeight;
        Graphmtx(int sz=maxvertices);
        ~Graphmtx(){delete []VerticesList; delete []Edge;}
        T getValue(int i){
            if(i>=0&&i<numV)
                return VerticesList[i].name;
            return NULL;
        }
        E getWeight(int v1,int v2){
            return (v1!=-1&&v2!=-1)?Edge[v1][v2]:0;
        }
        bool GraphEmpty(){
            if(numE==0) return true;
            else return false;
        }
        bool GraphFull(){
            if(numV==maxV||numE==maxV*(maxV-1)/2) return true;
            else return false;
        }
        int NumOfVertices(){return numV;}
        int NumOfEdge(){return numE;}
        int getFirstNeighbor1(int v);
        int getFirstNeighbor2(int v);
        int getNextNeighbor(int v,int w);
        bool insertVertex(T& vertex);
        bool insertEdge(int v1,int v2,E cost);
        bool removeVertex(int v);
        bool removeEdge(int v1,int v2);
        int* path(Graphmtx<T,E>& G,T& v);
        void start(Graphmtx<T,E>& G);
        void print(Graphmtx<T,E>& G);
        int getVertexPos(T vertex){
            for(int i=0;i<maxV;i++){
                if(VerticesList[i]==vertex) return i;
            }
            return -1;
        }
        void input0(const QString &str);
        void input1(const QString &str);
        int maxV;
        int numE;
        int numV;
        Vertex<T> *VerticesList;
        E **Edge;

};


template<class T,class E>
Graphmtx<T,E>::Graphmtx(int sz){
    maxWeight=999;
    maxV=sz;
    numV=0;
    numE=0;
    int i,j;
    VerticesList=new Vertex<T>[maxV];
    Edge=(E**)new E*[maxV];
    for(i=0;i<maxV;i++)
    {
            Edge[i]=new E[maxV];
            VerticesList[i].flag=0;
            VerticesList[i].name=0;
    }
    for(int i=0;i<maxV;i++)
        for(j=0;j<maxV;j++)
            Edge[i][j]=(i==j)?0:maxWeight;

}


template<class T,class E>
int Graphmtx<T,E>::getFirstNeighbor1(int v){					//从事发地点出发寻找第一个邻接顶点
    if(v!=-1){
        for(int col=0;col<numV;col++)
            if(Edge[v][col]>0&&Edge[v][col]<maxWeight)
                return col;
    }
    return -1;
}


template<class T,class E>
int Graphmtx<T,E>::getFirstNeighbor2(int v){					 //前期
    if(v!=-1){
        for(int col=0;col<numV;col++)
            if(Edge[col][v]>0&&Edge[col][v]<maxWeight)
                return col;
    }
    return -1;
}


template<class T,class E>
int* Graphmtx<T,E>::path(Graphmtx<T,E>& G,T& v){
    int i,w,n=G.NumOfVertices(),m=0;
    bool *visited=new bool[n];
    for(i=0;i<n;i++) visited[i]=false;
    int loc=G.getVertexPos(v);
    visited[loc]=true;
    SeqQueue<int> Q;
    Q.EnQueue(loc);
    int a[n];
    while(!Q.IsEmpty()){
        Q.DeQueue(loc);
        w=G.getFirstNeighbor2(loc);
        while(w!=-1){
            if(visited[w]==false){
                if(VerticesList[w].flag==1)
                    a[m++]=w;
                visited[w]=true;
                Q.EnQueue(w);
            }
            w=G.getNextNeighbor(loc,w);
        }
    }
    delete []visited;
}

struct Node{
    int pos;
    double dist;
    Node(int p=-1,double d=-1){
        pos=p;
        dist=d;
    }
    void insert(int p,double d){
        pos=p;dist=d;
    }
    bool operator>(Node& n){
        return dist>n.dist;
    }
    bool operator<=(Node& n){
        return dist<=n.dist;
    }
    Node* operator=(Node& n){
        dist=n.dist;
        pos=n.pos;
        return this;
    }
};



//求事故等级为flag的点v到所有点的最短路径，并将路径信息存储在path数组里返回，将路径总权值存在dist里
template<class T,class E>
int* printShortestPath(Graphmtx<T,E>& G,int v,E dist[],int path[],int flag,double& weight,int& count){
    int i,n=G.NumOfVertices();
    int *d=new int[n]{100};//存储到v的最短路径
    double min=999;int f=0;
    for(i=0;i<n;i++)
    {
        if(G.VerticesList[i].flag==flag&&dist[i]<min)
        {
            min=dist[i];
            f=i;
        }
    }
    weight=dist[f];
    count=0;while(f!=v){
        d[count]=f;
        f=path[f];
        count++;
    }

    d[count]=v;
    return d;
}


//打开文件并将点的坐标信息存在点的数组VerticesList里
template<class T,class E>
void Graphmtx<T,E>::input0(const QString &str){
    QFile aFile(str);
    if(!aFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
          cout<<"Can't open the file!"<<endl;
          exit(1);
  }
    QTextStream aStream(&aFile);
    aStream.setAutoDetectUnicode(true);
    int i=0;
    numV=0;
    QString str0="123";
    Vertex<T> t;
    while(!aStream.atEnd())
    {
      str0=aStream.readLine();
      QList<QString> ql=str0.split(" ");
      VerticesList[i].flag=ql.at(0).toInt();
      VerticesList[i].name=ql.at(1).toInt();
      VerticesList[i].x=ql.at(2).toInt();
      VerticesList[i].y=ql.at(3).toInt();
      i++;
      numV++;
    }
    aFile.close();

}

//打开文件并将点之间的路劲及权值信息存在邻接表里
template<class T,class E>
void Graphmtx<T,E>::input1(const QString &str){
    QFile aFile(str);
    if(!aFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
          cout<<"Can't open the file!"<<endl;
          exit(1);
  }
    QTextStream aStream(&aFile);
    aStream.setAutoDetectUnicode(true);
    int x,y;
    QString str0="123";
    while(!aStream.atEnd())
    {
      str0=aStream.readLine();
      QList<QString> ql=str0.split(" ");
      x=ql.at(0).toInt();
      y=ql.at(1).toInt();
      Edge[x-1][y-1]=Edge[y-1][x-1]=ql.at(2).toDouble();
    }
    aFile.close();

}


//用Djstrala算法求单元最短路径
template <class T,class E,class A>
class S{
public:

    void ShortestPath0(Graphmtx<T,E>& G,T v,E dist[],int path[],A m){
        int n=G.NumOfVertices(),u;
        bool *s=new bool[n];                                           //标记顶点是否已经寻找过
        int i,j,k,aa=n;
        E w,min;
        Node *node=new Node[n];                                        //定义结点数组，方便之后在最小堆中调整
        for(i=0;i<n;i++){                                              //初始化，初始化指定点到其它点的距离
            dist[i]=G.getWeight(v,i);
            s[i]=false;
            if(i!=v&&dist[i]<G.maxWeight) path[i]=v;
            else path[i]=-1;
            node[i].insert(i,dist[i]);                                  //把
        }
        s[v]=true; dist[v]=0;
        MinHeap<A> H(node,n);
        for(i=0;i<aa;i++){
            u=H.heap[0].pos;
            if(!s[u])
            {
                s[u]=true;
            for(k=0;k<n;k++){
                w=G.getWeight(u,k);
                if(w<G.maxWeight&&dist[u]+w<dist[k]){
                    dist[k]=dist[u]+w;
                    path[k]=u;
                    Node q(k,dist[k]);
                    H.Insert(q);
                    aa++;
                }
            }
            }
            H.Remove(H.heap[0]);
        }
    }



    void ShortestPath1(Graphmtx<T,E>& G,T v,E dist[],int path[]){
        int n=G.NumOfVertices();
        bool *s=new bool[n];
        int i,j,k;
        E w,min;
        for(i=0;i<n;i++){
            dist[i]=G.getWeight(v,i);
            s[i]=false;
            if(i!=v&&dist[i]<G.maxWeight) path[i]=v;
            else path[i]=-1;
        }
        s[v]=true; dist[v]=0;
        for(i=0;i<n;i++){
            min=G.maxWeight;int u=v;
            for(j=0;j<n;j++){
                if(s[j]==false&&dist[j]<min){
                    u=j;min=dist[j];
                }
            }
            s[u]=true;
            for(k=0;k<n;k++){
                w=G.getWeight(u,k);
                if(s[k]==false&&w<G.maxWeight&&dist[u]+w<dist[k]){
                    dist[k]=dist[u]+w;
                    path[k]=u;
                }
            }
        }
    }
};

#endif // GRAPH_H
