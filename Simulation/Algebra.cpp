#include "Algebra.h"
#include <cmath>

using namespace std;

template<typename Type> Type* solve_cholesky_tri_diag(Type* low_diag, Type* diag, Type* u, size_t n)
{
   Type *result, *dec_diag, *dec_low_diag; //Variables dec are think to store the decomposition
   
   result = (Type*) malloc(n*sizeof(Type));
   dec_diag = (Type*) malloc(n*sizeof(Type));
   dec_low_diag = (Type*) malloc((n-1)*sizeof(Type));


   //Decomposition
   dec_diag[0] = sqrt(low_diag[0]);
   for(size_t i = 0; i < (n-1); i++)
   {
      dec_low_diag[i] = low_diag[i]/dec_diag[i];
      dec_diag[i+1] = sqrt(diag[i+1]-dec_low_diag[i]*dec_low_diag[i]);
   }

   //Solve Equation
   result[0] = u[0];
   for(size_t i = 1; i < n; i++)
   {
      result[i] = (u[i]-dec_low_diag[i-1]*result[i-1])/dec_diag[i];
   }

   result[n-1] = result[n-1];
   for(size_t i = n-2; i-- > 0;)
   {
      result[i] = (result[i]-dec_low_diag[i+1]*result[i+1])/dec_diag[i];
   }

   free(dec_diag);
   free(dec_low_diag);
   return result;
}
