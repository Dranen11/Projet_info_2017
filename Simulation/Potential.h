#ifndef POTENTIAL_H
#define POTENTIAL_H

#include <cmath>
#include <string>

//Some possible potential(constant, sinusoidal, parabol and a well)

// param = valeur de base
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

//param[0] et param[1], limite à gauche et à droite, param[2] energie du puit et param[3] energie de base
inline double P_puit(double x, double t, double* param)
{
   if(x > param[0] && x < param[1])
   {
   		return param[2];
   }
   
   return param[3];
}

inline double P_def(double x, double t, double* param)
{
	return param[0]/pow(cosh(x/param[1]),2.0);
}

// Generate a table with the potential at each coordinate X
double* P_tableau(double length, size_t N_x, double* param, double (*potential)(double, double, double*));

// Generate a table with the potential at each coordinate X and time t
double** P_tableau(double length, size_t N_x, double dt, size_t N_t, double* param, double (*potential)(double, double, double*));


#endif
