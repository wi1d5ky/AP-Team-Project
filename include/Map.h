#ifndef MAP_H
#define MAP_H

#include <vector>
#include "Land.h"

class Map
{
	public:
		// with this constructor, you could get a map with [land_num] empty land
		Map(int land_num);

		bool push(Land & land);
		const Land * list() const {return &lands_[0];};
		int size() { return lands_.size(); }

	protected:

	private:
		std::vector<Land> lands_;
};

#endif // MAP_H
