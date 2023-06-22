#include <iostream>
#include <string>
#include <vector>
#include <random>
using namespace std;

void print(vector<int> ar){
    cout<<"[";
    for(int x=0;x<ar.size()-1;x++){
        cout<<ar[x]<<",";
    }
    cout<<ar.back()<<"]"<<endl;
}

void printsameline(vector<int> ar){
    cout<<"[";
    for(int x=0;x<ar.size()-1;x++){
        cout<<ar[x]<<",";
    }
    cout<<ar.back()<<"]";
}

bool issorted(vector<int> ar){
    for(int x=0;x<ar.size()-2;x++){
        if(ar[x]>ar[x+1]){return false;}
    }
    return true;
}

void shuff(vector<int>& ar,int it){
    //int n=ar.size();
    random_device gen;
    mt19937 rng(gen());
    shuffle(ar.begin(),ar.end(),rng);
    printsameline(ar);
    cout<<"<--- Attempt "<<it<<endl;
}

void bogo(vector<int> ar,bool& result){
    int iteration=1;
    while(!issorted(ar)&&iteration<=100){
        shuff(ar,iteration);
        iteration++;
    }
    if(iteration<=100){return;}
    result=true;
}

int main(){
    //vector<int> list={9,88,2000,100,43,546,2,32};
    vector<int> list={8,1,6};
    bool result=false;
    cout<<"Bogo Sort"<<endl;
    cout<<"Original Array: ";
    print(list);
    bogo(list,result);
    if(result){
        cout<<"Final Sorted Array: ";
        print(list);
    }else{
        cout<<"Stopped after 100 iterations, was not sorted :(";
    }
    return 0;
}