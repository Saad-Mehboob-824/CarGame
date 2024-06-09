// Saad 22i-2577 _ E  --  Hassan Mohiuddin 22i-2454

#pragma once
#include <iostream>
#include <conio.h>
#include <iomanip>
#include "DataStructure.h"
#include <thread> 
#include <chrono>
#include <windows.h>
#include<fstream>
#include<string>
#include <sstream>  


using namespace std;

void setTextColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

struct Edge;

struct Node {
    char value;
    int x, y;
    Node** neighbors;


    Node(char val, int xCoord, int yCoord) : value(val), x(xCoord), y(yCoord), neighbors(nullptr) {}

    ~Node() {
        delete[] neighbors;
    }

    void addNeighbor(Node* newNeighbor) {
        int count = 0;
        while (neighbors && neighbors[count]) {
            ++count;
        }

        Node** newNeighbors = new Node * [count + 2];
        for (int i = 0; i < count; ++i) {
            newNeighbors[i] = neighbors[i];
        }
        newNeighbors[count] = newNeighbor;
        newNeighbors[count + 1] = nullptr;

        delete[] neighbors;
        neighbors = newNeighbors;
    }
};

struct Edge {
    int weight;
    Node* destination;

    Edge(int w, Node* dest) : weight(w), destination(dest) {}
};

bool findNeighbor(Node* node, int targetX, int targetY) {
    if (!node->neighbors) {
        return false;
    }

    for (int i = 0; i < 8; ++i) {
        if (node->neighbors[i] && node->neighbors[i]->x == targetX && node->neighbors[i]->y == targetY) {
            return true;
        }
    }

    return false;
}

class TrackGraph {
public:
    TrackGraph(int width, int height) : trackWidth(width), trackHeight(height), score(0) {
        initializeTrack();

    }

    void initializeTrack() {
        nodes = new Node * [trackWidth * trackHeight]; // Allocate memory for the dynamic array
        for (int i = 0; i < trackHeight; ++i) {
            for (int j = 0; j < trackWidth; ++j) {
                char value = '.';
                if (i == trackHeight - 1 && j == trackWidth - 1) {
                    value = 'S'; // Start point
                }
                else if (i == 0 && j == 0) {
                    value = 'E'; // End point
                }
                nodes[i * trackWidth + j] = new Node(value, j, i); // Assign directly to the dynamic array
            }
        }
        int reward = 10;
        for (int i = 0; i < reward; ++i) {
            int rewardX = rand() % trackWidth;
            int rewardY = rand() % trackHeight;

            Node* rewardNode = getNode(rewardX, rewardY);

            while (rewardNode->value != '.') {
                rewardX = rand() % trackWidth;
                rewardY = rand() % trackHeight;
                rewardNode = getNode(rewardX, rewardY);
            }

            rewardNode->value = '$';
        }
    }

    void setObstacles() {
        for (int i = 0; i < numObs; i++)
        {
            int obstacleX = rand() % trackWidth;
            int obstacleY = rand() % trackHeight;

            Node* obstacleNode = getNode(obstacleX, obstacleY);

            while (obstacleNode->value != '.') {
                obstacleX = rand() % trackWidth;
                obstacleY = rand() % trackHeight;
                obstacleNode = getNode(obstacleX, obstacleY);
            }
            obstacleNode->value = Obstacles.dequeue();
        }
    }

    void addObstacles(int numObstacles) {
        numObs = numObstacles;
        for (int i = 0; i < numObstacles; ++i) {
            Obstacles.enqueue((rand() % 2 == 0) ? '*' : '#');
        }
        setObstacles();
    }

    Node* getNode(int x, int y) {
        return nodes[y * trackWidth + x];
    }

