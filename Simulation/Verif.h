#ifndef VERIF_H
#define VERIF_H
#include <cmath>
#include <iostream>
#include <string>

void verif_nan(std::string f_appel,std::complex<double>* tab, size_t N_x, size_t n_t)
{
   for(size_t i = 0; i < N_x; i++)
   {
      if(std::isnan(real(tab[i])) || std::isnan(imag(tab[i])))
	  {
		 if(i > 0){std::cerr<<std::endl <<"i-1 "<<tab[i-1]<<std::endl;}
		   std::cerr << "NAN" << std::endl << f_appel << std::endl << i << " " << tab[i] <<std::endl<< n_t<<std::endl;
		   throw "NaN";
	  }
	if(std::isinf(real(tab[i])) || std::isinf(imag(tab[i])))
	  {
		 if(i > 0){std::cerr<<std::endl <<"i-1 "<<tab[i-1]<<std::endl;}
		   std::cerr << "inf" << std::endl << f_appel << std::endl << i << " " << tab[i] <<std::endl<< n_t<<std::endl;
		   throw "inf";
	  }
   }
}

void verif_nan(std::string f_appel,double* tab, size_t N_x, size_t n_t)
{
   for(size_t i = 0; i < N_x; i++)
   {
      if(std::isnan(tab[i]))
	  {
		   std::cerr << std::endl << f_appel << std::endl << i <<std::endl<< n_t<<std::endl;
		   throw "NaN";
	  }
      if(std::isinf(tab[i]))
	  {
		   std::cerr << std::endl << f_appel << std::endl << i <<std::endl<< n_t<<std::endl;
		   throw "NaN";
	  }
   }
}

void integral(std::complex<double>* tab, size_t N_x, size_t n_t, double dx)
{
	double integrale = 0;
	for(size_t i = 0; i < N_x-1; i++)
	{
		integrale += dx*(norm(tab[i])+norm(tab[i+1]))/2.;
	}
	if((integrale-1.)>1e-10){std::cerr << n_t<< " int : " << integrale << std::endl;}
}
#endif
