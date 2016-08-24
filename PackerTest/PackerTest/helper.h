#ifndef HELPER_DEF_H
#define HELPER_DEF_H

#include <string>
#include <sstream>
#include <stdint.h>

const std::string i32toa(int32_t nNum)
{
	std::stringstream ss;
	ss << nNum;
	return ss.str();
}

const std::string i64toa(int64_t nNum)
{
	std::stringstream ss;
	ss << nNum;
	return ss.str();
}

const std::string dtoa(double nNum)
{
	std::stringstream ss;
	ss << nNum;
	return ss.str();
}

int32_t atoi32(const std::string &strNum)
{
	std::stringstream ss(strNum);
	int32_t nNum = 0;
	ss >> nNum;

	return nNum;
}

int64_t atoi64(const std::string &strNum)
{
	std::stringstream ss(strNum);
	int64_t nNum = 0;
	ss >> nNum;

	return nNum;
}

double atod(const std::string &strNum)
{
	std::stringstream ss(strNum);
	double dNum = 0;
	ss >> dNum;

	return dNum;
}

#endif