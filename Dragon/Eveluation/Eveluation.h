#pragma once

#ifndef __INCLUDE_EVELUATION_H__
#define __INCLUDE_EVELUATION_H__
#include "PublicToCountSpace.h"
class CEveluation : public CPublicToCountSpace
{
public:
	CEveluation();
	~CEveluation();
	int Eveluate(int position[10][10], int TURE,int nCeng);
public:
	//1.����������λ��
	void count_qi_num();
	//2.���߸���
	void count_bianxian_num();
	//3.������
	void count_lian_num();
	//4.����������
	void count_sanjiao_num();
	//5.������
	void count_zuozhongyou();
	//6.ѹ������
	void count_yazhi_num();
	//7.��ȫֵ
	void AnQuanZhi();
	//8��
	void Kong();
	//9.�м�
	void ZhongJian();
	//10.��ֹ����
	void FangZhiChengWang();
	//11.��ѹ��
	void WY();
	void shuzuTwo_shuzuOne(BYTE i,BYTE j,BYTE shuzu[51]);
public:
	//�ڰ����������
	BYTE m_shuzu_white[51];
	BYTE m_shuzu_black[51];
	//����
	int m_position[10][10];
	//�ڰ�
	int m_nntype;
	//˫����ֵ
	int m_value_white;
	int m_value_black;
	//���Ӹ���
	BYTE m_num_white;
	BYTE m_num_black;
	BYTE m_num_king_white;
	BYTE m_num_king_black;
	//ÿ������
	BYTE m_num_hang_white[10];
	BYTE m_num_hang_black[10];
	//ÿ������
	BYTE m_num_lie_white[10];
	BYTE m_num_lie_black[10];
	//���߸���
	BYTE m_num_bianxian_white;
	BYTE m_num_bianxian_black;
	//���ĸ���
	BYTE m_num_lian_white;
	BYTE m_num_lian_black;
	//�����θ���
	BYTE m_num_sanjiao_white;
	BYTE m_num_sanjiao_black;
	//������
	BYTE m_num_left_white;
	BYTE m_num_middle_white;
	BYTE m_num_right_white;
	BYTE m_num_left_black;
	BYTE m_num_middle_black;
	BYTE m_num_right_black;
	//ѹ��
	BYTE m_num_yazhi_white;
	BYTE m_num_yazhi_black;
};

#endif //__INCLUDE_EVELUATION_H__