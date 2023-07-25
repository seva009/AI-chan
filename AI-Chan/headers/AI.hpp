#include "IOFunc.hpp"
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <vector>
#include <random>

#ifndef AI_H
#define AI_H
constexpr int OneStr = 5;

enum Status {
    FuncExecutedNormal,
    FileIsTooShort,
    IncorrectNumOfString,
    CantOpenFile
};

// AI confs __Start__
constexpr double WeightsRangeMin = 0.001;
constexpr double WeightsRangeMax = 25.0;
constexpr int InputNeurons = 1600;
constexpr int HiddenNeuronLayers = 35;
constexpr int OutputNeurons = 2000;
constexpr int LayerHidden = 500;
constexpr int AllCountWeights = (InputNeurons * LayerHidden) + 8250000 + (LayerHidden * OutputNeurons);
// AI confs __End__

using namespace std;

class AIuse
{
public:
    bool isFileExist()
    {
        std::ifstream file("weights.txt");
        return file.good();
    }

    double RndWeightGen()
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<double> dis(WeightsRangeMin, WeightsRangeMax);
        return dis(gen);
    }

    void InitRandomWeights(int nof)
    {
        std::ofstream file("weights.txt");

        int count = (nof > AllCountWeights) ? AllCountWeights : nof;

        for (int i = 0; i < count; i++) {
            double Rand = (rand() / (double) RAND_MAX) * (25.0 - 0.005) + 0.005;

            file << Rand << std::endl;
        }
    }

    Status CheckFile(int Line, bool GW, double currentW) // true - get, false - write
    {
        std::fstream file("weights.txt", std::ios::in | std::ios::out);

        if (!file.is_open()) {
            return CantOpenFile;
        }

        if (GW) {
            std::string line;
            // считываем строки из файла, пока не достигнем нужной
            for (int i = 1; i < Line; ++i) {
                if (!std::getline(file, line)) {
                    return FileIsTooShort;
                }
            }
            // считываем нужную строку
            if (std::getline(file, line)) {
                std::cout << line << std::endl;
            } else {
                return FileIsTooShort;
            }
            file.close();
            return FuncExecutedNormal;
        }

        std::vector<std::string> lines;
        std::string line;

        while (std::getline(file, line)) {
            lines.push_back(line);
        }

        file.clear();
        file.seekp(0);

        std::string newLine = std::to_string(currentW); // новая строка

        if (Line < 1 || Line > lines.size()) {
            return IncorrectNumOfString;
        }

        lines[Line - 1] = newLine;

        for (const auto &l : lines) {
            file << l << std::endl;
        }

        file.close();

        return FuncExecutedNormal;
    }

    void CreateFile()
    {
        if (!isFileExist()) {
            std::ofstream file("weights.txt");

            if (file.is_open()) {
                file << "14.88\n";
                file.close();
                std::cout << "File created successfully.\n";
            }
        }
    }
    void CreateLine(int NumberOfCreatedLines)
    {
        std::ofstream file("weights.txt");
        if (file) {
            for (int i = 0; i < NumberOfCreatedLines; i++) {
                file << '\n';
            }
        }
    }
};
#endif // AI_H
