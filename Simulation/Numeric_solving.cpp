#include "Numeric_solving.h"

using namespace std;

void simulation_1D(basic_ostream output, size_t freq_writing, double length, size_t N_x, double simulation_time, size_t N_t, double* position,double (*potential)(double, double, double*), double* param_potential, void (*numeric_solving)(double, size_t, double, double*, double (*potential)(double, double, double*), double*))
{
   double dt = simulation_time/N_t, dx = lenght/(N_x-1), t = 0;
   size_t count = 1;
   writing_position_1D(output, t, position, N_x);
   
   for(size_t i = 1; i <= N_t; i++)
   {
      numeric_solving(t, N_x, dx, dt, position, potential, param_potential);

      if(count++ >= freq_writing)
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

void Crank_Nicholson_1D(double t, size_t N_x, double dx, double dt, double* position, double (*potential)(double, double, double*), double* param_potential);

void writing_position_1D(std::basic_ostream output, double t, double* position, size_t N_x)
{
   output << t << " ";
   for(size_t i = 0; i < N_x; i++)
   {
      output << position[i] << " ";
   }
   output << endl;
}
