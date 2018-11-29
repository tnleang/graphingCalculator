# graphingCalculator
Create a graphing calculator.

The calculator will take an expression made up of numbers, instances of a single variable, Trig functions, in addition to functions taking more than one argument such as Max(a, b)

The calculator will draw a graph of the function for a given interval and given increments:

queue<Point> PlotExpression (string expression, double low, double high, double increments);

This function takes an expression as a string, the high and low values for the function variable and the increments and produces a queue of points that represent the graph.

 Can handle:

 - Functions (specially, the Trig functions)
