#include "Map.h"
#include<assert.h>

Map::Map(int land_num)
{
	assert(land_num > 0 && land_num <= Land::max_num);

	for(int i = 0 ; i < land_num ; ++i)
	{
		Land tmp;
		lands_.push_back(tmp);
	}

}

bool Map::push(Land & land)
{
	if(lands_.size() == Land::max_num) return false;

	lands_.push_back(land);

	return true;
}
