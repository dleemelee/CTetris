// NewLine
// 안녕하세요 저는장원이입니다
//
//  main.cpp
//  OpenGL Tutorial
//
//  Created by PAKGI HYEOK on 2014. 6. 13..
//  Copyright (c) 2014년 anonymous. All rights reserved.
//

#ifdef WIN32
#include <windows.h>
#endif

#include <stdlib.h>
#include <iostream>
#include <fstream>



#ifdef __APPLE__
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>

// for bitmap Loadingtt
#else
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#endif

#include "CTetrimino.h"
#include "CTetrisBoard.h"

#define EYE_SPAN_DEGREE 45.0
#define Z_NEAR 1.0
#define Z_FAR 2000.0


/* global Variable */
using namespace std;

// For Open GL
int is_Calculated = 0;
float x_eyePoint = 20.0;
float y_eyePoint = 20.0;

// For Tetris Game
CTetrimino* myBlock;
CTetrisBoard* myBoard;


// CallBack Functions
void Reshape(int width, int height );
void Display( );
void Idle( );
void KeyboardCallBack(unsigned char, int, int );

void DrawAxis();
void DrawBlocks( CTetrimino* newBlockData  );

int main(int argc, char **argv )
{
    
    /* Initialization */
    glutInit(&argc, argv);
    glutInitWindowSize(1024, 768);
    glutInitWindowPosition(100, 100);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB );
    glutCreateWindow("empty project");
    glEnable(GL_POLYGON_SMOOTH);
    
    glClearColor(0,0,0,0);
    glutDisplayFunc( Display );
    glutReshapeFunc( Reshape );

    glutIdleFunc( Idle );
    glutKeyboardFunc(KeyboardCallBack );
    
    myBlock = new CTetrimino();
    myBoard = new CTetrisBoard();

    myBlock->SetPtrCTetrisBoard(myBoard);
    myBlock->RenderBlock();
    cout << "Main Loop Start" << endl;
    glutMainLoop();
    cout << "Main Loop End" << endl;


    return EXIT_SUCCESS;
}

void Reshape(int width, int height )
{
    cout << "Reshape( ) called" << endl;
//    glViewport(0, 0, width , height);     // Binding the Viewport to the Window
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();           // Identity Matrix
    
    gluPerspective(EYE_SPAN_DEGREE , width/height , Z_NEAR, Z_FAR); //

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void Display( )
{
    glClear( GL_COLOR_BUFFER_BIT ); // Clear previous frame data

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();           // Identity Matrix
    
    gluLookAt(x_eyePoint , y_eyePoint, 130.0f , 20.0f ,40.0f ,0.0f , 0.0f, 1.0f, 0.0f);

    DrawAxis();
    DrawBlocks( myBlock );
    
    glFlush();
}
void Idle ( )
{
}

void KeyboardCallBack(unsigned char keyValue, int mousePos_x , int mousePos_y )
{
    for ( int i = 0 ; i < 15 ; i++){
        for ( int j = 0 ; j < 10 ; j++ )
        {
            if ( myBoard->boardData[i][j] > 10 )
                 myBoard->boardData[i][j] = 0;
        }
    }

    switch ( keyValue )
    {
        case 'w':
        case 'W':
            myBlock->RotateCW();
            break;
        case 's':
        case 'S':
            myBlock->MoveDown();
            break;
        case 'a':
        case 'A':
            myBlock->MoveLeft();
            break;
        case 'd':
        case 'D':
            myBlock->MoveRight();
            break;

    }
    glutPostRedisplay();
    
}

void DrawAxis()
{
    // X-Axis
    glColor3f(1,0,0);
    glBegin(GL_LINES);
        glVertex3f(-1000, 0, 0);
        glVertex3f(1000, 0, 0);
    glEnd();
    
    // Y-Axis
    glColor3f(0,1,0);
    glBegin(GL_LINES);
    glVertex3f(0, -1000, 0);
    glVertex3f(0, 1000, 0 );
    glEnd();
    
    // Z-Axis
    glColor3f(0,0,1);
    glBegin(GL_LINES);
    glVertex3f(0, 0, -1000);
    glVertex3f(0, 0, 1000 );
    glEnd();
}

void DrawBlocks(CTetrimino* newBlockData )
{
    int blockColorR, blockColorG, blockColorB;
 
    for ( int i = 0 ; i < 15  ; i++ )
        for ( int j = 0 ; j < 10 ; j++ )
        {
            switch ( myBoard->boardData[i][j] )
            {
            case 1:
                blockColorR = 1;
                blockColorG = 0;
                blockColorB = 0;
                break;
            case 2:
                blockColorR = 0;
                blockColorG = 1;
                blockColorB = 0;
                break;
            case 3:
                blockColorR = 0;
                blockColorG = 0;
                blockColorB = 1;
                break;
            case 11:
                blockColorR = 0;
                blockColorG = 1;
                blockColorB = 1;
                break;
            default:
                blockColorR = 0;
                blockColorG = 0;
                blockColorB = 0;
                break;
            }
            
            glPushMatrix();
                glTranslated( 0+j*5, (0+i)*5, 0);
                glColor3f( blockColorR ,blockColorG, blockColorB );
                glutSolidCube(5);
                glColor3f( 0,1,0 );
                glutWireCube(5);
            glPopMatrix();
        
        }
}
