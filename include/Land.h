#ifndef LAND_H
#define LAND_H

#include <string>
#include <Plant.h>

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
