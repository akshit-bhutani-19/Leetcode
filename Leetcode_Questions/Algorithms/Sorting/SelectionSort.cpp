#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> SelectionSort(vector<int> v){
    int pointer=0;
    int min=v[0];
    int temp;
    int n=v.size();
    for(int i=0; i<n-1; i++){
        min=v[i];
        pointer=i;
        for(int j=i;j<n;j++){
            if(v[j]<min){
                min = v[j];
                pointer=j; 
            }
        }
        temp=v[i];
        v[i]=v[pointer];
        v[pointer]=temp;
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
    vector<int> v2 = SelectionSort(v);
    PrintVector(v2);
}