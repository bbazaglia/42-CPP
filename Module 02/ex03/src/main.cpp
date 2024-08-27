#include "Point.hpp"  

int main() {
    Point p1(0.0, 0.0);
    Point p2(4.0, 0.0);
    Point p3(2.0, 3.0);

    // Point inside the triangle
    Point pInside(2.0, 1.0);

    // Point outside the triangle
    Point pOutside(5.0, 5.0);

    if (bsp(p1, p2, p3, pInside)) {
        std::cout << "Point pInside is inside the triangle." << std::endl;
    } else {
        std::cout << "Point pInside is outside the triangle." << std::endl;
    }

    if (bsp(p1, p2, p3, pOutside)) {
        std::cout << "Point pOutside is inside the triangle." << std::endl;
    } else {
        std::cout << "Point pOutside is outside the triangle." << std::endl;
    }

    // Copy constructor test
    Point pCopy(p1);
    std::cout << "Copied Point: (" << pCopy.getX() << ", " << pCopy.getY() << ")" << std::endl;

    // Assignment operator test (should do nothing due to const members)
    Point pAssign = p2;
    std::cout << "Assigned Point: (" << pAssign.getX() << ", " << pAssign.getY() << ")" << std::endl;

    return 0;
}
