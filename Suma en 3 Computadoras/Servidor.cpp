#include <iostream>
#include <winsock2.h>
#include <sstream>  // Para convertir int a string

#pragma comment(lib, "ws2_32.lib")

using namespace std;

int main() {
    WSADATA wsa;
    SOCKET serverSocket, clientSocket1, clientSocket2;
    struct sockaddr_in server, client;
    int c;
    char buffer[1024];

    WSAStartup(MAKEWORD(2, 2), &wsa);

    serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(12345);

    bind(serverSocket, (struct sockaddr *)&server, sizeof(server));
    listen(serverSocket, 2);

    cout << "[SERVIDOR] Esperando conexiones..." << endl;
    c = sizeof(struct sockaddr_in);

    clientSocket1 = accept(serverSocket, (struct sockaddr *)&client, &c);
    cout << "[SERVIDOR] Cliente 1 conectado." << endl;

    clientSocket2 = accept(serverSocket, (struct sockaddr *)&client, &c);
    cout << "[SERVIDOR] Cliente 2 conectado." << endl;

    int numero;
    cout << "[SERVIDOR] Ingresa tu número: ";
    cin >> numero;

    int suma = numero + 100 + 200; // Simulación simple

    // Convertir suma a string
    stringstream ss;
    ss << suma;
    string resultado = ss.str();

    // Enviar resultado
    send(clientSocket1, resultado.c_str(), resultado.size(), 0);
    send(clientSocket2, resultado.c_str(), resultado.size(), 0);
    cout << "[SERVIDOR] Resultado enviado: " << resultado << endl;

    closesocket(clientSocket1);
    closesocket(clientSocket2);
    closesocket(serverSocket);
    WSACleanup();

    return 0;
}
