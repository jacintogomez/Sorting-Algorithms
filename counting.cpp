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

int getmax(vector<int> ar){
    int mx=ar[0];
    for(int i:ar){
        if(i>mx){
            mx=i;
        }
    }
    return mx;
}

void counting(vector<int>& ar){
    int max=getmax(ar);
    cout<<"This will use the max value of your array as the range...";
    int n=ar.size();
    vector<int> output(n,0);
    cout<<"Output array initialized as ---> ";
    print(output);
    vector<int> count(max+1,0);
    cout<<"Count array initialized as ---> ";
    print(count);
    for(int i=0;i<n;i++){count[ar[i]]++;}
    cout<<"Count updated with frequency of each index ---> ";
    print(count);
    for(int j=1;j<=max;j++){count[j]+=count[j-1];}
    cout<<"Count updated with index of each index --> ";
    print(count);
    for(int k=n-1;k>=0;k--){
        cout<<"Placing "<<ar[k]<<" into output array"<<endl;
        output[count[ar[k]]-1]=ar[k];
        count[ar[k]]--;
        cout<<"Output is now --> ";
        printsameline(output);
        cout<<"Count is now --> ";
        print(count);
    }
    ar=output;
}

int main(){
    vector<int> list={8,2,5,6,4,3,7,1,4,5,7,3,2,9,0,0,0,1,1,2};
    //vector<int> list={9,88,2000,100,43,546,2,32};
    int max=0,realmax=getmax(list);
    cout<<"Input max value: ";
    cin>>max;
    while(max<realmax){
        cout<<"range must be at least as large as the max array value"<<endl;
        cin>>max;
    }
    cout<<"Counting Sort"<<endl;
    cout<<"Original Array: ";
    print(list);
    counting(list);
    cout<<"Final Sorted Array: ";
    print(list);
    return 0;
}