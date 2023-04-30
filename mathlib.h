
//Simple math class with 4 methods
class Mathlib {
public:
	double add(double num1, double num2) {
		return num1 + num2;
	}

	double sub(double num1, double num2) {
		return num1 - num2;
	}

	double mul(double num1, double num2) {
		return num1 * num2;
	}

	double div(double num1, double num2) {
		return num1 / num2;
	}

};

/// <summary>
/// Fuction for turning string operation into integer for switch
/// </summary>
/// <param name="operation"></param>
/// <returns>integer</returns>
int choice(std::string operation) {
	if (operation == "add") return 1;
	else if (operation == "sub") return 2;
	else if (operation == "mul") return 3;
	else if (operation == "div") return 4;
	else return 5;
}
