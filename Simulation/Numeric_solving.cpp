#include "Numeric_solving.h"
#include "Constant.h"
#include "Algebra.h"
#include <complex>

using namespace std;
using namespace std::literals::complex_literals;

void simulation_1D(complex<double>** output, double length, size_t N_x, double simulation_time, size_t N_t, double m, complex<double>* position, double* potential, void (*numeric_solving)(size_t, double, double, double,complex<double>*, double* potential), size_t freq_writing)
{
   double dt = simulation_time/N_t, dx = length/(N_x-1), t = 0;
   size_t count = 1, nb_w = 1;
   output = (complex<double>**) malloc(number_output(N_t, freq_writing)*sizeof(complex<double>*));
   for(size_t i = 0; i <= N_t; i++)
   {
      output[i] = (complex<double>*) malloc((N_x+1)*sizeof(complex<double>));
   }
   writing_position_1D(output[0], t, position, N_x);

   for(size_t i = 1; i <= N_t; i++)
   {
      t+=dt;
      numeric_solving(N_x, dx, dt, m, position, potential);

      if(count++ >= freq_writing)
      {
         writing_position_1D(output[nb_w++], t, position, N_x);
         count = 1;
      }
   }

   if(count > 1)
   {
      writing_position_1D(output[nb_w++], t, position, N_x);
   }
}

void simulation_1D(std::complex<double>** output, double length, size_t N_x, double simulation_time, size_t N_t, double m, std::complex<double>* position, double (*potential)(double, double, double*), double* param_potential, void (*numeric_solving)(double, size_t, double, double, double, std::complex<double>*, double (*potential)(double, double, double*), double*), size_t freq_writing)
{
   double dt = simulation_time/N_t, dx = length/(N_x-1), t = 0;
   size_t count = 1, nb_w = 1;
   output = (complex<double>**) malloc(number_output(N_t, freq_writing)*sizeof(complex<double>*));
   for(size_t i = 0; i <= N_t; i++)
   {
      output[i] = (complex<double>*) malloc((N_x+1)*sizeof(complex<double>));
   }
   writing_position_1D(output[0], t, position, N_x);

   for(size_t i = 1; i <= N_t; i++)
   {
      t+=dt;
      numeric_solving(t, N_x, dx, dt, m, position, potential, param_potential);

      if(count++ >= freq_writing)
      {
         writing_position_1D(output[nb_w++], t, position, N_x);
         count = 1;
      }
   }

   if(count > 1)
   {
      writing_position_1D(output[nb_w++], t, position, N_x);
   }
}

void simulation_1D(Writing& output, double length, size_t N_x, double simulation_time, size_t N_t, double m, complex<double>* position, double (*potential)(double, double, double*), double* param_potential, void (*numeric_solving)(double, size_t, double, double, double,complex<double>*, double (*potential)(double, double, double*), double*))
{
   double dt = simulation_time/N_t, dx = length/(N_x-1), t = 0;
   size_t count = 1;
   writing_position_1D(output, t, position, N_x);

   for(size_t i = 1; i <= N_t; i++)
   {
      t+=dt;
      numeric_solving(t, N_x, dx, dt, m, position, potential, param_potential);

      if(count++ >= output.freq_writing)
      {
	      writing_position_1D(output, t, position, N_x);
	      count = 1;
      }
   }

   if(count > 1)
   {
      writing_position_1D(output, t, position, N_x);
   }
}

void simulation_1D(Writing &output, double length, size_t N_x, double simulation_time, size_t N_t, double m, std::complex<double>* position, double* potential, void (*numeric_solving)(size_t, double, double, double,std::complex<double>*, double* potential))
{
   double dt = simulation_time/N_t, dx = length/(N_x-1), t = 0;
   size_t count = 1;
   writing_position_1D(output, t, position, N_x);

   for(size_t i = 1; i <= N_t; i++)
   {
      t+=dt;
      numeric_solving(N_x, dx, dt, m, position, potential);

      if(count++ >= output.freq_writing)
      {
         writing_position_1D(output, t, position, N_x);
         count = 1;
      }
   }

   if(count > 1)
   {
      writing_position_1D(output, t, position, N_x);
   }
}

void simulation_1D(complex<double>** output, double length, size_t N_x, double simulation_time, size_t N_t, double m, complex<double>* position, double** potential, void (*numeric_solving)(size_t, double, double, double,complex<double>*, double* potential), size_t freq_writing)
{
   double dt = simulation_time/N_t, dx = length/(N_x-1), t = 0;
   size_t count = 1, nb_w = 1;
   output = (complex<double>**) malloc(number_output(N_t, freq_writing)*sizeof(complex<double>*));
   for(size_t i = 0; i <= N_t; i++)
   {
      output[i] = (complex<double>*) malloc((N_x+1)*sizeof(complex<double>));
   }
   writing_position_1D(output[0], t, position, N_x);

   for(size_t i = 1; i <= N_t; i++)
   {
      t+=dt;
      numeric_solving(N_x, dx, dt, m, position, potential[i-1]);

      if(count++ >= freq_writing)
      {
         writing_position_1D(output[nb_w++], t, position, N_x);
         count = 1;
      }
   }

   if(count > 1)
   {
      writing_position_1D(output[nb_w++], t, position, N_x);
   }
}

