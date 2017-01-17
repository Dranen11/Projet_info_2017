#include "Numeric_solving.h"
#include "Writing.h"

using namespace std;

void simulation_1D(complex<double>** output double length, size_t N_x, double simulation_time, size_t N_t, double m, complex<double>* position, double* potential, void (*numeric_solving)(double, size_t, double, double, double,complex<double>*, double* potential, double*), size_t freq_writing)
{
   double dt = simulation_time/N_t, dx = length/(N_x-1), t = 0;
   size_t count = 1;
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
         writing_position_1D(output[i], t, position, N_x);
         count = 1;
      }
   }

   if(count > 1)
   {
      writing_position_1D(output[i], t, position, N_x);
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


void Crank_Nicholson_1D(double t, size_t N_x, double dx, double dt, double m, complex<double>* position, double (*potential)(double, double, double*), double* param_potential)
{

}
