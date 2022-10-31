#ifndef SHMMANAGER_H
#define SHMMANAGER_H
#include "constantDefine.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief The ShmManager class
 * Shared memory do not include any lock mechanism ny it self
 * TODO: We need sync for Shm
 */
class ShmManager
{
public:
    ShmManager();
    void writeShm(char *content);
    char* readShm();
    void printShmInfo(int sharedId);

private:
    int getShm(char id);
    void removeShm(int shareId);
};

#endif // SHMMANAGER_H
