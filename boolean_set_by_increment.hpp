#include <iostream>

/*
Использование инкремента для установки булевой переменной приводит к тому, 
что при переполнении значение может стать ложным:
*/


uint8_t isPositionSet = 0;

void setPosition() {
    isPositionSet += 1; // Ошибка: не гарантирует истину, значение может обнулиться при переполнении
}

int main() {
    for (int i = 0; i < 256; ++i) {
        setPosition();
        if (isPositionSet == 0) {
            std::cout << "Position not set due to overflow." << std::endl;
            break;
        }
    }
    return 0;
}
