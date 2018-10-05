#include "graph.h"
#include <cmath>

Graph::Graph()
{
    // default set up
    domain_x.x = -10;
    domain_x.y = 10;

    origin.x = 0;
    origin.y = 0;
    SFML_origin = graph.SFML_transformation(origin  );

    sf::Vector2f size(SCREEN_WIDTH,1);
    y_axis = sf::RectangleShape(sf::Vector2f(SCREEN_WIDTH,1));
    y_axis.setPosition(0,SFML_origin.y);
    y_axis.setFillColor(sf::Color::White);

    x_axis = sf::RectangleShape(sf::Vector2f(1, SCREEN_HEIGHT));
    x_axis.setPosition(SFML_origin.x ,0);
    x_axis.setFillColor(sf::Color::White);

    shape.setFillColor(sf::Color::Red);
    shape.setRadius(1);



}


//------------------------------------------------------------------
//------------------------------------------------------------------

void Graph::Step(int command){


    if(command == 1){
        // pending left

        // pend origin appopriate with the graph pending
        origin.x -= (SCREEN_WIDTH - SIDE_BAR)/(domain_x.y - domain_x.x) * 0.1;
        domain_x.x += 0.1;
        domain_x.y += 0.1;
        Vector<sf::Vector2f> points = plot.points(postfix  , domain_x.x, domain_x.y, HOW_MANY);
        Vector<sf::Vector2f> SFML_points =  graph.SFML_transformation(points, domain_x.y - domain_x.x);
        _points = SFML_points;
        SFML_origin = graph.SFML_transformation(origin);
        x_axis.setPosition(SFML_origin.x ,0);
        y_axis.setPosition(0,SFML_origin.y);
    }
    else if ( command == 2){
        // pending right
        origin.x += (SCREEN_WIDTH - SIDE_BAR)/(domain_x.y - domain_x.x) *0.1;
        domain_x.x -= 0.1;
        domain_x.y -= 0.1;
        Vector<sf::Vector2f> points = plot.points(postfix  , domain_x.x, domain_x.y, HOW_MANY);
        Vector<sf::Vector2f> SFML_points =  graph.SFML_transformation(points, domain_x.y - domain_x.x );
        _points = SFML_points;
        SFML_origin = graph.SFML_transformation(origin );
        x_axis.setPosition(SFML_origin.x ,0);
        y_axis.setPosition(0,SFML_origin.y);
    }
    else if(command == 3){
        //zoom in 20%
        domain_x.x *= 0.8;
        domain_x.y *= 0.8;
        Vector<sf::Vector2f> points = plot.points(postfix  , domain_x.x, domain_x.y, HOW_MANY);
        Vector<sf::Vector2f> SFML_points =  graph.SFML_transformation(points, domain_x.y - domain_x.x);
        _points = SFML_points;
    }
    else if(command == 4){
        //zoom out 20%
        domain_x.x *= 1.2;
        domain_x.y *= 1.2;
        Vector<sf::Vector2f> points = plot.points(postfix  , domain_x.x, domain_x.y, HOW_MANY);
        Vector<sf::Vector2f> SFML_points = graph.SFML_transformation(points, domain_x.y - domain_x.x);
        _points = SFML_points;
    }
    else if(command == 5){
        //taking a new function

        cout << "y = ";
        getline(cin, string_equation);
        tokenizer tokenize;
        Queue<Token*> equation = tokenize.tokenizing( string_equation );
        ShuntingYard sy;
        postfix = sy.get_posfix(equation);
        Vector<sf::Vector2f> points = plot.points(postfix  , domain_x.x, domain_x.y, HOW_MANY);
        Vector<sf::Vector2f> SFML_points = graph.SFML_transformation(points, domain_x.y - domain_x.x);
        _points = SFML_points;
    }

}


void Graph::Draw(sf::RenderWindow &window){

    window.clear();
    window.draw(y_axis);
    window.draw(x_axis);

    for (int i =0; i < _points.get_size(); i++){
        shape.setPosition(_points[i]);
        window.draw( shape );
    }

}
