#pragma once
#include <string>
#include <fstream>
#include <ctime>

class CLog
{
public:
	CLog();
	~CLog();

	void Write(std::string objectParent, std::string objectType, std::string objectName);
	void Write(std::string openFile);
	static CLog* getInstance();

private:
	static CLog* instance;
	std::ofstream stream;
};