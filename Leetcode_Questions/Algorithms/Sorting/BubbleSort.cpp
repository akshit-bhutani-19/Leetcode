#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void PrintVector(vector<int> v){
    for (auto it:v){
        cout << it << " ";
    }
}

vector<int> BubbleSort(vector<int> v){
    int temp;
    int n= v.size();
    bool notSwap= true;
    for(int i=0;i<n-1;i++){
        notSwap=true;
        for(int j=0;j<n-i-1;j++){
            if(v[j]>v[j+1]){
                temp=v[j];
                v[j]=v[j+1];
                v[j+1]=temp;
                notSwap=false;
            }
            PrintVector(v);
            cout << endl;
        }
        if (notSwap){
            break;
        }
        cout << endl;
    }
    return v;
}


int main(){
    vector<int> v = {23,54,2,34,76,4,34,1,34,65,63,12,32,1,99,100,101};
    vector<int> v2 = BubbleSort(v);
    PrintVector(v2);
}