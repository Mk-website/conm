#include<stdio.h>

float func(float x, float y){
    return (x*y);
}

float rungaKuttaCalc(float initX, float initY, float h, float x){
    int i = 0;
    while (initX+h < x)
    {
        printf("Step %d : I = %d\n", i+1, i);
        printf("X%d = %f, Y%d = %f\n", i, initX, i, initY);
        initY += (h/2)*(func(initX, initY) + func(initX+h, initY+(h*func(initX, initY))));
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
    printf("\nValue of Y when x = %f is %f", val, rungaKuttaCalc(x, y, h, val));
    return 0;
}
