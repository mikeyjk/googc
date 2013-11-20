#include "item.h"

Item::Item(int cost)
{
	m_cost = cost;
}

int Item::getCost() const
{
	return(m_cost);
}

void Item::setCost(const int cost)
{
	m_cost = cost;
}
