#include "translator.h"

Translator::Translator()
{

}


Vector<sf::Vector2f> Translator::SFML_transformation(Vector<sf::Vector2f> points, double domain){
    const bool debug = false;                                                       // domain



    //source: https://www.khanacademy.org/math/linear-algebra/matrix-transformations/linear-transformations/v/linear-transformations
    // simple tranformation
    // to fit in the screen
    /*
     *        -     -       -                                                             -
     *        |     |       |                                                             |
     *        |  x  |       | point_per_distance * points[i].x + SFML_transformation.x;   |
     *      T |     |   =   |                                                             |
     *        |  y  |       | - (point_per_distance.y * point.y) + SFML.y                 |
     *        |     |       |                                                             |
     *        -     -       -                                                             -
     *
     */

    /*
     *        -     -       -                                                             -
     *        |     |       |                                                             |
     *        |  x  |       |                       index                                 |
     *      T |     |   =   |                                                             |
     *        |  y  |       | - (point_per_distance.y * point.y) + SFML.y                 |
     *        |     |       |                                                             |
     *        -     -       -                                                             -
     *
     */

    // T(1,1)
    sf::Vector2f SFML_transformation;
    SFML_transformation.x = (SCREEN_WIDTH / 2 - SIDE_BAR / 2);
    SFML_transformation.y = SCREEN_HEIGHT / 2;

    double point_per_distance_x = (SCREEN_WIDTH - SIDE_BAR)/ domain;
    double point_per_distance_y = SCREEN_HEIGHT/domain;

    Vector<sf::Vector2f> SFML_points;

    for (int i =0; i < points.get_size(); i++){
        sf::Vector2f SFML_point;
        SFML_point.x = i;
        //SFML_point.x = point_per_distance_x * (points[i].x) + SFML_transformation.x;
        SFML_point.y =  SFML_transformation.y - ( point_per_distance_y* points[i].y);
        SFML_points.push_back(SFML_point);

        if (debug){
            cout << "DEBUG: SFML_tranformation: point x: " << SFML_points[i].x << endl;
            cout << "DEBUG: SFML_tranformation: point y: " << SFML_points[i].y << endl;
        }

    }

    return SFML_points;
}

sf::Vector2f Translator::SFML_transformation(sf::Vector2f point){

    // tranformation in single point
    // use for translate origin

    sf::Vector2f SFML_transformation;
    SFML_transformation.x = SCREEN_WIDTH / 2 - SIDE_BAR / 2;
    SFML_transformation.y = SCREEN_HEIGHT / 2;


    sf::Vector2f SFML_point;
    SFML_point.x =  point.x + SFML_transformation.x;
    SFML_point.y = SFML_transformation.y - point.y;

    return SFML_point;

}
