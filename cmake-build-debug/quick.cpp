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

void insertion(vector<int> ar){
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
            cout << key << " was placed before " << temp << endl;
        }else{
            cout<<"no substitutions were necessary"<<endl;
        }
    }
    cout<<"Final Sorted Array: ";
    print(ar);
}

int main(){
    vector<int> list={999,104,2,1024,16};
    //vector<int> list={5,4,3,2,1};
    cout<<"Original Array: ";
    print(list);
    insertion(list);
    return 0;
}