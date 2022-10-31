#ifndef CONSTANTDEFINE_H
#define CONSTANTDEFINE_H
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <mqueue.h>
#include <unistd.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <errno.h>

#define QUEUE_PERMS ((int)(0660))
#define QUEUE_MAXMSG  16 /* Maximum number of messages. */
#define MESSAGE_BUFFER_SIZE 256
// #define QUEUE_ATTR_INITIALIZER ((struct mq_attr){0, QUEUE_MAXMSG, MESSAGE_BUFFER_SIZE, 0})

#define MQ_PATH_CLIENT_USER "/MQUEUE-USER"
#define MQ_PATH_CLIENT_ADMIN "/MQUEUE-ADMIN"


#define KEY_SHM 0x01
#define SEGMENT_SIZE 0xff // 256 bytes
#define NAME_SHM "s"

#endif // CONSTANTDEFINE_H
