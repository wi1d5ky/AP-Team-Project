#ifndef MAP_H
#define MAP_H

#include <string>
#include "Plant.h"
#include <vector>

class Land
{
	public:
		~Land();
		bool put( Plant* plant );
		bool getStood()const{return isStood_;}
		Plant * getPlant() { return plant_; }
		const Plant * getPlant() const { return plant_; }
        void recycle();

	private:
		Plant * plant_ = nullptr;
		bool isStood_ = false;
};


class Map
{
	public:
		// with this constructor, you could get a map with [land_num] empty land
		Map(int landnum);

		Land & operator[] (int i) { return lands_[i]; }
		const Land & operator[] (int i) const { return lands_[i]; }

		size_t size() { return landnum_; }
		bool put( Plant* plant, int position) { return lands_[position].put(plant); }
        std::vector<Plant*> getPlantList() ;

        constexpr static int maxLand = 10;

	private:
		int landnum_ ;
		std::vector<Land> lands_;
};

#endif // MAP_H
