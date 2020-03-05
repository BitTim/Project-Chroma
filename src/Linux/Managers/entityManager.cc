#include "../../lib/Managers/entityManager.hh"

void Entity::addGroup(Group nGroup)
{
  groupBitSet[nGroup] = true;
  manager.addToGroup(this, nGroup);
}