#ifndef CIRCLE_H
#define CIRCLE_H

class Circle
{
public:
	Circle();
	Circle(double);
	double getRadius() const;
	void setRadius(double);
	//ex06_04
	bool operator<(const Circle& secondCircle) const;
	bool operator>(const Circle& secondCircle) const;
	bool operator==(const Circle& secondCircle) const;
	private:
		double radius;
};

#endif