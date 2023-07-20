#include <iostream>
#include "timer.h"
#include <algorithm>
#include <iostream>
#include <vector>
#include <random>
#include <functional>
#include <iomanip>

int main() {

	std::cout << std::setw(25) << "TIMER'S REPORT\n";
	std::vector<int> nums(10000, 3);
	math273::timer<std::chrono::milliseconds> my_timer;
	my_timer.start();
	std::sort(nums.begin(), nums.end()); //Timing Algorith once
	my_timer.stop();
	//Report
	std::cout << "Pressed start() then stop(): " << my_timer.read() << " ms" << std::endl;
	my_timer.start();
	std::sort(nums.begin(), nums.end()); //Timing Algorithm twice
	//Report
	std::cout << "Pressed start() while STOPPED: " << my_timer.read() << " ms" << std::endl; 
	
	my_timer.start();
	std::sort(nums.begin(), nums.end()); //Timing Algorithm three times
	my_timer.stop();
	//Retesting if the running time is stored after stopping the timer
	std::cout << "Pressed start() without calling stop() " << my_timer.read() << " ms" << std::endl;

	//Testing if timer is running while the timer is STOPPED ( It shouldn't)
	std::sort(nums.begin(), nums.end()); //Algorithm
	my_timer.stop();
	//Report
	std::cout << "Pressed stop() while STOPPED: " << my_timer.read() << " ms" << std::endl;
	std::sort(nums.begin(), nums.end());//Algorithm
	my_timer.stop();
	std::cout << "Pressed stop() while STOPPED again : " << my_timer.read() << " ms" << std::endl;

	my_timer.start();
	std::sort(nums.begin(), nums.end()); //Timing Agorithm four times total
	my_timer.stop();
	//Report
	std::cout << "Start() function should continue the timer where it left off after stopping the timer : "
	<< my_timer.read() << " ms" << std::endl; 

	my_timer.start(); //Starting timer to test if timer keeps RUNNING without pressing Start() nor Stop()
	std::sort(nums.begin(), nums.end());
	//read() reads while RUNNING without starting nor stopping; timer should be RUNNING
	std::cout << "While RUNNING: " << my_timer.read() << " ms" << std::endl;
	std::cout << " *TIMING SOME ALGORITHM* " << std::endl;
	std::sort(nums.begin(), nums.end()); //Fifth time timing Algorithm
	std::cout << "While the timer is still RUNNING : " << my_timer.read() << " ms" << std::endl;

	my_timer.reset(); //Resetting while RUNNING without TIMING an Algorithm
	//Testing if reset() actually resets the timer; should read 0 since no algorithm has been timed
	std::cout << "After Resetting meanwhile it's RUNNING: " << my_timer.read() << " ms" << std::endl;
	std::cout << " *TIMING SOME ALGORITHM* " << std::endl;
	//Timing Algorithm After Reset() button was pressed
	std::sort(nums.begin(), nums.end()); //Seventh time timing the Algorithm
	std::cout << "Timer should still be running after Resetting and having timed an algorithm which reads: "
		<< my_timer.read() << " ms" << std::endl;

	//Testing stop() after timer was resetted
	my_timer.stop();
	//Report
	std::cout << "Stopped timer after last step reads() : "	<< my_timer.read() << " ms" << std::endl;
	my_timer.reset();
	std::cout << "Resetting while time is STOPPED: " << my_timer.read() << " ms" << std::endl;

}