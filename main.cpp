#include <iostream>
#include <thread>
#include "menu_txt.h"
#include "server.h"

using server::MyHTTPServer;
using namespace std;

void pullToTheThread(MyHTTPServer *myServer) {
    thread t(&MyHTTPServer::startServer, myServer);
    t.join();
}


int main() {
    MyHTTPServer *myServer = new MyHTTPServer();
    bool notFinish = true;
    int expression;

    while (notFinish) {
        cout << MAIN_TXT;
        cin >> expression;

        switch(expression) {
            case 1:
                pullToTheThread(myServer);
                break;
            case 2:
                myServer->receiveData();
                break;
            case 3:
                myServer->closeConnection();
                break;
            case 4:
                notFinish = false;
                break;
            default:
                cout << "Fill value from 1 to 3";
                break;
        }
    }
    return 0;
}