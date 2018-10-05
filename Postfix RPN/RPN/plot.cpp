#include "plot.h"
#include "rpn.h"


Plot::Plot()
{

}


Vector<sf::Vector2f> Plot::points(const Queue<Token *>& posfix_equation,double min_x, double max_x, int how_many_points){
    const bool debug = false;

    /* get in the post fix equation, range (min and MAX), and how many points wanted
     * caculate the epsilon
     * for (every epsilon from min to max)
     *      point.x = min + epsilon
     *      point.y = RPN( equation , x)
     *
     *   */

    Vector<sf::Vector2f> points;
    double epsilon = (max_x - min_x) / how_many_points;
    RPN rpn;
    for (int i =0; i <= how_many_points; i++){

        sf::Vector2f point;
        point.x = (min_x + (i * epsilon));
        point.y = rpn._get_result(posfix_equation, point.x);
        points.push_back(point);

        if (debug){
            cout << "DEBUG: ploting: x: " <<  points[i].x << endl;
            cout << "DEBUG: ploting: y: " <<  points[i].y << endl;
        }
    }


    return points;
}
