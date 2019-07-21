#include<iostream>
#include<vector>
#include<math.h>
#define PI 3.14159265
using namespace std;

bool inSoln(vector<int> soln, int nv) {
    vector<int>::iterator x = soln.begin();
    while(x!=soln.end()) {
        if(nv == *x)
            return 1;
        x++;
    }
    return 0;
}

vector<int> findConvexHull(vector<float> X, vector<float> Y) {
    int sv = 0;
    int n=X.size();
    //finding the sv i.e. vertex having minimum x coordinate
    for(int i=1;i<n;i++)
        if(X[sv]>X[i])
            sv = i;
    //finding the next vertices
    vector<int> soln;
    soln.push_back(sv);
    double minangle = 999999, angle;
    int nv;
    int pv = sv;
    //finding last before vertex
    int lbv;
    cout<<endl;
    for(int i=0;i<n;i++) {
            cout<<"i = "<<i;
            if(Y[i]>Y[sv] && X[i]>=X[sv])
                angle = atan((double)(Y[i]-Y[sv])/(double)(X[i]-X[sv])) + PI/2;
            else if(Y[i]<=Y[pv] && X[i]>X[pv])
                angle = atan((double)(X[i]-X[sv])/(double)(-Y[i]+Y[sv]));
            else if(Y[i]<Y[sv] && X[i]<=X[sv])
                angle = atan((double)(-Y[i]+Y[sv])/(double)(-X[i]+X[sv])) + 3*PI/2;
            else
                angle = atan((double)(-X[i]+X[sv])/(double)(Y[i]-Y[sv])) + PI;
            if(minangle>angle) {
                minangle = angle;
                lbv = i;
            }
            if(minangle == angle) {
                if(sqrt(pow(X[i]-X[sv], 2) + pow(Y[i]-Y[sv], 2)) > sqrt(pow(X[lbv]-X[sv], 2) + pow(Y[lbv]-Y[sv], 2)))
                    lbv = i;
            }
            cout<<" minangle=  "<<minangle<<"  angle=  "<<angle<<endl;
    }
    cout<<"last before vertex = "<<lbv<<endl;
    cout<<endl<<"start vertex = "<<sv<<endl;
    while(1) {
        minangle = 999999;
        for(int i=0;i<n;i++) {
            if(inSoln(soln, i) == 0) {
                cout<<"i = "<<i;
                if(Y[i]>Y[pv] && X[i]>=X[pv])
                    angle = atan((double)(X[i]-X[pv])/(double)(Y[i]-Y[pv]));
                else if(Y[i]<=Y[pv] && X[i]>X[pv])
                    angle = atan((double)(-Y[i]+Y[pv])/(double)(X[i]-X[pv])) + PI/2;
                else if(Y[i]<Y[pv] && X[i]<=X[pv])
                    angle = atan((double)(-X[i]+X[pv])/(double)(-Y[i]+Y[pv])) + PI;
                else
                    angle = atan((double)(Y[i]-Y[pv])/(double)(-X[i]+X[pv])) + 3*PI/2;
                if(minangle>angle) {
                    minangle = angle;
                    nv = i;
                }
                if(minangle == angle) {
                    if(sqrt(pow(X[i]-X[pv], 2) + pow(Y[i]-Y[pv], 2)) > sqrt(pow(X[nv]-X[pv], 2) + pow(Y[nv]-Y[pv], 2)))
                        nv = i;
                }
                cout<<" minangle=  "<<minangle<<"  angle=  "<<angle<<endl;
            }
        }
        soln.push_back(nv);
        cout<<"next vertex = "<<nv<<endl;
        if(nv==lbv)
            break;
        pv = nv;
    }
    return soln;
}

int main() {
    vector<float> X;
    float input;
    int n;
    cout<<"enter n:\n";
    cin>>n;
    cout<<"enter X values:\n";
    while(X.size()<n && cin>>input)
        X.push_back(input);
    cout<<endl;
    cout<<"enter Y values:\n";
    vector<float> Y;
    while(Y.size()<n && cin>>input)
        Y.push_back(input);

    cout<<endl<<"X values : ";
    vector<float>::iterator x = X.begin();
    while(x!=X.end()) {
        cout<<*x;
        x++;
    }
    cout<<endl<<"Y values : ";
    x = Y.begin();
    while(x!=Y.end()) {
        cout<<*x;
        x++;
    }
    vector<int> p = findConvexHull(X, Y);
    n = p.size();
    cout<<"\nvertices are:  ";
    for(int i=0;i<n;i++)
        cout<<p[i]<<"  ";

    return 0;
}
