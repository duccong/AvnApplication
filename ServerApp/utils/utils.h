#ifndef UTILS_H
#define UTILS_H
#include "lib/constantDefine.h"
#include "iostream"
#include "stdio.h"
#include "cstring"
#include "sstream"

using namespace std;

class Utils
{
public:
    Utils();
    static Server::DetailProfile strDataToProfile(std::string &in) {
        int size = in.size();
        cout << "Converting with input(" << size << "): " << in << endl;
        Server::DetailProfile profile;
        if (size == 0) {
            return profile;
        }
        char* ptr = nullptr;
        ptr = strtok(&in[0], "-");
        int got = 0;
        while (ptr != nullptr) {
            cout << ptr << endl;
            if (got == 0) {
                // Id
                got++;
                profile.id = charToInt(ptr);
            } else if (got == 1) {
                // name
                got++;
                strcpy(profile.name,ptr);
            } else if (got == 2){
                // list skill
                got++;
                // remove {}

                char *ptrSkill = nullptr;
                char skill[2];
                ptrSkill = strtok(ptr, ",");
                int i = 5;
                float point = 0;
                while (i-- > 0 && ptrSkill != nullptr) {
                    // cout << ptrSkill << endl;
                    int tmpPoint = (int)(ptrSkill[2]) - 48;
                    point += tmpPoint;
                    profile.mapSkill.insert({(Server::SKILL)((int)ptrSkill[0] - 48) // SkillId
                                             , tmpPoint}); // TODO: need make it commonly
                    ptrSkill = strtok(NULL, ",");
                }
                profile.averange = point/(profile.mapSkill.size());
            }
            ptr = strtok(NULL, "-");
        }
        printfProfile(profile);
        return profile;
    }

    static int charToInt(char *c) {
        int i = 0;
        sscanf(c, "%d", &i);
        return i;
    }

    static void printfProfile(const Server::DetailProfile &profile) {
        cout << " =================== \n Id: " << profile.id
             << " - " << "name: " << profile.name
             << " - Averange: " << profile.averange << endl;
        for (const auto& item : profile.mapSkill) {
            cout << "SkillID: " << item.first << "  - Point:  " << item.second << endl;
        }
        cout << " ==================="<< endl;
    }
};

#endif // UTILS_H
