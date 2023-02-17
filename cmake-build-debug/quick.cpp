#include <iostream>
#include <string>
#include <vector>
using namespace std;

void print(vector<int> ar){
    cout<<"[";
    for(int x=0;x<ar.size()-1;x++){
        cout<<ar[x]<<",";
    }
    cout<<ar.back()<<"]"<<endl;
}

void printsortedportion(int index){
}

int countspaces(vector<int> ve,int index){
}

int partition(vector<int>& ar,int low,int high){
    int pivot=ar[high];
    int i=low-1;
    for(int j=low;j<=high-1;j++){
        if(ar[j]<pivot){
            i++;
            int temp=ar[j];
            ar[j]=ar[i];
            ar[i]=temp;
        }
    }
    int other=ar[i+1];
    ar[i+1]=ar[high];
    ar[high]=other;
    return i+1;
}

void quick(vector<int>& ar,int low,int high){
    if(low<high){
        int pivot=partition(ar,low,high);
        quick(ar,low,pivot-1);
        quick(ar,pivot+1,high);
    }
}

int main(){
    //vector<int> list={999,104,2,1024,16};
    vector<int> list={8,2,5,6,4,3,7,1};
    cout<<"Quick Sort"<<endl;
    cout<<"Original Array: ";
    print(list);
    quick(list,0,list.size()-1);
    cout<<"Final Sorted Array: ";
    print(list);
    return 0;
}