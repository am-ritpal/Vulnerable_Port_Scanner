#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <iomanip>
#include <sstream>
using namespace std;

void create_file(string name, bool vul){
    auto now = chrono::system_clock::now();
    time_t currentTime = chrono::system_clock::to_time_t(now);
    tm* localTime = std::localtime(&currentTime);
    stringstream ss;
    ss << std::put_time(localTime, "%Y-%m-%d"); // Format as YYYY-MM-DD
    std::ofstream outputFile(ss.str()+".csv");
    // Check if the file was opened successfully
    if (outputFile.is_open()) {
        outputFile<<"Port no. "<<"Vulnerable"<<endl;
        if(vul == false){
            outputFile<<name<<" False";
        }
        else{
            outputFile<<name<<" True";
        }
        cout<<"The file is created"<<endl;
    }
        outputFile.close();

}