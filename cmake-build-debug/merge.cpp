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

void printsortedportion(int blanks,int range){
    for(int i=0;i<blanks;i++){
        cout<<" ";
    }
    cout<<"|";
    for(int i=0;i<range;i++){
        cout<<"_";
    }
    cout<<"| <-segment just sorted... ";
}

int countspaces(vector<int> ve,int index){
    int count=0;
    for(int i=0;i<index;i++){
        string element=to_string(ve[i]);
        count+=element.size();
    }
    count+=index;
    return count;
}

int countmiddleunderscores(vector<int> ve,int start,int end){
    int count=0;
    for(int i=start;i<=end;i++){
        string element=to_string(ve[i]);
        count+=element.size();
    }
    count+=end-start;
    return count;
}

void mergesort(vector<int>& ar,int left,int mid,int right){
    vector<int> half1= {};
    vector<int> half2= {};
    int half1length=mid-left+1;
    int half2length=right-mid;
    for(int i=0;i<half1length;i++){half1.push_back(ar[left+i]);}
    for(int i=0;i<half2length;i++){half2.push_back(ar[mid+i+1]);}
    int i=0;
    int j=0;
    int k=left;
    while(i<half1length&&j<half2length){
        if(half1[i]<=half2[j]){
            ar[k]=half1[i];
            i++;
        }else{
            ar[k]=half2[j];
            j++;
        }
        k++;
    }
    while(i<half1length){
        ar[k]=half1[i];
        i++;
        k++;
    }
    while(j<half2length){
        ar[k]=half2[j];
        j++;
        k++;
    }
}

void merge(vector<int>& ar,int begin,int end,int step){
    if(begin>=end){return;}
    int mid=begin+(end-begin)/2;
    merge(ar,begin,mid,step+1);
    merge(ar,mid+1,end,step+1);
    mergesort(ar,begin,mid,end);
    print(ar);
    printsortedportion(countspaces(ar,begin),countmiddleunderscores(ar,begin,end));
    cout<<" this call is "<<step<<" level(s) deep"<<endl;
    //cout<<" begin "<<begin<<" mid "<<mid<<" end "<<end<<endl;
}

int main(){
    vector<int> list={999,104,2,1024,16};
    //vector<int> list={8,7,6,5,4,3,2,1};
    cout<<"Original Array: ";
    print(list);
    merge(list,0,list.size()-1,0);
    cout<<"Final Sorted Array: ";
    print(list);
    return 0;
}