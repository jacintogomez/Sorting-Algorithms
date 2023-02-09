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

int countspacesmerge(vector<int> ve,int index){
    int count=0;
    for(int i=0;i<index;i++){
        string element=to_string(ve[i]);
        count+=element.size();
    }
    count+=index;
    return count;
}

int countspacesbubble(vector<int> ve,int index){
    int count=0;
    for(int i=0;i<=index-1;i++){
        string element=to_string(ve[i]);
        count+=element.size();
    }
    count+=index+1;
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

int counttotalspaces(vector<int> ve){
    int count=0;
    for(int i=0;i<ve.size();i++){
        string element=to_string(ve[i]);
        count+=element.size();
    }
    count+=ve.size()-1+2;//-1 because there will be 1 less comma than elements, +2 for the 2 brackets
    return count;
}

void printsortedportionbubble(int index,vector<int> ve){
    int totalchars=counttotalspaces(ve);
    int spacestoindex=countspacesbubble(ve,index);
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
    printsortedportionmerge(countspacesmerge(ar,begin),countmiddleunderscores(ar,begin,end));
    cout<<" this call is "<<step<<" level(s) deep"<<endl;
}

void bubble(vector<int> ar){
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
        printsortedportionbubble(i,ar);
        if(swap) {
            cout << " " << ar[i] << " was the next largest, and was 'bubbled' up to the end" << endl;
        }else{
            cout<<" next largest element "<<ar[i]<<" is already in sorted position"<<endl;
        }
    }
    cout<<"Final Sorted Array: ";
    print(ar);
}

void selection(vector<int> ar){
    for(int i=0;i<ar.size();i++){
        int min=i;
        for(int j=i+1;j<ar.size();j++){
            if(ar[min]>ar[j]){
                min=j;
            }
        }
        if(min!=i){
            int temp=ar[min];
            ar[min]=ar[i];
            ar[i]=temp;
        }
        print(ar);
        printsortedportion(countspaces(ar,i));
        if(ar[min]!=ar[i]){
            cout<<" the next minimum was "<<ar[i]<<" and was swapped with "<<ar[min]<<endl;
        }else{
            cout<<" "<<ar[min]<<" was the next smallest, so no swap occurred"<<endl;
        }
    }
    cout<<"Final Sorted Array: ";
    print(ar);
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
            cout << key << " was inserted before " << temp << endl;
        }else{
            cout<<"no insertions were necessary"<<endl;
        }
    }
    cout<<"Final Sorted Array: ";
    print(ar);
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
    int choice=0;
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
            cout<<"Merge Sort: "<<endl;
            cout<<"recursively break the array in half until sub-array lengths are 1, then combine in order"<<endl;
            cout<<"Time Complexity: Theta(nlog(n))"<<endl;
            cout<<"Space Complexity: O(n)"<<endl;
            merge(list,0,list.size()-1,0);
            break;
        case 2:
            cout<<"Insertion Sort: "<<endl;
            cout<<"insert the next element into its proper spot in the sorted part of the array"<<endl;
            cout<<"Time Complexity: O(n^2), Omega(n)"<<endl;
            cout<<"Space Complexity: O(1)"<<endl;
            insertion(list);
            break;
        case 3:
            cout<<"Selection Sort:"<<endl;
            cout<<"select the next smallest element from the unsorted part of the array and swap"<<endl;
            cout<<"Time Complexity: Theta(n^2)"<<endl;
            cout<<"Space Complexity: O(1)"<<endl;
            selection(list);
            break;
        case 4:
            cout<<"Bubble Sort:"<<endl;
            cout<<"compare side by side elements and swap if the left one is larger; with each trial of this the next largest element 'bubbles' to the top"<<endl;
            cout<<"Time Complexity: O(n^2), Omega(n)"<<endl;
            cout<<"Space Complexity: O(1)"<<endl;
            bubble(list);
            break;
        default:
            cout<<"No selection made/Invalid selection"<<endl;
    }
    return 0;
}