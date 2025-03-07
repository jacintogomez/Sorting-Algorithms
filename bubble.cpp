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

int counttotalspaces(vector<int> ve){
    int count=0;
    for(int i=0;i<ve.size();i++){
        string element=to_string(ve[i]);
        count+=element.size();
    }
    count+=ve.size()-1+2;//-1 because there will be 1 less comma than elements, +2 for the 2 brackets
    return count;
}

int countspaces(vector<int> ve,int index){
    int count=0;
    for(int i=0;i<=index-1;i++){
        string element=to_string(ve[i]);
        count+=element.size();
    }
    count+=index+1;
    return count;
}

void printsortedportion(int index,vector<int> ve){
    int totalchars=counttotalspaces(ve);
    int spacestoindex=countspaces(ve,index);
    int sortedduration=totalchars-spacestoindex;
    for(int i=1;i<spacestoindex;i++){
        cout<<" ";
    }
    cout<<"|";
    for(int i=1;i<sortedduration;i++){
        cout<<"_";
    }
    cout<<"| <-sorted portion... ";
}

void bubble(vector<int>& ar){
    for(int i=ar.size()-1;i>=0;i--){
        bool swap=false;
        for(int j=0;j<i;j++) {
            if(ar[j]>ar[j+1]){
                int temp=ar[j+1];
                ar[j+1]=ar[j];
                ar[j]=temp;
                swap=true;
            }
        }
        print(ar);
        printsortedportion(i,ar);
        if(swap) {
            cout << " " << ar[i] << " was the next largest, and was 'bubbled' up to the end" << endl;
        }else{
            cout<<" next largest element "<<ar[i]<<" is already in sorted position"<<endl;
        }
    }
}

int main(){
    //vector<int> list={999,104,2,1024,16};
    vector<int> list={9,88,2000,100,43,546,2,32};
    cout<<"Bubble Sort"<<endl;
    cout<<"Original Array: ";
    print(list);
    bubble(list);
    cout<<"Final Sorted Array: ";
    print(list);
    return 0;
}