#ifndef IO_H
#define IO_H

#include <ostream>
#include <complex>
#include <iomanip>
#include <string>

#define PRECISION 10

//Structure with all the information for writing the output
struct Writing
{
   std::basic_ostream<char> output;
   std::size_t freq_writing;
};

struct Table2D
{
   double **table;
   size_t S_x;
   size_t S_y;
};

struct Complex_Table2D
{
   std::complex<double> **table;
   size_t S_x;
   size_t S_y;
};

void writing_position_1D(Writing& output, double t, std::complex<double>* position, size_t N_x);

void writing_position_1D(std::complex<double>* output, double const& t, std::complex<double>* position, size_t N_x);

size_t number_output(size_t N_t, size_t freq_writing);

// Load a table 2D from a file
Table2D load_table(std::string const& file_name);

// Write a table in out stream
std::basic_ostream<char>& operator<< (std::basic_ostream<char>& output, Table2D const& input);

// Write a table in out stream
std::basic_ostream<char>& operator<< (std::basic_ostream<char>& output, Complex_Table2D const& input);

//A function that count the number of time a carracter appear in a string
size_t count_caracter(std::string const& string, char car);

//Fonction remplacant dans texte chaine à remplacer par chaine remplacement
void remplacement_chaine(std::string& texte, std::string const& chaine_a_remplacer, std::string const& chaine_remplacement);

#endif
