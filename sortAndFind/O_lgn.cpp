/*
 * 描述: 这个文件中记录的是时间复杂度在n*lgn的。   快速排序、归并排序
 *  1)快速排序: 原地排序，但不稳定
 *  2) 利用快排思想找到第k大的元素
 *  3）归并排序：非原地排序，但稳定
 *  1、为什么归并排序没有受到宠信？
 *  时间复杂度是 O(nlogn) 的排序算法不止一个，我们已经讲过的有归并排序、快速排序，后面讲堆的时候我们还会讲到堆排序。
 *  堆排序和快速排序都有比较多的应用，比如 Java 语言采用堆排序实现排序函数，C 语言使用快速排序实现排序函数
 *  归并排序并不是原地排序算法，空间复杂度是 O(n)。所以，粗略点、夸张点讲，如果要排序 100MB 的数据，
 *  除了数据本身占用的内存之外，排序算法还要额外再占用 100MB 的内存空间，空间耗费就翻倍了。
 * 作者：meluobote
 * 日期: 2020/3/27
 */
#include <vector>
#include <iostream>
using namespace std;

// 快速排序
void quickSort(vector<int>& v, int start, int end){
    if(start>=end){
        return;
    }
    int target=v[start];
    int i=start;
    int j=end;
    while(i<j){
        while(i<j&&v[j]>=target) j--;
        if(i<j){
            v[i]=v[j];
            i++;
        }
        while(i<j&&v[i]<=target) i++;
        if(i<j){
            v[j]=v[i];
            j--;
        }
    }
    v[i]=target;
    quickSort(v, start, i-1);
    quickSort(v, i+1, end);
}
//快排思想找到第K大的元素
int kLargestElement(vector<int>& v, int start, int end, int k){
    if(start==end){
        if(start==(v.size()-k)){
            return v[start];
        }else{
            return -1;
        }
    }
    int target=v[start];
    int i=start;
    int j=end;
    while(i<j){
        while(i<j&&v[j]>=target) j--;
        if(i<j){
            v[i]=v[j];

            i++;
        }
        while(i<j&&v[i]<=target) i++;
        if(i<j){
            v[j]=v[i];
            j--;
        }
    }
    v[i]=target;
    if(i==(v.size()-k)){
        return v[i];
    }else if(i<(v.size()-k)){
        return kLargestElement(v, i+1, end, k);
    }else{
        return kLargestElement(v, start, i-1, k);
    }
//    return -1;
}

// 归并排序
void guibingSort(vector<int>& v, int start, int end){
    if(start=end){
        return;
    }
    int mid=start+(end-start)/2;
    guibingSort(v, start, mid);
    guibingSort(v, mid+1, end);

    vector<int> v1(v.begin()+start, v.begin()+mid+1);
    vector<int> v2(v.begin()+mid+1, v.begin()+end+1);
    //将两个有序数组合并
    int i=0;
    int j=0;
    for(int k=start;k<=end;k++){
        if(i>=v1.size()){
            v[k]=v2[j++];
        }else if(j>=v2.size()){
            v[k]=v1[i++];
        }else{
            if(v1[i]<=v2[j]){
                v[k]=v1[i++];
            }else{
                v[k]=v2[j++];
            }
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
//    quickSort(v, 0, v.size()-1);
//    guibingSort(v, 0, v.size()-1);
//    print(v);
    cout<<"第3大的元素为: "<<kLargestElement(v,0,v.size()-1,3);
}