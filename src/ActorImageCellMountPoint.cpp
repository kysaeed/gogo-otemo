#include "ActorImageCellMountPoint.h"

ActorImageCellMountPoint::ActorImageCellMountPoint()
{
	this->id = 0;
}

ActorImageCellMountPoint::ActorImageCellMountPoint(int id, Vector offset)
{
	this->id = id;
	this->offset = offset;
}
