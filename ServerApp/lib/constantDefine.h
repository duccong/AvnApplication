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
#include <map>
#include <list>
#include <vector>
#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>

#define QUEUE_PERMS ((int)(0660))
#define QUEUE_MAXMSG  10 /* Maximum number of messages. */
#define MESSAGE_BUFFER_SIZE 256
// #define QUEUE_ATTR_INITIALIZER ((struct mq_attr){0, QUEUE_MAXMSG, MESSAGE_BUFFER_SIZE, 0})

#define MQ_PATH_CLIENT_USER "/MQUEUE-USER"
#define MQ_PATH_CLIENT_ADMIN "/MQUEUE-ADMIN"


#define KEY_SHM 0x01
#define SEGMENT_SIZE 1024 // 256 bytes or need larger?
#define NAME_SHM "/dev/shm"


#define DATA_FILE "data.txt"
#define CEOL ";"

#define GET_PROFILE_LIST_SYNC "getProfileListSync"
#define GET_PROFILE_DETAIL_SYNC "getProfileDetailSync"

namespace Server {
    enum SKILL {
        E_SKILL_DEFAULT = 0,
        E_SKILL_CPP,
        E_SKILL_OPENGL,
        E_SKILL_ASSEMBLY,
        E_SKILL_JS,
        E_SKILL_QML
    };

    struct DetailProfile
    {
        int id;
        char name[20];
        float averange;
        std::map<SKILL, int> mapSkill;

        std::string serializeMapSkill() {
            std::string str;
            std::stringstream ss;
            // template of mapp skill {1:2,5:4}
            str.push_back('{');
            for (const auto &item : mapSkill) {
                // str.push_back();
                // str.push_back(":");
                // str.push_back(",");
                ss << item.first << ":" << item.second << ",";
            }
            std::string skills(ss.str());
            skills.pop_back();
            str += skills;
            str.push_back('}');
            return str;
        }

        void updateFromSerializeMapSkill(char *in, int size) {
            // std::string s(in,size);
            char* ptr = nullptr;
            ptr = strtok(&in[0], ",");
            int got = 0;
            while (ptr != nullptr) {
                std::cout << ptr << std::endl;
                mapSkill.insert({(SKILL)((int)ptr[0] - '0')
                                 , ((int)ptr[2] - '0')}); // TODO: need make it commonly
                ptr = strtok(NULL, ",");
            }
        }
    };

    struct ShortDetailProfile
    {
        int id;
        char name[20];
        float averange;
    };

    struct ListProfile
    {
        std::vector<DetailProfile> listProfile;

        std::vector<char> convertToShortArray() {
            std::vector<char> detail;
            int sizeList = listProfile.size();
            detail.resize(size() * sizeof(ShortDetailProfile) + 4); // 4 first byte is using for size of list
            memcpy(detail.data(), &sizeList, sizeof(int));
            for (int i = 0; i < listProfile.size(); ++i) {
                memcpy(detail.data() + 4 + sizeof(ShortDetailProfile) * i, &(listProfile[i]), sizeof(ShortDetailProfile)); // TODO: need improve
            }
            return detail;
        }

        void convertFromShortArray(const char* in) {
            for (int i = 0; i < 30; i++) {
                std::cout << (int)*(in+i) << " ";
            }
            int sizeList = 0;
            memcpy(&sizeList, in, sizeof(int));
            std::cout << "\n sizeList: " << sizeList << std::endl;

            std::vector<char> data;
            data.resize(sizeList * sizeof(ShortDetailProfile));

            ShortDetailProfile shortList[sizeList];
            memcpy(shortList, (in + 4),  sizeof(shortList));
            listProfile.resize(sizeList);
            listProfile.clear();
            for (auto item : shortList) {
                DetailProfile detailProfile;
                memcpy(&detailProfile, &item, sizeof(ShortDetailProfile));
                listProfile.push_back(detailProfile);
            }
        }

        int size() {
            return listProfile.size();
        }
    };
}

#endif // CONSTANTDEFINE_H
