// Saad 22i-2577 _ E  --  Hassan Mohiuddin 22i-2454
#include <iostream>
#include <conio.h>
#include<iomanip>
#include <windows.h>
#include"CarGame.h"
#include"DataStructure.h"

using namespace std;




int main() {
    HWND console = GetConsoleWindow();
    ShowWindow(console, SW_MAXIMIZE);
     
    
    char car = 'C';
    while (true) {
        //Continue Menue       
        if (!isFileEmpty("game_state.txt")) {
            cout << endl << endl << endl << endl << endl << endl;
            string name;
            setTextColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);
            cout << setw(130) << " #######                                   #######                                        \n";
            cout << setw(130) << "    #    #    #  #####   #####    ####        #    #    #  #####   #    #   ####   #####  \n";
            cout << setw(130) << "    #    #    #  #    #  #    #  #    #       #    #    #  #    #  #    #  #         #    \n";
            setTextColor(FOREGROUND_BLUE);
            cout << setw(130) << "    #    #    #  #    #  #####   #    #       #    ######  #    #  #    #   ####     #    \n";
            cout << setw(130) << "    #    #    #  #####   #    #  #    #       #    #    #  #####   #    #       #    #    \n";
            setTextColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);
            cout << setw(130) << "    #    #    #  #   #   #    #  #    #       #    #    #  #   #   #    #  #    #    #    \n";
            cout << setw(130) << "    #     ####   #    #  #####    ####        #    #    #  #    #   ####    ####     #    \n";

            int intensity = FOREGROUND_INTENSITY;
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hConsole, intensity | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            cout << setw(110) << "   ____                   _     _                        \n";
            cout << setw(110) << "  / ___|   ___    _ __   | |_  (_)  _ __    _   _    ___ \n";
            cout << setw(110) << " | |      / _ \\  | '_ \\  | __| | | | '_ \\  | | | |  / _ \\\n";
            cout << setw(110) << " | |___  | (_) | | | | | | |_  | | | | | | | |_| | |  __/\n";
            cout << setw(110) << "  \\____|  \\___/  |_| |_|  \\__| |_| |_| |_|  \\__,_|  \\___|\n";



            setTextColor(FOREGROUND_GREEN);
            cout << "\n";
            setTextColor(FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            cout << setw(96) << "  ____    _                 \n";
            cout << setw(96) << " |  _ \\  | |   __ _   _   _ \n";
            cout << setw(96) << " | |_) | | |  / _` | | | | |\n";
            cout << setw(96) << " |  __/  | | | (_| | | |_| |\n";
            cout << setw(96) << " |_|     |_|  \\__,_| \\ __, |\n";
            cout << setw(96) << "                      |___/\n";
            setTextColor(FOREGROUND_GREEN);
            cout << "\n";

            setTextColor(FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            cout << setw(105) << "   ____                                       \n";
            cout << setw(105) << "  / ___|   __ _   _ __    __ _    __ _    ___ \n";
            cout << setw(105) << " | |  _   / _` | | '__|  / _` |  / _` |  / _ \\\n";
            cout << setw(105) << " | |_| | | (_| | | |    | (_| | | (_| | |  __/\n";
            cout << setw(105) << "  \\____|  \\__,_| |_|     \\__,_|  \\__, |  \\___|\n";
            cout << setw(105) << "                                   |___/        \n";
            setTextColor(FOREGROUND_GREEN);
            cout << "\n";

            setTextColor(FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            cout << setw(125) << "  ____                                    ____                               _ \n";
            cout << setw(125) << " / ___|    ___    ___    _ __    ___     | __ )    ___     __ _   _ __    __| |\n";
            cout << setw(125) << " \\___ \\   / __|  / _ \\  | '__|  / _ \\    |  _ \\   / _ \\   / _` | | '__|  / _` |\n";
            cout << setw(125) << "  ___) | | (__  | (_) | | |    |  __/    | |_) | | (_) | | (_| | | |    | (_| |\n";
            cout << setw(125) << " |____/   \\___|  \\___/  |_|     \\___|    |____/   \\___/   \\__,_| |_|     \\__,_|\n";
            setTextColor(FOREGROUND_GREEN);

            cout << endl << endl;

            setTextColor(FOREGROUND_RED);
            cout << setw(96) << "  ___            _   _   \n";
            cout << setw(96) << "  / _ \\   _   _  (_) | |_ \n";
            cout << setw(96) << " | | | | | | | | | | | __|\n";
            cout << setw(96) << " | |_| | | |_| | | | | |_ \n";
            cout << setw(96) << "  \\__\\_\\  \\__,_| |_|  \\__|\n";
            setTextColor(FOREGROUND_GREEN);


            cout << "\n";




            char userInput = _getch();
            switch (userInput) {
            case '1':
            {

                GamePlay3Resume(car, 10, 20, 7, name, 1);
            }
            break;


            case '2':
            {

                system("cls");
                cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

                setTextColor(FOREGROUND_GREEN);
                cout << setw(120) << "*************************************************************************\n";
                cout << setw(120) << "*                                                                       *\n";
                cout << setw(120) << "*                                                                       *\n";
                cout << setw(120) << "*                                                                       *\n";
                cout << setw(120) << "*                                                                       *\n";
                cout << setw(120) << "*                                                                       *\n";

                cout << setw(120) << "*                1. Maze                                                *\n";
                setTextColor(FOREGROUND_BLUE);
                cout << setw(120) << "*                2. Simple Game(Reach to end point)                     *\n";
                setTextColor(FOREGROUND_RED);

                cout << setw(120) << "*                3. Traffic mode (Avoid the incomming cars)             *\n";
                cout << setw(120) << "*                                                                       *\n";
                cout << setw(120) << "*                                                                       *\n";
                cout << setw(120) << "*                                                                       *\n";
                cout << setw(120) << "*                                                                       *\n";
                cout << setw(120) << "*                                                                       *\n";
                cout << setw(120) << "*************************************************************************\n";




                char choice = _getch();
                if (choice == '1')
                {
                    setTextColor(FOREGROUND_GREEN);
                    system("cls");
                    cout << endl << endl << endl << endl << endl << endl << endl << endl << endl;
                    cout << setw(100) << "Enter your name: ";
                    cin >> name;
                    GamePlay3(car, 10, 20, 7, name, 1);
                }
                else if (choice == '2')
                {
                    setTextColor(FOREGROUND_BLUE);
                    system("cls");
                    cout << endl << endl << endl << endl << endl << endl << endl << endl << endl;
                    cout << setw(100) << "Enter your name: ";
                    cin >> name;
                    GamePlay1(car, 5, 20, 5, name);
                }
                else if (choice == '3')
                {
                    setTextColor(FOREGROUND_RED);
                    system("cls");
                    cout << endl << endl << endl << endl << endl << endl << endl << endl << endl;
                    cout << setw(100) << "Enter your name: ";
                    cin >> name;
                    GamePlay2(car, 3, 20, 7, name);
                }
            }
            break;

            case '3':
            {

                system("cls");
                cout << "\n\n\n\n\n\n\n\n\n\n\n";
                cout << setw(67) << ".....Chose any car.....\n";
                cout << setw(60) << "1. ^   \n";
                cout << setw(60) << "2. A   \n" << setw(60) << "3. M   \n" << setw(60) << "4. I   \n" << setw(60) << "5. C   \n" << setw(60) << "6. ~   \n";
                cout << setw(75) << "!!!!!!PRESS ANY KEY TO RETURN TO HOME!!!!!!\n";
                char choice = _getch();
                if (choice == '1')
                {
                    car = '^';
                }
                else if (choice == '2')
                {
                    car = 'A';
                }
                else if (choice == '3')
                {
                    car = 'M';
                }
                else if (choice == '4')
                {
                    car = 'I';
                }
                else if (choice == '5')
                {
                    car = 'C';
                }
                else if (choice == '6')
                {
                    car = '~';
                }
            }

            system("cls");
            break;

            case '4':
                system("cls");
                readScoreFromFile("Score.txt");
                break;
            case '5':
                return 0;
                break;


            default:
                system("cls");
                break;
            }
        }
        //Simple Menue       
        else {
            cout << endl << endl << endl << endl << endl << endl;
            string name;
            setTextColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);
            cout << setw(130) << " #######                                   #######                                        \n";
            cout << setw(130) << "    #    #    #  #####   #####    ####        #    #    #  #####   #    #   ####   #####  \n";
            cout << setw(130) << "    #    #    #  #    #  #    #  #    #       #    #    #  #    #  #    #  #         #    \n";
            setTextColor(FOREGROUND_BLUE);
            cout << setw(130) << "    #    #    #  #    #  #####   #    #       #    ######  #    #  #    #   ####     #    \n";
            cout << setw(130) << "    #    #    #  #####   #    #  #    #       #    #    #  #####   #    #       #    #    \n";
            setTextColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);
            cout << setw(130) << "    #    #    #  #   #   #    #  #    #       #    #    #  #   #   #    #  #    #    #    \n";
            cout << setw(130) << "    #     ####   #    #  #####    ####        #    #    #  #    #   ####    ####     #    \n";

            int intensity = FOREGROUND_INTENSITY;
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);



            setTextColor(FOREGROUND_GREEN);
            cout << "\n";
            setTextColor(FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            cout << setw(96) << "  ____    _                 \n";
            cout << setw(96) << " |  _ \\  | |   __ _   _   _ \n";
            cout << setw(96) << " | |_) | | |  / _` | | | | |\n";
            cout << setw(96) << " |  __/  | | | (_| | | |_| |\n";
            cout << setw(96) << " |_|     |_|  \\__,_| \\ __, |\n";
            cout << setw(96) << "                      |___/\n";
            setTextColor(FOREGROUND_GREEN);
            cout << "\n";

            setTextColor(FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            cout << setw(105) << "   ____                                       \n";
            cout << setw(105) << "  / ___|   __ _   _ __    __ _    __ _    ___ \n";
            cout << setw(105) << " | |  _   / _` | | '__|  / _` |  / _` |  / _ \\\n";
            cout << setw(105) << " | |_| | | (_| | | |    | (_| | | (_| | |  __/\n";
            cout << setw(105) << "  \\____|  \\__,_| |_|     \\__,_|  \\__, |  \\___|\n";
            cout << setw(105) << "                                   |___/        \n";
            setTextColor(FOREGROUND_GREEN);
            cout << "\n";

            setTextColor(FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            cout << setw(125) << "  ____                                    ____                               _ \n";
            cout << setw(125) << " / ___|    ___    ___    _ __    ___     | __ )    ___     __ _   _ __    __| |\n";
            cout << setw(125) << " \\___ \\   / __|  / _ \\  | '__|  / _ \\    |  _ \\   / _ \\   / _` | | '__|  / _` |\n";
            cout << setw(125) << "  ___) | | (__  | (_) | | |    |  __/    | |_) | | (_) | | (_| | | |    | (_| |\n";
            cout << setw(125) << " |____/   \\___|  \\___/  |_|     \\___|    |____/   \\___/   \\__,_| |_|     \\__,_|\n";
            setTextColor(FOREGROUND_GREEN);

            cout << endl << endl;

            setTextColor(FOREGROUND_RED);
            cout << setw(96) << "  ___            _   _   \n";
            cout << setw(96) << "  / _ \\   _   _  (_) | |_ \n";
            cout << setw(96) << " | | | | | | | | | | | __|\n";
            cout << setw(96) << " | |_| | | |_| | | | | |_ \n";
            cout << setw(96) << "  \\__\\_\\  \\__,_| |_|  \\__|\n";
            setTextColor(FOREGROUND_GREEN);


            cout << "\n";




            char userInput = _getch();
            switch (userInput) {


            case '1':
            {

                system("cls");
                cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
                setTextColor(FOREGROUND_GREEN);
                cout << setw(120) << "*************************************************************************\n";
                cout << setw(120) << "*                                                                       *\n";
                cout << setw(120) << "*                                                                       *\n";
                cout << setw(120) << "*                                                                       *\n";
                cout << setw(120) << "*                                                                       *\n";
                cout << setw(120) << "*                                                                       *\n";

                cout << setw(120) << "*                1. Maze                                                *\n";
                setTextColor(FOREGROUND_BLUE);
                cout << setw(120) << "*                2. Simple Game(Reach to end point)                     *\n";
                setTextColor(FOREGROUND_RED);

                cout << setw(120) << "*                3. Traffic mode (Avoid the incomming cars)             *\n";
                cout << setw(120) << "*                                                                       *\n";
                cout << setw(120) << "*                                                                       *\n";
                cout << setw(120) << "*                                                                       *\n";
                cout << setw(120) << "*                                                                       *\n";
                cout << setw(120) << "*                                                                       *\n";
                cout << setw(120) << "*************************************************************************\n";




                char choice = _getch();
                if (choice == '1')
                {
                    setTextColor(FOREGROUND_GREEN);
                    system("cls");
                    cout << endl << endl << endl << endl << endl << endl << endl << endl << endl;
                    cout << setw(100) << "Enter your name: ";
                    cin >> name;
                    GamePlay3(car, 10, 20, 7, name, 1);
                }
                else if (choice == '2')
                {
                    setTextColor(FOREGROUND_BLUE);
                    system("cls");
                    cout << endl << endl << endl << endl << endl << endl << endl << endl << endl;
                    cout << setw(100) << "Enter your name: ";
                    cin >> name;
                    GamePlay1(car, 5, 20, 5, name);
                }
                else if (choice == '3')
                {
                    setTextColor(FOREGROUND_RED);
                    system("cls");
                    cout << endl << endl << endl << endl << endl << endl << endl << endl << endl;
                    cout << setw(100) << "Enter your name: ";
                    cin >> name;
                    GamePlay2(car, 3, 20, 7, name);
                }
            }
            break;
            case '2':
            {

                system("cls");
                cout << "\n\n\n\n\n\n\n\n\n\n\n";
                cout << setw(67) << ".....Chose any car.....\n";
                cout << setw(60) << "1. ^   \n";
                cout << setw(60) << "2. A   \n" << setw(60) << "3. M   \n" << setw(60) << "4. I   \n" << setw(60) << "5. C   \n" << setw(60) << "6. ~   \n";
                cout << setw(75) << "!!!!!!PRESS ANY KEY TO RETURN TO HOME!!!!!!\n";
                char choice = _getch();
                if (choice == '1')
                {
                    car = '^';
                }
                else if (choice == '2')
                {
                    car = 'A';
                }
                else if (choice == '3')
                {
                    car = 'M';
                }
                else if (choice == '4')
                {
                    car = 'I';
                }
                else if (choice == '5')
                {
                    car = 'C';
                }
                else if (choice == '6')
                {
                    car = '~';
                }
            }

            system("cls");
            break;

            case '3':
                system("cls");
                readScoreFromFile("Score.txt");
                break;
            case '4':
                return 0;
                break;


            default:
                system("cls");
                break;
            }
        }
    }


    return 0;
}