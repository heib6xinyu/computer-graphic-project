//
//  Models.h
//
//  Assignment-specific code for objects.
//
//  Created by Warren R. Carithers on 2021/09/02.
//  Based on earlier code created by Joe Geigel and Warren R. Carithers
//  Copyright 2021 Rochester Institute of Technology. All rights reserved.
//
//  This file should not be modified by students.
//

#ifndef MODELS_H_
#define MODELS_H_

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
#include "Buffers.h"
#include "Rasterizer.h"

///
/// Create an object
///
/// @param R  The Rasterizer we'll be using
/// @param B  The BufferSet for the created object
///
void createObject( Rasterizer &R, BufferSet &B );

#endif
