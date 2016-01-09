#include "Map.h"
#include<assert.h>


void Land::put(Plant & plant)
{
	plant_ = &plant;
	isStood_ = true;
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
	if(lands_[position].isStood())
		return false;

	lands_[position].put(plant);
	return true;
}
