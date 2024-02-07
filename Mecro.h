#pragma once

#include <iostream>
#include <string>
#include <conio.h>
#include <iomanip>
#include <Windows.h>
#include <cstdlib>
#include <vector>
#include <time.h>
using namespace std;

//x,y 좌표 구조체
struct Position
{
	int m_ix;
	int m_iy;
	//좌표 비교하기 위한 연산자 오버로드
	bool operator==(Position tmp)
	{
		if ((this->m_ix == tmp.m_ix) && (this->m_iy == tmp.m_iy))
			return true;
		else
			return false;
	}
};
//맵크기 구조체
struct Size
{
	int m_iWidth;
	int m_iHeight;
};