void simulation_1D(Writing &output, double length, size_t N_x, double simulation_time, size_t N_t, double m, std::complex<double>* position, double** potential, void (*numeric_solving)(size_t, double, double, double,std::complex<double>*, double* potential))
{
   double dt = simulation_time/N_t, dx = length/(N_x-1), t = 0;
   size_t count = 1;
   writing_position_1D(output, t, position, N_x);

   for(size_t i = 1; i <= N_t; i++)
   {
      t+=dt;
      numeric_solving(N_x, dx, dt, m, position, potential[i-1]);

      if(count++ >= output.freq_writing)
      {
         writing_position_1D(output, t, position, N_x);
         count = 1;
      }
   }

   if(count > 1)
   {
      writing_position_1D(output, t, position, N_x);
   }
}

void Crank_Nicholson_1D(double t, size_t N_x, double dx, double dt, double m, complex<double>* position, double (*potential)(double, double, double*), double* param_potential)
{
   complex<double> alpha = 1.0i*H_BAR/(2.0*m), beta = alpha/(2.0*dx*dx), calcul1;
   complex<double> *lambda, *u, *sub_diag;
   lambda = (complex<double>*) malloc(N_x*sizeof(complex<double>));
   u = (complex<double>*) malloc(N_x*sizeof(complex<double>));
   sub_diag = (complex<double>*) malloc((N_x-1)*sizeof(complex<double>));
   

   calcul1 = potential(0, t, param_potential)/(2.0*1.0i*H_BAR);
   lambda[0] = (1.0/dt)+2.0*beta-calcul1;
   u[0] = position[0] * ((1.0/dt)-2.0*beta+calcul1) + beta * position[1];
   sub_diag[0] = beta;
   for(size_t i = 1; i < (N_x-1); i++)
   {
      calcul1 = potential(i*dx, t, param_potential)/(2.0*1.0i*H_BAR);
      lambda[i] = (1.0/dt)+2.0*beta-calcul1;
      u[i] = beta*position[i-1] + position[i]*((1.0/dt)-2.0*beta+calcul1) + beta*position[i+1];
      sub_diag[i] = beta;
   }
   calcul1 = potential((N_x-1)*dx, t, param_potential)/(2.0*1.0i*H_BAR);
   lambda[N_x-1] = (1.0/dt)+2.0*beta-calcul1;
   u[N_x-1] = position[N_x-1] * ((1.0/dt)-2.0*beta+calcul1) + beta * position[N_x-2];

   free(position);
   position = solve_cholesky_tri_diag<complex<double>>(sub_diag, lambda, u, N_x);

   free(lambda);
   free(u);
   free(sub_diag);
}

void Crank_Nicholson_1D(size_t N_x, double dx, double dt, double m, complex<double>* position, double *potential)
{
   complex<double> alpha = 1.0i*H_BAR/(2.0*m), beta = alpha/(2.0*dx*dx), calcul1;
   complex<double> *lambda, *u, *sub_diag;
   lambda = (complex<double>*) malloc(N_x*sizeof(complex<double>));
   u = (complex<double>*) malloc(N_x*sizeof(complex<double>));
   sub_diag = (complex<double>*) malloc((N_x-1)*sizeof(complex<double>));
   

   calcul1 = potential[0]/(2.0*1.0i*H_BAR);
   lambda[0] = (1.0/dt)+2.0*beta-calcul1;
   u[0] = position[0] * ((1.0/dt)-2.0*beta+calcul1) + beta * position[1];
   sub_diag[0] = beta;
   for(size_t i = 1; i < (N_x-1); i++)
   {
      calcul1 = potential[i]/(2.0*1.0i*H_BAR);
      lambda[i] = (1.0/dt)+2.0*beta-calcul1;
      u[i] = beta*position[i-1] + position[i]*((1.0/dt)-2.0*beta+calcul1) + beta*position[i+1];
      sub_diag[i] = beta;
   }
   calcul1 = potential[N_x-1]/(2.0*1.0i*H_BAR);
   lambda[N_x-1] = (1.0/dt)+2.0*beta-calcul1;
   u[N_x-1] = position[N_x-1] * ((1.0/dt)-2.0*beta+calcul1) + beta * position[N_x-2];

   free(position);
   position = solve_cholesky_tri_diag<complex<double>>(sub_diag, lambda, u, N_x);

   free(lambda);
   free(u);
   free(sub_diag);
}