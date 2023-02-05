//
//  Models.cpp
//
//  Assignment-specific code for objects.
//
//  Created by Warren R. Carithers on 2021/09/02.
//  Based on earlier versions created by Joe Geigel and Warren R. Carithers
//  Copyright 2021 Rochester Institute of Technology. All rights reserved.
//
//  This file should not be modified by students.
//

#include <cstdlib>
#include <iostream>

#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#endif

//
// GLEW and GLFW header files also pull in the OpenGL definitions
//
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Types.h"
#include "ShaderSetup.h"
#include "Buffers.h"
#include "Rasterizer.h"

#include "Models.h"

using namespace std;

///
/// Create an object
///
/// @param R  The Rasterizer we'll be using
/// @param B  The BufferSet for the created object
///
void createObject( Rasterizer &R, BufferSet &B )
{
    Color green  = { 0.00f, 1.00f, 0.00f, 1.00f };
    Color orange = { 1.00f, 0.65f, 0.00f, 1.00f };
    Color yellow = { 1.00f, 1.00f, 0.00f, 1.00f };

    // start with a clean canvas
    R.C.clear();

    // ######## The letter 'G' in green ########

    R.C.setColor( green );

    R.drawLine(  80, 340, 220, 340 );  // Horizontal left to right 
    R.drawLine(  40, 380,  80, 340 );  // 315 degree slope        
    R.drawLine( 220, 340, 260, 380 );  // 45 degree slope          
    R.drawLine( 260, 380, 260, 440 );  // Vertical bottom to top
    R.drawLine( 260, 440, 180, 440 );  // Horizontal right to left
    R.drawLine( 180, 440, 180, 400 );
    R.drawLine( 180, 400, 220, 400 );
    R.drawLine( 220, 400, 200, 380 );
    R.drawLine( 200, 380, 100, 380 );
    R.drawLine( 100, 380,  80, 400 );
    R.drawLine(  80, 400,  80, 500 );
    R.drawLine(  80, 500, 100, 520 );
    R.drawLine( 100, 520, 200, 520 );
    R.drawLine( 200, 520, 220, 500 );
    R.drawLine( 220, 500, 220, 480 );
    R.drawLine( 220, 480, 260, 480 );
    R.drawLine( 260, 480, 260, 520 );
    R.drawLine( 260, 520, 220, 560 );  // 135 degree slope
    R.drawLine( 220, 560,  80, 560 );
    R.drawLine(  80, 560,  40, 520 );  // 225 degree slope
    R.drawLine(  40, 520,  40, 380 );  // Vertical top to bottom

    // ######## The letter 'O' in orange ########

    R.C.setColor( orange );

    R.drawLine( 450, 320, 520, 340 );  // 16.6 degree slope
    R.drawLine( 520, 340, 540, 360 );  // 45 degree slope
    R.drawLine( 540, 360, 560, 450 );  // 77.47 degree slope
    R.drawLine( 560, 450, 540, 540 );  // 102.83 degree slope
    R.drawLine( 540, 540, 520, 560 );  // 135 degree slope
    R.drawLine( 520, 560, 450, 580 );  // 163.3 degree slope
    R.drawLine( 450, 580, 380, 560 );  // 196.71 degree slope
    R.drawLine( 380, 560, 360, 540 );  // 225 degree slope
    R.drawLine( 360, 540, 340, 450 );  
    R.drawLine( 340, 450, 360, 360 );
    R.drawLine( 360, 360, 380, 340 );
    R.drawLine( 380, 340, 450, 320 );
    R.drawLine( 420, 380, 480, 380 );
    R.drawLine( 480, 380, 520, 420 );
    R.drawLine( 520, 420, 520, 480 );
    R.drawLine( 520, 480, 480, 520 );
    R.drawLine( 480, 520, 420, 520 );
    R.drawLine( 420, 520, 380, 480 );
    R.drawLine( 380, 480, 380, 420 );
    R.drawLine( 380, 420, 420, 380 );

    // now, draw the student's initials

    R.myInitials();

    // finally, create the buffers

    B.createBuffers( R.C );
}
