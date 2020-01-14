//
// Created by meluobote on 2020/1/14.
// 判断用单链表存储的字符串是否是回文的
//
#include<iostream>
#include<string>
using namespace std;

typedef struct CharList{
    char c;
    struct CharList* next;
}cl_t;

/*
 * 说明创建的头结点不存储数据
 */
cl_t* createListFromString(string s){
    cl_t* head=new cl_t;
    head->c=0;
    head->next= nullptr;

    for(auto c: s){
        cl_t* tmp= nullptr;
        tmp=new cl_t;
        tmp->c=c;
        tmp->next=head->next;
        head->next=tmp;
    }
    return head;
}

void printList(cl_t* head){
    while(head->next){
        cout<<head->next->c;
        head=head->next;
    }
}

void deleteList(cl_t* head){
    cl_t* tmp=nullptr;
    while(head){
        tmp=head->next;
        delete head;
        head=tmp;
    }
}

bool is_palindrom(cl_t* head){

}

int main(){
    cl_t* listHead=createListFromString("abcdef");
    printList(listHead);

    deleteList(listHead);
    return 0;
}