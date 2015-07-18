// access denied


//
//  CTetrimino.h
//  OpenGL Tutorial
//
//  Created by PAKGI HYEOK on 2014. 6. 17..
//  Copyright (c) 2014년 anonymous. All rights reserved.
//

#ifndef __OpenGL_Tutorial__CTetrimino__
#define __OpenGL_Tutorial__CTetrimino__

#include <iostream>
#include "CTetrisBoard.h"

class CTetrimino
{
private:
    static const int LEFT_MOVE = 0;
    static const int RIGHT_MOVE = 1;
    static const int DOWN_MOVE = 2;
    static const int ROTATE_CW = 3;
    static const int ROTATE_CCW = 4;
    
    static const int T_BLOCK = 1;
    static const int L_BLOCK = 2;
    static const int I_BLOCK = 3;
    
    int BlockCode;
    int BlockPattern;
    
    int coordX;  // 0 ~ 10
    int coordY;  // 0 ~ 15

    int blockPosition[4][2];
    int nextBlockPosition[4][2];

    CTetrisBoard* pCTetrisBoard;
    
public:
    CTetrimino();
    ~CTetrimino( ){;}
    
    
    void RenderBlock( );
    void NextBlockPosition( int movingDirection );

    void ResetCenterCoordinate();
    
    CTetrisBoard* GetPtrCTetrisBoard( );
    void SetPtrCTetrisBoard(CTetrisBoard* newPtrCTetrisBoard );
    
    int GetBlockCode( );
    int GetCoordX( );
    int GetCoordY( );
    
    int** GetBlockPosition( );
    int** GetNextBlockPosition();
    
    void RotateCW( );
    void RotateCCW( );
    
    void MoveLeft( );
    void MoveRight( );
    void MoveDown( );
    void MoveHardDrop( );
    
    // for collision detection
    bool CollisionCheck( int movingDirection );

};

#endif /* defined(__OpenGL_Tutorial__CTetrimino__) */
