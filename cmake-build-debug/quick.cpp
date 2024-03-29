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
    if(ar.size()==0){
        cout<<"[]";
        return;
    }
    cout<<"[";
    for(int x=0;x<ar.size()-1;x++){
        cout<<ar[x]<<",";
    }
    cout<<ar.back()<<"]";
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

void printsortedportionquick(int index,vector<int> ve){
    int totalchars=counttotalspaces(ve)-2; //-2 to subtract the brackets
    int spacestoindex=countspaces(ve,index)-2; //-2 to subtract the two |'s
    int spacesuptopivot=countspaces(ve,index+1)-2;
    int pivotspaces=spacesuptopivot-spacestoindex-1;
    int afterpiv=totalchars-spacesuptopivot-1;
    cout<<" <-- Pivot is "<<ve[index]<<", numbers greater than it placed to the left, smaller to the right"<<endl;
    if(index!=0){cout<<"|";}
    else{spacestoindex++;}
    for(int i=1;i<=spacestoindex;i++){
        cout<<"_";
    }
    cout<<"|";
    for(int i=1;i<=pivotspaces;i++){
        cout<<" ";
    }
    cout<<"|";
    for(int i=1;i<=afterpiv;i++){
        cout<<"_";
    }
    if(index!=ve.size()-1){cout<<"|";}
}

int partition(vector<int>& ar,int low,int high,int step){
    int pivot=ar[high];
    int i=low-1;
    for(int j=low;j<=high-1;j++){
        if(ar[j]<pivot){
            i++;
            int temp=ar[j];
            ar[j]=ar[i];
            ar[i]=temp;
        }
    }
    int other=ar[i+1];
    ar[i+1]=ar[high];
    ar[high]=other;
    printsameline(ar);
    printsortedportionquick(i+1,ar);
    cout<<"     This recursive call is "<<step<<" level(s) deep"<<endl;
    return i+1;
}

void quick(vector<int>& ar,int low,int high,int step){
    if(low<high){
        int pivot=partition(ar,low,high,step);
        quick(ar,low,pivot-1,step+1);
        quick(ar,pivot+1,high,step+1);
    }
}

int main(){
    vector<int> list={999,104,2,1024,16};
    //vector<int> list={10,1,9,2,8,3,7,4,6,5};
    //vector<int> list={9,88,2000,100,43,546,2,32};
    cout<<"Quick Sort"<<endl;
    cout<<"Original Array: ";
    print(list);
    quick(list,0,list.size()-1,0);
    cout<<"Final Sorted Array: ";
    print(list);
    return 0;
}