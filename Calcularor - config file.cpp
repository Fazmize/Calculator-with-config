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
    

    //Pointer and boolean variables for getting an array from a function
    int* ptr = new int[4];
    ptr = confread();
    bool add = (ptr[0] == 1) ? true : false;
    bool sub = (ptr[1] == 1) ? true : false;
    bool mul = (ptr[2] == 1) ? true : false;
    bool div = (ptr[3] == 1) ? true : false;
    ptr = nullptr;
    delete[](ptr);

    std::cout << std::boolalpha << "|-------SETTINGS-------|";
    std::cout << std::boolalpha << "\nadd = " << add;
    std::cout << std::boolalpha << "\nsub = " << sub;
    std::cout << std::boolalpha << "\nmul = " << mul;
    std::cout << std::boolalpha << "\ndiv = " << div;
    std::cout << "\n|-------SETTINGS-------|";
   

    while (programLoop) {
        std::cout << "\n|-------Calculator-------|\n1.add\n2.sub\n3.mul\n4.div\n5.exit\n6.gen config\n|-------Calculator-------|\n>";
        std::cin >> operation;
        if (operation == "exit") {
            exit(0);
        }
        else if (operation == "gen") {
            confgen();
            system("cls");
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
                    std::cout << "Cannot divide by 0\n";
                    main();
                }
                std::cout << "[div result: " << calc.div(number1, number2) << " ]";
                break;
            }

        default:
            break;
        }

    }

}
