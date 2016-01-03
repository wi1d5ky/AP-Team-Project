#include "Zombie.h"

void Attack(Zombie z, Plant p)
{
    p.gotHurt(z.attack());
}
