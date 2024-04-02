#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>
#include <fstream> //파일 입출력
#include <time.h>
#include <list>
#include <vector>
using namespace std;

#define col GetStdHandle(STD_OUTPUT_HANDLE)
#define ORIGINAL SetConsoleTextAttribute( col,0x0007 );
#define RED SetConsoleTextAttribute( col,0x000c );
#define YELLOW SetConsoleTextAttribute( col,0x000e );

#define WIDTH 25
#define HEIGHT 25
