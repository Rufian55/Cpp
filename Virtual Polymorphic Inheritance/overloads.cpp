#include <iostream>

class integer{
private:
	int val;

public:

	integer(int value)
	{
		this->val = value;
	}

	integer()
	{
		this->val = 0;
	}

	integer& operator=(const integer &RHS)
	{
		this->val = RHS.val;

		return *this;
	}

	integer(integer &value)
	{
		this->val = value.val;
	}

	~integer()
	{
		//intentionally left empty
	}

	int value()
	{
		return this->val;
	}

	int value() const
	{
		return this->val;
	}

	void set_value(int value)
	{
		this->val = value;
	}

	//++i
	integer& operator++()
	{
		++(this->val);

		return *this;
	}


	//i++
	integer& operator++(int ignored)
	{
		integer returned = integer(this->val);

		++(this->val);

		return returned; //return integer(--(this->val));
	}

	friend const integer operator-(const integer&, const integer&);

	//std::cout << *this << *this
	friend std::ostream& operator<<(std::ostream &outs, const integer& foo);
	friend std::istream& operator>>(std::istream &in, integer &foo);

	//overloading as operator:
	//integer b;
	//b.operator*(c); ----- b * c
	const integer operator*(const integer &RHS)
	{
		return integer(this->val * RHS.val);
	}

};

//Stream insertion operator overloading.
std::ostream& operator<<(std::ostream &outs, const integer& foo)
{
	outs << foo.val;
	
	return outs;
}

//Stream extraction operator overloading.
std::istream& operator>>(std::istream &in, integer &foo)
{
	in >> foo.val;

	return in;
}

//friend function -- can access variables directly
const integer operator-(const integer &LHS, const integer &RHS)
{
	return integer(LHS.val - RHS.val);
}

//completely unrelated function -- must use accessors
const integer operator+(const integer &LHS, const integer &RHS)
{
	return integer(LHS.value() + RHS.value());
}

int main(int argc, char **argv)
{
	integer a(3);
	integer b(7);
	
	integer c = a + b;

	//this is what we have
	std::cout << a.value() << " " << b.value() << std::endl;
	
	//this is what we want
	//std::cout << a << " " << b << std::endl;

	std::cout << "c = " << c.value() << std::endl;
	std::cout << "c - a = " << (c - a).value() << std::endl;
	std::cout << "c * a = " << (c * a).value() << std::endl;

	std::cout << "3 * c = " << (c * 3).value() << std::endl;
	std::cout << "3 + c = " << (3 + c).value() << std::endl;

	


	return 0;
}
