#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float func(float x) {
    return sqrt(25+3*x);
}

void leftRectangels(float min, float max, int n, float e) {
    float sum = 0, h, i1, i2, i;
    h = (max - min) / n;
    for (float i = min; i <= max - h; i += h)
        sum += func(i);
    sum *= h;
    i1 = sum;
    printf("The method of rectangles = %f\n", i1);
    }



void rightRectangles(float min, float max, int n, float e) {
    float sum = 0, h, i1, i2, i;
    h = (max - min) / n;
    for (float i = min + h; i <= max; i += h)
        sum += func(i);
    sum *= h;
    i1 = sum;
    printf("The method of rectangles = %f\n", i1);
do {
        h = (max - min) / n;
        for (float i = min; i <= max; i += h)
            sum += func(i);
        sum *= h;
        i1 = sum;
        n += 2;
        sum = 0;
        h = (max - min) / n;
        for (float i = min; i < max; i += h)
            sum += func(i);
        sum *= h;
        i2 = sum;
    } while (fabs(i1 - i2) >= e);
    printf("The method of rectangles = %f\nNumber of intervals %i\n", i2, n);
}




void Trapezoidal(float min, float max, int n, float e) {
    float sum = 0, h, i1, i2, y = 0;
    h = (max - min) / n;
    y += func(min) + func(max);
    for (int i = 1; i < n; i++)
        y += 2 * (func(min + h * i));
    i1 = ((max - min) / (2 * n) * y);

 do {
        y=0;
        y+=func(min)+func(max);
        for (float i = 1; i <= n; i++)
            y+=2*(func(min+h*i));
        y = 0;
        y+=func(min)+func(max);
        for (float i = 1; i < n; i++)
            y+=2*(func(min+h*i));
        i2=((max-min)/(2*n)*y);
    } while (fabs(i1 - i2) <= e);
    printf("The method of trapezoidal = %f\nNumber of intervals %i\n", i2, n);

}

void Simpson(float min, float max, int n, float e) {
    float i2 = e + 1, i1 = 0;
    float h, sum2 = 0, sum4 = 0, sum = 0;
    h = (max - min) / (2 * n);
    for (int i = 1; i <= 2 * n - 1; i += 2) {
        sum4 += func(min + h * i);
        sum2 += func(min + h * (i + 1));
    }
    sum = func(min) + 4 * sum4 + 2 * sum2 - func(max);
    i2 = i1;
    i1 = (h / 3) * sum;


    for(;n<=4 || fabs(i1-i2)>e; ) {
        sum2=0;
        sum4=0;
        sum=0;
        for (float i = 1; i <= 2*n; i+=2 ){
            sum4+=func(min+h*i);
            sum2+=func(min+h*(i+1));
        }
        sum=func(min)+4*sum4+2*sum2-func(max);
        i2=i1;
        i1=(h/3)*sum;
    }
    printf("The method Simpson = %f\nNumber of intervals %i\n", i2, n);

}




int main() {
    int n, method;
    float min, max, e;

    printf("Choice method:\n 1-left Rectangles\n 2-Right Rectangles\n 3-Trapezoidal\n 4-Simpson \n");
    scanf_s("%d", &method);
    printf("Enter data:\nLimit min: ");
    scanf_s("%f", &min);
    printf("Limit max: ");
    scanf_s("%f", &max);
    printf("Number of intervals n: ");
    scanf_s("%d", &n);



    switch (method) {
    case 1:
        leftRectangels(min, max, n, e);
break;
    case 2:
       rightRectangles(min, max, n, e);
break;
    case 3:
        Trapezoidal(min, max, n, e);
break;
    case 4:
        Simpson(min, max, n, e);
break;
    case 5:
        printf("case 5");
        break;

    }

}
