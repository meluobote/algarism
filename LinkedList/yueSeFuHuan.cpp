//
// Created by meluobote on 2020/1/14.
//  约瑟夫环
//
#include <list>
#include <iostream>
using namespace std;
typedef struct people{
    int xh;
    struct people* next;
}people_t;

/*
 * 创建一个约瑟夫环，大小为n
 */
people_t* createYuesefuCircle(int n){
    people_t* head=new people_t;
    head->next= nullptr;

    people_t* lastnode=head; //最后一个节点
    for(int i=1;i<=n;i++){
        people_t* newNode=new people_t;
        newNode->xh=i;
        newNode->next= nullptr;
        lastnode->next=newNode;
        lastnode=newNode;
    }
    lastnode->next=head->next;
    return lastnode;
}
/*
 * solveYuesefu: 解决约瑟夫环的问题
 * 将xh为m的删除出去
 */
int solveYuesefu(int m, int n, people_t* head){
    if(m<=0){
        return -1;
    }

    while(n>1){
        int index=0;
        people_t* prevnode= nullptr;
        people_t* node=head;
        while(index<m){
            prevnode=node;
            node=node->next;
            index++;
        }
        prevnode->next=node->next;
        delete node;
        head=prevnode;
        n--;
    }
    return head->xh;
}
/*
 * 打印
 */
void printCircle(int n, people_t* head){
    people_t* tmpnode=head;
    for(int i=0;i<n;i++){
        tmpnode=tmpnode->next;
        cout<<tmpnode->xh<<" ";
    }
    cout<<endl;
}


int main(){
    people_t* head=createYuesefuCircle(5);
    cout<<solveYuesefu(2, 5, head)<<endl;
}

