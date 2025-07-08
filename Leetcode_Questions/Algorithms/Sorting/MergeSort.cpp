#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void PrintVector(vector<int> v){
    for (auto it:v){
        cout << it << " ";
    }
}

void merge(vector<int>& v, int low, int mid, int high){
    vector<int> temp;
    int left=low;
    int right = mid+1;
    while(left<=mid && right<=high){
        if(v[left]<=v[right]){
            temp.push_back(v[left]);
            left++;
        }
        else{
            temp.push_back(v[right]);
            right++;
        }
    }
    while(left<=mid){
        temp.push_back(v[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(v[right]);
        right++;
    }
    for(int i=low; i<=high; i++){
        v[i]=temp[i-low];
    }
    
    // PrintVector(temp);
    cout << endl;
    return;
}

void merge_sort(vector<int>& v, int low, int high){
    if (low>=high){
        return;
    }
    int mid = (low+high)/2;
    cout << low << mid << high << endl;
    merge_sort(v,low,mid);
    merge_sort(v,mid+1,high);
    merge(v,low,mid,high);
}

vector<int> MergeSort(vector<int> v){
    merge_sort(v, 0, v.size()-1);
    return v;
}





int main(){
    vector<int> v = {2,4,7,1,23,54,2,34,76,4,34,1,34,65,63};
    vector<int> v2 = MergeSort(v);
    PrintVector(v2);
}