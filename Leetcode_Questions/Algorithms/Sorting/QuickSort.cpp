#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void PrintVector(vector<int> v){
    for (auto it:v){
        cout << it << " ";
    }
}


void quick_sort(vector<int> &v, int low, int high){
    cout << low << high<< endl;
    if(low>=high){
        return;
    }
    int pivot= low;
    int i = low;
    int j = high;
    int temp;
    while(i<j){
        while(v[i]<=v[pivot] && i<high){
            i++;
        }
        while(v[j]>v[pivot] && j>low){
            j--;
        }
        if(i<j){
            temp=v[i];
            v[i]=v[j];
            v[j]=temp;
        }
        else{
            break;
        }
    }
    temp=v[pivot];
    v[pivot]=v[j];
    v[j]=temp;

    quick_sort(v,low,j-1);
    quick_sort(v,j+1,high);
    // PrintVector(v);
    // cout << endl;
    return;
}

vector<int> QuickSort(vector<int> v){
    quick_sort(v,0,v.size()-1);
    return v;
}




int main(){
    vector<int> v = {2,4,7,1,23,54,2,34,76,4,34,1,34,65,63};
    vector<int> v2 = QuickSort(v);
    PrintVector(v2);
}