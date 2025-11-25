#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <ctime>

// شبیه‌سازی جریان داده‌
struct DataPoint {
    long long timestamp;
    double value;
};

class StreamSimulator {
public:
    std::vector<DataPoint> buffer;

    void generateData(int count = 10) {
        buffer.clear();
        std::srand(static_cast<unsigned>(std::time(nullptr)));
        for (int i = 0; i < count; ++i) {
            DataPoint d;
            d.timestamp = std::time(nullptr);
            d.value = (std::rand() % 1000) / 10.0;  // مقدار بین 0 تا 100
            buffer.push_back(d);
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    }

    void printAsJSON() {
        std::cout << "[\n";
        for (size_t i = 0; i < buffer.size(); ++i) {
            std::cout << "  {\"timestamp\": " << buffer[i].timestamp
                      << ", \"value\": " << buffer[i].value << "}";
            if (i < buffer.size() - 1) std::cout << ",";
            std::cout << "\n";
        }
        std::cout << "]\n";
    }
};

int main() {
    std::cout << "🚀 Live Data Engine Started...\n";
    StreamSimulator sim;
    sim.generateData(5);
    sim.printAsJSON();
    std::cout << "✅ Done.\n";
    return 0;
}
