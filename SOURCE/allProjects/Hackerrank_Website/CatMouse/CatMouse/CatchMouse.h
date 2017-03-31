//Two cats named  and  are standing at integral points on the x - axis.Cat  is standing at point 
//and cat  is standing at point.Both cats run at the same speed, and they want to catch a mouse named 
//that's hiding at integral point  on the x-axis. Can you determine who will catch the mouse?
//You are given  queries in the form of, , and.For each query, print the appropriate answer on a new line:
//If cat  catches the mouse first, print Cat A.
//If cat  catches the mouse first, print Cat B.
//If both cats reach the mouse at the same time, print Mouse C as the two cats fight and mouse escapes.
#pragma once
#include<math.h>
#include<string>
using namespace std;

class CatchMouse
{
public:
	string mouseCatcher(int cat1, int cat2, int mouse);
	CatchMouse();
	~CatchMouse();
};

