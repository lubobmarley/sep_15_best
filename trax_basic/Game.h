//------------------------------------------------------------------------------
// Game.h
//
// Group: Group 10, study assistant: Philipp Hafner
//
// Author: Lukas Bodner, 1431293
//------------------------------------------------------------------------------
//

#ifndef GAME_H
#define	GAME_H
#include "Color.h"
class Tile;

class Game
{
private:
    Color activeplayer_;
    bool running_;
    
    Game(const Game &);
    Game& operator= (const Game &);
    
    //--------------------------------------------------------------------------
    // checks the userinput if it is the Addtile-Comment
    //
    // @param part1 string including the comment
    //
    // @return true (correct Addtile comment) or false (wrong comment)
    //
    bool correctAddtile(std::string part1);
    
    //--------------------------------------------------------------------------
    // checks the userinput if it is the Write-Comment
    //
    // @param part1 string including the comment
    //
    // @return true (correct Write comment) or false (wrong comment)
    //
    
    bool correctWrite(std::string part1);
    
    //--------------------------------------------------------------------------
    // checks the userinput if it is time to quit the game
    //
    // @param part1 string including the comment
    //
    // @return true (correct Quit comment) or false (wrong comment)
    //
    bool correctQuit(std::string str);
    
public:
    
    //--------------------------------------------------------------------------
    // Constructor
    // Constructs the Gameboard and sets asctiveplayer and starttile
    //
    Game() : activeplayer_(COLOR_WHITE) {}
    
    //--------------------------------------------------------------------------
    // Destructor
    //
    ~Game();
    
    //--------------------------------------------------------------------------
    // runs the input environment 
   //
    // @param graphic_on checks if graphicmode is on or off
    // @param filename filename for graphicmode on
    //
    void run (bool graphicon, std::string filename);
    void setRunning (bool running) { running_ = running; }
    
    //--------------------------------------------------------------------------
    // changes the current player
    //
    void togglePlayer();
    
    //--------------------------------------------------------------------------
    // returns the current activeplayer_
    //
    Color getActivePlayer() { return activeplayer_; }
};

#endif	/* GAME_H */

