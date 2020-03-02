#ifndef __ACTOR_IMAGE_CELL_MOUNT_POINT_H__
#define __ACTOR_IMAGE_CELL_MOUNT_POINT_H__

#include "Vector.h"

class ActorImageCellMountPoint
{
public:
	ActorImageCellMountPoint();
	ActorImageCellMountPoint(int id, Vector offset);

	inline int getId() { return id; }
	inline const Vector& getOffset() { return offset; }

protected:
	int id;
	Vector offset;

};
#endif
