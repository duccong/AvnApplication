#ifndef SERVERMAIN_H
#define SERVERMAIN_H

#include <iostream>
#include <stdio.h>
#include <time.h>
#include <ctype.h>
#include "lib/constantDefine.h"
#include "lib/mqmanager.h"
#include "lib/shmmanager.h"
#include "lib/filemanager.h"
#include "utils/utils.h"
#include "string.h"

using namespace Server;
class ServerMain
{
public:
    ServerMain();
    void initData();
    ListProfile m_listProfile;
    std::string m_sSharedProfileList;
};

#endif // SERVERMAIN_H
