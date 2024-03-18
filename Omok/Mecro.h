#pragma once
#include <iostream>
#include <string>
#include <conio.h>
#include <iomanip>
#include <Windows.h>
#include <fstream>
#include <vector>
using namespace std;

//x, y 좌표 구조체
struct Position
{
	int m_ix;
	int m_iy;
};

struct Size
{
	int m_iWidth;
	int m_iHeight;
};