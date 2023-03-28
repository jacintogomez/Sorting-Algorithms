#include <iostream>
#include <string>
#include <vector>
using namespace std;

void print(vector<int> ar){
    if(ar.size()==0){
        cout<<"[]"<<endl;
        return;
    }
    cout<<"[";
    for(int x=0;x<ar.size()-1;x++){
        cout<<ar[x]<<",";
    }
    cout<<ar.back()<<"]"<<endl;
}

void printsameline(vector<int> ar){
    cout<<"[";
    if(ar.size()==0){
        cout<<"[]";
        return;
    }
    for(int x=0;x<ar.size()-1;x++){
        cout<<ar[x]<<",";
    }
    cout<<ar.back()<<"]";
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

void insertionwithoutmessages(vector<int>& ar){
    for(int i=1;i<ar.size();i++){
        int key=ar[i];
        int j=i-1;
        while(j>=0&&ar[j]>key){
            ar[j+1]=ar[j];
            j--;
        }
        ar[j+1]=key;
    }
}

int getmax(vector<int> ar){
    int mx=ar[0];
    for(int i:ar){
        if(i>mx){
            mx=i;
        }
    }
    return mx;
}

int getmin(vector<int> ar){
    int mn=ar[0];
    for(int i:ar){
        if(i<mn){
            mn=i;
        }
    }
    return mn;
}

void bucket(vector<int>& ar){
    double max=getmax(ar);
    double min=getmin(ar);
    int buckets;
    cout<<"If you want to choose your number of buckets then enter it below,"
          "\notherwise enter 0 to use the square root of n"<<endl;
    cout<<"Number of buckets: ";
    cin>>buckets;
    while(buckets<0){
        cout<<"Bucket number must be positive!"<<endl;
        cout<<"Re-enter the number of buckets: ";
        cin>>buckets;
    }
    if(buckets==0){
        buckets=int(pow(ar.size(),0.5));
    }
    double rnge=double((max-min)/buckets);
    vector<vector<int>> all;
    for(int x=0;x<buckets;x++){
        all.push_back(vector<int>());
    }
    for(int i=0;i<ar.size();i++){
        double diff=(ar[i]-min)/rnge-int((ar[i]-min)/rnge);
        if(diff==0&&ar[i]!=min){
            all[int((ar[i]-min)/rnge)-1].push_back(ar[i]);
        }else{
            all[int((ar[i]-min)/rnge)].push_back(ar[i]);
        }
    }
    cout<<"Sort elements of specific ranges into buckets:"<<endl;
    for(int j=0;j<all.size();j++){
        cout<<"Bucket "<<j+1<<": ";
        print(all[j]);
    }
    for(int j=0;j<all.size();j++){
        if(!all[j].empty()){
            insertionwithoutmessages(all[j]);
        }
    }
    cout<<"Sort each bucket with insertion sort, and concatenate into one array"<<endl;
    int k=0;
    for(vector<int>& l:all){
        if(!l.empty()){
            for(double i:l){
                ar[k]=i;
                k++;
            }
        }
    }
}

int main(){
    //vector<int> list={9,88,2000,100,43,546,2,32};
    //vector<int> list={5,4,3,2,1,7,9,6,0,8,8,9,7,9,4,3,2,1,4,3,5,6,5,4,5,6,7,8,7,6,7,0,9,8,5,4,3,2,1};
    vector<int> list={1,1,0,0,0,0,0,1,2,2,2,2,2,2,2,2,1,1,1,1,1,1,1,0,0,0,1};
    cout<<"Bucket Sort"<<endl;
    cout<<"Original Array: ";
    print(list);
    bucket(list);
    cout<<"Final Sorted Array: ";
    print(list);
    return 0;
}