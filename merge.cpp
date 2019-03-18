#include <stdio.h>
#define max 100000
void merge(int arr[],int start,int mid,int end);
void merge_sort(int arr[],int start, int end);


int main(){
    int n,arr[max];
    scanf("%d",&n);
    for(int i = 0; i<n; i++){
        scanf("%d",&arr[i]);
    }
    merge_sort(arr,0,n-1);
    for(int i=0;i<n;i++){
       printf("%d\n",arr[i]);
    }
}


void merge(int arr[],int start,int mid,int end){
    int i,j,k,tmp[max];
    i=start;
    j=mid+1;
    k=start;
    
    while(i<=mid&&j<=end){
        tmp[k++] = (arr[i]>arr[j]) ? arr[j++] : arr[i++];
    }
    while(k<=end){
        if(i>mid) tmp[k++]=arr[j++];
        else if(j>end) tmp[k++]=arr[i++];
    }
    for(i=start;i<=end;i++){
        arr[i]=tmp[i];
    }
    
}

void merge_sort(int arr[],int start, int end){
    int mid;
    if(start<end){
        mid=(start+end)/2;
        merge_sort(arr,start,mid);
        merge_sort(arr,mid+1,end);
        merge(arr,start,mid,end);
    }
}




