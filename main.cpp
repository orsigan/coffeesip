#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <thread>
#include <chrono>
#include <unistd.h>
#include <cstdlib>
#include <ctime>


using namespace std;

const string DELIMITER = "$";
const int FRAME_DELAY_MS = 200;

void clearScreen() {
    cout << "\033[2J\033[1;1H";
}

string randomizeSteam(const string& line) {
    string newLine = line;
    for (auto c : newLine) {
        if (c == '~' && rand() % 5 == 0) {
            c = ' ';
        } else if (c == ' ' && rand() % 10 == 0) {
            c = '~';
        }
    }
    return newLine;
}

void show_coffee_raw() {
    srand(time(0));

    vector<string> steam = {
        "             ",
        " ~ ~ ~~ ~  ~~ ~",
        "  ~ ~ ~ ~~ ~~  ~",
        " ~~ ~ ~~ ~~ ~ ~",
        "   ~ ~  ~ ~~  ~~",
        " ~ ~ ~~  ~ ~ ~~",
        "   ~~  ~~ ~~ ~ ~~",
        "   ~  ~~  ~~  ~"
    };

    vector<string> cup = {
        "  ;;####.|#|.|;;",
        "  |\\±±±±±±±±±±/|",
        "  |############|",
        "   \\##########/",
        "    ----------"
    };

    while (true) {
        clearScreen();

        string firstLine = steam.front();
        steam.erase(steam.begin());
        steam.push_back(randomizeSteam(firstLine));

        for (auto line : steam) {
            cout << line << endl;
        }

        for (auto line : cup) {
            cout << line << endl;
        }

        this_thread::sleep_for(chrono::milliseconds(300));
    }
}

vector<string> loadFrames(const string& filename) {
    ifstream file(filename);
    vector<string> frames;
    string row, frame;

    if (!file) {
        cerr << "Unable to open file: " << filename << endl;
        return frames;
    }

    while (getline(file, row)) {
        if (row.rfind(DELIMITER,0) == 0) {
            frames.push_back(frame);
            frame.clear();
        } else {
            frame += row + "\n";
        }
    }

    if (!frame.empty()) {
        frames.push_back(frame);
    }

    return frames;
}

void playAnimation(const vector<string>& frames) {
    for (const auto& frame : frames) {
        system("clear"); // WIndows would be system("cls")
        cout << frame << flush;
        this_thread::sleep_for(chrono::milliseconds(FRAME_DELAY_MS));
    }
}

int main() {
    string filename = "animations.txt";
    auto frames = loadFrames(filename);

    if (frames.empty()) {
        cerr << "No frames found!" << endl;
        return 1;
    }

    playAnimation(frames);
    show_coffee_raw();
    return 0;
}
