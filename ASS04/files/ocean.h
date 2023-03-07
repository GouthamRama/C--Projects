/*!************************************************************************
\file ocean.h
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



namespace HLP2 {
  namespace WarBoats {
    class Ocean; //Forward declaration for the Ocean 
    
    inline int const BOAT_LENGTH {4} ;   //length of a boat         
        inline int const HIT_OFFSET{100}; //baotid

    enum Orientation   { oHORIZONTAL, oVERTICAL };
    enum ShotResult    { srHIT, srMISS, srDUPLICATE, srSUNK, srILLEGAL };
    enum DamageType    { dtOK = 0, dtBLOWNUP = -1 };
    enum BoatPlacement { bpACCEPTED, bpREJECTED };

    //Coordinate 
    struct Point 
    {
      int x; // column
      int y; // row
    };

    //Boat
    struct Boat 
    {
      int hits;                 // Hits 
      int ID;                   //ID 
      Orientation orientation;  //orientation
      Point position;           //xcoordinate
    };

    //Stats
    struct ShotStats 
    {
      int hits;       //!< The number of boat hits
      int misses;     //!< The number of boat misses
      int duplicates; //!< The number of duplicate (misses/hits)
      int sunk;       //!< The number of boats sunk
    };

  } 

} 

namespace HLP2
{
  namespace WarBoats
  {
    class Ocean // class of the ocean
    {
      public:

      //constructors // fucntions
      Ocean(int nboats, int x ,   int y);
 ShotResult TakeShot(Point  const& coordinate);
      BoatPlacement PlaceBoat(Boat const& boat) const;
    ShotStats GetShotStats()  const;

      struct Dimensions
      {
        int  x; 
         int y; 
      };

      Dimensions GetDimensions() const 
      {
        return {xsize, ysize};
      }

      int const *GetGrid() const
      {
        return grid; 
      }

      ~Ocean();

      private: //unaccessible values
      
      int xsize; 
      int ysize; 
      int* grid; 
      Boat*  boats; 
      int numberofboats; 
      ShotStats stats;
     };

  }

}



