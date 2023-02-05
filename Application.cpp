//
//  Application.cpp
//
//  Assignment-specific code.
//
//  Created by Warren R. Carithers on 2019/09/09.
//  Based on earlier versions created by Joe Geigel and Warren R. Carithers
//  Copyright 2019 Rochester Institute of Technology. All rights reserved.
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
#include "Utils.h"
#include "ShaderSetup.h"
#include "Buffers.h"
#include "Models.h"
#include "Canvas.h"
#include "Rasterizer.h"

#include "Application.h"

using namespace std;

//
// PRIVATE GLOBALS
//

// names of our GLSL shader files (we assume GLSL 1.50)
static const char *vshader = "v150.vert";
static const char *fshader = "v150.frag";

// our Rasterizer
static Rasterizer *rasterizer;

// buffers for our shapes
static BufferSet shapes;

// shader program handle
static GLuint program;

// our VAO
static GLuint vao;

// do we need to do a display() call?
static bool updateDisplay = true;

// click counter for color selection
static int counter = 0;

//
// PUBLIC GLOBALS
//

//
// Drawing-related variables
//

// dimensions of the drawing window
int w_width  = 600;
int w_height = 600;

// drawing window title
const char *w_title = "Midpoint Line Algorithm";

// GL context we're using (we assume 3.0, for GLSL 1.30)
int gl_maj = 3;
int gl_min = 0;

// our GLFWwindow
GLFWwindow *w_window;

//
// PRIVATE FUNCTIONS
//

///
/// Create the shapes we'll display
///
static void createImage( void )
{
    // create the lines
    createObject( *rasterizer, shapes );
}

//
// Event callback routines for this assignment
//

///
/// Handle keyboard input
///
/// @param window   GLFW window being used
/// @param key      code for the key that was pressed
/// @param scan     scan code of the key
/// @param action   type of event (press, release, etc.)
/// @param mods     modifiers in use (shift, etc.)
///
static void keyboard( GLFWwindow *window, int key, int scan,
                      int action, int mods )
{
    // only react to "press" events
    if( action != GLFW_PRESS ) {
        return;
    }

    switch( key ) {
    case GLFW_KEY_H:    // help message
        cout << "  Key(s)             Action" << endl;
        cout << "=========   =======================" << endl;
        cout << "ESC, q, Q   Terminate the program" << endl;
        cout << " h, H       Print this message" << endl;
        break;

    case GLFW_KEY_ESCAPE:
    case GLFW_KEY_Q:
        glfwSetWindowShouldClose( window, 1 );
        break;
    }
}

///
/// Display the current image
///
static void display( void )
{
    int nv;

    // clear the frame buffer
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    // ensure we have selected the shader program
    glUseProgram( program );

    // set up our scale factors for normalization
    GLuint sf = glGetUniformLocation( program, "sf" );
    glUniform2f( sf, 2.0f / (w_width - 1.0f), 2.0f / (w_height - 1.0f) );

    // bind the vertex and element buffers
    shapes.selectBuffers( program, "vPosition", "vColor", NULL, NULL );

    // draw the shapes
    glDrawArrays( GL_POINTS, 0, shapes.numElements );
}

///
/// OpenGL initialization
///
/// @return boolean indicating status of initialization
///
static bool init( void )
{
    // Check the OpenGL major version
    if( gl_maj < 3 ) {
        vshader = "v120.vert";
        fshader = "v120.frag";
    }

    // Load shaders and use the resulting shader program
    ShaderError error;
    program = shaderSetup( vshader, fshader, &error );
    if( !program ) {
        cerr << "Error setting up shaders - " << errorString(error) << endl;
        return( false );
    }

    // create our Canvas and Rasterizer
    Canvas *canvas = new Canvas( w_width, w_height );
    if( canvas == NULL ) {
        cerr << "Error - cannot create Canvas" << endl;
        return( false );
    }

    rasterizer = new Rasterizer( w_height, *canvas );
    if( rasterizer == NULL ) {
        cerr << "Error - cannot create Rasterizer" << endl;
        return( false );
    }

    // need a VAO if we're using a core context;
    // doesn't hurt even if we're not using one
    glGenVertexArrays( 1, &vao );
    glBindVertexArray( vao );

    // OpenGL state initialization
    glEnable( GL_DEPTH_TEST );
    glEnable( GL_CULL_FACE );
    glCullFace( GL_BACK );
    glClearColor( 0.0, 0.0, 0.0, 1.0 );
    glPolygonMode( GL_FRONT_AND_BACK, GL_POINT );

    // create the geometry for our shapes.
    createImage();

    // register our callbacks

    // key callback - for when we only care about the physical key
    glfwSetKeyCallback( w_window, keyboard );

    return( true );
}

//
// PUBLIC FUNCTIONS
//

///
/// application-specific processing
///
/// @param argc   command-line argument count
/// @param argv   command-line argument strings
///
void application( int argc, char *argv[] )
{
    // keep the compiler happy
    (void) argc;
    (void) argv;

    // set up the objects and the scene
    if( !init() ) {
        return;
    }

    // loop until it's time to quit
    while( !glfwWindowShouldClose(w_window) ) {
        display();
        glfwSwapBuffers( w_window );
        glfwWaitEvents();
    }
}
