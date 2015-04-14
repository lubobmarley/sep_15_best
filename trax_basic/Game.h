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

#include "Tile.h"
#include "Color.h"

class Game
{
private:
    Color activeplayer_;
    Tile* starttile_;
    bool running_;
    
    Game(const Game &);
    Game& operator= (const Game &);
    
public:
    Game();
    ~Game();
    
    void setStartTile(Tile* starttile) { starttile_ = starttile; }
    void run ();
    void setRunning (bool running) { running_ = running; }
    void togglePlayer();
    Color getActivePlayer() { return activeplayer_; }
    
    
    
};


#endif	/* GAME_H */

