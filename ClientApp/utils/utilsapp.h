#ifndef UTILSAPP_H
#define UTILSAPP_H
#include "interface/serverinterface.h"
#include "iostream"

using namespace std;

class UtilsApp
{
public:
    UtilsApp();

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

#endif // UTILSAPP_H
