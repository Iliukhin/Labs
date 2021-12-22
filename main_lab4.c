#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <conio.h>

void Max_Min(int **a, int Na);
void Dobytok(int **a,int **b,int Na,int Nb,int Mb);
void Transp(int **b,int Nb,int Mb);
void Sorting_A(int **a,int Na);
void Suma(int **a, int **b,int Na,int Nb,int Mb);

void Max_Min(int **a,int Na)
{
    int max = 1;
    int min = 0;
    for(int i = 0; i < Na; i++ )
    {
        for (int j = Na - 1; j > i; j--)
        {
            if(a[i][j] > max)
                max = a[i][j];
            else max;
            if(a[i][j] < min)
                min = a[i][j];
            else min;
        }
    }
    printf("\n********************");
    printf("\nМаксимум матриці A: %d",max);
    printf("\nМінімум матриці A: %d",min);
    min = 1;
    max = 0;
    for(int i = 0;i < Na; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(a[i][j] > max)
                max = a[i][j];
            else max;
            if(a[i][j] < min)
                min = a[i][j];
            else min;
        }
    }
    printf("\n********************");
    printf("\nМаксимум матриці B: %d",max);
    printf("\nМінімум матриці В: %d",min);
    printf("\n********************");
}


void Dobytok(int **a,int **b,int Na,int Nb,int Mb)
{
    int **temp;
    temp = malloc(Nb * sizeof(int *));
    if(Na != Nb )
    {
        printf("Помилка!");
        return;
    }

    for(int i = 0; i < Nb;i++)
    {
        for (int j = 0; j < Mb;j++)
        {
            temp[i][j] = a[i][j] * b[i][j];
        }
    }
    for(int i = 0; i < Nb; i++)
    {
        for(int j = 0; j < Mb; j++)
        {
            printf("%d\t", temp[i][j]);
        }
        printf("\n");
    }
}



void Transp(int **b, int Nb, int Mb)
{
    int* a;
    int i, j;
    a = (int*)malloc(Mb * sizeof(int*));
    for (i = 0; i < Nb; i++)
    {
        for (j = 0; j < Mb; j++)
        {
            *(a + i * Nb + j) = *(b + i * Nb + j);
        }
    }
    for (i = 0; i < Nb; i++)
    {
        for (j = 0; j < Mb; j++)
        {
            printf("%5d ", *(a + i * Nb + j));
        }
        printf("\n\n");
    }
    getch();
}


void Sorting_A(int **a,int Na)
{
    int row;
    int arr[Na];
    printf("Вибір рядка: \t");
    scanf("%d",&row);
    row--;
    for(int i = 0 ; i < Na + 1; i++)
    {
       for(int j = 0 ; j < Na - i ; j++)
        {
           if(a[row][j] > a[row][j+1])
            {
                int sort = a[row][j];
                a[row][j] = a[row][j+1];
                a[row][j+1] = sort;
            }
        }
    }
    printf("\n");
    for (int i = 0;i < Na + 1;i++)
    {
        printf("%d\t", a[row][i]);
    }
}


void Suma(int **a, int **b,int Na,int Nb,int Mb)
{
    int sum = 0;
    printf("Сума елементів матриці A:\n");
    for (int i = 0; i < Na; i++)
    {
        for(int j = 0; j < Na; j++)
        {
            sum += a[i][j];
        }
        printf("A: %d\t",sum);
        sum = 0;
    }
    sum = 0;
    printf("\nСума елементів матриці B:\n");
    for (int i = 0; i < Nb; i++)
    {
        for(int j = 0; j < Mb; j++)
        {
            sum += b[j][i];
        }
        printf("B: %d\t",sum);
        sum = 0;
    }
    printf("\n\n");
}


int main()
{
    int **a;
    int **b;
    int i, j, Na = 0, Nb = 0, Mb = 0;
    system("chcp 1251");
    system("cls");
    printf("Введіть матрицю A:");
        scanf("%d",&Na);
    printf("Введіть матрицю B:");
        scanf("%d",&Nb);
    printf("Рядків B:");
        scanf("%d",&Mb);

    a = malloc(Na * sizeof(int *));

    for(int i=0; i < Na; i++)
    {
        a[i] =  malloc(Na * sizeof(int));
    }
    printf("Ввод матриці A:\n");
            for (int i = 0; i < Na; i++)
            {
                for (int j = 0; j < Na; j++)
                {
                    printf("a[%d][%d] = ", i, j);
                    scanf("%d", &a[i][j]);
                }
            }
        system ("cls");
    printf("Матриця A:\n");
        for (int i = 0; i < Na; i++)
        {
            for (int j = 0; j < Na; j++)
            {
                printf("%d \t", a[i][j]);
            }
            printf("\n");
        }

        b = malloc(Mb * sizeof(int *));

        for (int i = 0; i < Mb; i++)
        {
            b[i] =  malloc(Nb * sizeof(int));
        }
    printf("Ввод матриці B:\n");
        for (int i = 0; i < Mb; i++)
        {
            for (int j = 0; j < Nb; j++)
            {
                printf("b[%d][%d] = ", i, j);
                scanf("%d", &b[i][j]);
            }
        }

    printf("Матриця B:\n");
        for (int i = 0; i < Mb; i++)
        {
            for (int j = 0; j < Nb; j++)
            {
                printf("%d \t", b[i][j]);
            }
            printf("\n");
        }

        int var = 0;
        printf("1. Знайти максимальний та мінімальний елемент\n");
        printf("2. Множення матриць\n");
        printf("3. Транспонтування матриці B\n");
        printf("4. Виконати сортування\n");
        printf("5. Сума матриць\n");

        printf("Вибір: ",var);
            scanf("%d", &var);
        if(var == 1)
                Max_Min(a,Na);
        else if(var == 2)
                Dobytok(a,b,Na,Nb,Mb);
        else if(var == 3)
                Transp(b,Nb,Mb);
        else if(var == 4)
                Sorting_A(a,Na);
        else if(var == 5)
                Suma(a,b,Na,Nb,Mb);
    return 0;
}
