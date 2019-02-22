#pragma once
#include <string>
#include <iostream>
#include <thread>
#include <conio.h>
#include <istream>
#include "Client.h"
#include "Server.h"
#include "Serial.h"
#include "CControl.h"
#include "opencv.hpp"

using namespace cv;
/**
*
* @brief C++ object used to hold common code used in each object of the game
*
* This class has a all the characteristics on all objects
* for example lives, size and position  velocity.
*
*
* @author Balkaran Sidhu
*
*/
class CGameObject
{

	protected:
		Point2f _position;///< position of Object
		Point2f _velocity;///< velocity of Object
		int _radius;///< radius of Object
		int _lives;///< lives of Object
		double last;///< previous time before move
		int BLUE;///< blue color of object
		int GREEN;///< green color of Object
		int RED;///< red color of Object
	public:
		CGameObject();
		~CGameObject();
		/** @brief Moves the objects.
   *
   * @param NONE.
   * @return nothing to return
*/
		void move();
		/** @brief detects collision between objects.
   *
   * @param a game object for example asteroid.
   * @return True or False
*/
		bool collide(CGameObject &obj);
		/** @brief detects collision with wall.
   *
   * @param dimentions of the board.
   * @return True or false
*/
		bool collide_wall(Size board);
		/** @brief reduces lives by one after hit.
   *
   * @param NONE.
   * @return nothing to return
*/
		void hit();
		/** @brief Gives the lives of the object.
   *
   * @param NONE.
   * @return lives
*/
		int get_lives() { return _lives; }
		/** @brief sets the lives of the object.
   *
   * @param int lives.
   * @return nothing to return
*/
		void set_lives(int lives) { _lives = lives; }
		/** @brief Sets the position of the object.
   *
   * @param point position.
   * @return nothing to return
*/
		void set_pos(Point2f pos) { _position = pos; }
		/** @brief gets the position of the object.
   *
   * @param NONE.
   * @return returns position of object
*/
		Point2f get_pos() { return _position; }
		/** @brief Draws circle .
   *
   * @param CV mat object canvas.
   * @return nothing to return
*/
		void draw(Mat &im);

		
};

