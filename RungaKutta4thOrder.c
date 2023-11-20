#include<stdio.h>

float func(float x, float y){
    return (x*y);
}

float rungaKutta4thCalc(float initX, float initY, float h, float x){
    int i = 0;
    float s[4];
    while (initX+h < x)
    {
        printf("Step %d : I = %d\n", i+1, i);
        printf("X%d = %f, Y%d = %f\n", i, initX, i, initY);
        s[0] = func(initX, initY);
        s[1] = func(initX+(h/2), initY+(h/2*s[0]));
        s[2] = func(initX+(h/2), initY+(h/2*s[1]));
        s[3] = func(initX+(h/2), initY+(h*s[2]));
        initY += ((h/12)*(s[0] + 2*s[1] + 2*s[2] + s[3]));
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
    printf("\nValue of Y when x = %f is %f", val, rungaKutta4thCalc(x, y, h, val));
    return 0;
}
