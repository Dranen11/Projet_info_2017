#ifndef WRITING_H
#define WRITING_H

#include <ostream>

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

void writing_position_1D(Writing& output, double t, complex<double*> position, size_t N_x)
{
   output.output << t << " ";
   for(size_t i = 0; i < N_x; i++)
   {
      output.output << norm(position[i]) << " ";
   }
   output.output << endl;
}

void writing_position_1D(complex<double>* output, double const& t, complex<double>* position, size_t const& N_X)
{
   output[0] = t;
   for(size_t i = 1; i <= N_x; i++)
   {
      output[i] = position[i-1];
   }
}

void number_output(size_t N_t, size_t freq_writing)
{
   if(freq_writing == 1)
   {
      return N_t+1;
   }
   else if ((N_t+1)%freq_writing < 2)
   {
      return (N_t+1)/freq_writing + 1;
   }
   else
   {
      return (N_t+1)/freq_writing + 2;
   }
}

// Load a table 2D from a file
Table2D load_table(std::string const& file_name);

//A function that count the number of time a carracter appear in a string
size_t count_caracter(std::string const& string, char car);

#endif
