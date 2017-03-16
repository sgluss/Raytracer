#pragma once

class Color
{
private:
	double _red, _green, _blue, _special;

public:

	double getRed() { return _red; }
	double getGreen() { return _green; }
	double getBlue() { return _blue; }
	double getSpecial() { return _special; }

	void setRed(double value) { _red = value; };
	void setGreen(double value) { _green = value; };
	void setBlue(double value) { _blue = value; };
	void setSpecial(double value) { _special = value; };

	Color();

	Color(double, double, double, double);

	~Color();
};

