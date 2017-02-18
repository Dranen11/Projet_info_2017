#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <complex>
#include <chrono>
#include <random>
#include "../Simulation/Algebra.h"

#define MIN_SIZE 10
#define MAX_SIZE 300
#define NUMBER_TEST 100
#define PRECISION 1e-4

using namespace std;

random_device rd;
mt19937 gen(rd());
uniform_real_distribution<> dis(1, 10000);
double alea()
{
   return dis(gen);
}

void impr_vec(double* vec, size_t n)
{
   for(size_t i = 0; i < n; i++)
   {
      cout << vec[i] << " ";
   }
   cout << endl;
}

void impr_tri_diag(double* low, double* diag, double* upper, size_t n)
{
   for(size_t i = 0; i < n; i++)
   {
      for(size_t j = 0; j < n; j++)
      {
         if(i == j)
         {
            cout << diag[i];
         }
         else if(i == j+1)
         {
            cout << low[j];
         }
         else if (i+1 == j)
         {
            cout << upper[i];
         }
         else
         {
            cout << 0;
         }
         cout << " ";
      }
      cout << endl;
   }
}


void test1_unity();
void test2_random();
void test3_complex_random();

int main()
{
   cout << "Test decomposition de Cholesky and LU and resolution systeme" << endl;
   test1_unity();
   test2_random();
   test3_complex_random();

   return 0;
}

void test1_unity()
{
   bool verif_Cho = true;
   bool verif_LU = true;

   for(size_t j = MIN_SIZE; j <= MAX_SIZE; j++)
   {
      double epsilon = PRECISION;
      double *diag = (double*) malloc(j*sizeof(double)), *sub_diag = (double*) malloc((j-1)*sizeof(double)), *upper_diag = (double*) malloc((j-1)*sizeof(double)), *x = (double*) malloc(j*sizeof(double)), *y_LU, *y_Cho;

      for(size_t i = 0; i < j; i++)
      {
         x[i] = 1;
         diag[i] = 1;
         if(i < (j-1))
         {
           sub_diag[i] = 0;
           upper_diag[i] = 0;
         }
      }
      y_LU = solve_LU_tri_diag<double>(sub_diag, diag, upper_diag, x, j);
      y_Cho = solve_cholesky_tri_diag<double>(sub_diag, diag, x, j);
      for(size_t i = 0; i < j; i++)
      {
         if(abs(y_Cho[i]-1)>epsilon)
         {
           verif_Cho = false;
         }
         if(abs(y_LU[i]-1)>epsilon)
         {
           verif_LU = false;
         }
      }
      free(y_Cho);
      free(y_LU);
      free(x);
      free(diag);
      free(sub_diag);
      free(upper_diag);
   }

   cout << "Test 1 LU : Unite" << endl;
   if(verif_LU)
   {
      cout <<"Valide"<<endl;
   }
   else
   {
      cout << "Echec"<<endl;
   }

   cout << "Test 1 Cholesky : Unite" << endl;
   if(verif_Cho)
   {
      cout <<"Valide"<<endl;
   }
   else
   {
      cout << "Echec"<<endl;
   }
}

void test2_random()
{
   bool verif_Cho = true;
   bool verif_LU = true;
   double erreur_cho = 0.;
   double erreur_LU = 0.;
   
   for(size_t j = MIN_SIZE; j <= MAX_SIZE; j++)
   {
      for(size_t k = 0; k < NUMBER_TEST; k++)
      {
         double epsilon = PRECISION;
         double *diag = (double*) malloc(j*sizeof(double)), *sub_diag = (double*) malloc((j-1)*sizeof(double)), *upper_diag = (double*) malloc((j-1)*sizeof(double)), *x = (double*) malloc(j*sizeof(double)), *y_LU, *y_Cho;
   
         for(size_t i = 0; i < j; i++)
         {
            x[i] = alea();
            diag[i] = alea();
            if(i < (j-1))
            {
              sub_diag[i] = alea();
              upper_diag[i] = alea();
            }
         }

         y_LU = solve_LU_tri_diag<double>(sub_diag, diag, upper_diag, x, j);
         y_Cho = solve_cholesky_tri_diag<double>(sub_diag, diag, x, j);

         for(size_t i = 1; i < (j-1); i++)
         {
            if(abs((sub_diag[i-1]*y_Cho[i-1]+diag[i]*y_Cho[i]+sub_diag[i]*y_Cho[i+1])-x[i]) > epsilon)
            {
              verif_Cho = false;
              erreur_cho = fmax(abs((sub_diag[i-1]*y_Cho[i-1]+diag[i]*y_Cho[i]+sub_diag[i]*y_Cho[i+1])-x[i]),erreur_cho);
            }
            if(abs((sub_diag[i-1]*y_LU[i-1]+diag[i]*y_LU[i]+upper_diag[i]*y_LU[i+1])-x[i]) > epsilon)
            {
              verif_LU = false;
              erreur_LU = fmax(abs((sub_diag[i-1]*y_LU[i-1]+diag[i]*y_LU[i]+upper_diag[i]*y_LU[i+1])-x[i]), erreur_LU);
            }
         }
         if(abs((diag[0]*y_Cho[0]+sub_diag[0]*y_Cho[1])-x[0]) > epsilon)
         {
            verif_Cho = false;
         }
         if(abs((sub_diag[j-2]*y_Cho[j-2]+diag[j-1]*y_Cho[j-1])-x[j-1]) > epsilon)
         {
           verif_Cho = false;
         }
         if(abs((diag[0]*y_LU[0]+upper_diag[0]*y_LU[1])-x[0]) > epsilon)
         {
            verif_LU = false;
            erreur_LU = fmax(abs((diag[0]*y_LU[0]+upper_diag[0]*y_LU[1])-x[0]), erreur_LU);
         }
         if(abs((sub_diag[j-2]*y_LU[j-2]+diag[j-1]*y_LU[j-1])-x[j-1]) > epsilon)
         {
           verif_LU = false;
           erreur_LU = fmax(abs((sub_diag[j-2]*y_LU[j-2]+diag[j-1]*y_LU[j-1])-x[j-1]), erreur_LU);
         }

         free(y_Cho);
         free(y_LU);
         free(x);
         free(diag);
         free(sub_diag);
         free(upper_diag);
      }
   }

   cout << "Test 2 LU : Aleatoire" << endl;
   if(verif_LU)
   {
      cout <<"Valide"<<endl;
   }
   else
   {
      cout << "Echec"<<endl;
      cout << erreur_LU << endl;
   }

   cout << "Test 2 Cholesky : Aleatoire" << endl;
   if(verif_Cho)
   {
      cout <<"Valide"<<endl;
   }
   else
   {
      cout << "Echec"<<endl;
      cout << erreur_cho << endl;
   }
}

