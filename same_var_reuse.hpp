#include <iostream>
#include <thread>
#include <mutex>

/*
 одна и та же переменная currentAngle используется для анализа вводимых данных 
 и для управления положением поворотного круга. При быстром вводе и отсутствии
синхронизации возможны состояния гонки:
*/

int currentAngle = 0; // Используется как для ввода, так и для положения
std::mutex angleMutex;

void processInput(int input) {
    std::lock_guard<std::mutex> lock(angleMutex);
    currentAngle = input; // Обновление угла на основе ввода
}

void setPosition() {
    std::lock_guard<std::mutex> lock(angleMutex);
    // Логика, определяющая положение диска
    std::cout << "Setting position to angle: " << currentAngle << std::endl;
}

int main() {
    std::thread inputThread(processInput, 90); // Быстрое обновление угла
    std::thread positionThread(setPosition);   // Установка положения на основе угла

    inputThread.join();
    positionThread.join();
    return 0;
}
