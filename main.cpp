#include <httplib.h>
#include <iostream>

int main(void)
{
    using namespace httplib;

    Server svr;

    // 获取本机ip
    #if defined(_WIN32)
    char name[255];
    gethostname(name, sizeof(name));
    struct hostent *host = gethostbyname(name);
    #elif defined(__linux__)
    char name[255];
    gethostname(name, sizeof(name));
    struct hostent *host = gethostbyname(name);
    #endif

    std::string ip = inet_ntoa(*(struct in_addr *)*host->h_addr_list);
    std::cout << "localhost ip: " << ip << std::endl;


    svr.Get("/ip", [ip](const Request &req, Response &res)
            { res.set_content(ip, "text/plain"); });

    svr.Get("/server/stop", [&](const Request& req, Response& res) {
        svr.stop();
    });
    svr.listen("localhost", 12340);
}