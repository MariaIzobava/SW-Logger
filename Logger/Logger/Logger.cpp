// Logger.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <cstdio>
#include <string>

std::string message_concat() {
	return "\n";
}

template <typename First, typename ...Args>
std::string message_concat(First first, Args... args) {
	return first + message_concat(std::forward<Args>(args)...);
}

template <typename TErr>
void screen_logger(TErr error, std::string result) {
	std::cout << "log_level:: " << error << ' ' << result << std::endl;
}

template<class TFunc, typename TErr, typename ...Args>
void log(TFunc (*func)(TErr, std::string), TErr error, Args... args) {
	std::string result = message_concat(std::forward<Args>(args)...);
	func(error, result);
}


int main()
{
    
	log<void, int>(screen_logger<int>, 45, "Ip address", "10", "has been blocked, port = ", "80");
	getchar();

}


