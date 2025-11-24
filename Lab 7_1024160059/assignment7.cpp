#include <iostream>
using namespace std;

void selectionSort(int a[], int n){
    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[min]) min=j;
        }
        swap(a[i],a[min]);
    }
}

void improvedSelectionSort(int a[], int n){
    int left=0,right=n-1;
    while(left<right){
        int min=left,max=left;
        for(int i=left;i<=right;i++){
            if(a[i]<a[min]) min=i;
            if(a[i]>a[max]) max=i;
        }
        swap(a[left],a[min]);
        if(max==left) max=min;
        swap(a[right],a[max]);
        left++;
        right--;
    }
}

void insertionSort(int a[], int n){
    for(int i=1;i<n;i++){
        int key=a[i],j=i-1;
        while(j>=0 && a[j]>key){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}

void bubbleSort(int a[], int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]) swap(a[j],a[j+1]);
        }
    }
}

void merge(int a[], int l, int m, int r){
    int n1=m-l+1,n2=r-m;
    int L[n1],R[n2];
    for(int i=0;i<n1;i++) L[i]=a[l+i];
    for(int i=0;i<n2;i++) R[i]=a[m+1+i];
    int i=0,j=0,k=l;
    while(i<n1&&j<n2){
        if(L[i]<=R[j]) a[k++]=L[i++];
        else a[k++]=R[j++];
    }
    while(i<n1) a[k++]=L[i++];
    while(j<n2) a[k++]=R[j++];
}

void mergeSort(int a[], int l, int r){
    if(l<r){
        int m=(l+r)/2;
        mergeSort(a,l,m);
        mergeSort(a,m+1,r);
        merge(a,l,m,r);
    }
}

int partitionQ(int a[], int low, int high){
    int pivot=a[high],i=low-1;
    for(int j=low;j<high;j++){
        if(a[j]<pivot){
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[high]);
    return i+1;
}

void quickSort(int a[], int low, int high){
    if(low<high){
        int pi=partitionQ(a,low,high);
        quickSort(a,low,pi-1);
        quickSort(a,pi+1,high);
    }
}

void printArray(int a[], int n){
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<endl;
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    int choice;
    cin>>choice;

    if(choice==1) selectionSort(a,n);
    else if(choice==2) improvedSelectionSort(a,n);
    else if(choice==3) insertionSort(a,n);
    else if(choice==4) bubbleSort(a,n);
    else if(choice==5) mergeSort(a,0,n-1);
    else if(choice==6) quickSort(a,0,n-1);

    printArray(a,n);
}