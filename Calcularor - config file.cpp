//Simple calculator with custom library and config file
//allowing to turn off specyfic methods

#include <iostream>
#include "mathlib.h"
#include "fconfig.h"

int main()
{
    std::string operation;
    double number1 = 0.0;
    double number2 = 0.0;
    Mathlib calc;
    bool programLoop = true;
    
    int ptr[4];
    confread(ptr);
    bool add = (ptr[0] == 1) ? true : false;
    bool sub = (ptr[1] == 1) ? true : false;
    bool mul = (ptr[2] == 1) ? true : false;
    bool div = (ptr[3] == 1) ? true : false;
    
    system("cls");
    std::cout << std::boolalpha << "|-------SETTINGS-------|";
    std::cout << std::boolalpha << "\nadd = " << add;
    std::cout << std::boolalpha << "\nsub = " << sub;
    std::cout << std::boolalpha << "\nmul = " << mul;
    std::cout << std::boolalpha << "\ndiv = " << div;
    std::cout << "\n|-------SETTINGS-------|";
   

    while (programLoop) {
        std::cout << "\n|-------Calculator-------|\n";
        std::cout << "1.add\n";
        std::cout << "2.sub\n";
        std::cout << "3.mul\n";
        std::cout << "4.div\n";
        std::cout << "5.exit\n";
        std::cout << "6.gen config\n";
        std::cout << "7.update access\n";
        std::cout << "|-------Calculator-------| \n>";
        std::cin >> operation;
        if (operation == "exit") {
            exit(0);
        }
        if (operation == "gen") {
            confgen();
            system("cls");
            main();
        }
        if (operation == "update") {
            main();
        }
        std::cin >> number1;
        std::cin >> number2;
        

        //Chosing the operation and printing the result
        system("cls");
        switch (choice(operation))
        {
        case 1:
            if (add == false) {
                std::cout << "[access denied]";
                break;
            }
            else {
                std::cout << "[add result: " << calc.add(number1, number2) << " ]";
                break;
            }

        case 2:
            if (sub == false) {
                std::cout << "[access denied]";
                break;
            }
            else {
                std::cout << "[sub result: " << calc.sub(number1, number2) << " ]";
                break;
            }

        case 3:
            if (mul == false) {
                std::cout << "[access denied]";
                break;
            }
            else {
                std::cout << "[mul result: " << calc.mul(number1, number2) << " ]";
                break;
            }

        case 4:
            if (div == false) {
                std::cout << "[access denied]";
                break;
            }
            else {
                if (number2 == 0) {
                    std::cout << "[Cannot divide by 0]";
                    break;
                }
                std::cout << "[div result: " << calc.div(number1, number2) << " ]";
                break;
            }

        default:
            std::cout << "[Not a valid operation]";
            break;
        }

    }

}
