#include "Potential.h"
#include <cstdlib>

double* P_tableau(double length, size_t N_x, double* param, double (*potential)(double, double, double*))
{
   double dx = length/(N_x-1);
   double *pot = (double*) malloc(N_x*sizeof(double));
      
   for(size_t i = 0; i < N_x; i++)
   {
      pot[i] = potential(i*dx, 0, param);
   }
   
   return pot;
}

double** P_tableau(double length, size_t N_x, double dt, size_t N_t, double* param, double (*potential)(double, double, double*))
{
   double dx = length/(N_x-1);
   double **pot = (double**) malloc(N_t*sizeof(double));
   
   for (size_t j = 0; j < N_t; j++)
   {
   	pot[j] = (double*) malloc(N_x*sizeof(double));
      for(size_t i = 0; i < N_x; i++)
   	{
      	pot[j][i] = potential(i*dx, (j+1)*dt, param);
   	}
   }   
   
   return pot;
}