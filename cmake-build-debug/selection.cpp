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
    cout<<"|";
    for(int i=0;i<index;i++){
        cout<<"_";
    }
    cout<<"| <-sorted portion... ";
}

int countspaces(vector<int> ve,int index){
    int count=0;
    for(int i=0;i<=index;i++){
        string element=to_string(ve[i]);
        count+=element.size();
    }
    count+=index;
    return count;
}

void selection(vector<int>& ar){
    for(int i=0;i<ar.size();i++){
        int min=i;
        for(int j=i+1;j<ar.size();j++){
            if(ar[min]>ar[j]){
                min=j;
            }
        }
        if(min!=i){
            int temp=ar[min];
            ar[min]=ar[i];
            ar[i]=temp;
        }
        print(ar);
        printsortedportion(countspaces(ar,i));
        if(ar[min]!=ar[i]){
            cout<<" the next minimum selected was "<<ar[i]<<" and was swapped with "<<ar[min]<<endl;
        }else{
            cout<<" "<<ar[min]<<" was the next smallest, so no swap occurred"<<endl;
        }
    }
}

int main(){
    vector<int> list={9,88,2000,100,43,546,2,32};
    //vector<int> list={5,4,3,2,1};
    cout<<"Selection Sort"<<endl;
    cout<<"Original Array: ";
    print(list);
    selection(list);
    cout<<"Final Sorted Array: ";
    print(list);
    return 0;
}