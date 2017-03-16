#pragma once

class Color
{
private:
	double red, green, blue, special;

public:

	double getRed() { return red; }
	double getGreen() { return green; }
	double getBlue() { return blue; }
	double getSpecial() { return special; }

	void setRed(double value) { red = value; };
	void setGreen(double value) { green = value; };
	void setBlue(double value) { blue = value; };
	void setSpecial(double value) { special = value; };

	Color();

	Color(double, double, double, double);

	~Color();
};

