/*
 * 描述: 包含冒泡、选择、插入排序
 *      1） 稳定性：冒泡排序和插入排序都是稳定的排序算法， 但是选择排序不是（原因：
 *      选择排序是从未排序区间找到最小的元素然后放到已排序区间的末尾。比如：5,5,2,8,3;  第一次2和5交换时会把两个5的顺序交换）
 *      2） 是否是原地排序算法： 都是
 * 作者：meluobote
 * 日期: 2020/3/27
 */
#include <vector>
#include <iostream>
using namespace std;
// 冒泡排序
void maopao(vector<int>& v){
    int size=v.size();
    for(int i=size-1;i>0;i--){
        for(int j=0;j<i;j++){
            if(v[j]>v[j+1]){
                v[j]=v[j]^v[j+1];
                v[j+1]=v[j]^v[j+1];
                v[j]=v[j]^v[j+1];
            }
        }
    }
}
// 插入排序
void insertSort(vector<int>& v){
    for(int i=1;i<v.size();i++){
        int j=i-1;
        int tmp=v[i];
        while(j>=0&&tmp<v[j]){
            v[j+1]=v[j];
            j--;
        }
        v[j+1]=tmp;
    }
}

//选择排序
void selectSort(vector<int>& v){
    int minIdx{};
    for(int i=0;i<v.size()-1;i++){
        minIdx=i;
        for(int j=i+1;j<v.size();j++){
            if(v[j]<v[minIdx]){
                minIdx=j;
            }
        }
        if(minIdx!=i){
            v[i]=v[i]^v[minIdx];
            v[minIdx]=v[i]^v[minIdx];
            v[i]=v[i]^v[minIdx];
        }
    }
}
void print(vector<int>& v){
    for(auto e:v){
        cout<<e<<" ";
    }
    cout<<endl;
}
int main() {
    vector<int> v{3,2,1,5,6,4};
//    maopao(v);
//    insertSort(v);
    selectSort(v);
    print(v);

}