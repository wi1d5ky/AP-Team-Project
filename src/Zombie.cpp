#include "Zombie.h"

Zombie::Zombie(int pos)
{
	pos_ = pos;

}

void Attack(Zombie z, Plant p)
{
    p.gotHurt(z.attack());
}
