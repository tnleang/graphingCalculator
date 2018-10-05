#include "system.h"

#include <iostream>

#include "constants.h"

System::System()
{

}


//------------------------------------------------------------------
//------------------------------------------------------------------

void System::Step(int command){

    graph.Step( command );

}


void System::Draw(sf::RenderWindow& window /*, Vector<sf::Vector2f> points*/){

    graph.Draw( window );

}
