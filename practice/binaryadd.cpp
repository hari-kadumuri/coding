#include<iostream>
using namespace std;

/*int main() {
    int n;
    cin>>n;
    cout<<"\nn = "<<n;
    bool a[n];
    bool b[n];
    cout<<endl<<"enter a :\n";
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<endl<<"enter b :\n";
    for(int i=0;i<n;i++)
        cin>>b[i];
    cout<<"\nA :\t";
    for(int i=n-1;i>=0;i--)
        cout<<a[i]<<"\t";
    cout<<"\nB :\t";
    for(int i=n-1;i>=0;i--)
        cout<<b[i]<<"\t";
    bool* c = new int[n+1];
    int Cout = 0;
    for(int i=0;i<n;i++) {
        if(a[i]==0 && b[i]==0) {
            c[i] = Cout;
            Cout = 0;
        }
        else if((a[i]==0 && b[i]==1)||(a[i]==1 && b[i]==0)) {
            if(Cout == 0)
                c[i] = 1;
            else {
                c[i] = 0;
                Cout = 1;
            }
        }
        else if(a[i]==1 && b[i]==1) {
            if(Cout == 0)
                c[i] = 0;
            else
                c[i] = 1;
            Cout = 1;
        }
        else {
            cout<<endl<<"error in input...!!";
            break;
        }
    }
    c[n] = Cout;
    cout<<endl<<"Sum of a and b :\n";
    for(int i=n;i>=0;i--)
        cout<<c[i]<<"\t";
    delete []a;
    delete []b;
    delete []c;
    return 0;
}*/
