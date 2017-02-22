#include "IO.h"
#include <fstream>
#include <vector>
#include <cstdlib>

using namespace std;

// Load a table 2D from a file
Table2D load_table(string const& file_name)
{
   fstream file(file_name, ios_base::in);
   vector<string> line;
   Table2D output;
   string number;

   for(string prov; getline(file, prov);)
   {
      line.push_back(prov);
   }

   output.S_x = line.size();
   if(output.S_x == 0){throw "No data in the file";}
   output.S_y = count_caracter(line[0], ' ');
   output.table = (double**) malloc(output.S_x * sizeof(double*));


   
   for(size_t i = 0; i < output.S_x; i++)
   {
      if(count_caracter(line[i], ' ') != output.S_y){throw "Unconstant number of column in the data";}

      size_t x = 0;
      output.table[i] = (double*) malloc(output.S_y * sizeof(double));
      
      for(size_t j = 0; j < line[i].size(); j++)
      {
      	if(line[i][j] == ' ')
      	{
      	   output.table[i][x++] = stod(number);
      	   number.clear();
      	}
      	else if(line[i][j] != '\n')
      	{
      	   number+=line[i][j];
      	}
	    
      }
   }
   
   file.close();   
   return output;
}


size_t count_caracter(string const& string, char car)
{
   size_t count = 0;
   for(size_t i = 0; i < string.size(); i++)
   {
      if(string[i] == car){count++;}
   }

   return count;
}

size_t number_output(size_t N_t, size_t freq_writing)
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

std::basic_ostream<char>& operator<< (std::basic_ostream<char>& output, Table2D const& input)
{
   for(size_t j = 0; j < input.S_x; j++)
   {
      for(size_t i = 0; i < input.S_y; i++)
      {
         output << std::setprecision(PRECISION) << input.table[i][j] << " ";
      }
      output << "\n";
   }
   output << std::flush;  
   return output;
}

std::basic_ostream<char>& operator<< (std::basic_ostream<char>& output, Complex_Table2D const& input)
{
   for(size_t j = 0; j < input.S_x; j++)
   {
      for(size_t i = 0; i < input.S_y; i++)
      {
         output << std::setprecision(PRECISION) << norm(input.table[i][j]) << " ";
      }
      output << "\n";
   }
   output << std::flush;  
   return output;
}

void remplacement_chaine(string& texte, string const& chaine_a_remplacer, string const& chaine_remplacement)
{
   string::size_type pos = texte.find(chaine_a_remplacer);
   if(pos == string::npos)
   {
      throw "Erreur remplacement chaine inexistante";
   }
   texte.erase(pos, chaine_a_remplacer.size());
   texte.insert(pos, chaine_remplacement);
}

void writing_position_1D(std::complex<double>* output, double const& t, std::complex<double>* position, size_t N_x)
{
   output[0] = t;
   for(size_t i = 1; i <= N_x; i++)
   {
      output[i] = position[i-1];
   }
}

void writing_position_1D(Writing& output, double t, std::complex<double>* position, size_t N_x)
{
   output.output << std::setprecision(PRECISION) << t << " ";
   for(size_t i = 0; i < N_x; i++)
   {
      output.output << std::setprecision(PRECISION) << norm(position[i]) << " ";
   }
   output.output << std::endl;
}