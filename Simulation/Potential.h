#ifndef POTENTIAL_H
#define POTENTIAL_H

#include <cmath>
#include <string>

//Some possible potential(constant, sinusoidal and parabol)
inline double P_const(double x, double t, double* param)
{
   return *param;
}

inline double P_sinus(double x, double t, double* param)
{
   return param[0] * sin(param[2]*x+param[4]*t+param[3]) + param[1];
}

inline double P_parabol(double x, double t, double* param)
{
   return param[0]*x*x + param[1]*x + param[2];
}


// Generate a table with the potential at each coordinate X
double* P_tableau(double length, size_t N_x, double* param, double (*potential)(double, double, double*));



#endif
