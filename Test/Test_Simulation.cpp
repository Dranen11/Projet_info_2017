#include <complex>
#include <cmath>
#include "../Simulation/Constant.h"
#include "../Simulation/IO.h"
#include "../Simulation/Numeric_Solving.cpp"
#include "../Simulation/Potentiel.h"

#define V0 -1.6e-9

using namespace std;

//Teste l'équivalence entre les différentes méthodes de simulation
void test_equivalence();
void simulation_comparaison(double length, double mass, double simulation_time, size_t N_x, size_t N_t, double (*potential)(double, double, double*), double* param_pot);

int main()
{
	test_equivalence();
	return 0;
}

void test_equivalence()
{

}

void simulation_comparaison(double length, double mass, double simulation_time, size_t N_x, size_t N_t, double (*potential)(double, double, double*), double* param_pot)
{
	//Position de départ
	complex<double> *position1, *position2 = (complex<double>*) malloc(N_x*sizeof(complex<double>)), *position3 = (complex<double>*) malloc(N_x*sizeof(complex<double>)), *position4 = (complex<double>*) malloc(N_x*sizeof(complex<double>)), *position5 = (complex<double>*) malloc(N_x*sizeof(complex<double>)), *position6 = = (complex<double>*) malloc(N_x*sizeof(complex<double>));
	double *param_pos = (double*) malloc(3*sizeof(double));
	param_pos[0] = 1e-15;
	param_pos[1] = sqrt(mass*2.0*V0)/H_BAR;
	param_pos[2] = 30e-15;
	position1 = paquet_gaussien(length, N_x, param_pos);
	for(size_t i = 0; i < N_x; i++)
	{
		position2[i] = position1[i];
		position3[i] = position1[i];
		position4[i] = position1[i];
		position5[i] = position1[i];
		position6[i] = position1[i];
	}


	//Potential
	double* pot1; double **pot2;
	pot1 = P_tableau(length, N_x, param_pot, potential);
	pot2 =  P_tableau(length, N_x, simulation_time/N_t, N_t, param_pot, potential);


	//Output


	free(position1);
	free(position2);
	free(position3);
	free(position4);
	free(position5);
	free(position6);
	free(pot1);
	free(pot2);
}
