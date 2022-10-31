#include "shmmanager.h"

using namespace std;

ShmManager::ShmManager()
{

}

void ShmManager::writeShm(char *content)
{
    int shareId = getShm(KEY_SHM);
    // attach the shared memory
    char *sharedMemory = nullptr;

    if ((sharedMemory = (char*)shmat(shareId, NULL, 0)) == nullptr) {
        perror("Shared memory cannot be attached");
        exit(EXIT_FAILURE);
    }

    memcpy(sharedMemory, content, strlen(content) + 1);

    // detach
    if (shmdt(sharedMemory) == -1) {
        perror("Shared memory cannot be attached");
        exit(EXIT_FAILURE);
    }
}

char* ShmManager::readShm()
{
    int shareId = getShm(KEY_SHM);
    // attach the shared memory
    char *sharedMemory = nullptr;
    char *data = nullptr;

    if ((sharedMemory = (char*)shmat(shareId, NULL, 0)) == nullptr) {
        perror("Shared memory cannot be attached");
        exit(EXIT_FAILURE);
    }

    cout << "Reading shared memory: " << sharedMemory << endl;
    if (data != nullptr) {
        delete data;
    }
    cout << "Storing data" << endl;
    data = new char(strlen(sharedMemory) + 1);
    strcpy(data, sharedMemory);
    cout << "Storing done: " << data << endl;

    // detach
    if (shmdt(sharedMemory) == -1) {
        perror("Shared memory cannot be attached");
        exit(EXIT_FAILURE);
    }
    cout << "Reading finish" << endl;
    return data;

}

void ShmManager::printShmInfo(int sharedId)
{

}

int ShmManager::getShm(char id)
{
    key_t sharedKey = ftok(NAME_SHM, id);
    cout << "Created key " << sharedKey << endl;

    // get shared memory
    int sharedId;
    if ((sharedId = shmget(sharedKey, SEGMENT_SIZE, IPC_CREAT | 0666)) == -1) {
        perror("Cannot retrive shared memory");
        exit(EXIT_FAILURE);
    }
    return sharedId;
}

void ShmManager::removeShm(int shareId)
{
    struct shmid_ds info;
    if (shmctl(shareId, IPC_RMID, NULL) == -1) {
        perror("Cannot remove shared memory");
        exit(EXIT_FAILURE);
    }
    cout << "Shared memory removed" << endl;

}
