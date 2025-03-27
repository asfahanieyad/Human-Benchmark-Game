#include "square.h"

Square::Square()
{
	x = 0;
	y = 0;
	size = 1;
}

Square::Square(float x_in, float y_in, float size_in)
{
	x = x_in;
	y = y_in;
	size = size_in;
}

void Square::set(float x_in, float y_in, float size_in)
{
	x = x_in;
	y = y_in;
	size = size_in;
}

void Square::draw()
{
	ofDrawRectangle(x, y, size, size);
}

void Square::print(string label)
{
	printf("\nSquare Object: %s----------", label.c_str());
	printf("\n x: %f", x);
	printf("\n y: %f", y);
	printf("\n r: %f", size);
}

void Square::getUniformXSamples(float min, float max, float step, Square samp[])
{
	int n;
	n = max - min / step;
	for (int i = 0; i < n; i++)
	{
		samp[i].x = min + i * step;
	}
}

void Square::getUniformYSamples(float min, float max, float step, Square samp[])
{
	int n;
	n = max - min / step;
	for (int i = 0; i < n; i++)
	{
		samp[i].y = min + i * step;
	}
}

bool Square::clicked(float px, float py)
{
	if (px > x && px < size && py > y && py < size)
	{
		return(true);
	}
}

void Square::setNumber(int number_in)
{
	number = number_in;
}


void Square::drawNumber()
{
	ofSetColor(0, 0, 0);
	font.load("C:\\Users\\asfah\\Downloads\\open-sans\\OpenSans-Regular.ttf", 36);
	font.drawString(ofToString(number), x + size / 2, y + size / 2);
}

bool Square::inside(float x_in, float y_in)
{
	if (x_in > x && x_in < x + size && y_in > y && y_in < y + size)
	{
		return(true);
	}
	else return(false);
}






