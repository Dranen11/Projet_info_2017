#ifndef ALGEBRA_H
#define ALGEBRA_H

#include <cstdlib>

//Solving a symmetric linear system using alternative cholesky decomposition (LDLt)
template<typename Type>
Type* solve_cholesky_tri_diag(Type* low_diag, Type* diag, Type* u, std::size_t n)
{
   Type *result, *dec_diag, *dec_low_diag; //Variables dec are think to store the decomposition
   
   result = (Type*) malloc(n*sizeof(Type));
   dec_diag = (Type*) malloc(n*sizeof(Type));
   dec_low_diag = (Type*) malloc((n-1)*sizeof(Type));


   //Decomposition
   dec_diag[0] = diag[0];
   for(size_t i = 0; i < (n-1); i++)
   {
      dec_low_diag[i] = low_diag[i]/dec_diag[i];
      dec_diag[i+1] = diag[i+1]-dec_diag[i]*dec_low_diag[i]*dec_low_diag[i];
   }

   //Solve Equation
   result[0] = u[0];
   for(size_t i = 1; i < n; i++)
   {
      result[i] = u[i]-dec_low_diag[i-1]*result[i-1];
   }

   result[n-1] = result[n-1]/dec_diag[n-1];
   for(size_t i = n-1; i-- > 0;)
   {
      result[i] = (result[i]/dec_diag[i])-dec_low_diag[i]*result[i+1];
   }

   free(dec_diag);
   free(dec_low_diag);
   return result;
}

//Solving a linear system using LU decomposition
template<typename Type>
Type* solve_LU_tri_diag(Type* low_diag, Type* diag, Type* upper_diag, Type* u, std::size_t n)
{
   Type *result, *result_int, *dec_diag, pivot; //Variables dec are think to store the decomposition
   
   result = (Type*) malloc(n*sizeof(Type));
   result_int = (Type*) malloc(n*sizeof(Type));
   dec_diag = (Type*) malloc(n*sizeof(Type));

   //Decomposition and first step of solving
   dec_diag[0] = diag[0];
   result_int[0] = u[0];
   for(size_t i = 0; i < (n-1); i++)
   {
      pivot = low_diag[i]/dec_diag[i];
      dec_diag[i+1] = diag[i+1] - pivot*upper_diag[i];
      result_int[i+1] = u[i+1]-pivot*result_int[i];
   }

   //Second step of solving
   result[n-1] = result_int[n-1]/dec_diag[n-1];
   for(size_t i = n-1; i-- > 0;)
   {
      result[i] = (result_int[i]-upper_diag[i]*result[i+1])/dec_diag[i];
   }

   free(dec_diag);
   free(result_int);
   return result;
}

/*Solving a symmetric linear system using cholesky decomposition (LLt)
template<typename Type>
Type* solve_cholesky_tri_diag(Type* low_diag, Type* diag, Type* u, std::size_t n)
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
}*/

#endif