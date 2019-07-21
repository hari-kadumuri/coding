#include<iostream>
using namespace std;

void Merge(int* a, int left, int mid, int right) {
    int i, k, i1, j, i2,c[right-left+1];
    i = k = i1 = left;
    int j1 = mid;
    j = i2 = mid+1;
    int j2 = right;
    while(i<=j1 && j<=j2) {
        if(a[i]>a[j])
            c[k++] = a[j++];
        else
            c[k++] = a[i++];
    }
    while(i<=j1)
        c[k++] = a[i++];
    while(j<=j2)
        c[k++] = a[j++];
    for(i=left;i<=right;i++)
        a[i] = c[i];
}

void mergesort(int* a, int left, int right) {
    int mid = (left+right)/2;
    if(right>left) {
        mergesort(a, left, mid);
        mergesort(a, mid+1, right);
        Merge(a,left, mid, right);
    }
    else {
        int temp;
        if(a[right]>a[left]) {
            temp = a[right];
            a[right] = a[left];
            a[left] = temp;
        }
    }
}

void sortaccordingtofinishtimes(int* S, int* F, int n) {
    int tempS[n];
    int idxarray[100];
    for(int i=0;i<100;i++)
        idxarray[i] = -1;
    for(int i=0;i<n;i++)
        idxarray[F[i]] = i;
    mergesort(F, 0, n-1);
    for(int i=0;i<n;i++)
        tempS[i] = S[idxarray[F[i]]];
    for(int i=0;i<n;i++)
        S[i] = tempS[i];
    delete []tempS;
    delete []idxarray;
}

void printmaxnumberofactivities(int* S, int* F, int n) {
    int count=1,pft=F[0];
    for(int i=1;i<n;i++)
        if(S[i]>=pft) {
            count++;
            pft+=F[i]-S[i];
        }
    cout<<"Max number of Activities =\t"<<count;
}

int main() {
    cout<<"enter n:\n";
    int n;
    cin>>n;
    int i,S[n],F[n];
    cout<<"enter start times :\n";
    for(i=0;i<n;i++)
        cin>>S[i];
    cout<<"enter finish times :\n";
    for(i=0;i<n;i++)
        cin>>F[i];
    sortaccordingtofinishtimes(S, F, n);
    printmaxnumberofactivities(S, F, n);
    delete []S;
    delete []F;
    return 0;
}
+++++==
