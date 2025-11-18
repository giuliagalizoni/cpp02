#include "../include/Point.hpp"
#include <iostream>

bool bsp(Point const a, Point const b, Point const c, Point const point);

static void printTest(const char *description, bool result)
{
	std::cout << description << ": "
			  << (result ? "INSIDE ✓" : "OUTSIDE ✗")
			  << std::endl;
}

int main(void)
{
	std::cout << "=== BSP (Binary Space Partitioning) Tests ===" << std::endl;
	std::cout << std::endl;

	Point a(0.0f, 0.0f);
	Point b(10.0f, 0.0f);
	Point c(5.0f, 10.0f);

	std::cout << "Triangle vertices:" << std::endl;
	std::cout << "A: (" << a.getX() << ", " << a.getY() << ")" << std::endl;
	std::cout << "B: (" << b.getX() << ", " << b.getY() << ")" << std::endl;
	std::cout << "C: (" << c.getX() << ", " << c.getY() << ")" << std::endl;
	std::cout << std::endl;

	std::cout << "--- Test 1: Points clearly inside ---" << std::endl;
	Point p1(5.0f, 5.0f);
	std::cout << "Point (" << p1.getX() << ", " << p1.getY() << "): ";
	printTest("Center point", bsp(a, b, c, p1));

	Point p2(3.0f, 3.0f);
	std::cout << "Point (" << p2.getX() << ", " << p2.getY() << "): ";
	printTest("Inside point", bsp(a, b, c, p2));

	Point p3(7.0f, 3.0f);
	std::cout << "Point (" << p3.getX() << ", " << p3.getY() << "): ";
	printTest("Inside point", bsp(a, b, c, p3));
	std::cout << std::endl;

	std::cout << "--- Test 2: Points clearly outside ---" << std::endl;
	Point p4(15.0f, 5.0f);
	std::cout << "Point (" << p4.getX() << ", " << p4.getY() << "): ";
	printTest("Far right", bsp(a, b, c, p4));

	Point p5(-5.0f, 5.0f);
	std::cout << "Point (" << p5.getX() << ", " << p5.getY() << "): ";
	printTest("Far left", bsp(a, b, c, p5));

	Point p6(5.0f, 15.0f);
	std::cout << "Point (" << p6.getX() << ", " << p6.getY() << "): ";
	printTest("Above triangle", bsp(a, b, c, p6));

	Point p7(5.0f, -5.0f);
	std::cout << "Point (" << p7.getX() << ", " << p7.getY() << "): ";
	printTest("Below triangle", bsp(a, b, c, p7));
	std::cout << std::endl;

	std::cout << "--- Test 3: Points on edges (should be OUTSIDE) ---" << std::endl;
	Point p8(5.0f, 0.0f); // Middle of edge AB
	std::cout << "Point (" << p8.getX() << ", " << p8.getY() << "): ";
	printTest("On edge AB", bsp(a, b, c, p8));

	Point p9(2.5f, 5.0f); // On edge AC
	std::cout << "Point (" << p9.getX() << ", " << p9.getY() << "): ";
	printTest("On edge AC", bsp(a, b, c, p9));

	Point p10(7.5f, 5.0f); // On edge BC
	std::cout << "Point (" << p10.getX() << ", " << p10.getY() << "): ";
	printTest("On edge BC", bsp(a, b, c, p10));
	std::cout << std::endl;

	std::cout << "--- Test 4: Points on vertices (should be OUTSIDE) ---" << std::endl;
	Point p11(0.0f, 0.0f); // Vertex A
	std::cout << "Point (" << p11.getX() << ", " << p11.getY() << "): ";
	printTest("On vertex A", bsp(a, b, c, p11));

	Point p12(10.0f, 0.0f); // Vertex B
	std::cout << "Point (" << p12.getX() << ", " << p12.getY() << "): ";
	printTest("On vertex B", bsp(a, b, c, p12));

	Point p13(5.0f, 10.0f); // Vertex C
	std::cout << "Point (" << p13.getX() << ", " << p13.getY() << "): ";
	printTest("On vertex C", bsp(a, b, c, p13));
	std::cout << std::endl;
	return 0;
}