void test3_complex_random()
{
   bool verif_Cho = true;
   bool verif_LU = true;
   double erreur_LU = 0, erreur_cho = 0;

   for(size_t j = MIN_SIZE; j <= MAX_SIZE; j++)
   {
      for(size_t k = 0; k < NUMBER_TEST; k++)
      {
         double epsilon = PRECISION;
         complex<double> *diag = (complex<double>*) malloc(j*sizeof(complex<double>)), *sub_diag = (complex<double>*) malloc((j-1)*sizeof(complex<double>)), *upper_diag = (complex<double>*) malloc((j-1)*sizeof(complex<double>)), *x = (complex<double>*) malloc(j*sizeof(complex<double>)), *y_LU, *y_Cho;

         for(size_t i = 0; i < j; i++)
         {
            x[i] = (double) alea() + 1.0i * (double) alea();
            diag[i] = (double) alea() + 1.0i*(double) alea();
            if(i < (j-1))
            {
              sub_diag[i] = (double) alea() + 1.0i * (double) alea();
              upper_diag[i] = (double) alea() + 1.0i * (double) alea();
            }
         }

         y_LU = solve_LU_tri_diag<complex<double>>(sub_diag, diag, upper_diag, x, j);
         y_Cho = solve_cholesky_tri_diag<complex<double>>(sub_diag, diag, x, j);
      

         for(size_t i = 1; i < (j-1); i++)
         {
            if(abs((sub_diag[i-1]*y_Cho[i-1]+diag[i]*y_Cho[i]+sub_diag[i]*y_Cho[i+1])-x[i]) > epsilon)
            {
              verif_Cho = false;
              erreur_cho = fmax(abs((sub_diag[i-1]*y_Cho[i-1]+diag[i]*y_Cho[i]+sub_diag[i]*y_Cho[i+1])-x[i]),erreur_cho);
            }
            if(abs((sub_diag[i-1]*y_LU[i-1]+diag[i]*y_LU[i]+upper_diag[i]*y_LU[i+1])-x[i]) > epsilon)
            {
              verif_LU = false;
              erreur_LU = fmax(abs((sub_diag[i-1]*y_LU[i-1]+diag[i]*y_LU[i]+upper_diag[i]*y_LU[i+1])-x[i]), erreur_LU);
            }
         }
         if(abs((diag[0]*y_Cho[0]+sub_diag[0]*y_Cho[1])-x[0]) > epsilon)
         {
            verif_Cho = false;
         }
         if(abs((sub_diag[j-2]*y_Cho[j-2]+diag[j-1]*y_Cho[j-1])-x[j-1]) > epsilon)
         {
           verif_Cho = false;
         }
         if(abs((diag[0]*y_LU[0]+upper_diag[0]*y_LU[1])-x[0]) > epsilon)
         {
            verif_LU = false;
            erreur_LU = fmax(abs((diag[0]*y_LU[0]+upper_diag[0]*y_LU[1])-x[0]), erreur_LU);
         }
         if(abs((sub_diag[j-2]*y_LU[j-2]+diag[j-1]*y_LU[j-1])-x[j-1]) > epsilon)
         {
           verif_LU = false;
           erreur_LU = fmax(abs((sub_diag[j-2]*y_LU[j-2]+diag[j-1]*y_LU[j-1])-x[j-1]), erreur_LU);
         }

         free(y_Cho);
         free(y_LU);
         free(x);
         free(diag);
         free(sub_diag);
         free(upper_diag);
      }
   }

   cout << "Test 3 LU : Aleatoire Complexe" << endl;
   if(verif_LU)
   {
      cout <<"Valide"<<endl;
   }
   else
   {
      cout << "Echec"<<endl;
      cout << erreur_LU << endl;
   }

   cout << "Test 3 Cholesky : Aleatoire Complexe" << endl;
   if(verif_Cho)
   {
      cout <<"Valide"<<endl;
   }
   else
   {
      cout << "Echec"<<endl;
      cout << erreur_cho << endl;
   }
}