#ifndef PLOT_H
#define PLOT_H

#include "../../../Includes/Queue/my_queue.h"
#include "../../../Includes/Vector Class/vector_class.h"
#include <SFML/Graphics.hpp>
#include "cmath" //For absolute value (maybe??)
#include "token.h"


class Plot
{
public:
    Plot();

    Vector<sf::Vector2f> points (const Queue<Token*>& posfix_equation ,double min_x, double max_x, int how_many_points );
    /* get in the post fix equation, range (min and MAX), and how many points wanted
     * caculate the epsilon
     * for (every epsilon from min to max)
     *      point.x = min + epsilon
     *      point.y = RPN( equation , x)
     *
     *   */

};

#endif // PLOT_H
