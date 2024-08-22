#include <iostream>
#include <string>

double calculateBMR(int weight, int height, int age, char gender) {
    double bmr;
    if (gender == 'M' || gender == 'm') {
        bmr = 10 * weight + 6.25 * height - 5 * age + 5;
    } else if (gender == 'F' || gender == 'f') {
        bmr = 10 * weight + 6.25 * height - 5 * age - 161;
    } else {
        std::cerr << "Invalid gender input." << std::endl;
        return 0;
    }
    return bmr;
}

double adjustForActivity(double bmr, int activityLevel) {
    switch (activityLevel) {
        case 1: return bmr * 1.2;
        case 2: return bmr * 1.375;
        case 3: return bmr * 1.55;
        case 4: return bmr * 1.725;
        case 5: return bmr * 1.9;
        default:
            std::cerr << "Invalid activity level input." << std::endl;
            return 0;
    }
}

double calculateCalories(double tdee, const std::string& goal) {
    if (goal == "cutting") {
        return tdee - 500;
    } else if (goal == "bulking") {
        return tdee + 500;
    } else if (goal == "recomposition") {
        return tdee;
    } else {
        std::cerr << "Invalid goal input." << std::endl;
        return 0;
    }
}

int main() {
    int weight, height, age, activityLevel;
    char gender;
    std::string goal;

    std::cout << "Enter your weight (kg): ";
    std::cin >> weight;
    std::cout << "Enter your height (cm): ";
    std::cin >> height;
    std::cout << "Enter your age (years): ";
    std::cin >> age;
    std::cout << "Enter your gender (M/F): ";
    std::cin >> gender;
    std::cout << "Enter your activity level (1-5): ";
    std::cin >> activityLevel;
    std::cout << "Enter your goal (cutting/bulking/recomposition): ";
    std::cin.ignore();
    std::getline(std::cin, goal);

    double bmr = calculateBMR(weight, height, age, gender);
    if (bmr == 0) return 1;
    double tdee = adjustForActivity(bmr, activityLevel);
    if (tdee == 0) return 1;
    double caloriesNeeded = calculateCalories(tdee, goal);
    if (caloriesNeeded == 0) return 1;

    std::cout << "Your estimated daily caloric needs: " << caloriesNeeded << " calories." << std::endl;

    return 0;
}
