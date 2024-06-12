#pragma once
#include "Component.h"

class Box;


class EnemySpawner :
    public Component
{
public:
	EnemySpawner(std::shared_ptr<Actor> owner);

	// game functions
	virtual void InitializeComponent();
	virtual void TickComponent(float deltaSeconds);
	std::list<std::shared_ptr<Box>> ObstacleList;

	bool canSpawn = true;
};

