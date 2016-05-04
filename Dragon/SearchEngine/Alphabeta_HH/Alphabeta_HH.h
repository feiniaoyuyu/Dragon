#pragma once
#ifndef __INCLUDE_ALPHABETA_HH_H__
#define __INCLUDE_ALPHABETA_HH_H__

#include "SearchEngine.h"
#include "HistoryHeuristic.h"

class CAlphabeta_HH : public CSearchEngine , public CHistoryHeuristic
{
public:
	CAlphabeta_HH();
	virtual ~CAlphabeta_HH();
	virtual void SearchAGoodMove(int position[10][10],int m_UpDown);
protected:
	int alphabeta(int depth, int alpha, int beta,int m_UpDown);
};

#endif // __INCLUDE_ALPHABETA_HH_H__
