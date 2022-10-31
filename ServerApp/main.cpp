#include <iostream>
#include "lib/constantDefine.h"
#include "clienttest.h"
#include "servermain.h"

using namespace std;

int main(int argc, char *argv[])
{
    cout << "argc: " << argc << endl;
    if (argc > 1) {
        cout << "Client testing is running" << endl;
        ClientTest client;
        client.sendMsg(argv[1]);
    } else {
        cout << "Servier is running" << endl;
        ServerMain sever;
    }
    return 0;
}
