#ifndef __ACTOR_IMAGE_CELL_DATA_H__
#define __ACTOR_IMAGE_CELL_DATA_H__

#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_filesystem.h>

#include "Rect.h"
#include "ActorImageCellMountPoint.h"

class ActorImageCellData
{
public:
	ActorImageCellData();
	inline Rect *getBoundingBox()
	{
		return &boundingBox;
	}

	inline ActorImageCellMountPoint *getMoutPoint(int id)
	{
		return mountPoints[id];
	}

	virtual ~ActorImageCellData();

	bool setMountPoint(ActorImageCellMountPoint* point);

	void read(SDL_RWops* file);

protected:
	static const int MountPointsCount = 128;
	Rect boundingBox;
	std::vector <ActorImageCellMountPoint *> mountPoints;
};


#endif
