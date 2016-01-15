#include "Map.h"
#include <iostream>
#include<assert.h>

bool Land::put( Plant* plant)
{
	if(isStood_) return false;

	plant_ = plant ;
	isStood_ = true;

	return true;
}

Land::~Land()
{
	if(plant_ != nullptr)
	{
        delete plant_;
        plant_ = 0 ;
        isStood_ = false;
	}
}

Map::Map(int land_num)
{
	if(!(land_num > 0 && land_num <= max_land_num))
		throw "Number of Land should less than " + max_land_num;

	for(int i = 0 ; i < land_num ; ++i)
	{
		//Land tmp;
		lands_.push_back(Land());
	}
}

