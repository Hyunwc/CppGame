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

//x,y ��ǥ ����ü
struct Position
{
	int m_ix;
	int m_iy;
	//��ǥ ���ϱ� ���� ������ �����ε�
	bool operator==(Position tmp)
	{
		if ((this->m_ix == tmp.m_ix) && (this->m_iy == tmp.m_iy))
			return true;
		else
			return false;
	}
};
//��ũ�� ����ü
struct Size
{
	int m_iWidth;
	int m_iHeight;
};