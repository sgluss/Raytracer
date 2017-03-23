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

	double brightness() {
		return (_red + _green + _blue) / 3;
	}

	Color colorScalar(double s){
		return Color(_red*s, _green*s, _blue*s, _special);
	}

	Color colorAdd(Color color) {
		return Color(_red + color.getRed(),
			_green + color.getGreen(),
			_blue + color.getBlue(),
			_special);
	}

	Color colorMultiply(Color color) {
		return Color(_red * color.getRed(),
			_green * color.getGreen(),
			_blue * color.getBlue(),
			_special);
	}

	Color colorAverage(Color color) {
		return Color((_red + color.getRed()) / 2,
			(_green + color.getGreen()) / 2,
			(_blue + color.getBlue()) / 2,
			_special);
	}

	void clip();

	Color();

	Color(double, double, double, double);

	~Color();
};
