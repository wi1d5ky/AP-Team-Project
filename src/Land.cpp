#include "Land.h"

bool Land::standHere()
{
	if(sbIsHere) return false;

	sbIsHere = true;
	return true;
}
