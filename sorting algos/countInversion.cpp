#include<iostream>
using namespace std;

long long mergeInv(int arr[], int l, int mid, int r){
    long long inv = 0;
    int n1 = mid-l+1;
    int n2 = r-mid;

    int a[n1];
    int b[n2];//temp arrays

    for(int i=0; i<n1; i++){
        a[i] = arr[l+i];
    }

    for(int i=0; i<n2; i++){
        b[i] = arr[mid+1+i];
    }

    int i=0;
    int j=0;
    int k=l;

    while(i<n1 && j<n2){
        if(a[i]<b[j]){
            arr[k] = a[i];
            k++;
            i++;
        }
        else{
            arr[k] = b[j];
            inv = n1-i;
            k++;
            j++;
        }               
    }
    while (i<n1)
    {
        arr[k] = a[i];
        k++;
        i++;
    }
    while (j<n2)
    {            
        arr[k] = b[j];
        k++;
        j++;
    }
    return inv;
}

long long countInv(int arr[], int l, int r){
    long long inv = 0;
    if(l<r){
        int mid = (l+r)/2;
        inv += countInv(arr, l, mid);
        inv += countInv(arr, mid+1, r);

        inv += mergeInv(arr, l, mid, r);
    }
    return inv;
}

int main(){
    int arr[] = {32, 43, 45, 56, 23, 23 ,53, 84,43, 23, 48, 65};
    cout<<countInv(arr, 0, 9)<<endl;
        
}