/*!************************************************************************
\file q.cpp
\author Ramalingam Gouthaman
\DP email: gouthaman.r@digipen.edu
\Course: CS1171
\par Programming Lab #02
\date 14-01-2023
\brief
This lab is concerned with retrieving tsunami data from a filen putting it
in a dynamically allocated array of type Tsunami and then outputting a output
 file
with some extra information.

The functions include:
struct tsunami which delcares the data members
read tsunami data reads the data from a file and places it in a dynamically 
allocated array
print tsunami data takes the data from that created array
avg_max_ht which returns the average max height
largest_max_height returns the largest max height in the array

**************************************************************************/// This file can only have these 5 files included and therefore you should not
// remove the following include directives nor provide additional include directives!!!

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "q.hpp" // compiler needs definition of type Tsunami

// anonymous namespace for any helper functions that you wish to implement
namespace {

    /// @brief calculate the average height of the tsunami from the array
    /// @param arr 
    /// @param size 
    /// @return double
    double avg_max_ht(hlp2::Tsunami const *arr, int size)
    {
     double value=0;

     for(int i=0;i<size;++i)
      {
     
        value+=arr[i].wave_height;
      }
    
     return value/size;
   }

   /// @brief calculate the max height of the tsunami from the array
   /// @param arr 
   /// @param size 
   /// @return 
   double largest_max_ht(hlp2::Tsunami const *arr, int size)
   {
     double value=arr[0].wave_height;

     for(int i=1;i<size;++i)
     {
       if (arr[i].wave_height>value)
       {
        value=arr[i].wave_height;
       }
     }
     return value;
   }
}


namespace hlp2 {
  // provide definitions of functions declared in q.hpp here ...

  /// @brief reads the data from a file and places it in a dynamically allocated array
  /// @param file_name 
  /// @param max_cnt 
  /// @return pointer to the dynamically allocated array
Tsunami* read_tsunami_data(std::string const& file_name, int& max_cnt)
{
  std::fstream Tsu(file_name, std::fstream::in);
  if(!Tsu.is_open())
  {
    return nullptr;
  }

  std::string dataperline;
  max_cnt=0;
  while(std::getline(Tsu,dataperline))
  {
     ++max_cnt;
  } 

  Tsunami *tsun_data {new Tsunami[max_cnt]};
  Tsu.clear();
  Tsu.seekg(0);



  for(int i=0;i<max_cnt;i++)
  { 
      Tsu >>  tsun_data[i].month;    
      Tsu >>  tsun_data[i].day;   
      Tsu >>  tsun_data[i].year;   
      Tsu >>  tsun_data[i].fatalities;   
      Tsu >>  tsun_data[i].wave_height;
      getline(Tsu,tsun_data[i].place);  
  }

Tsu.close();
return tsun_data;
}

/// @brief takes the data from that created array
/// @param arr 
/// @param size 
/// @param file_na
void print_tsunami_data(Tsunami const *arr,
int size, std::string const& file_name)
{
  std::fstream Tsuopen(file_name, std::fstream::out);
  if(!Tsuopen.is_open()) return;



 Tsuopen<<"List of tsunamis:"<<std::endl;
 Tsuopen<<"-----------------"<<std::endl;

 for(int i=0;i<size;i++)
{
  Tsuopen<<(arr[i].month < 10 ? "0" : "")<<arr[i].month<<" ";
  Tsuopen<<(arr[i].day < 10 ? "0" : "")<<arr[i].day<<" ";
  Tsuopen<<arr[i].year<<std::right<<std::setw(7);
  Tsuopen<<arr[i].fatalities<<std::right<<std::setw(11);
  Tsuopen<<arr[i].wave_height<<std::fixed<<std::setprecision(2)<<"     ";
  std::string input = arr[i].place;
  input.erase(0, input.find_first_not_of(" \t\n\r\f\v"));
  input.erase(input.find_last_not_of(" \t\n\r\f\v") + 1);
  Tsuopen<<input<<std::endl;
}
Tsuopen<<std::endl;
Tsuopen<<"Summary information for tsunamis"<<std::endl;
Tsuopen<<"--------------------------------"<<std::endl<<std::endl;
Tsuopen<<"Maximum wave height (in meters): "<<largest_max_ht(arr,size)<<std::endl<<std::endl;
Tsuopen<<"Average wave height (in meters): "<<avg_max_ht(arr,size)<<std::endl<<std::endl;
Tsuopen<<"Tsunamis with greater than average height "<<avg_max_ht(arr,size)<<":"<<std::endl;

for(int i=0;i<size;i++)
{
  if (arr[i].wave_height > avg_max_ht(arr,size)){
  Tsuopen<<arr[i].wave_height<<"     ";
   std::string input = arr[i].place;
  input.erase(0, input.find_first_not_of(" \t\n\r\f\v"));
  input.erase(input.find_last_not_of(" \t\n\r\f\v") + 1);
  Tsuopen<<input<<std::endl;
  }
}



}
}