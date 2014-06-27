//
//  CTetrimino.cpp
//  OpenGL Tutorial
//
//  Created by PAKGI HYEOK on 2014. 6. 17..
//  Copyright (c) 2014년 anonymous. All rights reserved.
//
#define ECHO_FLAG 1

#include "CTetrimino.h"
#include <iostream>
using namespace std;

CTetrimino::CTetrimino()
{
    BlockCode = 1;
    BlockPattern = 0;
    this->ResetCenterCoordinate();
}
void CTetrimino::SetPtrCTetrisBoard(CTetrisBoard* newPtrCTetrisBoard )
{
    this->pCTetrisBoard = newPtrCTetrisBoard;
}

CTetrisBoard* CTetrimino::GetPtrCTetrisBoard()
{
    return this->pCTetrisBoard;
}

void CTetrimino::ResetCenterCoordinate()
{
    this->coordX = 4;
    this->coordY = 14;
}

int CTetrimino::GetBlockCode( )
{
    return this->BlockCode;
}

void CTetrimino::NextBlockPosition(int movingDirection)
{
    // 이동 방향에 따라서 deltaX, deltaY 값 결정
    bool is_rotated = false;
    int deltaX = 0;
    int deltaY = 0;
    int nextBlockPattern = BlockPattern+8;
    switch (movingDirection) {
        case LEFT_MOVE:
            deltaX = (-1);
            deltaY = 0;
            break;
        case RIGHT_MOVE:
            deltaX = +1;
            deltaY = 0;
            break;
        case DOWN_MOVE:
            deltaX = 0;
            deltaY = (-1);
            break;
        case ROTATE_CW:
            nextBlockPattern--;
            is_rotated = true;
        case ROTATE_CCW:
            //nextBlockPattern--;
            // 모듈화 필요
            switch ( BlockCode ) {
                case T_BLOCK:
                    switch ( nextBlockPattern % 4 ) {
                        case 0:
                            nextBlockPosition[0][0] = coordX;
                            nextBlockPosition[0][1] = coordY;
                            
                            nextBlockPosition[1][0] = coordX+1;
                            nextBlockPosition[1][1] = coordY;
                            
                            nextBlockPosition[2][0] = coordX-1;
                            nextBlockPosition[2][1] = coordY;
                            
                            nextBlockPosition[3][0] = coordX;
                            nextBlockPosition[3][1] = coordY+1;
                            
                            break;
                        case 1:
                            nextBlockPosition[0][0] = coordX;
                            nextBlockPosition[0][1] = coordY;
                            
                            nextBlockPosition[1][0] = coordX+1;
                            nextBlockPosition[1][1] = coordY;
                            
                            nextBlockPosition[2][0] = coordX;
                            nextBlockPosition[2][1] = coordY-1;
                            
                            nextBlockPosition[3][0] = coordX;
                            nextBlockPosition[3][1] = coordY+1;
                            
                            break;
                        case 2:
                            nextBlockPosition[0][0] = coordX;
                            nextBlockPosition[0][1] = coordY;
                            
                            nextBlockPosition[1][0] = coordX+1;
                            nextBlockPosition[1][1] = coordY;
                            
                            nextBlockPosition[2][0] = coordX-1;
                            nextBlockPosition[2][1] = coordY;
                            
                            nextBlockPosition[3][0] = coordX;
                            nextBlockPosition[3][1] = coordY-1;
                            
                            break;
                        case 3:
                            nextBlockPosition[0][0] = coordX;
                            nextBlockPosition[0][1] = coordY;
                            
                            nextBlockPosition[1][0] = coordX;
                            nextBlockPosition[1][1] = coordY-1;
                            
                            nextBlockPosition[2][0] = coordX-1;
                            nextBlockPosition[2][1] = coordY;
                            
                            nextBlockPosition[3][0] = coordX;
                            nextBlockPosition[3][1] = coordY+1;
                            
                            break;
                        default:
                            break;
                    }
                    break;
                default:
                    break;
            }

            break;
        default:
            deltaX = 0;
            deltaY = 0;
            break;
    }
    
    if ( is_rotated != true ){
        // 현재 블럭 위치로 nextBlockPosition 배열 초기화
        for ( int i = 0 ; i < 4 ; i++ )
            for ( int j = 0 ; j < 2 ; j++ )
            {
                nextBlockPosition[i][j] = blockPosition[i][j];
            }
        // 다음 블럭 위치 계산해서 nextBlockPosition에 저장
        for ( int i = 0 ; i < 4 ; i++ )
        {
            nextBlockPosition[i][0] += deltaX;
            nextBlockPosition[i][1] += deltaY;
        }
    }
}

