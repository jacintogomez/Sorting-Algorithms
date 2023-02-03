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

void printsortedportionbubble(int index,vector<int> ve){
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

void printsortedportionmerge(int blanks,int range){
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
    for(int i=0;i<=index;i++){
        string element=to_string(ve[i]);
        count+=element.size();
    }
    count+=index;
    return count;
}


vector<int> vecmaker(string in){
    vector<int> out={};
    int index=0;
    int length=0;
    for(int i=0;i<in.size();i++){
        if(in[i]==' '){
            out.push_back(stoi(in.substr(index,length)));
            index=i+1;
            length=0;
        }else{
            length++;
        }
    }
    out.push_back(stoi(in.substr(index,length)));
    return out;
}

int main(){
    string ar;
    int choice;
    cout<<"Choose an array and enter without brackets or commas, separated by spaces"<<endl;
    cout<<"Example: [1,2,3] should be entered as 1 2 3"<<endl;
    cout<<"Enter your array: ";
    getline(cin,ar);
    vector<int> list=vecmaker(ar);
    cout<<"Next, choose a sorting algorithm from the options below by entering the corresponding number:"<<endl;
    cout<<"1. Merge Sort"<<endl;
    cout<<"2. Insertion Sort"<<endl;
    cout<<"3. Selection Sort"<<endl;
    cout<<"4. Bubble Sort"<<endl;
    cin>>choice;
    cout<<"Original Array: ";
    print(list);
    switch(choice){
        case 1:
            merge(list);
            break;
        case 2:
            insertion(list);
            break;
        case 3:
            selection(list);
            break;
        case 4:
            bubble(list);
            break;
        default:
            cout<<"No selection made"<<endl;
    }
    return 0;
}