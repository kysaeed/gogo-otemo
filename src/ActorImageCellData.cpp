#include "ActorImageCellData.h"

ActorImageCellData::ActorImageCellData()
{
	mountPoints.resize(MountPointsCount);
	std::fill(mountPoints.begin(), mountPoints.end(), nullptr);
}

ActorImageCellData::~ActorImageCellData()
{
	for (std::vector <ActorImageCellMountPoint *>::iterator it = mountPoints.begin(); it != mountPoints.end(); it++) {
		delete (*it);
	}
}

bool ActorImageCellData::setMountPoint(ActorImageCellMountPoint* point)
{
	if (point->getId() >= mountPoints.size()) {
		return false;
	}

	std::cout << "id:" << point->getId() << " (" << point->getOffset().getX() << ", " << point->getOffset().getY() <<
		")" << std::endl;

	mountPoints[point->getId()] = point;
	return true;
}

void ActorImageCellData::read(SDL_RWops* file)
{
	int32_t r[4];
	SDL_RWread(file, r, sizeof(int32_t), 4);
	boundingBox = Rect(r[0], r[1], r[2], r[3]);

	int32_t pointCount = 0;
	SDL_RWread(file, &pointCount, sizeof(int32_t), 1);

	for (int i = 0; i < pointCount; i++) {
		int32_t id;
		SDL_RWread(file, &id, sizeof(int32_t), 1);

		int32_t p[2];
		SDL_RWread(file, p, sizeof(int32_t), 2);

		ActorImageCellMountPoint* mountPoint = new ActorImageCellMountPoint(id, Vector(p[0], p[1]));
		setMountPoint(mountPoint);
	}
}
