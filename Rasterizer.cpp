//
//  Rasterizer.cpp
//
//  Created by Warren R. Carithers on 2021/09/05.
//  Based on a C++ version created by Joe Geigel on 11/30/11.
//  Copyright 2021 Rochester Institute of Technology. All rights reserved.
//
//  Contributor:  YOUR_NAME_HERE
//

#include <cmath>

#include "Rasterizer.h"

//
//
// Simple class that performs rasterization algorithms
//
//

///
/// Constructor
///
/// @param n number of scanlines
/// @param C the Canvas to be used
///

Rasterizer::Rasterizer( int n, Canvas &canvas ) : n_scanlines(n), C(canvas)
{
}


///
/// Draw my initials
///
/// Draw my own initials using calls to drawLine(), in the same
/// manner that makeLines() in the driver program draws 'CG'.
///

void Rasterizer::myInitials( void ) {

    // ######## Use yellow for the initials ######## 
    Color yellow = { 1.000f, 1.000f, 0.000f, 1.000f };

    C.setColor( yellow );

    //
    // Add code here to draw your initials with calls to your
    // drawLine() function (see Models.cpp for examples)
    // 
}

///
/// Draw a line from (x0,y0) to (x1, y1)
///
/// Implementation should be using the integer Midpoint Line Algorithm.
///
/// You are to add the implementation here using only calls to the
/// addPixel() method of the Canvas.
///
/// @param x0 x coord of first endpoint
/// @param y0 y coord of first endpoint
/// @param x1 x coord of second endpoint
/// @param y1 y coord of second endpoint
///

void Rasterizer::drawLine( int x0, int y0, int x1, int y1 )
{
    //
    // Replace the two calls to C.addPixel() with
    // your implementation of drawLine()
    //

    C.addPixel( x0, y0 );
    C.addPixel( x1, y1 );
}
