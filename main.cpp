#include <utility>

#include <iostream>
#include <dirent.h>
#include <stdio.h>
#include <cstring>
#include <vector>
#include <list>
#include <algorithm>
#include <set>
#include <map>

void scanclon(std::vector<std::string>& retur_n);
void scanone(const std::string &folder, std::vector<std::string>& namecpp, std::vector<std::string>& namehpp);
void info(const std::string &message);
void scanfander(std::vector<std::string> inpu_t, std::vector<std::string>& retur_n);
void scanfind(const std::string &key, std::vector<std::string> inpu_t, std::vector<std::string>& retur_n, const std::string &folder);
void scandir(const std::string &folder, std::vector<std::string>& retur_n);
void scanhpp(const std::vector<std::string> &inpu_t, std::vector<std::string>& retur_n, const std::string &folder);
void scancpp(std::vector<std::string> inpu_t, std::vector<std::string>& retur_n, const std::string &folder);

int main()
{
    std::vector<std::string> names, namescpp, nameshpp, fander;
    std::string folder = std::string("/home/") + std::getenv("USER") + "";

    scanone(folder, namescpp, nameshpp);
    scanclon(namescpp);
    scanclon(nameshpp);

    info("#####################################################################################################: cpp");
    info("Количество файлов: " + std::to_string(namescpp.size()) + "\n");
    for (const std::string &s : namescpp)
        info(s);

    info("#####################################################################################################: hpp");
    info("Количество файлов: " + std::to_string(nameshpp.size()) + "\n");
    for (const std::string &sy : nameshpp)
        info(sy);

    return 0;
}

void scanclon(std::vector<std::string>& retur_n)
{/*
    sort(retur_n.begin(), retur_n.end());

    std::set<std::string> uvec(retur_n.begin(), retur_n.end());

    std::list<std::string> output;

    set_difference(retur_n.begin(), retur_n.end(),
                   uvec.begin(), uvec.end(),
                   back_inserter(output));*/

}

void scanone(const std::string &folder, std::vector<std::string>& namecpp, std::vector<std::string>& namehpp)
{
    std::vector<std::string> names, fander;
    scandir(folder, names);
    scancpp(names, namecpp, folder);
    scanhpp(names, namehpp, folder);
    scanfander(names, fander);

    for (const std::string &si : fander)
        scanone(folder + "/" + si, namecpp, namehpp);
}

void scanfander(std::vector<std::string> inpu_t, std::vector<std::string>& retur_n)
{
    for (auto &i : inpu_t)
        if(i.find('.') == std::string::npos)
            retur_n.emplace_back(i);
}

void scancpp(std::vector<std::string> inpu_t, std::vector<std::string>& retur_n, const std::string &folder)
{
    scanfind(".cpp", std::move(inpu_t), retur_n, folder);
}

void scanhpp(const std::vector<std::string> &inpu_t, std::vector<std::string>& retur_n, const std::string &folder)
{
    scanfind(".hpp", inpu_t, retur_n, folder);
  //  scanfind(".h", inpu_t, retur_n, folder);
}

void scanfind(const std::string &key, std::vector<std::string> inpu_t, std::vector<std::string>& retur_n, const std::string &folder)
{
    for (auto &i : inpu_t)
        if(i.find(key) != std::string::npos)
            retur_n.emplace_back(folder + "/" + i);
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