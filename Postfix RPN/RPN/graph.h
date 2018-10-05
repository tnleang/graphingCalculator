#ifndef GRAPH_H
#define GRAPH_H

#include "../../../Includes/Vector Class/vector_class.h"
#include "constants.h"
#include <SFML/Graphics.hpp>

#include "../../../Includes/Queue/my_queue.h"
#include "plot.h"
#include "translator.h"
#include "shunting_yard.h"
#include "tokenizer.h"


class Graph
{
public:
    Graph();

    void Step(int command);
    int Size();
    void Draw(sf::RenderWindow& window);

    // accessor
    double get_min_domain() const {return domain_x.x;}
    double get_max_domain() const {return domain_x.y;}
    string get_equation() const {return string_equation;}




private:
    sf::RectangleShape y_axis;
    sf::RectangleShape x_axis;
    sf::CircleShape shape;
    Vector<sf::Vector2f> _points;
    string string_equation;
    Queue<Token*> postfix;

    sf::Vector2f origin;
    sf::Vector2f SFML_origin;
    sf::Vector2f domain_x; //.x is min .y is max

    Plot plot;
    Translator graph;

};

#endif // GRAPH_H
