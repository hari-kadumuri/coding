#include<stdio.h>

void greedy(float** EF, int** PP, int n) {
    int i=0, j=0, k, dumj;
    float engylvl = 1, hz, max;
    printf("\nAt (%d,%d) with energy level = %f", i, j, engylvl);
    while(i<n-1 || j<n-1) {
        if(i!=n-1 && j==n-1) {
            engylvl *= EF[i++][j];
            printf("\nAt (%d,%d) with energy level = %f", i, j, engylvl);
        }
        else if(i==n-1 && j!=n-1) {
            engylvl = engylvl + 0.25*engylvl*PP[i][j++];
            printf("\nAt (%d,%d) with energy level = %f", i, j, engylvl);
        }
        else {
            k = j;
            hz = engylvl;
            max = engylvl*EF[i][k];
            dumj = j;
            while(k<n-1) {
                hz += 0.25*hz*PP[i][k];
                if(hz*EF[i][k+1] > max) {
                    max = hz*EF[i][k+1];
                    dumj = k+1;
                }
                k++;
            }
            i++;
            j = dumj;
            engylvl = max;
            printf("\nAt (%d,%d) with energy level = %f", i, j, engylvl);
        }
    }
    printf("\n--- Energy level during exit = %f", engylvl);
}

void DP(float** EF, int** PP, int n) {
    int i,j;
    float** T;
    T = (float**)malloc(n*sizeof(float*));
    for(i=0;i<n;i++)
        T[i] = (float*)malloc(n*sizeof(float));
    T[0][0] = 1;
    for(j=1;j<n;j++)
        T[0][j] = T[0][j-1]*(1 + 0.25*PP[0][j-1]);
    for(i=1;i<n;i++)
        T[i][0] = T[i-1][0]*EF[i-1][0];
    for(i=1;i<n;i++) {
        for(j=1;j<n;j++) {
            if(T[i-1][j]*EF[i-1][j] > T[i][j-1]*(1 + 0.25*PP[i][j-1]))
                T[i][j] = T[i-1][j]*EF[i-1][j];
            else
                T[i][j] = T[i][j-1]*(1 + 0.25*PP[i][j-1]);

        }
    }
    printf("\n\n+++ Part 2: Dynamic-programming algorithm");
    printf("\n--- Energy level during exit = %f", T[n-1][n-1]);

    for(i=0;i<n;i++)
        free(T[i]);
    free(T);
}

void findpath(int* path, float** T, int n, int i, int j) {
    if(i==0&&j==0)
        printf("\nAt (0,0) with energy level = 1.000000");
    else {
        int newpathidx = path[n*i+j];
        int newi = newpathidx/n;
        int newj = newpathidx%n;
        findpath(path, T, n, newi, newj);
        printf("\nAt (%d,%d) with energy level = %f", i, j, T[i][j]);
    }
}

void DPsol(float** EF, int** PP, int n) {
    int i,j;
    float** T;
    T = (float**)malloc(n*sizeof(float*));
    for(i=0;i<n;i++)
        T[i] = (float*)malloc(n*sizeof(float));
    T[0][0] = 1;
    int *path = (int*)malloc(n*n*sizeof(int));
    path[0] = 0;
    for(j=1;j<n;j++) {
        T[0][j] = T[0][j-1]*(1 + 0.25*PP[0][j-1]);
        path[j] = j-1;
    }
    for(i=1;i<n;i++) {
        T[i][0] = T[i-1][0]*EF[i-1][0];
        path[i*n] = n*(i-1);
    }
    for(i=1;i<n;i++) {
        for(j=1;j<n;j++) {
            if(T[i-1][j]*EF[i-1][j] > T[i][j-1]*(1 + 0.25*PP[i][j-1])) {
                T[i][j] = T[i-1][j]*EF[i-1][j];
                path[n*i+j] = n*(i-1)+j;
            }
            else {
                T[i][j] = T[i][j-1]*(1 + 0.25*PP[i][j-1]);
                path[n*i+j] = n*i+j-1;
            }
        }
    }

    printf("\n\n+++ Part 3: Dynamic-programming algorithm with solution");
    findpath(path, T, n, n-1, n-1);

    for(i=0;i<n;i++)
        free(T[i]);
    free(T);
    free(path);
}

/*int main() {
    int n, **PP;
    float** EF;
    printf("enter n :\n");
    scanf("%d",&n);
    int i;
    PP = (int**)malloc(n*sizeof(int*));
    for(i=0;i<n;i++)
        PP[i] = (int*)malloc((n-1)*sizeof(int));
    EF = (int**)malloc((n-1)*sizeof(int*));
    for(i=0;i<n;i++)
        EF[i] = (int*)malloc(n*sizeof(int));
    int j;
    printf("\n+++ Exhaustive factors\n");
    for(i=0;i<n-1;i++)
        for(j=0;j<n;j++)
            scanf("%f",&EF[i][j]);
    printf("\n+++ Potion positions\n");
    for(i=0;i<n;i++)
        for(j=0;j<n-1;j++)
            scanf("%d",&PP[i][j]);
    printf("+++ Part 1: Greedy algorithm");
    greedy(EF, PP, n);
    DP(EF, PP, n);
    DPsol(EF, PP, n);

    //for(i=0;i<n-1;i++)
    //    free(PP[i]);
    //free(PP);
    //for(i=0;i<n;i++)
    //    free(EF[i]);
    //free(EF);
    return 0;
}
*/
