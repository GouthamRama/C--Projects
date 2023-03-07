
#include <iostream> // std::cout
#include <iomanip>  // std::setw, std::endl 
#include <string>   // std::string
#include <fstream>  // std::ifstream
#include <vector>   // std::vector<std::string>
#include <iterator> // std::istream_iterator<std::string>
#include "q.hpp"    // to_piglatin


namespace hlp2 {

std::string to_piglatin(std::string normal)
{
    int i =1;
    int x= 0;
    std::string yay ="-yay";
    std::string ay ="-ay";
    std::string way ="-way";
    std::string temp;
    
    if ( normal[0]=='a' || normal[0]=='e' || normal[0]=='i' || normal[0]=='o' || normal[0]=='u')
        {
            return normal+yay;  
        }
    if(normal[0]>=65 && normal[0]<=90)
    {
         if (normal[0]=='A' || normal[0]=='E' || normal[0]=='I'||normal[0]=='O'||normal[0]=='U')
         {
            return normal+yay;         
         }
         
         temp+=tolower(normal[0]);

         while(normal[i]!='\0')
         {
            if (normal[i]=='a' || normal[i]=='e' || normal[i]=='i' || normal[i]=='o' || normal[i]=='u' || normal[i]=='y')
            {
                std::string capital;
                capital += toupper(normal[i]);
                return capital+(normal.erase(0,i+1))+temp+ay;
            }
            temp += normal[i] ;
            
            ++i;
         }
    }
    
    while (normal[x] != '\0' )
    {
          if (normal[x]=='a' || normal[x]=='e' || normal[x]=='i' || normal[x]=='o' || normal[x]=='u' || normal[x]=='y' || normal[x]=='A' || normal[x]=='E' || normal[x]=='I'||normal[x]=='O'||normal[x]=='U' || normal[x]=='Y' )
            {
                
                return normal.erase(0,x)+temp+ay;
            }
            temp += normal[x];
            
            ++x;
    }
    
    return normal+way;
}


}