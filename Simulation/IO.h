#ifndef IO_H
#define IO_H

#include <ostream>
#include <complex>
#include <iomanip>

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
   double S_x;
   double S_y;
};

void writing_position_1D(Writing& output, double t, std::complex<double>* position, size_t N_x)
{
   output.output << std::setprecision(PRECISION) << t << " ";
   for(size_t i = 0; i < N_x; i++)
   {
      output.output << std::setprecision(PRECISION) << norm(position[i]) << " ";
   }
   output.output << std::endl;
}

void writing_position_1D(std::complex<double>* output, double const& t, std::complex<double>* position, size_t N_x)
{
   output[0] = t;
   for(size_t i = 1; i <= N_x; i++)
   {
      output[i] = position[i-1];
   }
}

size_t number_output(size_t N_t, size_t freq_writing);

// Load a table 2D from a file
Table2D load_table(std::string const& file_name);

// Write a table in out stream
std::basic_ostream& operator<< (std::basic_ostream& output, Table2D const& input);

//A function that count the number of time a carracter appear in a string
size_t count_caracter(std::string const& string, char car);

#endif
