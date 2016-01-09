#include "Map.h"
#include<assert.h>

bool Land::put(Plant & plant)
{
	if(isStood_)
		 return false;

	plant_ = &plant;
	isStood_ = true;
	return true;
}

Map::Map(int land_num)
{
	assert(land_num > 0 && land_num <= Land::max_num);

	for(int i = 0 ; i < land_num ; ++i)
	{
		Land tmp;
		lands_.push_back(tmp);
	}
}

bool Map::put(Plant & plant, int position)
{
	return lands_[position].put(plant);
}
