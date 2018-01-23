#include "Log.h"

CLog* CLog::instance = 0;

CLog::CLog()
{
	stream.open("Logs/Log.txt", std::ofstream::out | std::ofstream::app);
	time_t t = time(0);   // get time now
	struct tm * now = localtime(&t);
	stream << "--------------------" << (now->tm_year + 1900) << '-'
		<< (now->tm_mon + 1) << '-'
		<< now->tm_mday << "-----" << now->tm_hour << ":" << now->tm_min << ":" <<now->tm_sec << "-------------------"
		<< "\n";
}

CLog::~CLog()
{
	stream.close();
}

CLog* CLog::getInstance()
{
	if (instance == NULL)
	{
		instance = new CLog();
	}

	return instance;
}

void CLog::Write(std::string objectParent, std::string objectType, std::string objectName)
{
	stream << "Parent hierarchy : " << objectParent << "\n";
	stream << "Object type : " << objectType << "\n";
	stream << "Object name : " << objectName << "\n\n\n";
}