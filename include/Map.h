#ifndef LAND_H
#define LAND_H

#include <string>
#include <Plant.h>
#include <Zombie.h>

class Land
{
	public:
		constexpr static int max_num = 10;
		const std::string getPlantName() const { return plant_ == nullptr? "Empty" : plant_->getName(); };
		bool isStand() { return sbIsHere; };
		bool standHere();
	protected:

	private:
		Plant * plant_ = nullptr;
		bool sbIsHere = false;
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

		const std::string land(int i) const {return lands_[0].getPlantName();};
		int size() { return lands_.size(); }

	protected:

	private:
		std::vector<Land> lands_;
};

#endif // MAP_H
