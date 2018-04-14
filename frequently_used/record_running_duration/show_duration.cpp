
//
//									Hello World!
//------------------------------------------------------------------------------------------------
//
//						this is a cpp source file.
//
//						Lucius@LUCIUS-PC
//											--4/14/2018 13:01:21
//
//
//			Copyright (c) 2018 LuciusKyle@outlook.com. All rights reserved.
//
//------------------------------------------------------------------------------------------------
//									Goodbye World!
//


#include<iostream>
#include<boost/chrono.hpp>
#include<chrono>
#include<boost/timer/timer.hpp>

void boost_chrono_ver(void)
{
	auto start = boost::chrono::system_clock::now();


	start = boost::chrono::system_clock::now();
	//do something.
	std::cout << "time: "
		<< boost::chrono::duration_cast<boost::chrono::milliseconds>(boost::chrono::system_clock::system_clock::now() - start).count()
		<< " milliseconds"
		<< std::endl;
}

void stl_ver(void)
{
	auto start = std::chrono::system_clock::now();


	start = std::chrono::system_clock::now();
	//do something.
	std::cout << "time: "
		<< std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::system_clock::now() - start).count()
		<< " milliseconds"
		<< std::endl;
}

void boost_timer_ver()
{
	boost::timer::cpu_timer timer;

	timer.start();
	//do something.
	std::cout << "time: "
		<< timer.elapsed().wall
		<< " nanoseconds"
		<< std::endl;

}

int main(int argc, char *argv[])
{
	boost_chrono_ver();
	stl_ver();
	boost_timer_ver();
	return 0;
}
