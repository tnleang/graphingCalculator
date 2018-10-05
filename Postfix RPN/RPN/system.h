#ifndef SYSTEM_H
#define SYSTEM_H
#include <vector>
#include <SFML/Graphics.hpp>
#include "../../../Includes/Vector Class/vector_class.h"
#include <string>

#include "../../../Includes/Queue/my_queue.h"
#include "token.h"
#include "graph.h"
#include "tokenizer.h"

using namespace std;
class System
{
public:
    System();
    void Step(int command);
    int Size();
    void Draw(sf::RenderWindow& window);

    //accessor
    double get_min_domain() const {return graph.get_min_domain();}
    double get_max_domain() const {return graph.get_max_domain();}
    string get_equation() const {return graph.get_equation();}


private:

    Queue<Token*> equation;
    Graph graph;
};

#endif // SYSTEM_H
