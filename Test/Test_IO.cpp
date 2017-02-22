#include <string>
#include <iostream>
#include "../Simulation/IO.h"

using namespace std;

void test_remplacement();

int main()
{
	test_remplacement();
	return 0;
}

void test_remplacement()
{
	string texte = "Ceci est @remplacer valide", remp = "@remplacer", t_remp = "bien", validation = "Ceci est bien valide";

	cout << "Test 1  remplacement dans une chaine" << endl;

	remplacement_chaine(texte, remp, t_remp);
	if(texte == validation)
	{
		cout << "Valide" << endl;
	}
	else
	{
		cout << "Echec" << endl;
		cout << texte << endl;
		cout << validation << endl;
	}
}