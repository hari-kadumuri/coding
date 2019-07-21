#include<stdio.h>
#include<stdlib.h>

typedef struct _point{
    float x;
    float y;
}point;

int main() {
    point p1, p2, p3;
    printf("enter point 1:\n");
    scanf("%f%f", &p1.x, &p1.y);
    printf("enter point 2:\n");
    scanf("%f%f", &p2.x, &p2.y);
    printf("enter point 3:\n");
    scanf("%f%f", &p3.x, &p3.y);

    point vector1;
    vector1.x = p2.x-p1.x;
    vector1.y = p2.y-p1.y;
    point vector2;
    vector2.x = p3.x-p2.x;
    vector2.y = p3.y-p2.y;

    if(vector1.x*vector2.y > vector1.y*vector2.x)
        printf("\npoint 3 lies on left side line from p1 to p2");
    else if(vector1.x*vector2.y < vector1.y*vector2.x)
        printf("\npoint 3 lies on right side line from p1 to p2");
    else
        printf("\nall points are collinear");
    return 0;
}
