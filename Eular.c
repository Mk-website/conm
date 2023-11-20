#include<stdio.h>

float func(float x, float y){
    return ((y-x)/(y+x));
}

float eularCalc(float initX, float initY, float h, float x){
    int i = 0;
    while (initX+h < x)
    {
        printf("Step %d : I = %d\n", i+1, i);
        printf("X%d = %f, Y%d = %f\n", i, initX, i, initY);
        initY = initY + h * func(initX, initY);
        initX += h;
        i++;
    }
    return initY;
}

int main(){
    float x, y, h, val;

    printf("Enter Initial value of x\n");
    scanf("%f", &x);
    printf("Enter Initial value of y\n");
    scanf("%f", &y);
    printf("Enter height\n");
    scanf("%f", &h);
    printf("Enter value of x to find y\n");
    scanf("%f", &val);
    printf("\nValue of Y when x = %f is %f", val, eularCalc(x, y, h, val));
    return 0;
}
