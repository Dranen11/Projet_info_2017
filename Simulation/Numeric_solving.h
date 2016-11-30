//Functions for numerically solving SE
#include <ostream>
#include <complex>

/*1D numeric simulation
output : stream that contain output, each line begin with the time associated to the line and after there are the value on each position
freq_writing : how many time step there are between each writing on the output
N_x : number of space step
N_t : number of time step
m : mass of the particle
potential : Function of position and time and parameters, which return the potential at this point
position : contained the initial position and at the end of the simulation, the last position
 */
void simulation_1D(std::basic_ostream output, size_t freq_writing, double length, size_t N_x, double simulation_time, size_t N_t, double m, complex<double>* position, double (*potential)(double, double, double*), double* param_potential, void (*numeric_solving)(double, size_t, double, double, double, complex<double>*, double (*potential)(double, double, double*), double*));

void Crank_Nicholson_1D(double t, size_t N_x, double dx, double dt, double m, complex<double>* position, double (*potential)(double, double, double*), double* param_potential);


//Function who write the time and the value at position in the output
void writing_position_1D(std::basic_ostream output, double t, complex<double>* position, size_t N_x);
