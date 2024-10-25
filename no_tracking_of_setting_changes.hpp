#include <iostream>
#include <thread>
#include <atomic>

/*
предположена задержка настройки магнитов, 
и если в это время параметры меняются, система может не успеть 
зафиксировать изменение:
*/

std::atomic<int> radiationLevel(0);
std::atomic<bool> magnetsSet(false);

void setRadiationLevel(int level) {
    radiationLevel = level;
    magnetsSet = false; // Переустановка магнитов требуется
}

void applyMagnets() {
    std::this_thread::sleep_for(std::chrono::seconds(8));
    magnetsSet = true;
    if (!magnetsSet.load()) {
        std::cout << "Magnet settings outdated due to parameter change." << std::endl;
    }
}

int main() {
    std::thread levelThread(setRadiationLevel, 5);
    std::thread magnetsThread(applyMagnets);

    levelThread.join();
    magnetsThread.join();
    return 0;
}
