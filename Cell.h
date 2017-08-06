#include <iostream>
#include <windows.h>

#ifndef GRAPHYCALELEMENT_H
#define GRAPHYCALELEMENT_H
#include "GraphycalElement.h"
#endif

using namespace std;

class Cell : public GraphycalElement {
	public:
		Cell(int x,
			 int y,
			 int textColor = 15,
			 int backgroundColor = 0,
			 int width = 2,
			 int height = 2)
		{
			x_ = x;
			y_ = y;
			width_ = width;
			height_ = height;
			textColor_ = textColor;
			backgroundColor_ = backgroundColor;
		};

		void draw();
	private:
		int x_;
		int y_;
		int width_;
		int height_;
		int textColor_;
		int backgroundColor_;
};