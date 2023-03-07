#include "ocean.h"
#include <iostream> // std::cout
#include <iomanip>  // std::setw

namespace HLP2 {
  namespace WarBoats {
    int const BOAT_LENGTH {4};   //!< Length of a boat
    int const HIT_OFFSET  {100}; //!< Add this to the boat ID

    /*
     * ALL STUDENT IMPLEMENTATION GOES HERE 
     
    */
    Ocean* CreateOcean(int num_boats, int x_size, int y_size){
      Ocean *object = new Ocean;
      object->grid= new int[x_size*y_size];

      for(int i=0;i<x_size*y_size;i++)
      {
        object->grid[i] =  DamageType::dtOK;
      }
     
      object->x_size=x_size;
      object->y_size=y_size;

      //clearing data members of member stats to zero
      object->stats.hits = 0;
      object->stats.misses = 0;
      object->stats.duplicates = 0;
      object->stats.sunk = 0;

      //dynamically allocate memory for an array of Boats 
      object->boats=new Boat[num_boats];
      object->num_boats=num_boats;
      for(int i=0 ; i<num_boats ; i++)
      {
        object->boats[i].hits=0;
        object->boats[i].ID=0;
      }

      return object;
    }


    void DestroyOcean(Ocean *theOcean)
    {
      delete[] theOcean->grid;
      delete[] theOcean->boats;
      delete theOcean;

    }

   
//     BoatPlacement PlaceBoat(Ocean& ocean, Boat const& boat)
//     {
//          if (boat.position.y >= ocean.y_size||boat.position.x >= ocean.x_size||boat.position.x + BOAT_LENGTH < 0||boat.position.y + BOAT_LENGTH < 0||boat.position.x + BOAT_LENGTH * (boat.orientation == Orientation::oHORIZONTAL) >= ocean.x_size || boat.position.y + BOAT_LENGTH * (boat.orientation == Orientation::oVERTICAL) >= ocean.y_size) 
//          {
//            return BoatPlacement::bpREJECTED;
//          }

// for (int i = 0; i < BOAT_LENGTH; i++) 
//     {
//       int x = boat.position.x + i * (boat.orientation == Orientation::oHORIZONTAL);
//       int y = boat.position.y + i * (boat.orientation == Orientation::oVERTICAL);

//       if (x < 0 || x >= ocean.x_size || y < 0 || y >= ocean.y_size) {
//         return BoatPlacement::bpREJECTED;
//       }

//       if (ocean.grid[y * ocean.x_size + x] != DamageType::dtOK) 
//       {
//          return BoatPlacement::bpREJECTED;
//       }
//     }
//     for (int i = 0; i < BOAT_LENGTH; i++) 
//     {
//       int x = boat.position.x + i * (boat.orientation == Orientation::oHORIZONTAL);
//       int y = boat.position.y + i * (boat.orientation == Orientation::oVERTICAL);
//        ocean.grid[y * ocean.x_size + x] = boat.ID;
//     }
//         // for (int i = 0; i < BOAT_LENGTH; i++) 
//         // {
//         //  int x = boat.position.x + i * (boat.orientation == Orientation::oHORIZONTAL);
//         //  int y = boat.position.y + i * (boat.orientation == Orientation::oVERTICAL);

//         //  if (ocean.grid[y * ocean.x_size + x] != DamageType::dtOK) 
//         //  {
//         //     return BoatPlacement::bpREJECTED;
//         //  }
//         // }

//         //   for (int i = 0; i < BOAT_LENGTH; i++) 
//         // {
//         //   int x = boat.position.x + i * (boat.orientation == Orientation::oHORIZONTAL);
//         //   int y = boat.position.y + i * (boat.orientation == Orientation::oVERTICAL);
//         //   ocean.grid[y * ocean.x_size + x] = boat.ID;
//         // }
//     return BoatPlacement::bpACCEPTED;
//     }

BoatPlacement PlaceBoat(Ocean& ocean, Boat const& boat)

