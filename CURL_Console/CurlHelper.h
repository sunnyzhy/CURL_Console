#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#include "include\\curl\\curl.h"
#pragma comment(lib,"lib\\libcurl.lib")

class CurlHelper
{
public:
	CurlHelper(void);
	void Get(const char *url);
	void Post(const char *url,const char *data);
	~CurlHelper(void);
};

