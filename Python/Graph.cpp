#include <fstream>
#include <iomanip>	
#include <sstream>
#include </usr/include/python2.7/Python.h>

#include "Graph.h"
#include "../Simulation/IO.h"

#define S_GRAPH_SIMPLE "Graph_Simple.py"
#define S_GRAPH_HEATMAP "Graph_2D.py"

#define S_TAB "@tableau"
#define S_X_LAB "@x_label"
#define S_Y_LAB "@y_label"
#define S_NAME "@graph_name"
#define S_X "@x"
#define S_Y "@y"

using namespace std;


void lancement_script(string script)	
{
	Py_Initialize(); \
  	PyRun_SimpleString(script.c_str()); \
  	Py_Finalize();
}	

//Realise un graph classique avec X la premiere ligne du tableau et y la deuxieme ligne du tableau 
void graph_simple(Table2D tableau, string label_x, string label_y, string graph_name)
{
	fstream f_script(S_GRAPH_SIMPLE);
	string ligne, script, tab;

	while(getline(f_script, ligne)) //Tant qu'on n'est pas à la fin, on lit
	{
		script += ligne;
    }
	f_script.close();

	tab = "[";
	for(size_t i = 0; i < tableau.S_x; i++)
	{
		tab += "[";
		for(size_t j = 0; j < tableau.S_y; j++)
		{
			stringstream prov;
			prov << setprecision(PRECISION) << tableau.table[i][j]; 
			tab += prov.str();
			if(j != tableau.S_y - 1){tab += ",";}
		}
		tab += "]";
		if(i != tableau.S_x - 1){tab += ",";}
	}
	tab += "]";

	remplacement_chaine(script, S_TAB, tab);
	remplacement_chaine(script, S_X_LAB, label_x);
	remplacement_chaine(script, S_Y_LAB, label_y);
	remplacement_chaine(script, S_NAME, graph_name);

	lancement_script(script);
}

//Realise une heatmap à partir du tableau en 2D de sortie de simulation
void graph_heatmap(Table2D tableau, double length, string label_x, string label_y, string graph_name)
{
	fstream f_script(S_GRAPH_HEATMAP);
	string ligne, script, tab, x, y;

	while(getline(f_script, ligne)) //Tant qu'on n'est pas à la fin, on lit
	{
		script += ligne;
    }
	f_script.close();

	tab = "[";
	y = "[";
	for(size_t i = 0; i < tableau.S_x; i++)
	{
		tab += "[";
		for(size_t j = 1; j < tableau.S_y; j++)
		{
			stringstream prov;
			prov << setprecision(PRECISION) << tableau.table[i][j]; 
			tab += prov.str();
			if(j != tableau.S_y - 1){tab += ",";}
		}
		tab += "]";
		stringstream prov;
		prov << setprecision(PRECISION) << tableau.table[i][0]; 
		y += prov.str();
		if(i != tableau.S_x - 1){tab += ",";y += ",";}
	}
	tab += "]";
	y += "]";

	x = "[";
	for(size_t j = 0; j < tableau.S_y-1; j++)
	{
		stringstream prov;
		prov << setprecision(PRECISION) << (j-1)*length/(tableau.S_y-2) << ","; 
		x += prov.str();
	}
	stringstream prov;
	prov << setprecision(PRECISION) << length << ","; 
	x += prov.str();
	x += "]"; 

	remplacement_chaine(script, S_TAB, tab);
	remplacement_chaine(script, S_X_LAB, label_x);
	remplacement_chaine(script, S_Y_LAB, label_y);
	remplacement_chaine(script, S_NAME, graph_name);
	remplacement_chaine(script, S_X, x);
	remplacement_chaine(script, S_Y, y);

	lancement_script(script);
}
