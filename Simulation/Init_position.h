#ifndef INIT_POSITION_H
#define INIT_POSITION_H

#include <complex>

std::complex<double>* paquet_gaussien(double length, size_t N_x, double* param)
{
	std::complex<double> *output = (complex<double>*) malloc(N_x*sizeof(complex<double>));
	double dx = length/((double)N_x-1.)

	for(size_t i = 0; i < N_x; i++)
	{
		output[i] = pow(2/(M_PI*param[0]*param[0]),0.25) * exp(1.0i*param[1]*dx*(double)i) * exp(-pow((i*dx-param[2])/param[0],2));		
	}

	return output;
}

std::complex<double>* paquet_uniforme(double length, size_t N_x, double* param)
{
	std::complex<double> *output = (complex<double>*) malloc(N_x*sizeof(complex<double>));

	for(size_t i = 0; i < N_x; i++)
	{
		output[i] = 1./((double)N_x-1.);		
	}

	return output;	
}

#endif