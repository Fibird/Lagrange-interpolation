#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 10
#define a -5.0
#define b 5.0

#define PI 3.1415926535
//It is no use
//const double h = (b - a) / N;

double func(double x)
{
    double y = (1 / (x * x + 1));
    return y;
}

double omega(double x, int k)
{
    int i;
    double omega = 1.0, Xn;
    for (i = 0; i <= N; i++)
    {
        Xn = 5 * cos((21 - 2 * i) * PI / 22);
        if (i == k)
            continue;
        omega *= (x - Xn);
    }
    return omega;
}

double omega_deri(int k)
{
    int i;
    double omega_deri = 1.0, Xn;
    double Xk = 5 * cos((21 - 2 * k) * PI / 22);
    for (i = 0; i <= N; i++)
    {
        Xn = 5 * cos((21 - 2 * i) * PI / 22);
        if (i == k)
            continue;
        omega_deri *= (Xk - Xn);
    }
    return omega_deri;
}
int main()
{
    double Lagra;
    double Xn, x;
    int i;
    double j;
    FILE *fp = fopen("result.txt", "w+");

    //printf("Please enter x: ");
    //scanf("%lf", &x);
    x = -4.0;
    for (j = a; j < b; j += 0.1)
    {
    x = j;
    for (i = 0; i <= N; i++)
    {
        Xn = 5 * cos((21 - 2 * i) * PI / 22);
        Lagra += ((func(Xn) * omega(x, i)) / omega_deri(i));
    }
    //printf("The approximate value is: %lf\n", Lagra);
    //printf("The real value is: %lf\n", func(x));
    fprintf(fp, "%lf\t%lf\t%lf\n", x, Lagra, func(x));
    Lagra = 0.0;
    }
    fclose(fp);
    return 0;
}
