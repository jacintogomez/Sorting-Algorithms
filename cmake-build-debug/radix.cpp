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
}

int countspaces(vector<int> ve,int index){
}

void printsortedportion(int index,vector<int> ve){
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

void countsort(vector<int>& ar,int exp){
    int n=ar.size();
    vector<int> output(n,0);
    vector<int> count(10,0);
    for(int i=0;i<n;i++){count[(ar[i]/exp)%10]++;}
    for(int i=1;i<10;i++){count[i]+=count[i-1];}
    for(int i=n-1;i>=0;i--){
        output[count[(ar[i]/exp)%10]-1]=ar[i];
        count[(ar[i]/exp)%10]--;
    }
    for(int i=0;i<n;i++){ar[i]=output[i];}
}

void radix(vector<int>& ar){
    int m=getmax(ar);
    for(int exp=1;m/exp>0;exp*=10){
        countsort(ar,exp);
    }
}

int main(){
    vector<int> list={999,104,2,1024,16};
    //vector<int> list={8,2,5,6,4,3,7,1};
    //vector<int> list={9,88,2000,100,43,546,2,32};
    cout<<"Radix Sort"<<endl;
    cout<<"Original Array: ";
    print(list);
    radix(list);
    cout<<"Final Sorted Array: ";
    print(list);
    return 0;
}