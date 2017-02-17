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

   output.S_y = line.size();
   if(output.S_y == 0){throw "No data in the file";}
   output.S_x = count_caracter(line[0], ' ');
   output.table = (double**) malloc(output.S_y * sizeof(double*));


   
   for(size_t i = 0; i < output.S_y; i++)
   {
      if(count_caracter(line[i], ' ') != output.S_x){throw "Unconstant number of column in the data";}

      size_t x = 0;
      output.table[i] = (double*) malloc(output.S_x * sizeof(double));
      
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

std::basic_ostream& operator<< (std::basic_ostream& output, Table2D const& input);
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