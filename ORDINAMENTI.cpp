#include <iostream>

using namespace std;

void stampa(int *v , int n){
    for(int i=0;i<n;i++)
        cout<<v[i]<<" - ";
}

int posMax(int *v,int n){
    int pos=0;
    for(int i=1;i<n;i++)
        if(v[i]>v[pos])
            pos=i;
    return pos;
}

void swap(int *v, int i , int j){
    int temp=v[i];
    v[i]=v[j];
    v[j]=temp;
}

int partition(int *v , int n){
    int pos=rand()%n;
    swap(v,0,pos);
    int pivot=v[0];
    int i=-1;
    int j=n;
    do{
        do i++; while(v[i]<pivot);
        do j--; while(v[j]>pivot);
        if(i<j) swap(v,i,j);
    } while (i<j);
    return j;
}

void merge(int *v , int m , int n){
    int i=0,j=m,k=0;
    int *a=new int[n];
    while(i<m && j<n){
        if(v[i]<v[j]) a[k++]=v[i++];
        else a[k++]=v[j++];
    }
    while(i<m) a[k++] = v[i++];
    while(j<n) a[k++] = v[j++];
    for(i=0;i<n;i++)
        v[i]=a[i];
    delete [] a;
}

void insertionSortRicorsivo(int *v,int n) {
    if(n<=1) return;
    insertionSortRicorsivo(v,n-1);
    int j=n-1;
    while(j>0 && v[j]<v[j-1]){
        swap(v,j,j-1);
        j--;
    }
}

void selectionSortRicorsivo(int *v,int n) {
    if(n<=1) return;
    int p = posMax(v,n);
    swap(v,p,n-1);
    selectionSortRicorsivo(v,n-1);
}

void quickSortRicorsivo(int *v , int n){
    if(n<=1) return;
    int m=partition(v,n);
    quickSortRicorsivo(v,m+1);
    quickSortRicorsivo(v+m+1,n-m-1);
}

void mergeSort(int *v, int n){
    if(n<=1) return;
    int m=n/2;
    mergeSort(v,m);
    mergeSort(v+m,n-m);
    merge(v,m,n);
}

void bubbleSort(int *v,int n)
{
    for(int i=1;i<n-1;i++)
        for(int j=0;j<n-i;j++)
            if(v[j+1]<v[j]) swap(v,j+1,j);
}

bool ricercaBinaria(int*v,int n,int num){
    cout<<"Stato vettore di ricerca: "<<endl;
    stampa(v,n);
    cout<<endl;
    if(n==0) return false;
    if(n==1) return v[0] == num;
    if(v[n/2]>num)
        return ricercaBinaria(v,n/2,num);
    else
        return ricercaBinaria(v+n/2,n-(n/2),num);
}

int main()
{
    int v[]={4,5,1,7,2,8,1,5,7,12,14,8,9,12,10,2,34,6,12,37,86,8,98};
    stampa(v,23);
    cout<<endl;
    bubbleSort(v,23);
    stampa(v,23);
    cout<<endl;
    cout<<"Ricerca: ";
    ricercaBinaria(v,23,7);
}