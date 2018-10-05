#ifndef TRANSLATOR_H
#define TRANSLATOR_H


#include "../../../Includes/Vector Class/vector_class.h"
#include "constants.h"
#include <SFML/Graphics.hpp>


class Translator
{
public:
    Translator();

    Vector<sf::Vector2f> SFML_transformation ( Vector<sf::Vector2f> points , double domain);
    sf::Vector2f SFML_transformation(sf::Vector2f point);

};

#endif // TRANSLATOR_H
