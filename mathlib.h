
//Simple math class with 4 methods
class Mathlib {
public:
	//Returns a sum of num1 and num2
	double add(double num1, double num2) {
		return num1 + num2;
	}

	//Returns a diffrence of num1 and num2
	double sub(double num1, double num2) {
		return num1 - num2;
	}

	//Returns product of num1 and num2
	double mul(double num1, double num2) {
		return num1 * num2;
	}

	//Returns quotient of num1 and num2
	double div(double num1, double num2) {
		return num1 / num2;
	}

};

//Function resposible for turning string operation into integer for switch
int choice(std::string operation) {
	if (operation == "add") return 1;
	else if (operation == "sub") return 2;
	else if (operation == "mul") return 3;
	else if (operation == "div") return 4;
	else return 5;
}