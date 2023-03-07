/*!************************************************************************
\file ocean.cpp
\author Ramalingam Gouthaman
\DP email: gouthaman.r@digipen.edu
\Course: CS1171
\par Programming Assignment #04
\date 20-02-2023
\brief
This assignment is to implement a simple version of the popular board game Battleship.

CreateOcean
-This function is called by the client to create an ocean by allocating memory an initializing values
DestroyOcean
-This is called by the client to clean up after the game by deallocating all previously
allocated memory 
PlaceBoat
-The client will create a boat, specify a position to locate this boat in the ocean, and then call this
function to record the boat's placement in the ocean
 TakeShot
-The client will pick a position coordinate in the ocean to aim a shot at and then call this function
to determine the result of the shot
GetShotStats
-returns the statistics from the free store object referenced by ocean
**************************************************************************/

#include "ocean.h"
#include <iostream> // std::cout
#include <iomanip>  // std::setw

namespace HLP2 {
  namespace WarBoats {
     /*
     * ALL STUDENT IMPLEMENTATION GOES HERE 
     
    */
    /// @brief this function is called by the client to create an ocean by allocating memory an initializing values
    /// @param nboats
    /// @param x
    /// @param y
    /// @return intialized value of zero
    Ocean::Ocean (int nboats, int x, int y):
    xsize {x},
    ysize {y},
    grid {new int [x* y]{dtOK}},     
    boats{new Boat[nboats]}, 
 
   numberofboats {nboats},

    stats {0,0,0,0}

    { 
    for(int i = 0; i < nboats; i++){
      boats[i].ID = 0; 
      boats[i].hits = 0;
    }
    }
    
    
     /// @brief this function is called by the client to clean up after the game by deallocating all previouslyallocated memory
    Ocean::~Ocean()
    {
      delete[] grid; 
      delete[] boats;
    }

   

    /// @brief client will create a boat, specify a position to locate this boat in the ocean, and then call this
    ///function to record the boat's placement in the ocean
    /// @param boat
    /// @param ocean
    /// @return boatplacement enum
    BoatPlacement Ocean::PlaceBoat( Boat const& boat) const
    {

        if (boat.orientation == oHORIZONTAL)
        {   

      // Check if boat is not in grid
            if (boat.position.x + BOAT_LENGTH > xsize) return bpREJECTED;
        

            if (boat.position.x + BOAT_LENGTH < 0) return bpREJECTED;
        

        // Check if placement is outside grid
            for (int x=boat.position.x; x<(boat.position.x + BOAT_LENGTH); x++)
            {
                if (grid[boat.position.y * xsize + x] != (DamageType::dtOK))
                {
                    return bpREJECTED;
                }

            }
        

        // Placement of the boat
            for (int x=boat.position.x; x<(boat.position.x+BOAT_LENGTH); x++) 
            {
                grid[boat.position.y*xsize+x] = boat.ID;
            }

        }
        else if (boat.orientation == oVERTICAL)
        {    

        // check if boat is not in grid
            if (boat.position.y + BOAT_LENGTH > ysize) return bpREJECTED;
        
        
            if (boat.position.y+BOAT_LENGTH < 0) return bpREJECTED;
        
        // Check if placement is outside grid or on placed boat

            for (int y=boat.position.y; y<(boat.position.y + BOAT_LENGTH); y++) 
            {
                if (grid[y * xsize +boat.position.x] != (DamageType::dtOK) ) 
                {
                return bpREJECTED;
                }
        }   

      //place boat on grid 
            for (int y =boat.position.y; y<(boat.position.y + BOAT_LENGTH); y++) 
            {
                grid[y * xsize + boat.position.x] = boat.ID;
            }
        }

     return BoatPlacement::bpACCEPTED;
    }

    /// @brief client will will pick a position coordinate in the ocean to aim a shot at and then call this function
    /// to determine the result of the shot
    /// @param coordinate
    /// @param ocean
    /// @return shotresult enum
     ShotResult Ocean::TakeShot( Point const& coordinate)
    {
      if(coordinate.x < 0|| coordinate.x>xsize || coordinate.y < 0 || coordinate.y>ysize ) return srILLEGAL;

      int v=grid[coordinate.y * xsize + coordinate.x];
    if (grid[coordinate.y * xsize + coordinate.x] == DamageType::dtOK) 
    {
        grid[coordinate.y * xsize + coordinate.x] = DamageType::dtBLOWNUP;
        stats.misses++;
        return ShotResult::srMISS;
    } 
    if (grid[coordinate.y * xsize + coordinate.x] == DamageType::dtBLOWNUP || (grid[coordinate.y * xsize + coordinate.x]>=1+HIT_OFFSET && grid[coordinate.y * xsize + coordinate.x] <= 99+HIT_OFFSET))
    {
        stats.duplicates++;
        return ShotResult::srDUPLICATE;
    }
    
        
        stats.hits++;
        boats[v-1].hits++;
        grid[coordinate.y * xsize + coordinate.x] += HIT_OFFSET;

        if (boats[v-1].hits == BOAT_LENGTH)
        {
          stats.sunk+=1;
          return  ShotResult::srSUNK;
        }
      

      return ShotResult::srHIT;
    }
    
    /// @brief returns the statistics from the free store object referenced by ocean
    /// @param ocean
    /// @return shotstats
    ShotStats Ocean::GetShotStats()const
    {
       ShotStats current;

    current.hits = stats.hits;
    current.misses =stats.misses;
    current.duplicates = stats.duplicates;
    current.sunk = stats.sunk;

    return current;
    }

  } // namespace WarBoats
} // namespace HLP2
