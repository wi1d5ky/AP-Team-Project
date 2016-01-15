#include "Map.h"
#include <iostream>
#include<assert.h>
using namespace std ;

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
        plant_ = nullptr ;
        isStood_ = false;
    }
}

void Land::recycle()
{
    this->~Land();
}

Map::Map(int landnum):landnum_(landnum)
{
	if(!(landnum > 0 && landnum <= maxLand)){
        landnum_ = maxLand ;
		throw "Number of Land should less than " + maxLand ;
	}
	for(int i = 0 ; i < landnum_ ; ++i)
	{
		lands_.push_back(Land());
	}

}


vector<Plant*> Map::getPlantList()
{
    vector<Plant*> plantlist ;

    for( int i = 0 ; i < landnum_ ; i+=1 )
    {
        if( lands_[i].getPlant() != nullptr )
            plantlist.push_back(lands_[i].getPlant()) ;
    }
    return plantlist ;
}
