#include "Path.h"

Path::Path(Direction direction): direction(direction)
{
	this->scene = nullptr;
}

Path::~Path() = default;

void Path::setScene(Scene* scene)
{
	this->scene = scene;
}
