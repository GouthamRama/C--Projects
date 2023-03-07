/*!************************************************************************
\file q.hpp
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

**************************************************************************/
#ifndef Q_HPP
#define Q_HPP

// This file can have only one include directive ...

// required since type Tsunami has data member of type std::string
#include <string> // don't remove

namespace hlp2 {
  
  struct Tsunami {
    // declare data members ...
    int month;
    int day;
    int year;
    int fatalities;
    double wave_height;
    std::string place; 

  };
  
  /// @brief reads the data from a file and places it in a dynamically allocated array
  /// @param file_name 
  /// @param max_cnt 
  /// @return pointer to the dynamically allocated array
  Tsunami* read_tsunami_data(std::string const& file_name, int& max_cnt);

/// @brief takes the data from that created array
/// @param arr 
/// @param size 
/// @param file_name 
void print_tsunami_data(Tsunami const *arr,
int size, std::string const& file_name);

  
} // end namespace hlp2
#endif
