#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include "CircleWithConstantMemberFunctions.h"
using namespace std;

//ex06_05
class Complex{
public:
	Complex(); 
	Complex(double A);
	Complex(double A, double B); 
	void SetA(double);
	void SetB(double);
	double GetA() const;
	double GetB() const;
	Complex add(Complex v);
	Complex multiply(Complex v);
	Complex divide(Complex v);
	Complex subtract(Complex v);
	void print();
private:
	double A;
	double B;

};

int main(){

	//ex06_01
	ofstream K;
	srand(time(NULL));
	K.open("Exercise13_1.txt");
	for (int i = 0; i < 100; i++){
	int value = rand() % 10;
	K << value << " " << endl;
	}
	K.close();

	//ex06_02
	string file;
	cout << "Enter file name: ";
	cin >> file;

	ifstream input(file.c_str());

	int q = 0;

	if (input.fail()){
	cout << "File does not exist" << endl;
	}

	else {
	while (!input.eof()){
	input.get();
	q++;
	}
	}
	cout << "# of characters: " << q - 1 << endl;

	//ex06_03
	string Name, bName, gName;
	ifstream bFile;
	int r = 0;
	int t = 0;
	int rank;

		bFile.open("c:\\Users\\Shane\\Desktop\\Babynameranking2013.txt");
		if (bFile.fail())
		{
			cout << "Can't open Babynameranking2013.txt" << endl;
		}

		cout << "Enter name: ";
		cin >> Name;
		while (bFile >> rank)
		{
			bFile >> bName;
			bFile >> gName;

			if (Name == bName)
			{
				cout << Name << " is ranked " << rank << " among boys." << endl;
			}
			else if (Name == gName)
			{
				cout << Name << " is ranked " << rank << "  among girls." << endl;
			}
	}

	//ex06_04
		Circle c1, c2;
		c1.setRadius(5);
		c2.setRadius(10);

		if (c1 < c2)
		{
			cout << "Circle 2 with radius " << c2.getRadius() << " is greater than circle 1 with a radius of " << c1.getRadius() << endl;
		}
		else if (c1 == c2){
			cout << "Circle 1 with radius " << c1.getRadius() << " is the same as circle 2 with radius " << c2.getRadius() << endl;
		}
		else 
		{
			cout << "Circle 1 with radius " << c1.getRadius() << " is greater than circle 2 with a radius of " << c2.getRadius() << endl;
		}
		
		//ex06_05

	cout << "Enter first complex number: ";
	double a1, b1, a2, b2;
	cin >> a1 >> b1;
	cout << "Enter second complex number: ";
	cin >> a2 >> b2;
	Complex a(a1, b1);
	Complex b(a2, b2);
	Complex c(a.add(b));
		a.print();
		cout << " + ";
		b.print();
		cout << " = ";
		c.print();
		cout << endl;

		c = a.subtract(b);
		a.print();
		cout << " + ";
		b.print();
		cout << " = ";
		c.print();
		cout << endl;

		c = a.multiply(b);
		a.print();
		cout << " + ";
		b.print();
		cout << " = ";
		c.print();
		cout << endl;

		c = a.divide(b);
		a.print();
		cout << " + ";
		b.print();
		cout << " = ";
		c.print();
		cout << endl;

		a.print();
		cout << " + ";
		b.print();
		cout << " = ";
		cout << sqrt(a1*a1 + b1*b1) << endl;

}

//ex06_04
Circle::Circle(){
	radius = 1;
}
Circle::Circle(double newRadius){
	radius = newRadius;
}
double Circle::getRadius() const{
	return radius;
}
void Circle::setRadius(double newRadius){
	radius = (newRadius >= 0) ? newRadius : 0;
}
bool Circle::operator<(const Circle& secondCircle) const{
	return getRadius() < secondCircle.getRadius();
}

bool Circle::operator==(const Circle& secondCircle) const{
	return getRadius() == secondCircle.getRadius();
}

//ex06_05

Complex::Complex(){
	A = B = 0;
}
Complex::Complex(double r){
	A = r;
	B = 0;
}
Complex::Complex(double r, double i){
	A = r;
	B = i;
}
Complex Complex::add(Complex c){
	Complex add;
	add.A = A + c.A;
	add.B = B + c.B;
	return add;
}
Complex Complex::subtract(Complex c){
	Complex subtract;
	subtract.A = A - c.A;
	subtract.B = B - c.B;
	return subtract;
}
Complex Complex::multiply(Complex c){
	Complex multiply;
	multiply.A = A*c.A - B*c.B;
	multiply.B = A*c.B + c.A*B;
	return multiply;
}
Complex Complex::divide(Complex c){
	Complex divide;
	divide.A = (A*c.A + B*c.B) / (c.A*c.A + c.B*c.B);
	divide.B = (B*c.A - A*c.B) / (c.A*c.A + c.B*c.B);
	return divide;
}

double Complex::GetA() const{
	return A;
}
double Complex::GetB() const{
	return B;
}
void Complex::SetA(double r){
	A = r;
}
void Complex::SetB(double i){
	B = i;
}
void Complex::print(){
	cout << '(' << A << " + " << B << "i)";
}