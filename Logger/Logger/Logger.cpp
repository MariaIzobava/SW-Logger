// Logger.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <cstdio>
#include <string>

std::string message_concat() {
	return "\n";
}

template <class First, typename ...Args>
std::string message_concat(First first, Args... args) {
	return first + message_concat(args);
}

template <typename TErr>
void screen_logger(TErr error, std::string result) {
	std::cout << "log_level:: " << error << ' ' << result << std::endl;
}

template<typename TErr, typename ...Args>
void log(TErr error, Args... args) {
	std::string result = message_concat(std::forward<Args>(args)...);
	screen_logger(error, result);
}



int main()
{
    
	log(45, "Ip address ", "10", "has been blocekd? port = ", "80");

	/*log(
		screen_logger
		log_level::error,
		"Ip address ",
		ip_host,
		" has been blocked, port=",
		port,
		);*/

}


