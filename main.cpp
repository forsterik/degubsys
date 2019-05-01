#include <utility>

#include <iostream>
#include <dirent.h>
#include <stdio.h>
#include <cstring>
#include <vector>

void info(const std::string &message);
void scanfind(const std::string &key, std::vector<std::string> inpu_t, std::vector<std::string>& retur_n);
void scandir(const std::string &folder, std::vector<std::string>& retur_n);
void scanhpp(const std::vector<std::string> &inpu_t, std::vector<std::string>& retur_n);
void scancpp(std::vector<std::string> inpu_t, std::vector<std::string>& retur_n);

int main()
{
    std::vector<std::string> names, namescpp, nameshpp;

    scandir("/home/test/encrychan/test", names);

    for (const std::string &si : names)
        info(si);

    info("#####################################################################################################: cpp");
    scancpp(names, namescpp);
    info("Количество файлов: " + std::to_string(namescpp.size()));
    for (const std::string &s : namescpp)
        info(s);

    info("#####################################################################################################: hpp");
    scanhpp(names, nameshpp);
    info("Количество файлов: " + std::to_string(nameshpp.size()));
    for (const std::string &sy : nameshpp)
        info(sy);

    return 0;
}

void scancpp(std::vector<std::string> inpu_t, std::vector<std::string>& retur_n)
{
    scanfind(".cpp", std::move(inpu_t), retur_n);
}

void scanhpp(const std::vector<std::string> &inpu_t, std::vector<std::string>& retur_n)
{
    scanfind(".hpp", inpu_t, retur_n);
    scanfind(".h", inpu_t, retur_n);
}

void scanfind(const std::string &key, std::vector<std::string> inpu_t, std::vector<std::string>& retur_n)
{
    for (auto &i : inpu_t)
        if(i.find(key) != std::string::npos)
            retur_n.emplace_back(i);
}

void scandir(const std::string &folder, std::vector<std::string>& retur_n)
{
    DIR *dfd;
    struct dirent *dp;
    char filename[NAME_MAX];

    strcpy(filename, folder.c_str());

    dfd=opendir(filename);

    if(dfd != nullptr)
        while( (dp=readdir(dfd)) != nullptr)
                retur_n.emplace_back(dp->d_name);
    closedir(dfd);
}

void info(const std::string &message)
{
    std::cout << message << std::endl;
}