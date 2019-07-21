#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
int main() {
    int n, q=0, i;
    char s[100];
    printf("enter string :\n");
    scanf("%s", s);
    n = strlen(s);
    char **p;
    for(i=0;i<n;i++)
        if(s[i] == '.')
            q++;
    q++;
    p = (char**)malloc(q*sizeof(char*));
    for(i=0;i<q;i++)
        p[i] = (char*)malloc(n*sizeof(char));
    int j=0;
    int k=0;
    for(i=0;i<n;i++) {
        if(s[i]=='.') {
            p[j++][k] = '\0';
            k = 0;
        }
        else
            p[j][k++] = s[i];
    }
    p[j][k] = '\0';
    k=0;j=0;
    printf("\n");
    for(i=q-1;i>=0;i--)
    {
        while(p[i][k]!='\0') {
            s[j++] = p[i][k++];
            if(j==n)
                break;
        }
        if(p[i][k] == '\0') {
            s[j++] = '.';
            k=0;
        }
    }
    s[--j] = '\0';
    printf("\nModified String :  %s", s);
    for(i=0;i<q;i++)
        free(p[i]);
    free(p);
    return 0;
}
*/
