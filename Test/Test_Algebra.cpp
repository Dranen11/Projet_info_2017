#include <iostream>
#include <cstdlib>
#include <cmath>
#include "../Simulation/Algebra.h"
#define SIZE 10

using namespace std;

int main()
{
   bool verif = true;
   double epsilon = 1e-15;
   double *diag = (double*) malloc(SIZE*sizeof(double)), *sub_diag = (double*) malloc((SIZE-1)*sizeof(double)), *x = (double*) malloc(SIZE*sizeof(double)), *y;

   cout << "Test Cholesky decomposition and solving" << endl;
   cout << "Test 1 : Unite" << endl;

   for(int i = 0; i < SIZE; i++)
   {
      x[i] = 1;
      diag[i] = 1;
      if(i < (SIZE-1))
      {
	 sub_diag[i] = 0;
      }
   }
   y* = solve_cholesky_tri_diag<double>(sub_diag, diag, x, std::size_t SIZE);
   for(int i = 0; i < SIZE; i++)
   {
      if(abs(y[i]-1)>epsilon)
      {
	 verif = false;
      }
   }
   free(y);
   
   if(verif)
   {
      cout <<"Valide"<<endl;
   }
   else
   {
      cout << "Echec"<<endl;
   }

   free(x);
   free(diag);
   free(sub_diag);

   return 0;
}
