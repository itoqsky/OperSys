#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <math.h>

typedef struct{
    float x;
    float y;
}Point;

float distance(Point A, Point B){
    float result;
    result = sqrt(fabs((A.x - B.x)*(A.x - B.x)) + fabs((A.y - B.y)*(A.y - B.y)));
    return result;
}

float area(Point A, Point B, Point C){
    float result;
    result = fabs(A.x*B.y - B.x*A.y + B.x*C.y - C.x*B.y + C.x*A.y - A.x*C.y) / 2;
    return result;
}

int main (){
    Point A={2.5, 6}, B={1, 2.2}, C={10, 6};
    float f = distance(A, B);
	printf("A -- B distance is %f\n", f);
    float a = area(A, B, C);
	printf("Area of triangle ABC is %f\n", a);
    return 0;

}   