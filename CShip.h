#pragma once

#include <string>
#include <iostream>
#include <thread>
#include <conio.h>
#include <istream>
#include "Client.h"
#include "Server.h"
#include "Serial.h"
#include "opencv.hpp"
#include "CBase4618.h"
#include "CGameObject.h"
/**
*
* @brief C++ ship object contains ship data
*
* This class has a all the characteristics of a ship
*
*
* @author Balkaran Sidhu
*
*/
class CShip:public CGameObject
{
public:
	/** @brief contains intial object stats.
*
* @param NONE.
* @return nothing to return
*/
	CShip();
	~CShip();
};

