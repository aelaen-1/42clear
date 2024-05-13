# ifndef
 # define max_i = 80
# endif

int julia(int u, int complex)
{
    int iter;

    if (u == 0)
        mandelbrot(complex);
    else
    {
        iter = 0;
        while (u <= 2 && iter < max_i)
        {
            u = u*u + complex;
            iter++;
        }
        return(iter);
    }
}


int mandelbrot(int complex)
{
    int iter; 
    int u;

    u = 0;
    iter = 0;

    while (u <= 2 && iter < max_i)
    {
        u = u*u + complex;
        iter++;
    }
    return (iter);
    }


    void plot_number(int u, int complex) /*first term, c*/
    {
        int iter;

        iter = julia(u, complex);
        if (iter == max_i)
            /*pixel noir*/
        else
            /*pixel en fonction de la valeur d'iter*/

    }