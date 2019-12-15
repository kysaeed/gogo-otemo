#ifndef __ANIMATION_FRAME_H__
#define __ANIMATION_FRAME_H__


class AnimationFrame
{
public:
	AnimationFrame();
	AnimationFrame(int cell, int frameCount);

	inline int getCell() const
	{
		return cell;
	}

	inline int getFrameCount() const
	{
		return frameCount;
	}

	inline int getX() const
	{
		return x;
	}

	inline int getY() const
	{
		return y;
	}

	inline void setPosition(int x, int y)
	{
		this->x = x;
		this->y = y;
	}

	inline bool isNull() const
	{
		return cell < 0;
	}

	int ec;
protected:
	int cell;
	int frameCount;
	int x;
	int y;
};


#endif
