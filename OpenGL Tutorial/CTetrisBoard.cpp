//
//  CTetrisBoard.cpp
//  OpenGL Tutorial
//
//  Created by PAKGI HYEOK on 2014. 6. 27..
//  Copyright (c) 2014년 anonymous. All rights reserved.
//

#include "CTetrisBoard.h"

CTetrisBoard::CTetrisBoard()
{
    /* Init Tetris Board Data */
    int tetrisBlocks[15][10] =
    {
        {0,0,0,0,0,0,0,0,0,0 },
        {0,0,0,0,0,0,0,0,0,0 },
        {0,0,0,0,0,0,0,0,0,0 },
        {0,0,0,0,0,0,0,0,0,0 },
        {0,0,0,0,0,0,0,0,0,0 },
        
        {0,0,0,0,0,0,0,0,0,0 },
        {0,0,0,0,0,0,0,0,0,0 },
        {0,0,0,0,0,0,0,0,0,0 },
        {0,0,0,0,0,0,0,0,0,0 },
        {0,0,0,0,0,0,0,0,0,0 },
        
        {0,0,0,0,0,0,0,0,0,0 },
        {0,0,0,0,0,0,0,0,0,0 },
        {0,0,0,0,0,0,0,0,0,0 },
        {0,0,0,0,0,0,0,0,0,0 },
        {1,2,3,2,1,2,3,3,1,2 }
    };
    
    for ( int i = 0 ; i < 15 ; i++ )
        for ( int j = 0 ; j < 10 ; j++ )
        {
            boardData[i][j] = tetrisBlocks[14-i][j];
        }
    numberOfClearedLines = 0;
}


CTetrisBoard::~CTetrisBoard()
{
}

void CTetrisBoard::LineClear( )
{
}
