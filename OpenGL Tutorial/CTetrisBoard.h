//
//  CTetrisBoard.h
//  OpenGL Tutorial
//
//  Created by PAKGI HYEOK on 2014. 6. 27..
//  Copyright (c) 2014년 anonymous. All rights reserved.
//

#ifndef __OpenGL_Tutorial__CTetrisBoard__
#define __OpenGL_Tutorial__CTetrisBoard__

#include <iostream>

class CTetrisBoard
{
private:
    int numberOfClearedLines; // "Score"
public:
    int boardData[15][10];    // movable Block + stacked Block Data

    CTetrisBoard();  // Constructor
    ~CTetrisBoard(); // Destructor

    void LineClear( ); // Line Clear Check and Process
    
    // Getter and setter
    int GetNumberOfClearedLines( );
};

#endif /* defined(__OpenGL_Tutorial__CTetrisBoard__) */
