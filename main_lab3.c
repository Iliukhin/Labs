#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double func(double x);
double method_hord(double x1, double x2, double iter, double eps, double mod);
double method_polovina(double x1, double x2, double eps, double mod, double iter );
int var3();

double func(double x){
    return 2*pow(x-4,3)+2*x;
}

double method_hord(double x1, double x2, double iter, double eps, double mod){
    double f1, f2, x;
    unsigned int n, N=iter, i=0;
    do{

        f2 = func(x2);
        f1 = func(x1);
        x1=x2-((x2-x1)*f2)/(f2-f1);
        x2=x1-((x1-x2)*f1)/(f1-f2);
        i++;

        if(mod==1){
            printf("x = %0.4f, F(x) = %0.4f, iteration = %0.4u\n", x2, f2, i);
        }
    }while(fabs(f2) > eps && i<1000);

printf("x = %0.f, f(x) = %0.f, iteration = %0.u\n", x2, f2, i);
}

double method_polovina(double x1, double x2, double eps, double mod, double iter ){
    double x, f, f1, f2;
    unsigned int n, N=iter, i=0;
    do{

        f2 = func(x2);
        f1 = func(x1);
            x = (x1 + x2) / 2;
            f = func(x);
            if(f1*f2<0)
                x2 = x;
            else
                x1 = x;
            i++;
            if(mod==1){
            printf("x = %0.4f, F(x) = %0.4f, iteration = %0.4u\n", x, f, i);
        }
        }while(fabs(f) > eps && i < 1000);

    printf("x = %0.4f, F(x) = %0.4f, iteration = %0.4u\n", x, f, i);
}


int main()
{
    int var;
    double x1=0, x2=1, eps, iter, mod, start, stop;

    printf("1 - Method Hords\n2 - Method Polovina\nChoice you method = ");
    scanf("%d", &var);
    printf("Enter data:\n");

        do{
            printf("x1 = ");
            scanf("%lf", &x1);
            printf("x2 = ");
            scanf("%lf", &x2);
        }while((func(x1)*func(x2) > 0));

    printf("eps = ");
    scanf("%lf", &eps);
    printf("Iterations = ");
    scanf("%lf", &iter);
    printf("mode = ");
    scanf("%lf", &mod);

    start = clock();

         if(var==1) method_hord(x1,x2,iter,eps,mod);
    else if(var==2) method_polovina(x1,x2,iter,eps,mod);
    else var3();

    stop = clock();
    printf("\nelapsed time=%lf", (stop-start)/CLK_TCK);
    getch();
   return 0;
}
int var3(){
    printf("Start again\n");
    main();
}
