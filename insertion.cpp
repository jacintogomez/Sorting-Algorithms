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

void insertion(vector<int>& ar){
    for(int i=1;i<ar.size();i++){
        int key=ar[i];
        int j=i-1;
        while(j>=0&&ar[j]>key){
            ar[j+1]=ar[j];
            j--;
        }
        int temp=ar[j+1];
        ar[j+1]=key;
        print(ar);
        printsortedportion(countspaces(ar,i));
        if(key!=temp) {
            cout << key << " was inserted before " << temp << endl;
        }else{
            cout<<"no insertions were necessary"<<endl;
        }
    }
}

int main(){
    vector<int> list={9,88,2000,100,43,546,2,32};
    //vector<int> list={5,4,3,2,1};
    cout<<"Insertion Sort"<<endl;
    cout<<"Original Array: ";
    print(list);
    insertion(list);
    cout<<"Final Sorted Array: ";
    print(list);
    return 0;
}