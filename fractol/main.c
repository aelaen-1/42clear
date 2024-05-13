#include "fractol.h"
#ifndef
 #define max_i = 100
#endif

typedef struc s_complex
{
    double real; 
    double i;  
}   t_complex;

int module(t_complex z)
{

}
int main()
{
    t_complex z;
    t_complex c;
    double  tmp_real;

    int iter;
    int abs;

    iter = 0;
    z.real = 0;
    z.i = 0;

    c.real = 5;
    c.i = 2;

    while ((abs <= 2) && (iter <= MAX_I))
    {
        tmp_real = z.real * z.real - z.i * z.i;
        z.i = 2 * z.real * z.i;
        z.real = tmp_real + c.real;
        z.i = z.i + c.i;
        iter++;
    }
}