#include "../include/Observer.h"

// Реализация методов класса ConsoleObserver
void ConsoleObserver::handleEvent(const std::string& event) {
    std::cout << event << std::endl;
}

// Реализация методов класса FileObserver
FileObserver::FileObserver(const std::string& filename) 
    : logFile(filename) {
    if (!logFile.is_open()) {
        throw std::runtime_error("Failed to open log file: " + filename);
    }
}

void FileObserver::handleEvent(const std::string& event) {
    if (logFile.is_open()) {
        logFile << event << std::endl;
    }
}

FileObserver::~FileObserver() {
    if (logFile.is_open()) {
        logFile.close();
    }
}