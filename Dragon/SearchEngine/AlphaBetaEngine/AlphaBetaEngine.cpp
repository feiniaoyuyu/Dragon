#include "stdafx.h"
#include "AlphaBetaEngine.h"


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
CAlphaBetaEngine::CAlphaBetaEngine()
{/////////////////////////////////
}

CAlphaBetaEngine::~CAlphaBetaEngine()
{

}
void CAlphaBetaEngine::SearchAGoodMove(int position[10][10],int m_UpDown)
{
	CPublicToMakeMove ptmm;
	memcpy(CurPosition, position, sizeof(CurPosition));
	m_nMaxDepth = m_nSearchDepth;
	alphabeta(m_nMaxDepth, -2000000, 2000000,m_UpDown);
	MakeMove(&m_cmBestMove,ptmm,WHITE * m_UpDown);
	memcpy(position, CurPosition, sizeof(CurPosition));
}

int CAlphaBetaEngine::alphabeta(int depth, int alpha, int beta,int m_UpDown)
{
	int score;
	int Count,i;
	int mtype = (m_nMaxDepth%2 == depth%2) ? (-1) : (1);
	CPublicToMakeMove ptmm;
	i = IsGameOver(CurPosition, depth,mtype * m_UpDown);	
	if (i != 0)
		return i;

	if (depth <= 0)	//叶子节点取估值
	{
		if(1 == m_UpDown)
			return m_pEval->Eveluate(CurPosition,mtype * m_UpDown,(m_nMaxDepth-depth)%2);
		else
			return m_pEval->Eveluate(CurPosition,mtype * m_UpDown,(m_nMaxDepth-depth+1)%2);
	}
	
	Count = m_pMG->CreatePossibleMove(CurPosition, depth,mtype * m_UpDown);

	if(1 == Count && depth == m_nMaxDepth)
	{
		m_cmBestMove = m_pMG->m_nMoveList[depth][0];
		return 0;
	}
	for (i=0;i<Count;i++) 
	{

		MakeMove(&m_pMG->m_nMoveList[depth][i],ptmm);
		score = -alphabeta(depth - 1, -beta, -alpha,m_UpDown);
		UnMakeMove(&m_pMG->m_nMoveList[depth][i],ptmm); 

		if (score > alpha)
		{
			alpha = score;
			if(depth == m_nMaxDepth)
				m_cmBestMove = m_pMG->m_nMoveList[depth][i];
		}
        if (alpha >= beta) 
              break;
	}
	return alpha;
}