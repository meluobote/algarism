#include <iostream>
#include <vector>
#include <set>
#include <climits>
#include <cmath>
#include <map>
#include <algorithm>
using namespace std;

vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
    vector<int> rev(1001,0);
    vector<int>res(arr1.size());
    vector<int> notInvec;

    for(int i=0;i<arr1.size();i++){
        if(find(arr2.begin(), arr2.end(), arr1[i])!=arr2.end()){
            rev[arr1[i]]++;
        }else{
            notInvec.push_back(arr1[i]);
        }
    }
    int idx=0;
    for(int i=0;i<arr2.size();i++){
        int n=rev[arr2[i]];
        int j=0;
        while(j<n){
            res[idx++]=arr2[i];
            j++;
        }
    }

    sort(notInvec.begin(), notInvec.end());
    int tmp=arr1.size()-1;
    for(int i=notInvec.size()-1;i>=0;i--){
        res[tmp]=notInvec[i];
        tmp--;
    }
    return res;
}

int main() {
    vector<int> arr1{2,3,1,3,2,4,6,7,9,2,19};
    vector<int> arr2{2,1,4,3,9,6};
    vector<int> res=relativeSortArray(arr1, arr2);
    for(auto e:res){
        cout<<e<<" ";
    }
    cout<<endl;
}