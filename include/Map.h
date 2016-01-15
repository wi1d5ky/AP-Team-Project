#ifndef LAND_H
#define LAND_H

#include <string>
#include "Plant.h"

class Land
{
	public:
		//~Land();
		bool put( Plant* plant);
		bool getStood()const{return isStood_;}
		Plant * getPlant() { return plant_; }
		const Plant * getPlant() const { return plant_; }

	private:
		Plant * plant_ = nullptr;
		bool isStood_ = false;
};

#endif // LAND_H

#ifndef MAP_H
#define MAP_H

#include <vector>

class Map
{
	public:
		// with this constructor, you could get a map with [land_num] empty land
		Map(int land_num);

		Land operator[] (int i) { return lands_[i]; }
		const Land operator[] (int i) const { return lands_[i]; }

		size_t size() { return lands_.size(); }
		bool put( Plant* plant, int position) { return lands_[position].put(plant); }

	private:
		constexpr static int max_land_num = 10;
		std::vector<Land> lands_;
};

#endif // MAP_H
