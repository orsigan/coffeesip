#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <ctime>

#ifdef _WIN32
#include <windows.h>
void sleep_ms(int ms) { Sleep(ms); }
#else
#include <unistd.h>
void sleep_ms(int ms) { usleep(ms * 1000); }
#endif

void clearScreen() {
    std::cout << "\033[2J\033[H";
}

int main() {
    std::srand(std::time(0));

    std::vector<std::string> steam_patterns = {
        "  (    )",
        " (  )",
        " (    )",
        "  ( )",
        "   (   )",
        "        ",
        " (     )"
    };

    while (true) {
        clearScreen();

        std::string s1 = steam_patterns[rand() % steam_patterns.size()];
        std::string s2 = steam_patterns[rand() % steam_patterns.size()];
        std::string s3 = steam_patterns[rand() % steam_patterns.size()];
        std::string s4 = steam_patterns[rand() % steam_patterns.size()];
        std::string s5 = steam_patterns[rand() % steam_patterns.size()];

        std::cout << "   " << s1 << "\n";
        std::cout << "   " << s2 << "\n";
        std::cout << "   " << s3 << "\n";
        std::cout << "   " << s4 << "\n";
        std::cout << "   " << s5 << "\n";
        std::cout << "  ........\n";
        std::cout << "  |      |]\n";
        std::cout << "  \\      /\n";
        std::cout << "   \\____/\n";
        std::cout << "   Coffee?\n";

        sleep_ms(300);
    }

    return 0;
}
