#include "stdafx.h"
#include "CAsteriodGame.h"
using namespace cv;


CAsteriodGame::CAsteriodGame()
{
	
}
CAsteriodGame::CAsteriodGame(cv::Size d,int com)
{l = ship.get_lives();
	control.init_com(com);
	_canvas=cv::Mat::zeros(d, CV_8UC3);
	high = d.height;
	wide = d.width;
}
void CAsteriodGame:: update()
{
	int y, x;
	int read1 = control.get_button();
	if (read1 == 0)
	{
		ship.set_lives(10);
		flag_reset = 1;
		cout << "RESET HAPPENED\n";
		reset();
	}
	if (ship.get_lives() <= 0)
	{
		ship.set_lives(10);
		reset();
	}
	 
	int read2 = missile_button();
	if (read2 == 0)
	{
		CMissile missile;
			pos_missile.x = pos_ship.x;
			 pos_missile.y = pos_ship.y-15;
			 
		missile.set_pos(pos_missile);
		missile_list.push_back(missile);
		flag_missile = 1;
		cout << "MISSILE SHOT\n";
		
	}
		control.get_data("G", "1", "9", y);
		control.get_data("G", "1", "15", x);
		y_pos = (high / 60)*(control.get_analog(y) - 15);
		x_pos = (wide/ 60)*(control.get_analog(x) - 15);
		 if (x_pos > wide)
			 x_pos = wide-1;
		 if (y_pos <= 0)
			 y_pos = 1;
		 if(y_pos>high)
			 y_pos = high - 1;
		 if (x_pos <= 0)
			 x_pos = 1;
		 pos_ship.x = x_pos;
		 pos_ship.y =high- y_pos;
		 ship.set_pos(pos_ship);//setting ship position with joystick
	
		 for (int i = 0; i < asteroid_list.size(); i++)
		 { 
			 asteroid_list[i].move();

			 if (asteroid_list[i].collide(ship) == TRUE)
			 {
				 asteroid_list[i].hit();
				 ship.hit();
			 }
			 for (int count = 0; count < missile_list.size(); count++)
			 {
				 missile_list[count].move();
				
				 if (missile_list[count].collide(asteroid_list[i]) == TRUE)
				 {
					 missile_list[count].hit();
					 asteroid_list[i].hit();
					 score = score + 10;
				 }
			 }
				if (asteroid_list[i].collide_wall(Size(high, wide)) == TRUE)
					asteroid_list[i].hit();
		 }

		for (int count= 0; count < missile_list.size(); count++)
		 {
			 missile_list[count].move();
			 if (missile_list[count].collide_wall(Size(high, wide)) == TRUE)
				 missile_list[count].hit();
		 }

		 for (int j = 0; j < asteroid_list.size(); j++)
		 {
			 if (asteroid_list[j].get_lives() <= 0)
			 { 
				  asteroid_list.erase(asteroid_list.begin() + j);
			 }
		 }
		 for (int j = 0; j < missile_list.size(); j++)
		 {
			 if (missile_list[j].get_lives() <= 0)
			 {
				 missile_list.erase(missile_list.begin() + j);
			 }
		 }

 }
void CAsteriodGame::draw()
{

_canvas = cv::Mat::zeros(_canvas.size(), _canvas.type());
		
		ship.draw(_canvas);		
		for (int index = 0; index < asteroid_list.size(); index++)
		{
		
			asteroid_list[index].draw(_canvas);
		
		}
		for (int i = 0; i < missile_list.size(); i++)
		{

			missile_list[i].draw(_canvas);		
		}
		putText(_canvas, "Poor Man's Asteroid", Size(10, 15), FONT_HERSHEY_PLAIN, 1, Scalar(255, 255, 255), 1, cv::LINE_AA);
		putText(_canvas, "Lives :" + to_string(ship.get_lives()), Size(225, 30), FONT_HERSHEY_PLAIN, 2, Scalar(255, 255, 255), 1, cv::LINE_AA);
		putText(_canvas, "score "+to_string(score), Size(400, 15), FONT_HERSHEY_PLAIN, 1, Scalar(255, 255, 255), 1, cv::LINE_AA);
		imshow("Image", _canvas);
	
}
int CAsteriodGame::missile_button()
{
	int lastp = 1;
	int p;

	control.get_data("G", "0", "33", p);
	
	if (p != lastp)
	{
		if (p == 0)
		{
			
		}
     return p;
	}
	
	lastp = p;
}

void CAsteriodGame::reset()
{
	
	putText(_canvas, "Poor Man's Asteroid", Size(10, 15), FONT_HERSHEY_PLAIN, 1, Scalar(255, 255, 255), 1, cv::LINE_AA);
	putText(_canvas, "Lives :" + to_string(l), Size(225, 30), FONT_HERSHEY_PLAIN, 2, Scalar(255, 255, 255), 1, cv::LINE_AA);
	_canvas = cv::Mat::zeros(_canvas.size(), _canvas.type());
	asteroid_list.clear();
	missile_list.clear();

	imshow("Image", _canvas);
	score = 0;
	Sleep(1000);
	run();
}

void CAsteriodGame::astroid_creation()
{
	
 CAsteroid asteroid;
	asteroid_list.push_back(asteroid);

}

CAsteriodGame::~CAsteriodGame()
{
	
}
