#include "Path.h"

Path::Path(eDirection direction): direction(direction)
{
	this->scene = nullptr;
}


void Path::setScene(Scene* scene)
{
	this->scene = scene;
}
