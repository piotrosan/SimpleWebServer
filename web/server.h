#ifndef SERVER_H
#define SERVER_H

#include <netinet/in.h>
#include <iostream>

using namespace std;
namespace server {
    class MyHTTPServer {

        private:
            int serverSocket;
            sockaddr_in serverConfiguration;
            int clientSocket;
            int MY_HTTP_SERVER_PORT = 8080;
            int MAX_CONNECTION_TO_SERVER = 20;

        public:
            MyHTTPServer() {
                serverSocket = socket( AF_INET, SOCK_STREAM, 0 );
                serverConfiguration = {
                    .sin_family = AF_INET,
                    .sin_port = htons(MY_HTTP_SERVER_PORT),
                };
                serverConfiguration.sin_addr.s_addr = htons(INADDR_ANY);
            }

        private:
            void printReceivedData(char buffer[]) {
                std::cout << "Message from client : " << buffer << std::endl;

            }

            void printExecption(exception& e) {
                std::cout << "Server said : " <<  e.what() << std::endl;
            }

            void serviceRegister() {
                int result = bind(
                    serverSocket,
                    (sockaddr*)& serverConfiguration,
                    sizeof(serverConfiguration)
                );
            }

        public:
            void startServer() {
                try {
                    serviceRegister();
                    listen(serverSocket, MAX_CONNECTION_TO_SERVER);
                }catch (std::exception& e) {
                    printExecption(e);
                }
            }
            void receiveData() {
                    clientSocket = accept(serverSocket, nullptr, nullptr);
                    char buffer[1024] = {};
                    recv(clientSocket, buffer, sizeof(buffer), 0);
                    printReceivedData(buffer);
                }
            void closeConnection() {
                shutdown(serverSocket, SHUT_RDWR);
            }
    };
} // server
#endif //SERVER_H
