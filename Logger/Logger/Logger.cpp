// Logger.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>

template <class TErr>
void screen_logger(TErr error, std::string result) {
	std::cout << "log_level:: " << error << " -" << result;
}

std::string message_concat() {
	return "\n";
}

template <typename First, typename ...Args>
std::string message_concat(First first, Args... args) {
	std::stringstream ss;
	ss << " " << first;
	return ss.str() + message_concat(std::forward<Args>(args)...);
}

template<class TErr, typename ...Args>
void log(void (*output_func)(TErr, std::string), TErr error, Args... args) {
	std::string result = message_concat(std::forward<Args>(args)...);
	output_func(error, result);
}


int main()
{

	log(screen_logger, 
					45, 
					"Ip address", 
					"10.0.0.10", 
					"has been blocked, port", 
					80);
	log(screen_logger,
		"UNKNOWN_ERROR",
		"Exit code",
		13.13);

	log(screen_logger,
		false
		);

	log(screen_logger,
		"DEAD BEAF",
		'E',
		'R',
		'R',
		'O',
		'R',
		'-',
		"1101 1110 1010 1101 1011 1110 1010 1111"
	);
	getchar();
}