void CTetrimino::RenderBlock( )
{
    switch ( BlockCode ) {
        case T_BLOCK:
            switch ( BlockPattern % 4 ) {
                case 0:
                    blockPosition[0][0] = coordX;
                    blockPosition[0][1] = coordY;
                    
                    blockPosition[1][0] = coordX+1;
                    blockPosition[1][1] = coordY;
                    
                    blockPosition[2][0] = coordX-1;
                    blockPosition[2][1] = coordY;
                    
                    blockPosition[3][0] = coordX;
                    blockPosition[3][1] = coordY+1;

                    break;
                case 1:
                    blockPosition[0][0] = coordX;
                    blockPosition[0][1] = coordY;
                    
                    blockPosition[1][0] = coordX+1;
                    blockPosition[1][1] = coordY;
                    
                    blockPosition[2][0] = coordX;
                    blockPosition[2][1] = coordY-1;
                    
                    blockPosition[3][0] = coordX;
                    blockPosition[3][1] = coordY+1;

                    break;
                case 2:
                    blockPosition[0][0] = coordX;
                    blockPosition[0][1] = coordY;
                    
                    blockPosition[1][0] = coordX+1;
                    blockPosition[1][1] = coordY;
                    
                    blockPosition[2][0] = coordX-1;
                    blockPosition[2][1] = coordY;
                    
                    blockPosition[3][0] = coordX;
                    blockPosition[3][1] = coordY-1;

                    break;
                case 3:
                    blockPosition[0][0] = coordX;
                    blockPosition[0][1] = coordY;
                    
                    blockPosition[1][0] = coordX;
                    blockPosition[1][1] = coordY-1;
                    
                    blockPosition[2][0] = coordX-1;
                    blockPosition[2][1] = coordY;
                    
                    blockPosition[3][0] = coordX;
                    blockPosition[3][1] = coordY+1;
                    
                    break;
                default:
                    break;
            }

            break;
        default:
            break;
    }
    for ( int i = 0 ; i < 4 ; i++ )
    {
        int x = blockPosition[i][0];
        int y = blockPosition[i][1];
        this->pCTetrisBoard->boardData[ y ][ x ] = 11;
    }
}

int CTetrimino::GetCoordX( )
{
    return this->coordX;
    
}
int CTetrimino::GetCoordY( )
{
    return this->coordY;
    
}

void CTetrimino::RotateCW( )
{
    if ( this->CollisionCheck( ROTATE_CW ) != true )
    {
        this->BlockPattern--;
        this->RenderBlock();
        cout << " Rotate CW Collision" << endl;
    }
    else
    {
        this->RenderBlock();
    }

}
void CTetrimino::RotateCCW( )
{
    if ( this->CollisionCheck( ROTATE_CCW ) != true )
    {
        this->BlockPattern++;
        this->RenderBlock();
    }
    else
    {
        this->RenderBlock();
    }
}

void CTetrimino::MoveLeft( )
{
    if ( this->CollisionCheck( LEFT_MOVE ) != true )
    {
        this->coordX--;
        this->RenderBlock();
    }
    else
    {
        this->coordX += 0;
        this->RenderBlock();
    }

}

void CTetrimino::MoveRight( )
{
    if ( this->CollisionCheck( RIGHT_MOVE) != true )
    {
        this->coordX++;
        this->RenderBlock();
    }
    else
    {
        this->coordX += 0;
        this->RenderBlock();
    }
    

}
void CTetrimino::MoveDown( )
{
    if ( this->CollisionCheck( DOWN_MOVE ) != true )
    {
        this->coordY--;
        this->RenderBlock();
    }
    else
    {
        this->coordY += 0;
        this->RenderBlock();
    }
}

void CTetrimino::MoveHardDrop( )
{
    
}

bool CTetrimino::CollisionCheck( int movingDirection )
{
    bool isCollide = false;
    // 이동 방향에 따라서 다음 블럭 위치 계산
    switch ( movingDirection ) {
        case LEFT_MOVE:
            NextBlockPosition( LEFT_MOVE );
            break;
        case RIGHT_MOVE:
            NextBlockPosition( RIGHT_MOVE );
            break;
        case DOWN_MOVE:
            NextBlockPosition( DOWN_MOVE );
            break;
        case ROTATE_CW:
            NextBlockPosition( ROTATE_CW );
            break;
        case ROTATE_CCW:
            NextBlockPosition( ROTATE_CCW );
            break;
        
            
            
            
        default:
            break;
    }
#if ECHO_FLAG
    cout << "Next Coordinate of tetrimno" << endl;
    for ( int i = 0 ; i < 4 ; i++){
        cout << "(Block " << i+1 << ") ";
        for ( int j = 0 ; j < 2 ; j++){
            cout << this->nextBlockPosition[i][j] << " ";
        }
        cout << endl;
    }
#endif
    // wall collision check
    for ( int i = 0 ; i < 4 ; i++){
        int nextX = this->nextBlockPosition[i][0];
        int nextY = this->nextBlockPosition[i][1];

        if ( nextX < 0 || nextX > 9 || // left or right wall collision
            nextY < 0 ) // ground collision
        {
            isCollide = true;
            cout << "collision occrurs."  << endl;
        }
            
        // block collison check
        if ( this->pCTetrisBoard->boardData[nextY][nextX] != 0 // next position of Movable block is not empty
            && this->pCTetrisBoard->boardData[nextY][nextX] < 11 ) // nextPosition of Movable block is not filled by itself
        {
            isCollide = true;
            cout << "collision occrurs."  << endl;
        }
    }
    return isCollide;
    
}