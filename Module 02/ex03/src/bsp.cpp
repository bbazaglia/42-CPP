#include "Point.hpp"

/* 
 * Binary Space Partitioning (BSP) to check if a point is inside a triangle.
 * Consider the triangle as being split by its edges into three half-spaces. 
 * If the point lies within all three half-spaces formed by the triangle's edges, it is inside the triangle.
*/

#include "Point.hpp"

// Function to determine if the point is on the left or right of the line formed by points A and B
// It calculates the horizontal and vertical distances from point ????
bool isPointOnSameSide(Point const &a, Point const &b, Point const &point1, Point const &point2) {
    // Calculate the difference in x and y coordinates to get the vector AB
    float abX = b.getX() - a.getX();
    float abY = b.getY() - a.getY();
    
    // Calculate the vector from point A to point1 (AP1)
    float ap1X = point1.getX() - a.getX();
    float ap1Y = point1.getY() - a.getY();
    
    // Calculate the vector from point A to point2 (AP2)
    float ap2X = point2.getX() - a.getX();
    float ap2Y = point2.getY() - a.getY();
    
    // Calculate the cross product of AB and AP1, and AB and AP2
    float crossProduct1 = abX * ap1Y - abY * ap1X;
    float crossProduct2 = abX * ap2Y - abY * ap2X;
    
    // Check if the cross products have the same sign (both positive or both negative)
    return (crossProduct1 * crossProduct2 >= 0);
}


// Function to determine if a point is inside the triangle using Binary Space Partitioning
bool bsp(Point const a, Point const b, Point const c, Point const point) {
    bool onSameSideAB = isPointOnSameSide(a, b, c, point);
    bool onSameSideBC = isPointOnSameSide(b, c, a, point);
    bool onSameSideCA = isPointOnSameSide(c, a, b, point);
    
    // The point is inside the triangle if it is on the same side of all three edges
    return onSameSideAB && onSameSideBC && onSameSideCA;
}
