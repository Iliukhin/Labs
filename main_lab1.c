#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>



double func(double x)
{
    return x * sin(x);
}
int main()
{

    double x1, x2, x, z, delta, temp;
    unsigned int variant; // 1 or 2
    int N, n;

printf("variant 1: x1 x2 N\n");
printf("variant 2: x1 x2 delta\n");
printf("Choise variant (1 or 2): ");
scanf("%u", &variant);

while( variant !=1  &&  variant !=2   ){
    printf("ERROR. Invalid data \n");
    printf("Choise variant (1 or 2): ");
scanf("%u", &variant);
}

if ( variant==1 ){
    printf("\n\nEnter N ( N>=0 ) :");
    scanf("%u", &N);
    while (N<0 ){
        printf(" N bilshe 0!!! \n");
        printf("N=");
        scanf("%u", &N);
    }

   if( N == 0 ){
    printf("\n\n Good Bye.");
    getch();
    exit (0);
   }
   else{
    printf("\n\nstart value   x1=");
    scanf("%lf", &x1);
    printf("\n\nfinish value   x2=");
    scanf("%lf", &x2);


    if(N==1){
        system("cls");
        printf("Only one\n");
        printf("x1=%.2lf\n", x1);
        printf("x2=%.2lf\n", x2);
        printf("+******+************+************+\n");
        printf("| %4d | %10.2lf | %10.2lf |\n", N, x1, x2 );
        printf("+******+************+************+\n");

    }
else{
   system("cls");

        printf("x1=%.2lf\n", x1);
        printf("x2=%.2lf\n", x2);

        printf("+******+************+************+\n");

        delta = (x2 - x1) / (N - 1);

    for( n=1; n<=N ; n++ ){
        printf("| %4d | %10.2lf | %10.2lf |\n", n, func(x1), x1 );
        printf("+******+************+************+\n");

    x1+=delta;
    if( n%11 == 0){
        printf("press botton\r");
        getch();
    }
    }
}
   }
}
if (variant == 2){

   printf("X1 :");
        scanf("%lf", &x1);
        printf("X2 :");
        scanf("%lf", &x2);
        printf("delta :");
        scanf("%lf", &delta);

        printf("x1=%.2lf\n", x1);
        printf("x2=%.2lf\n", x2);
        printf("delta=%.2lf\n", delta);

N=(x2-delta)/(x1);
    for( n=1; n<=N ; n++ ){

        printf("+******+************+************+\n");
        printf("| %4d | %10.2lf | %10.2lf |\n", n, func(x1), x1 );

if( n%11 == 0){
        printf("press botton\r");
        getch();    }
x1+=delta;
}
        printf("+******+************+************+\n");
        printf("x1=%.2f  x2=%.2f delta=%.2f\n", x1, x2, delta);
    }

    return 0;
}


