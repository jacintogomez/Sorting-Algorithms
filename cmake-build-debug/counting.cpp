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

int getmax(vector<int> ar){
    int mx=ar[0];
    for(int i:ar){
        if(i>mx){
            mx=i;
        }
    }
    return mx;
}

void counting(vector<int>& ar,int max){
    int n=ar.size();
    vector<int> output(n,0);
    cout<<"output array initialized as ---> ";
    print(output);
    vector<int> count(max+1,0);
    cout<<"count array initialized as ---> ";
    print(count);
    for(int i=0;i<n;i++){count[ar[i]]++;}
    cout<<"count updated with frequency of each index ---> ";
    print(count);
    for(int j=1;j<=max;j++){count[j]+=count[j-1];}
    cout<<"count updated with index of each index --> ";
    print(count);
    for(int k=n-1;k>=0;k--){
        cout<<"placing "<<ar[k]<<" into output array"<<endl;
        output[count[ar[k]]-1]=ar[k];
        count[ar[k]]--;
        cout<<"output is now --> ";
        print(output);
    }
    ar=output;
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
    int e=1;
    for(int exp=1;m/exp>0;exp*=10){
        countsort(ar,exp);
        print(ar);
        cout<<"---> all numbers lower than "<<pow(10,e)<<" are now sorted with respect to each other"<<endl;
        e++;
    }
}

int main(){
    //vector<int> list={8,2,5,6,4,3,7,1};
    vector<int> list={9,88,2000,100,43,546,2,32};
    int max=0,realmax=getmax(list);
    cout<<"Input max value: ";
    cin>>max;
    if(max<realmax){
        cout<<"range must be at least as large as the max array value";
        exit(1);
    }
    cout<<"Counting Sort"<<endl;
    cout<<"Original Array: ";
    print(list);
    counting(list,max);
    cout<<"Final Sorted Array: ";
    print(list);
    return 0;
}