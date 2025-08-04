#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fstream>
#include "files/ipaddr.h"
#include <string>
#include "files/logfile.h"

using namespace std;

//ip address and ports 
string ipaddr;
int startPort = 0;
int endPort = 0;

void getaddr(){
    int system;
    //choice to scan system 
    cout<<"Enter 1 , if you need to scan our system "<<endl;
    cout<<"Enter 2 , if you want to scan other system"<<endl; 
    cin>>system;
    if(system == 1){
        ipaddr = ipaddre();
    }
    else if(system == 2){
        cout<<"Enter the IP address you wanna to scan"<<endl;
        cin>>ipaddr;
    }
    else{
        cout<<"Invalid Input"<<endl;
    }
    //scan ports in a range 
    cout<<"Enter the start port you wanna to scan"<<endl;
    cin>>startPort;
    cout<<"Enter the end port you wanna to scan"<<endl;
    cin>>endPort;
    if(startPort && endPort == 0){
        cout<<"Invalid Input"<<endl;
    }
}


void scanPort(const std::string& ipAddress, int port) {
    fstream Port ("files/vulnerable_ports.txt");
    
    if(!Port.is_open()){
        cerr<<"Vulnerable port file not found"<<endl;
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        std::cerr << "Error creating socket." << std::endl;
        return;
    }
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(port);
    inet_pton(AF_INET, ipAddress.c_str(), &serverAddress.sin_addr);

    if (connect(sock, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == 0) {
        string line;
        string Portno=to_string(port);

        while(getline(Port, line)){
            if(line == Portno){
                create_file(Portno , false);
                break;
            }
        }
    }
    Port.close();
    close(sock);
}

int main() {
    cout<<"=========================================="<<endl;
    cout<<"Welcome to Vulnerable port scanning tool "<<endl;
    cout<<endl;
    cout<<"The list of open vulnerbale port is saved to the program directory"<<endl;
    cout<<"=========================================="<<endl;
    getaddr();

    for (int port = startPort; port <= endPort; ++port) {
        scanPort(ipaddr, port);
    }
    cout<<"=========================================="<<endl;
    cout<<"Thanks for using the tool"<<endl;

    return 0;
}