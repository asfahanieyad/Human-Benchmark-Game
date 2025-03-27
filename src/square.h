#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <ofRectangle.h>
#include <ofGraphics.h>
#include <ofTrueTypeFont.h>

using namespace std;

class Square
{
public:
	//Member variables
	float x;
	float y;
	float size;
	int number;

	//Methods

	Square();
	Square(float x_in, float y_in, float size_in);
	void set(float x_in, float y_in, float size_in);
	void draw();
	void print(string label);
	void getUniformXSamples(float min, float max, float step, Square samp[]);
	void getUniformYSamples(float min, float max, float step, Square samp[]);
	bool clicked(float px, float py);
	void setNumber(int number_in);
	void drawNumber();
	bool inside(float x_in, float y_in);


private:
	ofTrueTypeFont font;
};
