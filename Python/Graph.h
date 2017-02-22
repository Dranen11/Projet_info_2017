#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include "../Simulation/IO.h"

//	Realise un graph classique avec X la premiere ligne du tableau et y la deuxieme ligne du tableau
void graph_simple(Table2D tableau, std::string label_x, std::string label_y, std::string graph_name);
//void graph_simple(std::string file_name, std::string label_x, std::string label_y, std::string grapĥ_name);

//Realise une heatmap à partir du tableau en 2D de sortie de simulation
void graph_heatmap(Table2D tableau, double length, std::string label_x, std::string label_y, std::string graph_name);
//void graph_heatmap(std::string file_name, double lenght, std::string label_x, std::string label_y, std::string grapĥ_name);

void lancement_script(std::string script);

#endif