    {

     if (boat.orientation == oHORIZONTAL)
    {   

      // Check if boat is not in grid
        if (boat.position.x + BOAT_LENGTH > ocean.x_size) return bpREJECTED;
        

        if (boat.position.x + BOAT_LENGTH < 0) return bpREJECTED;
        

        // Check if placement is outside grid
        for (int i = boat.position.x; i < (boat.position.x + BOAT_LENGTH); i++)
        {
            if (ocean.grid[boat.position.y * ocean.x_size + i] != (DamageType::dtOK))
            {
                return bpREJECTED;
            }

        }
        

        // Placement of the boat
        for (int i = boat.position.x; i < (boat.position.x + BOAT_LENGTH); i++) 
        {
            ocean.grid[boat.position.y * ocean.x_size + i] = boat.ID;
        }

    }
    else if (boat.orientation == oVERTICAL)
    { 

      // check if boat is not in grid
        if (boat.position.y + BOAT_LENGTH > ocean.y_size) return bpREJECTED;
        
        
         if (boat.position.y + BOAT_LENGTH < 0) return bpREJECTED;
        



        // Check if placement is outside grid or on placed boat

        for (int i = boat.position.y; i < (boat.position.y + BOAT_LENGTH); i++) 
        {
            if (ocean.grid[i * ocean.x_size + boat.position.x] != (DamageType::dtOK) ) 
            {
              return bpREJECTED;
            }
        }

      //place boat on grid 
        for (int i = boat.position.y; i < (boat.position.y + BOAT_LENGTH); i++) 
        {
            ocean.grid[i * ocean.x_size + boat.position.x] = boat.ID;
        }
    }

    return BoatPlacement::bpACCEPTED;
    }


     ShotResult TakeShot(Ocean& ocean, Point const& coordinate)
    {
      if(coordinate.x < 0|| coordinate.x>ocean.x_size || coordinate.y < 0 || coordinate.y>ocean.y_size ) return srILLEGAL;

      int v=ocean.grid[coordinate.y * ocean.x_size + coordinate.x];
    if (ocean.grid[coordinate.y * ocean.x_size + coordinate.x] == DamageType::dtOK) 
    {
        ocean.grid[coordinate.y * ocean.x_size + coordinate.x] = DamageType::dtBLOWNUP;
        ocean.stats.misses++;
        return ShotResult::srMISS;
    } 
    if (ocean.grid[coordinate.y * ocean.x_size + coordinate.x] == DamageType::dtBLOWNUP || (ocean.grid[coordinate.y * ocean.x_size + coordinate.x]>=1+HIT_OFFSET && ocean.grid[coordinate.y * ocean.x_size + coordinate.x] <= 99+HIT_OFFSET))
    {
        ocean.stats.duplicates++;
        return ShotResult::srDUPLICATE;
    }
    
        
        ocean.stats.hits++;
        ocean.boats[v-1].hits++;
        ocean.grid[coordinate.y * ocean.x_size + coordinate.x] += HIT_OFFSET;

        if (ocean.boats[v-1].hits == BOAT_LENGTH)
        {
          ocean.stats.sunk+=1;
          return  ShotResult::srSUNK;
        }
      

      return ShotResult::srHIT;
    }
    
    ShotStats GetShotStats(Ocean const& ocean)
    {
       ShotStats current;

    current.hits = ocean.stats.hits;
    current.misses = ocean.stats.misses;
    current.duplicates = ocean.stats.duplicates;
    current.sunk = ocean.stats.sunk;

    return current;
    }
    /**************************************************************************/
    /*!
      \brief
        Prints the grid (ocean) to the screen.
      
      \param ocean
        The Ocean to print
      
      \param field_width
        How much space each position takes when printed.
      
      \param extraline
        If true, an extra line is printed after each row. If false, no extra
        line is printed.
        
      \param showboats
        If true, the boats are shown in the output. (Debugging feature)
    */
    /**************************************************************************/
    void DumpOcean(const HLP2::WarBoats::Ocean &ocean,
                                    int field_width, 
                                    bool extraline, 
                                    bool showboats) {
      for (int y = 0; y < ocean.y_size; y++) { // For each row
        for (int x = 0; x < ocean.x_size; x++) { // For each column
            // Get value at x/y position
          int value = ocean.grid[y * ocean.x_size + x];
            // Is it a boat that we need to keep hidden?
          value = ( (value > 0) && (value < HIT_OFFSET) && (showboats == false) ) ? 0 : value;
          std::cout << std::setw(field_width) << value;
        }
        std::cout << "\n";
        if (extraline) { std::cout << "\n"; }
      }
    }
  } // namespace WarBoats
} // namespace HLP2