    void displayTrack(int carX, int carY, char car) {
        system("cls");
        Node* check = getNode(carX, carY);
        if (check->value == '$') {
            rewards.insertAtEnd('$');
            check->value = '.';
        }



        cout << endl << endl << endl << setw(20);

        for (int i = 0; i < trackHeight; ++i) {
            for (int j = 0; j < trackWidth; ++j) {
                Node* currentNode = getNode(j, i);
                if (i == carY && j == carX) {
                    if (j == trackWidth - 1) {
                        cout << "|  ";
                        setTextColor(FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                        cout << car;
                        setTextColor(FOREGROUND_BLUE);
                        cout << "  |";
                    }
                    else
                    {
                        cout << "|  ";
                        setTextColor(FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                        cout << car;
                        setTextColor(FOREGROUND_BLUE);

                        cout << "   ";
                    }

                }
                else if (j == trackWidth - 1) {
                    cout << "|  " << currentNode->value << "  |";
                }
                else {
                    cout << "|  " << currentNode->value << "   ";
                }
            }
            if (i == trackHeight / 2 - 1)
            {
                cout << "Score: " << score;
            }
            else if (i == trackHeight / 2) {
                cout << "Rewards: ";
                rewards.display();
            }
            cout << endl << setw(20);
        }
    }

    void displayTrack2(int carX, int carY, char car) {
        system("cls");
        Node* check = getNode(carX, carY);
        if (check->value == '$') {
            rewards.insertAtEnd('$');
            check->value = '.';
        }



        cout << endl << endl << endl << setw(20);

        for (int i = 0; i < trackHeight; ++i) {
            for (int j = 0; j < trackWidth; ++j) {
                Node* currentNode = getNode(j, i);
                if (i == carY && j == carX) {
                    if (j == trackWidth - 1) {
                        cout << "|  ";
                        setTextColor(FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                        cout << car;
                        setTextColor(FOREGROUND_RED);
                        cout << "  |";
                    }
                    else
                    {
                        cout << "|  ";
                        setTextColor(FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                        cout << car;
                        setTextColor(FOREGROUND_RED);

                        cout << "   ";
                    }

                }
                else if (j == trackWidth - 1) {
                    cout << "|  " << currentNode->value << "  |";
                }
                else {
                    cout << "|  " << currentNode->value << "   ";
                }
            }
            if (i == trackHeight / 2 - 1)
            {
                cout << "Score: " << score;
            }
            else if (i == trackHeight / 2) {
                cout << "Rewards: ";
                rewards.display();
            }
            cout << endl << setw(20);
        }
    }

    void displayTrack3(int carX, int carY, char car, string name, int level) {
        system("cls");
        Node* check = getNode(carX, carY);
        if (check->value == '$') {
            rewards.insertAtEnd('$');
            check->value = '.';
        }

        cout << endl << endl << endl << setw(20);

        for (int i = 0; i < trackHeight; ++i) {
            for (int j = 0; j < trackWidth; ++j) {
                Node* currentNode = getNode(j, i);
                if (i == carY && j == carX) {
                    if (findNeighbor(currentNode, j - 1, i) && j == trackWidth - 1) {
                        cout << "<- ";
                        setTextColor(FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                        cout << car;
                        setTextColor(FOREGROUND_GREEN);
                        cout << "  |";
                    }
                    else if (findNeighbor(currentNode, j - 1, i)) {
                        cout << "<- ";
                        setTextColor(FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                        cout << car;
                        setTextColor(FOREGROUND_GREEN);
                        cout << "   ";
                    }
                    else if (j == trackWidth - 1) {
                        cout << "|  ";
                        setTextColor(FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                        cout << car;
                        setTextColor(FOREGROUND_GREEN);
                        cout << "  |";
                    }

                    else
                    {
                        cout << "|  ";
                        setTextColor(FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

                        cout << car;
                        setTextColor(FOREGROUND_GREEN);

                        cout << "   ";
                    }
                }

                else if (j == trackWidth - 1) {
                    if (findNeighbor(currentNode, j - 1, i)) {
                        cout << "<- " << currentNode->value << "  |";
                    }
                    else
                        cout << "|  " << currentNode->value << "  |";
                }
                else {
                    if (findNeighbor(currentNode, j - 1, i)) {
                        cout << "<- " << currentNode->value << "   ";
                    }
                    else
                        cout << "|  " << currentNode->value << "   ";
                }
            }
            if (i == trackHeight / 2 - 1) {
                cout << "Score: " << score;
            }
            else if (i == trackHeight / 2) {
                cout << "Rewards: ";
                rewards.display();
            }
            else if (i == trackHeight / 2 - 2) {
                cout << "Name: " << name;
            }
            else if (i == trackHeight / 2 - 3) {
                cout << "Level: " << level;
            }

            cout << endl << setw(20);
        }
    }

    void setnabours() {
        for (int j = 1; j < trackWidth; j++) {
            for (int i = 0; i < 3; ++i) {


                int neighborY = rand() % trackHeight;


                int neighborX = j;

                if (neighborX > 0 && neighborX < trackWidth) {
                    Node* neighborNode = getNode(neighborX - 1, neighborY);


                    getNode(neighborX, neighborY)->addNeighbor(neighborNode);


                }
            }
        }
    }

    void increaseScore(int amount) {
        score += amount;
    }

    int getScore() const {
        return score;
    }

    bool allowed(int carY, int carX, char c) {
        Node* currentNode = getNode(carX, carY);
        if (c == 'a' && findNeighbor(currentNode, carX - 1, carY))
            return true;
        else if (c == 'd' && findNeighbor(currentNode, carX + 1, carY))
            return true;
        else
            return false;
    }

    ~TrackGraph() {
        for (int i = 0; i < trackWidth * trackHeight; ++i) {
            delete nodes[i];
        }
        delete[] nodes;
    }

    int getTrackHeight() {
        return trackHeight;
    }

    int getTrackWidth() {
        return trackWidth;
    }

    void setScore(int s) {
        score = s;
    }



private:
    int trackWidth;
    int trackHeight;
    int score;
    int numObs;
    Queue Obstacles;
    Node** nodes;

    LinkedList rewards;
};

void writeToFile(const char* filename, TrackGraph& trackGraph, int carX, int carY, char car, string name, int level) {
    ofstream file(filename, ios::app);

    if (file.is_open()) {
        file << trackGraph.getScore() << "\n";

        for (int i = 0; i < trackGraph.getTrackHeight(); ++i) {
            for (int j = 0; j < trackGraph.getTrackWidth(); ++j) {
                Node* currentNode = trackGraph.getNode(j, i);
                file << currentNode->value;
            }
            file << "\n";
        }

        file << "Car position: (" << carX << ", " << carY << ")\n";

        file << "Car character: " << car << "\n";

        file << name << "\n";

        file << level << "\n";



        file << "\n";
        file.close();


    }
    else {
        cout << "Error: Unable to open the file for writing.\n";
    }
}

void clearFileContents(const char* filename) {
    ofstream file(filename, ios::trunc);
    if (file.is_open()) {
        file.close();
    }
    else {
        cout << "Error: Unable to open the file for clearing contents.\n";
    }
}

void readFromFile(const char* filename, TrackGraph& trackGraph, int& carX, int& carY, char& car, string& name, int& level) {
    ifstream file(filename);

    if (file.is_open()) {
        string scoreLine;
        getline(file, scoreLine);
        trackGraph.setScore(stoi(scoreLine));

        for (int i = 0; i < trackGraph.getTrackHeight(); ++i) {
            string line;
            getline(file, line);
            for (int j = 0; j < trackGraph.getTrackWidth(); ++j) {
                trackGraph.getNode(j, i)->value = line[j];
            }
        }

        string carPosLine;
        getline(file, carPosLine);
        sscanf_s(carPosLine.c_str(), "Car position: (%d, %d)", &carX, &carY);

        string carCharLine;
        getline(file, carCharLine);
        sscanf_s(carCharLine.c_str(), "Car character: %c", &car);

        getline(file, name);
        name.erase(0, name.find_first_not_of(" \t\r\n"));
        name.erase(name.find_last_not_of(" \t\r\n") + 1);

        string levelLine;
        getline(file, levelLine);
        level = stoi(levelLine);


        file.close();
        cout << "Game state loaded successfully.\n" << scoreLine;
    }
    else {
        cout << "Error: Unable to open the file for reading.\n";
    }
}

bool isMoveAllowed(TrackGraph& trackGraph, int carY, int carX, char c) {
    Node* currentNode = trackGraph.getNode(carX, carY);

    if (c == 'a' && trackGraph.allowed(carY, carX, 'a')) {
        return (currentNode->value == '.' || currentNode->value == '$' || currentNode->value == '*' || currentNode->value == '#' || currentNode->value == 'S');
    }
    else if (c == 'd' && trackGraph.allowed(carY, carX, 'd')) {
        return (currentNode->value == '.' || currentNode->value == '$' || currentNode->value == '*' || currentNode->value == '#' || currentNode->value == 'S');
    }

    return false;
}

void GamePlay1(char c, int trackWidth, int trackHeight, int numObstacles, string name) {
    TrackGraph trackGraph(trackWidth, trackHeight);

    srand(static_cast<unsigned int>(time(0)));

    trackGraph.addObstacles(numObstacles);

    int carX = trackWidth - 1;
    int carY = trackHeight - 1;
    bool check = true;



    while (check) {
        trackGraph.displayTrack(carX, carY, c);

        char userInput = _getch();

        switch (userInput) {
        case 'w':
            if (carY > 0) {
                carY--;
            }
            break;
        case 's':
            if (carY < trackHeight - 1) {
                carY++;
            }
            break;
        case 'a':
            if (carX > 0) {
                carX--;
            }
            break;
        case 'd':
            if (carX < trackWidth - 1) {
                carX++;
            }
            break;
        case 'q':
            return;
            break;
        default:
            break;
        }

        Node* currentNode = trackGraph.getNode(carX, carY);
        if (currentNode->value == '*' || currentNode->value == '#') {
            trackGraph.displayTrack(carX, carY, c);
            cout << "Game Over! You hit an obstacle." << endl;
            check = false;
        }
        else if (currentNode->value == '$') {
            trackGraph.increaseScore(100);

        }
        else {
            trackGraph.increaseScore(20);
        }

        if (carX == 0 && carY == 0) {
            trackGraph.displayTrack(carX, carY, c);
            check = false;
            system("cls");
            ofstream file("Score.txt", ios::app);

            if (file.is_open()) {
                file << name << ": " << trackGraph.getScore() << "\n";
            }
            else {
                cout << "Error: Unable to open the file for writing.\n";
            }

            cout << setw(50) << "You Won!!!" << endl;
            cout << setw(50) << "Any key - Go back to main" << endl;
            cout << setw(50) << "n - Next level" << endl;
            char Input = _getch();
            if (Input == 'n' || Input == 'N')
                GamePlay1(c, trackWidth + 1, trackHeight, numObstacles + 5, name);
        }
    }
    system("cls");
    return;
}

void moveCars(TrackGraph& trackGraph) {
    for (int i = 0; i < trackGraph.getTrackWidth(); ++i) {
        for (int j = trackGraph.getTrackHeight() - 1; j >= 0; --j) {
            Node* currentNode = trackGraph.getNode(i, j);
            if (currentNode->value == 'T' || currentNode->value == 'A') {
                int newJ = (j + 1) % trackGraph.getTrackHeight();
                trackGraph.getNode(i, newJ)->value = currentNode->value;
                currentNode->value = '.';
            }
        }
    }
}

void generateCars(TrackGraph& trackGraph, int numCars) {
    for (int i = 0; i < numCars; ++i) {
        int carX = rand() % trackGraph.getTrackWidth();
        int carY = rand() % trackGraph.getTrackHeight();

        Node* carNode = trackGraph.getNode(carX, carY);

        while (carNode->value != '.') {
            carX = rand() % trackGraph.getTrackWidth();
            carY = rand() % trackGraph.getTrackHeight();
            carNode = trackGraph.getNode(carX, carY);
        }

        carNode->value = (rand() % 2 == 0) ? 'T' : 'A';
    }
}

void GamePlay2(char c, int trackWidth, int trackHeight, int numCars, string name) {
    TrackGraph trackGraph(trackWidth, trackHeight);
    Node* EdNode = trackGraph.getNode(trackWidth - 1, trackHeight - 1);
    EdNode->value = '.';
    srand(static_cast<unsigned int>(time(0)));

    generateCars(trackGraph, numCars);

    int playerX = trackWidth - 1;
    int playerY = trackHeight - 1;
    bool check = true;

    while (check) {
        moveCars(trackGraph);
        trackGraph.displayTrack2(playerX, playerY, c);

        for (int i = 0; i < 5; ++i) {
            this_thread::sleep_for(chrono::milliseconds(100));

            if (_kbhit()) {
                char userInput = _getch();
                switch (userInput) {
                case 'w':
                    if (playerY > 0) {
                        playerY--;
                    }
                    break;
                case 's':
                    if (playerY < trackHeight - 1) {
                        playerY++;
                    }
                    break;
                case 'a':
                    if (playerX > 0) {
                        playerX--;
                    }
                    break;
                case 'd':
                    if (playerX < trackWidth - 1) {
                        playerX++;
                    }
                    break;
                case 'q':
                    return;
                }
            }
        }

        Node* currentPlayerNode = trackGraph.getNode(playerX, playerY);
        if (currentPlayerNode->value == 'T' || currentPlayerNode->value == 'A') {
            trackGraph.displayTrack(playerX, playerY, c);
            cout << "Game Over! You hit a moving car." << endl;
            check = false;
        }
        else if (currentPlayerNode->value == '$') {
            trackGraph.increaseScore(100);

        }
        else {
            trackGraph.increaseScore(20);
        }
    }
    system("cls");
    return;
}

void AUTO(TrackGraph& trackGraph, int& carX, int& carY, char c, string name, int level) {
    bool check = true, hit = false;

    while (check == true) {
        Node* currentNode = trackGraph.getNode(carX, carY);
        if (currentNode->value == 'E') {
            check = false;
            return;
        }
        else if (currentNode->value == '*' || currentNode->value == '#') {
            trackGraph.displayTrack3(carX, carY, c, name, level);
            trackGraph.increaseScore(-20);
        }
        else if (currentNode->value == '$') {
            trackGraph.increaseScore(100);
        }
        else {
            trackGraph.increaseScore(20);
        }
        trackGraph.displayTrack3(carX, carY, c, name, level);
        this_thread::sleep_for(chrono::milliseconds(200));

        if (carY == 0) {
            hit = true;
        }
        if (!findNeighbor(currentNode, carX - 1, carY)) {
            if (hit == false)
                carY--;
            else if (hit == true)
                carY++;
        }
        else if (findNeighbor(currentNode, carX - 1, carY)) {
            carX--;
            hit = false;
        }
        else if (findNeighbor(currentNode, carX + 1, carY)) {
            carX++;

        }

    }
}

void GamePlay3(char c, int trackWidth, int trackHeight, int numObstacles, string name, int level) {
    TrackGraph trackGraph(trackWidth, trackHeight);

    srand(static_cast<unsigned int>(time(0)));



    int carX = trackWidth - 1;
    int carY = trackHeight - 1;
    bool check = true;
    trackGraph.addObstacles(numObstacles);
    trackGraph.setnabours();
    while (check) {
        trackGraph.displayTrack3(carX, carY, c, name, level);
        clearFileContents("game_state.txt");
        writeToFile("game_state.txt", trackGraph, carX, carY, c, name, level);
        char userInput = _getch();

        switch (userInput) {
        case 72:
            if (carY > 0) {
                carY--;
            }
            break;
        case 80:
            if (carY < trackHeight - 1) {
                carY++;
            }
            break;
        case 75:
            if (carX > 0 && isMoveAllowed(trackGraph, carY, carX, 'a')) {
                carX--;
            }
            break;
        case 77:
            if (carX < trackWidth - 1 && isMoveAllowed(trackGraph, carY, carX, 'd')) {
                carX++;
            }
            break;
        case 'm':
            AUTO(trackGraph, carX, carY, c, name, level);
            break;
        case 'q':
            return;
            break;
        default:
            break;
        }

        Node* currentNode = trackGraph.getNode(carX, carY);
        if (currentNode->value == '*' || currentNode->value == '#') {
            trackGraph.displayTrack3(carX, carY, c, name, level);
            trackGraph.increaseScore(-30);
        }
        else if (currentNode->value == '$') {
            trackGraph.increaseScore(100);
        }
        else {
            trackGraph.increaseScore(20);
        }

        if (carX == 0 && carY == 0) {
            clearFileContents("game_state.txt");
            trackGraph.displayTrack3(carX, carY, c, name, level);
            check = false;
            ofstream file("Score.txt", ios::app);

            if (file.is_open()) {
                file << name << ": " << trackGraph.getScore() << ": " << level << "\n";
            }
            else {
                cout << "Error: Unable to open the file for writing.\n";
            }

            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n";
            cout << setw(80) << "********************************************\n";
            cout << setw(81) << "*                   You Won!!!                *" << endl;
            cout << setw(81) << "*           Any key - Go back to main         *" << endl;
            cout << setw(81) << "*                n - Next level               *" << endl;
            cout << setw(80) << "********************************************\n";
            char Input = _getch();
            if (Input == 'n' || Input == 'N')
                GamePlay3(c, trackWidth + 1, trackHeight, numObstacles + 5, name, level + 1);
        }
    }
    system("cls");
}

void GamePlay3Resume(char c, int trackWidth, int trackHeight, int numObstacles, string name, int level) {
    TrackGraph trackGraph(trackWidth, trackHeight);

    srand(static_cast<unsigned int>(time(0)));



    int carX = trackWidth - 1;
    int carY = trackHeight - 1;
    bool check = true;
    readFromFile("game_state.txt", trackGraph, carX, carY, c, name, level);
    trackGraph.setnabours();
    while (check) {
        trackGraph.displayTrack3(carX, carY, c, name, level);
        clearFileContents("game_state.txt");
        writeToFile("game_state.txt", trackGraph, carX, carY, c, name, level);
        char userInput = _getch();

        switch (userInput) {
        case 'w':
            if (carY > 0) {
                carY--;
            }
            break;
        case 's':
            if (carY < trackHeight - 1) {
                carY++;
            }
            break;
        case 'a':
            if (carX > 0 && isMoveAllowed(trackGraph, carY, carX, 'a')) {
                carX--;
            }
            break;
        case 'd':
            if (carX < trackWidth - 1 && isMoveAllowed(trackGraph, carY, carX, 'd')) {
                carX++;
            }
            break;
        case 'q':
            return;
            break;
        default:
            break;
        }

        Node* currentNode = trackGraph.getNode(carX, carY);
        if (currentNode->value == '*' || currentNode->value == '#') {
            trackGraph.displayTrack3(carX, carY, c, name, level);
            trackGraph.increaseScore(-20);
        }
        else if (currentNode->value == '$') {
            trackGraph.increaseScore(100);
        }
        else {
            trackGraph.increaseScore(20);
        }

        if (carX == 0 && carY == 0) {
            trackGraph.displayTrack3(carX, carY, c, name, level);
            clearFileContents("game_state.txt");
            check = false;
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n";
            cout << setw(80) << "********************************************\n";
            cout << setw(81) << "*                   You Won!!!                *" << endl;
            cout << setw(81) << "*           Any key - Go back to main         *" << endl;
            cout << setw(81) << "*                n - Next level               *" << endl;
            cout << setw(80) << "********************************************\n";
            char Input = _getch();
            if (Input == 'n' || Input == 'N')
                GamePlay3(c, trackWidth + 1, trackHeight, numObstacles + 5, name, level + 1);
        }
    }
    system("cls");
}

void readScoreFromFile(const char* filename) {
    ifstream file(filename);
    MaxHeap maxHeap(10);

    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            istringstream iss(line);
            User entry;

            iss >> entry.name >> entry.score;
            maxHeap.insert(entry);
        }
        file.close();
    }
    else {
        cout << "Error: Unable to open the file for reading.\n";
    }

    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

    cout << setw(75) << "Name" << setw(20) << "Score" << endl;
    cout << setw(115) << setfill('-') << "-" << setfill(' ') << endl;

    while (!maxHeap.isEmpty()) {
        User extractedUser = maxHeap.extractMax();

        cout << setw(75) << extractedUser.name << setw(20) << extractedUser.score << endl;
    }

    cout << setw(120) << "********************Press any key to return to Menu********************\n";
    char userInput = _getch();
    system("cls");
}

bool isFileEmpty(const char* filename) {
    ifstream file(filename);

    if (file.is_open()) {
        return file.peek() == ifstream::traits_type::eof();
    }
    else {
        cout << "Error: Unable to open the file for reading.\n";
        return false;
    }
}

//We tried to impliment the shortest past finding using digestras algorithm but due to some complications we couldnt impliment it fully
//We had planed to use it  along with gameplay3 function and we had planned to make it move automatically to the end
/*
void findSPath(TrackGraph& t, int startX, int startY, int endX, int endY) {
    const int trackWidth = t.getTrackWidth();
    const int trackHeight = t.getTrackHeight();

    bool visited[trackWidth][trackHeight];
    memset(visited, false, sizeof(visited));

    int distances[trackWidth][trackHeight];
    int predecessors[trackWidth][trackHeight];

    for (int i = 0; i < trackWidth; ++i) {
        for (int j = 0; j < trackHeight; ++j) {
            distances[i][j] = numeric_limits<int>::max();
            predecessors[i][j] = -1;
        }
    }

    distances[startX][startY] = 0;

    for (int count = 0; count < trackWidth * trackHeight - 1; ++count) {
        int minDist = numeric_limits<int>::max();
        int minI, minJ;

        for (int i = 0; i < trackWidth; ++i) {
            for (int j = 0; j < trackHeight; ++j) {
                if (!visited[i][j] && distances[i][j] < minDist) {
                    minDist = distances[i][j];
                    minI = i;
                    minJ = j;
                }
            }
        }

    }

    int currentX = endX;
    int currentY = endY;

    while (currentX != startX || currentY != startY) {
        int pred = predecessors[currentX][currentY];
        int predX = pred / trackHeight;
        int predY = pred % trackHeight;

        t.setCell(currentX, currentY, '*');
        currentX = predX;
        currentY = predY;
    }

    t.displayTrack3(startX, startY, '*', "", 0);
}
*/