/*
 * ����: ����ļ��м�¼����ʱ�临�Ӷ���n*lgn�ġ�   �������򡢹鲢����
 *  1)��������: ԭ�����򣬵����ȶ�
 *  2) ���ÿ���˼���ҵ���k���Ԫ��
 *  3���鲢���򣺷�ԭ�����򣬵��ȶ�
 *  1��Ϊʲô�鲢����û���ܵ����ţ�
 *  ʱ�临�Ӷ��� O(nlogn) �������㷨��ֹһ���������Ѿ��������й鲢���򡢿������򣬺��潲�ѵ�ʱ�����ǻ��ὲ��������
 *  ������Ϳ��������бȽ϶��Ӧ�ã����� Java ���Բ��ö�����ʵ����������C ����ʹ�ÿ�������ʵ��������
 *  �鲢���򲢲���ԭ�������㷨���ռ临�Ӷ��� O(n)�����ԣ����Ե㡢���ŵ㽲�����Ҫ���� 100MB �����ݣ�
 *  �������ݱ���ռ�õ��ڴ�֮�⣬�����㷨��Ҫ������ռ�� 100MB ���ڴ�ռ䣬�ռ�ķѾͷ����ˡ�
 * ���ߣ�meluobote
 * ����: 2020/3/27
 */
#include <vector>
#include <iostream>
using namespace std;

// ��������
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
//����˼���ҵ���K���Ԫ��
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

// �鲢����
void guibingSort(vector<int>& v, int start, int end){
    if(start=end){
        return;
    }
    int mid=start+(end-start)/2;
    guibingSort(v, start, mid);
    guibingSort(v, mid+1, end);

    vector<int> v1(v.begin()+start, v.begin()+mid+1);
    vector<int> v2(v.begin()+mid+1, v.begin()+end+1);
    //��������������ϲ�
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
    cout<<"��3���Ԫ��Ϊ: "<<kLargestElement(v,0,v.size()-1,3);
}