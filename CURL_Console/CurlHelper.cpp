#include "stdafx.h"
#include "CurlHelper.h"

CurlHelper::CurlHelper(void)
{
}

CurlHelper::~CurlHelper(void)
{
}

size_t write_data( void *ptr, size_t size, size_t nmemb, void *stream)
{
	char *buf=(char*)ptr;
    cout << buf;
	ofstream out;
	out.open((char*)stream,ios_base::app);
	if(out.is_open())
	{
		int len=strlen(buf);
		buf[len]='\0';
		out.write(buf,len+1);
		out.close();
	}
    return nmemb;
}

void CurlHelper::Get(const char *url)
{
	curl_global_init(CURL_GLOBAL_ALL);
    CURL* curl = curl_easy_init();
    if (NULL == curl)
    {
		system("PAUSE");
        return;
    }
	curl_version_info_data *data=curl_version_info(CURLVERSION_NOW);
	char *c=data->ssl_version==NULL?"null":"ok";
	cout<<c<<endl;
	curl_easy_setopt(curl, CURLOPT_URL, url);
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA,"get.txt");
    CURLcode res = curl_easy_perform(curl);
	switch(res)  
        {  
			case CURLE_OK:  
                cout<<endl<<"ok"<<endl; 
				break;
            case CURLE_UNSUPPORTED_PROTOCOL:  
				cout<<endl<<"不支持的协议"<<endl; 
                break;
            case CURLE_COULDNT_CONNECT:  
				cout<<endl<<"不能连接到远程主机"<<endl; 
                break;
			case CURLE_HTTP_RETURNED_ERROR:  
				cout<<endl<<"http返回错误"<<endl; 
                break;
            case CURLE_REMOTE_ACCESS_DENIED:  
				cout<<endl<<"访问被拒绝"<<endl; 
                break;
            case CURLE_READ_ERROR: 
				cout<<endl<<"读本地文件错误"<<endl; 
                break;
            default:  
				cout<<endl<<"error:"<<res<<endl; 
        } 	 
    curl_easy_cleanup(curl);
}

void CurlHelper::Post(const char *url,const char *data)
{
	curl_global_init(CURL_GLOBAL_ALL);
	CURL *curl= curl_easy_init();
	if (curl == NULL)
    {
		system("PAUSE");
        return;
    }
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);
    curl_easy_setopt(curl, CURLOPT_URL, url);
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA,"post.txt");
    CURLcode res = curl_easy_perform(curl);
	switch(res)  
        {  
			case CURLE_OK:  
                cout<<endl<<"ok"<<endl; 
				break;
            case CURLE_UNSUPPORTED_PROTOCOL:  
				cout<<endl<<"不支持的协议"<<endl; 
                break;
            case CURLE_COULDNT_CONNECT:  
				cout<<endl<<"不能连接到远程主机"<<endl; 
                break;
			case CURLE_HTTP_RETURNED_ERROR:  
				cout<<endl<<"http返回错误"<<endl; 
                break;
            case CURLE_REMOTE_ACCESS_DENIED:  
				cout<<endl<<"访问被拒绝"<<endl; 
                break;
            case CURLE_READ_ERROR: 
				cout<<endl<<"读本地文件错误"<<endl; 
                break;
            default:  
				cout<<endl<<"error:"<<res<<endl; 
        } 
    curl_easy_cleanup(curl);
}