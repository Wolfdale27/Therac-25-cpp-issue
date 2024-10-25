#include <iostream>

/*
При отсутствии проверки деления на ноль аппарат может применить 
максимально возможное облучение:
*/

float calculateDose(int radiationPower, int exposureTime) {
    if (exposureTime == 0) {
        std::cerr << "Error: Division by zero in exposure time." << std::endl;
        return -1; // Сообщение об ошибке
    }
    return radiationPower / exposureTime;
}

int main() {
    int radiationPower = 100;
    int exposureTime = 0; // Ошибка: значение равно нулю

    float dose = calculateDose(radiationPower, exposureTime);
    if (dose < 0) {
        std::cerr << "Invalid dose calculation." << std::endl;
    } else {
        std::cout << "Calculated dose: " << dose << std::endl;
    }
    return 0;
}
