// CURL_Console.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <regex>
#include "CurlHelper.h"

char* TCharToChar(TCHAR* lpIn,char* lpOut)  
{  
	DWORD len = WideCharToMultiByte(CP_OEMCP,NULL,lpIn,-1,NULL,0,NULL,FALSE);
    WideCharToMultiByte (CP_OEMCP,NULL,lpIn,-1,lpOut,len,NULL,FALSE);
    return lpOut;  
} 

int _tmain(int argc, _TCHAR* argv[])
{
	if(argc==1)
	{
		system("PAUSE");
        return 0;
	}
	regex getPattern("get", regex_constants::icase);
	regex postPattern("post", regex_constants::icase);
	char method[5];
	TCharToChar(argv[1],method);
	CurlHelper c;
	if(regex_match(method,getPattern))
	{
		if(argc!=3)
		{
			system("PAUSE");
			return 0;
		}
		char url[2048];
		TCharToChar(argv[2],url);
		c.Get(url);
	}
	else if(regex_match(method,postPattern))
	{
		if(argc!=4)
		{
			system("PAUSE");
			return 0;
		}
		char url[2048],data[2048];
		TCharToChar(argv[2],url);
		TCharToChar(argv[3],data);
		c.Post(url,data);
	}

	system("PAUSE");
	return 0;
}

