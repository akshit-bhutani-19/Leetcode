#include<bits/stdc++.h>
using namespace std;

void print(vector<int> v){
    for(int i=0;i<v.size();i++){
        cout << v[i] << endl;
    }
    return;
}

void take_input(vector<int> v, int n){
    int input_val;
    for(int i=0; i<n; i++){
        cout << "Enter " << i << " value : ";
        cin >> input_val;
        v.emplace_back(input_val); 
    }
    print(v);
    return;
}

void create_vector_trial(){
    vector<int> v3(5);                    //Create vector of size 5 with all 0s or garbage value depending on compiler
    print(v3);
    cout << endl;
    
    vector<int> v4(5,10);                //Size 5 with all values 10
    print(v4);
    cout << endl;

    vector<int> v5(v3);                   //Copies v3 into new vector v5
    print(v5);

    return;
}


int main(){
    vector<int> v1 = {1,2,3,4,5};
    vector<int> v2;

    // print(v1);                             //print all elements in vector

    // create_vector_trial();

    // take_input(v2, 3);

    return 0;
}