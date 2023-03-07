/*!************************************************************************
\file q.hpp
\author Ramalingam Gouthaman
\DP email: gouthaman.r@digipen.edu
\Course: CS1171
\par Programming Assignment #01
\date 12-01-2023
\brief
This assignment is concerned with reading the data from a input file and sends a file with analysis on the number and letters
The functions include:
- q
reads the data from a input file and sends a file with analysis on the number and letters


**************************************************************************/
#ifndef Q_HPP_
#define Q_HPP_

// Important note:
// If there any includes in this file, the auto grade will not
// accept the submission.

namespace hlp2 {
 
  /// @brief reads the data from a input file and sends a file with analysis on the number and letters
  /// @param input_filename 
  /// @param analysis_file 
  void q(char const *input_filename, char const *analysis_file);
}

#endif