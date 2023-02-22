//Created by Jacinto Gomez

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

int counttotalspacesquick(vector<int> ve){
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
            cout<<" next largest element "<<ar[i]<<" was already in sorted position"<<endl;
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
            cout<<" the next largest was "<<ar[i]<<" and was swapped with "<<ar[min]<<endl;
        }else{
            cout<<" "<<ar[min]<<" happened to be the next smallest, so no swap occurred"<<endl;
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
            cout << key << " was the next element in line, and was inserted before " << temp << endl;
        }else{
            cout<<"next element was the largest so far, no insertions were necessary"<<endl;
        }
    }
    cout<<"Final Sorted Array: ";
    print(ar);
}

void printsortedportionquick(int index,vector<int> ve){
    int totalchars=counttotalspacesquick(ve)-2; //-2 to subtract the brackets
    int spacestoindex=countspacesbubble(ve,index)-2; //-2 to subtract the two |'s
    int spacesuptopivot=countspacesbubble(ve,index+1)-2;
    int pivotspaces=spacesuptopivot-spacestoindex-1;
    int afterpiv=totalchars-spacesuptopivot-1;
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
    cout<<" <-pivot is "<<ve[index]<<"... ";
}

int partition(vector<int>& ar,int low,int high){
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
    print(ar);
    printsortedportionquick(i+1,ar);
    cout<<"numbers greater than "<<pivot<<" are placed to the left of it, and ones smaller than it on the right"<<endl;
    return i+1;
}

void quick(vector<int>& ar,int low,int high){
    if(low<high){
        int pivot=partition(ar,low,high);
        quick(ar,low,pivot-1);
        quick(ar,pivot+1,high);
    }
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
    print(ar);
    cout<<"----> call heapify to turn array into binary tree"<<endl;
    int n=ar.size();
    for(int i=n/2-1;i>=0;i--){heapify(ar,n,i);}
    print(ar);
    cout<<"----> keep calling heapify each time a max element is taken away"<<endl;
    int prevfront=-1;
    for(int j=n-1;j>=0;j--){
        int temp=ar[0];
        ar[0]=ar[j];
        ar[j]=temp;
        heapify(ar,j,0);
        print(ar);
        printsortedportionbubble(j,ar);
        if(prevfront==ar[j]){
            cout<<" next max "<<ar[j]<<" was already at heap root, then removed to the back"<<endl;
        }else{
            cout<<" the max element "<<ar[j]<<" was pushed to the root of the heap and then removed"<<endl;
        }
        prevfront=ar[0];
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

vector<int> vecmaker(string in){
    vector<int> out={};
    int index=0;
    int length=0;
    string potentialdigit;
    if(in.size()==0){
        cout<<"Error: cannot enter empty array";
        exit(1);
    }
    for(int i=0;i<in.size();i++){
        if(in[i]==' '){
            potentialdigit=in.substr(index,length);
            if(!isdigit(potentialdigit[0])){
                cout<<"Error: improper formatting, try again please";
                exit(1);
            }
            out.push_back(stoi(potentialdigit));
            index=i+1;
            length=0;
        }else{
            length++;
        }
    }
    out.push_back(stoi(in.substr(index,length)));
    return out;
}

void displayoptions(){
    cout<<"1. Merge Sort"<<endl;
    cout<<"2. Insertion Sort"<<endl;
    cout<<"3. Selection Sort"<<endl;
    cout<<"4. Bubble Sort"<<endl;
    cout<<"5. Quick Sort"<<endl;
    cout<<"6. Heap Sort"<<endl;
    cout<<"7. Radix Sort"<<endl;
}

void afteroptions(){
    cout<<"1. Choose new algorithm for same array"<<endl;
    cout<<"2. Enter new array"<<endl;
    cout<<"3. Exit"<<endl;
}

void switchloop1(int choice,vector<int> list){
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
        case 5:
            cout<<"Quick Sort:"<<endl;
            cout<<"pick a random element and place all numbers greater than it on one side, and less than on the other; repeat this recursively for the two halves"<<endl;
            cout<<"Time Complexity: O(n^2), Omega(nlog(n))"<<endl;
            cout<<"Space Complexity: O(nlog(n))"<<endl;
            quick(list,0,list.size()-1);
            break;
        case 6:
            cout<<"Heap Sort:"<<endl;
            cout<<"treat all elements as a heap (tree) and recursively move the max element to the root and remove it"<<endl;
            cout<<"Time Complexity: Theta(nlog(n))"<<endl;
            cout<<"Space Complexity: O(1)"<<endl;
            heap(list);
            break;
        case 7:
            cout<<"Radix Sort:"<<endl;
            cout<<"sort all elements by the digit in the 1's place, then by the digit in the 10's place.. continue through the max digit"<<endl;
            cout<<"Time Complexity: Theta(d(n*k)) d=max # of digits, k=number of possible values for each digit (here is 10 for decimal #s)"<<endl;
            cout<<"Space Complexity: O(n+k)"<<endl;
            radix(list);
            break;
        default:
            cout<<"No selection made/Invalid selection"<<endl;
    }
}

void switchloop2(int choice,vector<int>& list){
    string ar;
    int newchoice;
    switch(choice){
        case 1:
            displayoptions();
            cin>>newchoice;
            switchloop1(newchoice,list);
            break;
        case 2:
            cout<<"Pick a new array and type in the same format as before"<<endl;
            cout<<"Example: [3,1,2] should be entered as 3 1 2"<<endl;
            cout<<"Enter your array: ";
            //validateinput(ar);
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            getline(cin,ar);
            list=vecmaker(ar);
            displayoptions();
            cin>>newchoice;
            switchloop1(newchoice,list);
            break;
        case 3:
            cout<<"Hope this was helpful :)";
            break;
        default:
            cout<<"Invalid selection"<<endl;
    }
}

int main(){
    string ar;
    int choice=0;
    cout<<"This program will trace the sorting of an array with whatever sorting algorithm you select"<<endl;
    cout<<"Note: the output will only appear properly In a compiler that displays all output letters and symbols \nin fixed sized spaces. For instance, if your compiler displays lllll and WWWWW as the same length, then it is good\nfor it; if it displays them as drastically different, it is not"<<endl;
    cout<<"This program will also not work for negative numbers or inputs other than int"<<endl;
    cout<<"Choose an array and enter without brackets or commas, separated by spaces"<<endl;
    cout<<"Example: [3,1,2] should be entered as 3 1 2"<<endl;
    cout<<"This array will be sorted in increasing order"<<endl;
    cout<<"Enter your array: ";
    getline(cin,ar);
    vector<int> list=vecmaker(ar);
    cout<<"Next, choose a sorting algorithm from the options below by entering the corresponding number:"<<endl;
    displayoptions();
    cin>>choice;
    cout<<"Original Array: ";
    print(list);
    switchloop1(choice,list);
    do{
        afteroptions();
        cin>>choice;
        switchloop2(choice,list);
    }while(choice!=3);
    return 0;
}