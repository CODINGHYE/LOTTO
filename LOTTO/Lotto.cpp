#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstring>
#include "Lotto.h"
const int row = 10;
const int col = 7;
int cnt=0;
using namespace std;
void sort(int& a, int& b)
{
	int tmp = 0;
	tmp = a;
	a = b;
	b = tmp;
}

void Lotto::draw()
{
	int r = 0;
	//array �迭 ���� ����
	m_cnt++;
	for (int i = 0;i < 7;i++)
	{
		r = rand() % 45 + 1;
		m_array[i] = r;
		m_countTable[r]++;
		for (int j = 0; j < i; j++)
		{
			if (m_array[i] == m_array[j])
			{
				i--;
				break;
			}
		}
	}
	//swap�� �̿��� m_array ����
	for (int i = 0;i < 5;i++)
	{
		for (int j = 0;j < 5 - i;j++)
		{
			if (m_array[j] > m_array[j + 1])
				sort(m_array[j], m_array[j + 1]);
		}
	}
	//m_show_array�� m_array�� �������
	if (cnt == 11)
	{
		for (int i = 1;i < row;i++)
		{
			for (int j = 0;j < col;j++)
				m_show_array[i - 1][j] = m_show_array[i][j];
		}
		for (int j = 0;j < col;j++)
		{
			m_show_array[cnt-2][j] = m_array[j];
		}
		cnt--;
	}
	else
	{
		for (int j = 0;j < col;j++)
		{
			m_show_array[cnt-1][j] = m_array[j];
		}
	}
	//m_array ���
	for (int i = 0;i < col;i++)
	{
		cout << m_array[i] << ' ';
	}
	cout << endl;
}

void Lotto::show(int n)// n�� ���� ���� ���� �ε���
{
	cout << "�ֱ����κ��� " << n << "��° draw: ";
	for (int i = 0;i < col;i++)
	{
		cout << m_show_array[cnt- 1 - n][i] << ' ';
	}
	cout << endl;
}

void Lotto::stat()
{
	for (int i = 1; i <= 45; i++)
	{
		float p;
		const float value = static_cast<float>(m_countTable[i]);
		const float rangeSize = 45.0f;
		std::cout << std::fixed;
		std::cout.precision(7);
		if (this->m_cnt == 0)
		{
			p = 0;
		}
		else
		{
			p = (value / (rangeSize * this->m_cnt)) * 100;
		}
		std::cout << i << "�� ���� Ȯ��: " << p << "%\n";
	}
}