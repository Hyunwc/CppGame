#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>
#include <fstream> //���� �����
#include <time.h>
#include <list>
using namespace std;

#define col GetStdHandle(STD_OUTPUT_HANDLE)
#define ORIGINAL SetConsoleTextAttribute( col,0x0007 );
#define RED SetConsoleTextAttribute( col,0x000c );
#define YELLOW SetConsoleTextAttribute( col,0x000e );

#define WIDTH 30
#define HEIGHT 30
