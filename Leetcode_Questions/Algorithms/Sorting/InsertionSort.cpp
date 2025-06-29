#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void PrintVector(vector<int> v){
    for (auto it:v){
        cout << it << " ";
    }
    cout << endl;
}

vector<int> InsertionSort(vector<int> v){
    int temp,temp2;
    bool to_sort = false;
    int i,j;
    for(i=1; i<v.size(); i++){
        to_sort=false;
        for(j=0;j<i;j++){
            if(v[j]>v[i]){
                cout << i << " " << j << endl;
                temp=v[j];
                v[j]=v[i];
                j++;
                to_sort=true;
                break;
            }
        }
        if (to_sort){
            while(j<=i){
                temp2=v[j];
                v[j]=temp;
                temp=temp2;
                j++;
            }
        }
        PrintVector(v);

    }
    return v;
}



int main(){
    vector<int> v = {23,54,2,34,76,4,34,1,34,65,63,12,32,1,99,100,101};
    vector<int> v2 = InsertionSort(v);
    PrintVector(v2);
}