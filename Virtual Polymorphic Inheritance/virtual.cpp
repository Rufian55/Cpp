/*********************************************************************************
 * A C++ Virtual Functions Demo Program.
*********************************************************************************/
#include <iostream>
#include <cmath>

enum { NOCOLOR, PURPLE, RED, BLUE, GREEN, BLACK, CYAN, MAGENTA, YELLOW };

class shape {
private:
	int side_count;
	int color;
public:
	shape() {
		this->side_count = -1;
		this->color = NOCOLOR;
	}

	shape(int sides) {
		this->side_count = sides;
	}

	virtual double area() {
		if (side_count == -1) {
			return -17;
		}
		else {
			return 14;
		}
	}

	virtual double perimeter() {
		return 0;
	}

	virtual std::string name() = 0;
	// {
	// 	return std::string("SHAPE");
	// }
};


class triangle : public shape {
private:
protected:
	double side1;
	double side2;
	double side3;
public:
	triangle() : shape(3) {
		this->side1 = 0;
		this->side2 = 0;
		this->side3 = 0;
	}

	triangle(double side1, double side2, double side3) : shape(3) {
		this->side1 = side1;
		this->side2 = side2;
		this->side3 = side3;
	}

	std::string name() {
		return std::string("TRIANGLE");
	}

	//use semi-perimeter area formula: sqrt(s(s-a)(s-b)(s-c))
	double area() {
		double s = this->perimeter() / 2;
		return std::sqrt(s *
			(s - this->side1) *
			(s - this->side2) *
			(s - this->side3)
			);
	}

	double perimeter() {
		return this->side1 + this->side2 + this->side3;
	}
};

class rectangle : public shape {
private:
protected:
	double side1;
	double side2;
public:
	rectangle() : shape(4) {
		this->side1 = 0;
		this->side2 = 0;
	}

	rectangle(double side1, double side2) : shape(4) {
		this->side1 = side1;
		this->side2 = side2;
	}

	std::string name() {
		return std::string("RECTANGLE");
	}


	//use semi-perimeter area formula: sqrt(s(s-a)(s-b)(s-c))
	double area() {
		return this->side1 * this->side2;
	}

	double perimeter() {
		return this->side1 * 2 + this->side2 * 2;
	}
};

class square : public rectangle {

protected:
public:
	square() : rectangle() {
		this->side1 = 0;
		this->side2 = 0;
	}

	square(double side) : rectangle(side, side) {
		this->side1 = side;
		this->side2 = side;
	}

	// square operator=(const square &RHS)
	// {
	// 	rectangle::operator=(RHS);
	// 	//additional necessary stuff
	// }

	std::string name() {
		return std::string("SQUARE");
	}

	double area() {
		return rectangle::area();
	}

	double perimeter() {
		return rectangle::perimeter();
	}
};

void print_area(shape *s, std::string name) {
	std::cout << "Area of " << s->name() << " s (should be "
		<< name << "): " << s->area() << std::endl;
	std::cout << "Perimeter of " << s->name() << " s (should be "
		<< name << "): " << s->perimeter() << std::endl;
}


int main(int argc, char **argv) {
	//shape s;
	triangle *t = new triangle(5, 12, 13);
	rectangle *r = new rectangle(8, 12.5);
	square *q = new square(10);

	//print_area(&s, "shape");
	print_area(t, "triangle");
	print_area(r, "rectangle");
	print_area(q, "square");

	return 0;
}
