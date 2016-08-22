#include <iostream>
#include <cmath>

enum {NOCOLOR, PURPLE, RED, BLUE, GREEN, BLACK, CYAN, MAGENTA, YELLOW};


class shape{
public:
	shape()
	{
		this->side_count = -1;
		this->color = NOCOLOR;
	}

	shape(int sides)
	{
		this->side_count = sides;
	}

	double area()
	{
		if (side_count == -1){
			return -17;
		}else{
			return 14;
		}
	}
	
	double perimeter()
	{
		return 0;
	}

private:
	int side_count;
	int color;
};


class triangle : public shape{
public:
	triangle() : shape(3)
	{
		this->side1 = 0;
		this->side2 = 0;
		this->side3 = 0;
	}

	triangle(double side1, double side2, double side3) : shape(3)
	{
		this->side1 = side1;
		this->side2 = side2;
		this->side3 = side3;
	}

	//use semi-perimeter area formula: sqrt(s(s-a)(s-b)(s-c))
	double area()
	{
		double s = this->perimeter() / 2;
		return std::sqrt(s * 
		                 (s - this->side1) * 
		                 (s - this->side2) * 
		                 (s - this->side3)
		                 );
	}

	double perimeter()
	{
		return this->side1 + this->side2 + this->side3;
	}

protected:
	double side1;
	double side2;
	double side3;

private:

};

class rectangle : public shape{
public:
	rectangle() : shape(4)
	{
		this->side1 = 0;
		this->side2 = 0;
	}

	rectangle(double side1, double side2) : shape(4)
	{
		this->side1 = side1;
		this->side2 = side2;
	}

	//use semi-perimeter area formula: sqrt(s(s-a)(s-b)(s-c))
	double area()
	{
		return this->side1 * this->side2;
	}

	double perimeter()
	{
		return this->side1 * 2 + this->side2 * 2;
	}

protected:
	double side1;
	double side2;

private:
	
};

class square : public rectangle{
	
public:
	square() : rectangle()
	{
		this->side1 = 0;
		this->side2 = 0;
	}

	square(double side) : rectangle(side, side)
	{
		this->side1 = side;
		this->side2 = side;
	}

	square operator=(const square &RHS)
	{
		rectangle::operator=(RHS);
		//additional necessary stuff
	}

	double area()
	{
		return rectangle::area();
	}

	double perimeter()
	{
		return rectangle::perimeter();
	}

protected:

private:
	
};




int main(int argc, char **argv)
{
	shape s;
	triangle t(5,12,13);
	rectangle r(8, 12.5);
	square q(10);


	std::cout << "Area of shape s: " << s.area() << std::endl;
	std::cout << "Perimeter of shape s: " << s.perimeter() << std::endl;
	std::cout << "Area of triangle t: " << t.area() << std::endl;
	std::cout << "Perimeter of triangle t: " << t.perimeter() << std::endl;
	std::cout << "Area of rectangle t: " << r.area() << std::endl;
	std::cout << "Perimeter of rectangle t: " << r.perimeter() << std::endl;
	
	std::cout << "Area of square q: " << q.area() << std::endl;
	std::cout << "Perimeter of square q: " << q.perimeter() << std::endl;
	

	return 0;
}
