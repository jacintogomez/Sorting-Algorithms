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

void heapify(vector<int>& ar,int n,int parent){
    int max=parent;
    int left=2*parent+1;
    int right=2*parent+2;
    if(left<n&&ar[left]>ar[max]){max=left;}
    if(right<n&&ar[right]>ar[max]){max=right;}
    if(max!=parent){
        int temp=ar[parent];
        ar[parent]=ar[max];
        ar[max]=temp;
        heapify(ar,n,max);
    }
}

void heap(vector<int>& ar){
    int n=ar.size();
    for(int i=n/2-1;i>=0;i--){heapify(ar,n,i);}
    for(int j=n-1;j>=0;j--){
        int temp=ar[0];
        ar[0]=ar[j];
        ar[j]=temp;
        heapify(ar,j,0);
        print(ar);
        printsortedportion(j,ar);
        cout<<" the max element "<<ar[j]<<" was pushed to the root of the heap and then removed"<<endl;
    }
}

int main(){
    //vector<int> list={999,104,2,1024,16};
    vector<int> list={8,2,5,6,4,3,7,1};
    //vector<int> list={9,88,2000,100,43,546,2,32};
    cout<<"Heap Sort"<<endl;
    cout<<"Original Array: ";
    print(list);
    heap(list);
    cout<<"Final Sorted Array: ";
    print(list);
    return 0;
}