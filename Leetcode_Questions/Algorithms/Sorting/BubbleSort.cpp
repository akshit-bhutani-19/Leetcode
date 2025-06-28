#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> BubbleSort(vector<int> v){
    int temp;
    int n= v.size();
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(v[j]>v[j+1]){
                temp=v[j];
                v[j]=v[j+1];
                v[j+1]=temp;
            }
        }
    }
    return v;
}

void PrintVector(vector<int> v){
    for (auto it:v){
        cout << it << " ";
    }
}

int main(){
    vector<int> v = {2,4,7,1,23,54,2,34,76,4,34,1,34,65,63};
    vector<int> v2 = BubbleSort(v);
    PrintVector(v2);
}