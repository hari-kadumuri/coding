#include<iostream>
using namespace std;
/*
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

void sortaccordingtostarttimes(int* S, int* F, int n) {
    int tempF[n];
    int idxarray[100];
    for(int i=0;i<100;i++)
        idxarray[i] = -1;
    for(int i=0;i<n;i++)
        idxarray[S[i]] = i;
    mergesort(S, 0, n-1);
    for(int i=0;i<n;i++)
        tempF[i] = F[idxarray[S[i]]];
    for(int i=0;i<n;i++)
        F[i] = tempF[i];
    delete []idxarray;
    delete []tempF;
}

void printminnumberofplatforms(int* S, int* F, int n) {
    int presentdepth = 0, maxdepthtillnow = 0;
    int i, compatibilityarray[n];
    for(i=0;i<n;i++)
        compatibilityarray[i] = 0;
    for(i=1;i<n;i++) {
        for(int j=0;j<i;j++) {
            if(F[j]>S[i])
                compatibilityarray[i]++;
        }
    }
    for(i=n-1;i>=0;i--) {
        for(int j=n-1;j>i;j--) {
            if(S[j]<F[i])
                compatibilityarray[i]++;
        }
    }
    maxdepthtillnow = compatibilityarray[0];
    for(i=1;i<n;i++) {
        presentdepth = compatibilityarray[i];
        if(presentdepth>maxdepthtillnow)
            maxdepthtillnow = presentdepth;
    }
    cout<<endl<<"Minimum number of platforms required =\t"<<maxdepthtillnow;
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
    sortaccordingtostarttimes(S, F, n);
    printminnumberofplatforms(S, F, n);
    delete []S;
    delete []F;
    return 0;
}
*/
