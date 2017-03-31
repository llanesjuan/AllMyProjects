#include "breakRecord.h"




void breakRecord::recordBreaker(vector<int>a,int &inc, int & dec)
{
	int scoreInc, scoreDec;
	scoreInc = scoreDec = a.front(), inc=dec = 0;
	
	vector<int>::iterator itr;
	for (itr = a.begin() + 1; itr != a.end();itr++) {
		if ((*itr) > scoreInc) {
			inc++;
			scoreInc = (*itr);
		}
		else if((*itr)<scoreDec)
		{
			dec++;
			scoreDec = (*itr);
		}
	}
}

breakRecord::breakRecord()
{
}


breakRecord::~breakRecord()
{
}
