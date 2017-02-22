#include <iostream>
#include <string>
#include <complex>
#include <cstdlib>

#include "../Simulation/Init_position.h"
#include "../Simulation/Potential.h"
#include "../Simulation/IO.h"
#include "../Simulation/Numeric_solving.h"
#include "../Python/Graph.h"


using namespace std;

int main()
{
	size_t choix;
	double length, temps, masse;
	size_t N_x, N_t, frequence_ecriture, nb_ecriture;
	string nom_simulation;
	complex<double>* position;
	double *param;
	std::complex<double> **output;
	double (*pot)(double, double, double*);
	void (*numeric_solving)(double, size_t, double, double, double, std::complex<double>*, double (*potential)(double, double, double*), double*) = Crank_Nicholson_1D;
	Table2D data_affichage;

	cout << "Simulation numerique SE" << endl;
	
	cout << "Nom de la simulation" << endl;
	nom_simulation = "Result/Test1";

	cout << "Toute les unités sont en SI" << endl << "Longeur boite :" << endl;
	length = 1e-8;

	cout << endl << "Nombre de point :" << endl;
	N_x = 1000;

	cout << endl << "Temps de simulation :" << endl;
	temps = 1e-6;

	cout << endl << "Nombre d'intervalle de temps (en pas de temps) :" << endl;
	N_t = 1000;

	cout << endl << "Frequence ecriture temporelle :" << endl;
	frequence_ecriture = 1;
	nb_ecriture = number_output(N_t, frequence_ecriture);

	cout << endl << "Masse :" << endl;
	masse = 1.822e-27;

	cout << endl << "Choix de la position initial \n 1. Uniforme \n 2. Gaussien" << endl;
	choix = 2;

	if(choix == 1)
	{
		position = paquet_uniforme(length, N_x, param);
	}
	else if(choix == 2)
	{
		param = (double*) malloc(3*sizeof(double));
		cout << endl << "psi(x) = (2/(M_PI*a0^2))^0.25 * exp(i*k0*x) * exp(((x-x0)/a0)^2))" << endl;
		cout << endl << "a0 :" << endl;
		param[0] = 1e-15;
		cout << endl << "k0 :" << endl;
		param[1] = 2.3e-16;
		cout << endl << "x0 :" << endl;
		param[2] = 3.0e-14;
		position = paquet_gaussien(length, N_x, param);
		free(param);
	}
	else
	{
		throw "Erreur saisie position initial";
	}

	cout << endl << "Choix du potentiel \n 1. Constant \n 2. Sinusoidale \n 3. Parabole \n 4. Puit \n 5. Potentiel du sujet" << endl;
	choix = 1;

	if(choix == 1)
	{	
		param = (double*) malloc(sizeof(double));
		cout << endl << "V(x) = V" << endl << "V :" << endl;
		*param = 0.;
		pot = P_const;
	}
	else if(choix == 2)
	{
		param = (double*) malloc(5*sizeof(double));
		cout << endl << "V(x) = a * sin(c*x+d*t+e) + b" << endl << "a :" << endl;
		cin >> param[0];
		cout << endl << "b :" << endl;
		cin >> param[1];
		cout << endl << "c :" << endl;
		cin >> param[2];
		cout << endl << "d :" << endl;
		cin >> param[3];
		cout << endl << "e :" << endl;
		cin >> param[4];
		pot = P_sinus;
	}
	else if(choix == 3)
	{
		param = (double*) malloc(3*sizeof(double));
		cout << endl << "a*x^2 + b*x + c" << endl << "a :" << endl;
		cin >> param[0];
		cout << endl << "b :" << endl;
		cin >> param[1];
		cout << endl << "c :" << endl;
		cin >> param[2];
		pot = P_parabol;	
	}
	else if(choix == 4)
	{
		param = (double*) malloc(4*sizeof(double));
		cout << endl << "Position gauche de la barriere :" << endl;
		cin >> param[0];
		cout << endl << "Position gauche de la barriere :" << endl;
		cin >> param[1];
		cout << endl << "Potentiel haut :" << endl;
		cin >> param[2];
		cout << endl << "Potentiel bas :" << endl;
		cin >> param[3];
		pot = P_puit;
	}
	else if(choix == 5)
	{
		param = (double*) malloc(2*sizeof(double));
		cout << endl << "a/(cosh(x/b))^2" << endl << "a :" << endl;
		cin >> param[0];
		cout << endl << "b :" << endl;
		cin >> param[1];
		pot = P_def;
	}
	else
	{
		throw "Erreur saisisie potentiel";
	}
	
	Table2D data_pot;
	data_pot.S_x = N_x;
	data_pot.S_y = 2;
	data_pot.table = (double**) malloc(data_pot.S_x*sizeof(double));
	double *V = P_tableau(length, N_x, param, pot);
	for(size_t i = 0; i < N_x; i++)
	{
		data_pot.table[i] = (double*) malloc(2*sizeof(double));
	}
	graph_simple(data_pot, "x", "y", nom_simulation + "_potentiel");
	for(size_t i = 0; i < N_x; i++)
	{
		free(data_pot.table[i]);
	}
	free(data_pot.table);


	//simulation_1D(std::complex<double>** output, double length, size_t N_x, double simulation_time, size_t N_t, double m, std::complex<double>* position, double (*potential)(double, double, double*), double* param_potential, void (*numeric_solving)(double, size_t, double, double, double, std::complex<double>*, double (*potential)(double, double, double*), double*), size_t freq_writing = 1);
	simulation_1D(output, length, N_x, temps, N_t, masse, position, pot, param, numeric_solving, frequence_ecriture);


	data_affichage.S_x = nb_ecriture;
	data_affichage.S_y = N_x+1;
	data_affichage.table = (double**) malloc(nb_ecriture*sizeof(double));
	for(size_t i = 0; i < nb_ecriture; i++)
	{
		data_affichage.table[i] = (double*) malloc((N_x+1)*sizeof(double));
		for(size_t j = 0; j < N_x+1; j++)
		{
			data_affichage.table[i][j] = norm(output[i][j]);
		}
	}
	graph_heatmap(data_affichage, length, "x", "t", nom_simulation + "_heatmap");
	

	for(size_t i = 0; i < nb_ecriture; i++)
	{
		free(output[i]);
		free(data_affichage.table[i]);
	}
	free(output);
	free(data_affichage.table);
	free(position);
	return 0;
}