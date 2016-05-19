#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 40
#define a -5.0
#define b 5.0

const double h = (b - a) / N;

double func(double x)
{
    double y = (1 / (x * x + 1));
    return y;
}

double omega(double x, int k)
{
    int i;
    double omega = 1.0, Xn;
    for (i = 0; i < N; i++)
    {
        Xn = a + i * h;
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
    double Xk = a + k * h;
    for (i = 0; i < N; i++)
    {
        Xn = a + i * h;
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

    printf("Please enter x: ");
    scanf("%lf", &x);

    for (i = 0; i < N; i++)
    {
        Xn = a + i * h;
        Lagra += ((func(Xn) * omega(x, i)) / omega_deri(i));
    }

    printf("The approximate value is: %lf\n", Lagra);
    printf("The real value is: %lf\n", func(x));
    return 0;
}
