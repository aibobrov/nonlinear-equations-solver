#ifndef JUSTGRAPH_PLOTTINGGRAPH_H
#define JUSTGRAPH_PLOTTINGGRAPH_H

// keyboard function
void key(unsigned char c, int x, int y);

// setting window's matrix
void reshape(int w, int h);

// drawing coordinate lines
void drawCoordinateLines(double x1, double x2, double y1, double y2);

// plotting main graph
void draw(double x1, double x2, double y1, double y2, int N);

// reshape function
void redraw();

// initialization of our window and setting function
void windowStart(int argc, char **argv, const char *titleOfWindow);

#endif //JUSTGRAPH_PLOTTINGGRAPH_H