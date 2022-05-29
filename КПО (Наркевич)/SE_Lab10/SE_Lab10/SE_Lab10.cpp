#include <iostream>
#include <float.h>
#include "Varparm.h"
using namespace Varparm;
using namespace std;

void main()
{
	ivarparm(0);
	ivarparm(1, 2);
	ivarparm(2, 4, 5);
	ivarparm(6, 2, 3, 4, 5, 6, 7);

	svarparm(0);
	svarparm(1, 2);
	svarparm(2, 4, 5);
	svarparm(6, 2, 3, 4, 5, 6, 7);

	fvarparm(FLT_MAX);
	fvarparm(1, FLT_MAX);
	fvarparm(2, 4, FLT_MAX);
	fvarparm(6, 2, 3, 4, 5, 6, FLT_MAX);

	dvarparm(DBL_MAX);
	dvarparm(1, DBL_MAX);
	dvarparm(2, 4, DBL_MAX);
	dvarparm(6, 2, 3, 4, 5, 6, DBL_MAX);
}