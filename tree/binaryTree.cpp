/*
 * 描述: 二叉树按层遍历实现（1） 队列实现
 * 作者：meluobote
 * 日期: 2020/4/1
 */
/*
 * 简单的树结构定义（数据存储不是void*类型， 也不能自定义比较方式）
 */
typedef struct Node{
    int data;
    struct Tree* left;
    struct Tree* right;
}node_t;
//给树添加元素
void addNodde(node_t* root, int val){

}
//用vector创建一颗树
void createTree(vector<int> v){
    struct Node* root= nullptr;

}