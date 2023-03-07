/*!************************************************************************
\file q.cpp
\author Ramalingam Gouthaman
\DP email: gouthaman.r@digipen.edu
\Course: CS1171
\par Programming Assignment #01
\date 12-01-2023
\brief
This assignment is concerned with reading the data from a input file and sends a file with analysis on the number and letters
The functions include:
-char_counter
-ws_counter
-digit_counter
-letter_counter
-upper_counter
-lower_counter
-integer_counter
-sumofint_counter
-alphabet_counter
-percentage
**************************************************************************/
// You must only include the following header files ...
#include <iostream>
#include <iomanip>
#include <fstream>

// Important notes:

// The auto grader will look for exactly the above three includes.
// If there any additional includes, it will not compile your file.
// The auto grade will not accept any functions not declared in
// these three header files [even in comments]!!!
// You're warned!!!


namespace {
    const size_t MAX_LINE_LEN {2048};

    /// @brief counts the number of characters
    /// @param arr 
    /// @return number of characters
    int char_counter(char* arr){
        int bytes{};
        for(int i=0;arr[i]!='\0';i++) bytes ++;
        return bytes;
    }

    /// @brief counts the number of whitespaces
    /// @param arr 
    /// @return number of whitespaces
    int ws_counter(char *arr)
    {
        int i=0,count=0;
        while(arr[i]!='\0') 
        {
            if(arr[i]==' ') ++count;
            ++i;
        }
        return count;
    }

  /// @brief counts the number of digits
    /// @param arr 
    /// @return number of digits
    int digit_counter(char* arr)
    {
        int i=0,count=0;
        while(arr[i]!='\0') 
        {
           if('0'<=arr[i] && arr[i]<='9')  ++count;
           ++i;
        }
        return count;
    }

  /// @brief counts the number of letters
    /// @param arr 
    /// @return number of letters
    int letter_counter(char *arr)
    {
        int i=0,count=0;
        while(arr[i]!='\0') 
        {
            if( ('a'<=arr[i] && arr[i]<='z') || ('A'<=arr[i] && arr[i]<='Z') ) ++count;
            ++i;
        }
        return count;
    }

  /// @brief counts the number of upper
    /// @param arr 
    /// @return number of upper
    int upper_counter(char *arr)
    {
        int i=0,count=0;
        while(arr[i]!='\0') 
        {
            if(  ('A'<=arr[i] && arr[i]<='Z') ) ++count;
            ++i;
        }
        return count;
    }

  /// @brief counts the number of lowercase letters
    /// @param arr 
    /// @return number of lowercase letters
    int lower_counter(char *arr)
    {
        int i=0,count=0;
        while(arr[i]!='\0') 
        {
            if( ('a'<=arr[i] && arr[i]<='z')  ) ++count;
            ++i;
        }
        return count;
    }

  /// @brief counts the number of integers
    /// @param arr 
    /// @return number of integers
    int integer_counter(char* arr)
    {
        int i=0,count=0;
        while(arr[i]!='\0') 
        {
           if('0'<=arr[i] && arr[i]<='9') //if its a digit
           {
                int j=i;
                ++count;
                    while(arr[j] != '\0') //to cycle through and see if there are other digits
                    {
                        if(!('0'<=arr[j] && arr[j]<='9') ) 
                        {
                    
                            break;
                        }
                     ++j;
                    }
                 i=j;
           }  
           ++i;
        }
        return count;

    }

  /// @brief counts the sum of all the integers
    /// @param arr 
    /// @return number of whitespaces
    int sumofint_counter (char* arr)
    {
        int i=0,value=0,final=0;
        while(arr[i]!='\0') 
        {
           if('0'<=arr[i] && arr[i]<='9') //if its a digit
           {
                int j=i+1;
                value=(arr[i]-48);
                    while(arr[j] != '\0') //to cycle through and see if there are other digits
                    {
                        if(!('0'<=arr[j] && arr[j]<='9') ) 
                        {
                    
                            break;
                        }
                        
                     value=(value*10)+ (arr[j]-48);
                     ++j;
                     
                    }
                 i=j;
                 final+=value;
                 
           }  
           ++i;
        }
        return final;
    }

  /// @brief counts the number of alphabets
    /// @param arr 
    /// @return number of alphabets
    void alphabet_counter (char * arr,int * arr2)
     {

        int i=0;
        char word;

         while(arr[i]!='\0')
          {
             if(  ('A'<=arr[i] && arr[i]<='Z') )
            {
             word=arr[i];
             word +=32;
             arr2[word-97]+=1;
             ++i;
             continue;
            }

             word=arr[i];
             arr2[word-97]++;
             ++i;

          }
    }
  /// @brief calculates the percentage
    /// @param arr 
    /// @return double
   double percentage (int share,int total)
   {
        if(total==0) return 0;
        double percent=0;
        percent = (double)share/total;
        return percent*100;
    }
}

