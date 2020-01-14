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
 * head无数据
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
/*
 * head无数据
 */
void printList(cl_t* head){
    while(head->next){
        cout<<head->next->c;
        head=head->next;
    }
    cout<<endl;
}
/*
 * head无数据
 */
void deleteList(cl_t* head){
    cl_t* tmp=nullptr;
    while(head){
        tmp=head->next;
        delete head;
        head=tmp;
    }
}

/*
 * 从当前节点开始翻转
 * 返回翻转后的头结点
 */
cl_t* reverseList(cl_t* node){
    if(node== nullptr||node->next== nullptr){
        return node;
    }

    cl_t* firstNode=node;
    cl_t* endNode=node;
    cl_t* nextNode=node->next;

    while(nextNode){
        cl_t* nextNextNode=endNode->next->next;
        nextNode->next=firstNode;
        endNode->next=nextNextNode;
        firstNode=nextNode;
        nextNode=endNode->next;
    }

    return firstNode;
}
/*
 * head无数据
 * 通过求链表长度找到linknode节点
 *      linknode: 右半部分节点的左边的哪个节点，可能是奇数节点下中间的那个节点，也可能是偶数节点下左半部分节点最后的那个节点
 */
bool isPalindrom1(cl_t* head){
    if(head->next== nullptr ||(head->next!= nullptr && head->next->next== nullptr)){
        return true;
    }

    bool ret=true;
    int dataLen=0;
    cl_t* node=head->next;
    while(node){
        dataLen++;
        node=node->next;
    }

    cl_t* leftNode=head->next;
    cl_t* rightNode= nullptr;

    cl_t* leftEnd=head;
    cl_t* linkNode= nullptr;

    //先找到左半部分的末尾位置
    for(int i=0;i<dataLen/2;i++){
        leftEnd=leftEnd->next;
    }

    if(dataLen%2==0){
        linkNode=leftEnd;
    }else{
        linkNode=leftEnd->next;

    }
    //将右半部分翻转
    rightNode=reverseList(linkNode->next);
    linkNode->next=rightNode;

    //左右部分对比
    for(int i=0;i<dataLen/2;i++){
        if(leftNode->c!=rightNode->c){
            ret=false;
            break;
        }
        leftNode=leftNode->next;
        rightNode=rightNode->next;
    }
    //将右半部分恢复
    linkNode->next=reverseList(linkNode->next);
    return ret;
}

/*
 * head无数据
 * 通过快慢节点找到linkNode
 *      linknode: 右半部分节点的左边的哪个节点，可能是奇数节点下中间的那个节点，也可能是偶数节点下左半部分节点最后的那个节点
 */
bool isPalindrom2(cl_t* head){
    if(head->next== nullptr ||(head->next!= nullptr && head->next->next== nullptr)){
        return true;
    }

    bool ret=true;
    cl_t* leftNode=head->next;
    cl_t* rightNode= nullptr;
    cl_t* linkNode= nullptr;

    cl_t* fastnode=head;
    cl_t* slownode=head;
    while(fastnode->next && fastnode->next->next){
        fastnode=fastnode->next->next;
        slownode=slownode->next;
    }
    if(fastnode->next){
        //奇数个节点
        linkNode=slownode->next;
    }else{
        //偶数个节点
        linkNode=slownode;
    }

    //将右半部分翻转
    rightNode=reverseList(linkNode->next);
    linkNode->next=rightNode;

    //左右部分对比
    while(rightNode){
        if(leftNode->c!=rightNode->c){
            ret=false;
            break;
        }
        leftNode=leftNode->next;
        rightNode=rightNode->next;
    }
    //将右半部分恢复
    linkNode->next=reverseList(linkNode->next);
    return ret;
}

int main(){
    cl_t* listHead=createListFromString("acba");
    printList(listHead);
//    cout << "is_palidrom1: " << isPalindrom1(listHead) << endl;
    cout << "is_palidrom2: " << isPalindrom2(listHead) << endl;
    printList(listHead);
    return 0;
}