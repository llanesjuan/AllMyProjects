#include "BirdMigration.h"



int BirdMigration::maxMigration(vector<int> a)
{
	int indexMax = INT_MIN;
	int max = INT_MIN;
	vector<int>bird(5);
	vector<int>::iterator itr;
	for (itr = a.begin(); itr != a.end(); itr++) {
		bird[(*itr)-1]++;
		if (bird[(*itr)-1] > max) {
			max = bird[(*itr)-1];
			indexMax = (*itr)-1;
		}
	}
	return indexMax+1;
	
}

BirdMigration::BirdMigration()
{
}


BirdMigration::~BirdMigration()
{
}
