#pragma once


/* Put the necessary #include statements for your solution below to expose them
 * to the entrypoint driver.
 *
 * The driver expects the following methods and functions:
 *    - Constructor for CircularRobot.
 *    - Constructor for RectangularRobot.
 *    - A function isColliding() that can take in any two Robots.
 */

#include <vector>


class Robot {
	public:
		Robot(float centerPosX, float centerPosY)
		{
			setCenter(centerPosX, centerPosY);

		}
		Robot() = default;
		~Robot() = default;
		virtual void getAttributes(float* const attr1, float* const attr2) const;

		float getCenterX() const; 	// idk if the const keywords are necessary. prolly not
		float getCenterY() const;
		bool getCircular() const;

		void setCenter(float centerPosX, float centerPosY);
		void setCircular(bool c);


	protected:
	    bool isCircular;
		float centerPosX;
		float centerPosY;

};



class CircularRobot: public Robot{
	public:
		// lalallalaa
	CircularRobot(float centerPosX, float centerPosY, float rad)
	{
		setCenter(centerPosX, centerPosY);
		setRadius(rad);
		isCircular = true;
	};
	void setRadius(float rad);
	~CircularRobot() = default;
    void getAttributes(float* const radius, float* const na) const override;

	    protected: 		// (still has same member vars as robot..)
		float rad;

};

class RectangularRobot: public Robot{
	public:
		// lallalallalalla
	RectangularRobot(float centerPosX, float centerPosY, float wid, float h)
	{
		setCenter(centerPosX, centerPosY);
		setDimensions(wid, h);
		isCircular=false;

	};
	~RectangularRobot() = default;
	void setDimensions(float width, float height);
	void  getAttributes(float* const rectWidth, float* const rectHeight) const override;
	protected:
		float wid;
		float h;
};


bool isColliding(const Robot& a, const Robot& b);
inline std::vector<float>drawRectCoords (float centerx, float centery, float wid, float h);

inline bool checkCircleRect(std::vector<float> rectCoords, float cX, float cY, float cR);