namespace hlp2 {
  // provide definition of q here ...
  /// @brief reads the data from a input file and sends a file with analysis on the number and letters
  /// @param input_filename 
  /// @param analysis_file 
  void q(char const *input_filename, char const *analysis_file)
  {
        std::fstream ifs(input_filename,std::fstream::in);
        if(!ifs.is_open())
        {
            std::cout<<"File input.txt not found."<<std::endl;
            
        }
        
        std::fstream my_file(analysis_file,std::fstream::out);
        if(!my_file.is_open())
        {
            std::cout<<"Unable to create output file output.txt."<<std::endl;
            
        }

        //analysis data
        //int arraycounter[5];
        int charcounter=0,newlinecounter=0,lettercounter=0,wscounter=0,digitcounter=0,others=0,uppercounter=0,lowercounter=0,integercounter=0,sumofintegers=0;
       int alphabetcount[26]={0};
       char line[MAX_LINE_LEN];



        //number of characters in the file
         while ( ifs.getline(line, MAX_LINE_LEN-1) )
        {
            if (ifs.good())
            {
                ++newlinecounter;
            }
       
        charcounter += char_counter(line);
        lettercounter += letter_counter(line);
        wscounter += ws_counter(line);
        digitcounter += digit_counter(line);
        uppercounter+= upper_counter(line);
        lowercounter+= lower_counter(line);
        alphabet_counter(line,alphabetcount);
        integercounter+=integer_counter(line);
        sumofintegers+=sumofint_counter(line);
        }
        wscounter+=newlinecounter;
        charcounter +=newlinecounter;
        others=charcounter-lettercounter-wscounter-digitcounter;
        
        
                
        my_file<<"Statistics for file: "<<input_filename<<std::endl;
        my_file<<"---------------------------------------------------------------------"<<std::endl<<std::endl;
        my_file<<"Total # of characters in file: "<<charcounter<<std::endl<<std::endl;
        my_file << std::left << std::setw(20)<< "Category"
                << std::left << std::setw(12)<< "How many in file"
                << std::right << std::setw(22)<< "% of file"<<std::endl;
        my_file<<"---------------------------------------------------------------------"<<std::endl;
        my_file<<"Letters"<<std::right << std::setw(29)<<lettercounter<<std::right << std::setw(20)<<std::fixed<<std::setprecision(2)<<percentage(lettercounter,charcounter)<<" %"<<std::endl;
        my_file<<"White space"<<std::right << std::setw(25)<<wscounter<<std::right << std::setw(20)<<std::fixed<<std::setprecision(2)<<percentage(wscounter,charcounter)<<" %"<<std::endl;
        my_file<<"Digits"<<std::right << std::setw(30)<<digitcounter<<std::right << std::setw(20)<<std::fixed<<std::setprecision(2)<<percentage(digitcounter,charcounter)<<" %"<<std::endl;
        my_file<<"Other characters"<<std::right << std::setw(20)<<others<<std::right << std::setw(20)<<std::fixed<<std::setprecision(2)<<percentage(others,charcounter)<<" %"<<std::endl<<std::endl<<std::endl;
        my_file<<"LETTER STATISTICS"<<std::endl<<std::endl;
        my_file << std::left << std::setw(20)<< "Category"
                << std::left << std::setw(12)<< "How many in file"
                << std::right << std::setw(22)<< "% of all letters"<<std::endl;
        my_file<<"---------------------------------------------------------------------"<<std::endl;
        my_file<<"Uppercase"<<std::right << std::setw(27)<<uppercounter<<std::right << std::setw(20)<<std::fixed<<std::setprecision(2)<<percentage(uppercounter,lettercounter)<<" %"<<std::endl;
        my_file<<"Lowercase"<<std::right << std::setw(27)<<lowercounter<<std::right << std::setw(20)<<std::fixed<<std::setprecision(2)<<percentage(lowercounter,lettercounter)<<" %"<<std::endl;

        char letter ='a';
        for(int i=0;i<26;i++){
            
            my_file<<(char)(letter+i)<<std::right << std::setw(35)<<alphabetcount[i]<<std::right << std::setw(20)<<std::fixed<<std::setprecision(2)<<percentage(alphabetcount[i],lettercounter)<<" %"<<std::endl;
            
        }
        my_file<<std::endl<<std::endl;

        
         my_file<<"NUMBER ANALYSIS"<<std::endl<<std::endl;
        my_file<<"Number of integers in file:          "<<integercounter<<std::endl;
        my_file<<"Sum of integers:                     " <<sumofintegers<<std::endl;
        my_file<<"Average of integers:                 "<<percentage(sumofintegers,integercounter)/100<<std::endl;
        my_file<<"_____________________________________________________________________"<<std::endl;

        // my_file<<"upper "<<uppercounter<<std::endl;
        // my_file<<"lower "<<lowercounter<<std::endl;
        // my_file<<"integer "<<integercounter<<std::endl;
        // my_file<<"sum of integer "<<sumofintegers<<std::endl;
        // my_file<< "avg "<< std::fixed<<std::setprecision(2)<<percentage(sumofintegers,integercounter)/100 << std::endl;

        // char letter ='a';
        // for(int i=0;i<26;i++){
           
        //     my_file<<(char)(letter+i)<<std::setw(2)<<alphabetcount[i]<<std::endl;
        // }




        ifs.close();
        my_file.close();
    }
}
