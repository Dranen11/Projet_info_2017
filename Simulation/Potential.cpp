#include "Potential.h"
#include <cstdlib>

double* P_tableau(double length, size_t N_x, double* param, double (*potential)(double, double, double*))
{
   double dx = lenght/(N_x-1);
   double *pot = (double*) malloc(N_x*sizeof(double));
      
   for(size_t i = 0; i < N_x; i++)
   {
      pot[i] = potential();
   }
   
   return pot;
}
