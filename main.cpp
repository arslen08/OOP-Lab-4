#include <iostream>
#include <memory>
#include <limits>
#include "point.h"
#include "figure.h"
#include "pentagon.h"
#include "hexagon.h"
#include "octagon.h"
#include "array.h"

void showMenu() {
    std::cout << "\n=== Figure Management System ===" << std::endl;
    std::cout << "1. Add Pentagon" << std::endl;
    std::cout << "2. Add Hexagon" << std::endl;
    std::cout << "3. Add Octagon" << std::endl;
    std::cout << "4. Remove Figure" << std::endl;
    std::cout << "5. Print All Figures" << std::endl;
    std::cout << "6. Calculate Total Area" << std::endl;
    std::cout << "7. Show Array Info" << std::endl;
    std::cout << "8. Demo Functions" << std::endl;
    std::cout << "9. Exit" << std::endl;
    std::cout << "Choose option: ";
}

void addPentagon(Array<std::shared_ptr<Figure<double>>>& array) {
    double x, y, radius;
    std::cout << "Enter center coordinates (x y): ";
    std::cin >> x >> y;
    std::cout << "Enter radius: ";
    std::cin >> radius;
    
    auto pentagon = std::make_shared<Pentagon<double>>(x, y, radius);
    array.push_back(std::static_pointer_cast<Figure<double>>(pentagon));
    std::cout << "Pentagon added successfully." << std::endl;
}

void addHexagon(Array<std::shared_ptr<Figure<double>>>& array) {
    double x, y, radius;
    std::cout << "Enter center coordinates (x y): ";
    std::cin >> x >> y;
    std::cout << "Enter radius: ";
    std::cin >> radius;
    
    auto hexagon = std::make_shared<Hexagon<double>>(x, y, radius);
    array.push_back(std::static_pointer_cast<Figure<double>>(hexagon));
    std::cout << "Hexagon added successfully." << std::endl;
}

void addOctagon(Array<std::shared_ptr<Figure<double>>>& array) {
    double x, y, radius;
    std::cout << "Enter center coordinates (x y): ";
    std::cin >> x >> y;
    std::cout << "Enter radius: ";
    std::cin >> radius;
    
    auto octagon = std::make_shared<Octagon<double>>(x, y, radius);
    array.push_back(std::static_pointer_cast<Figure<double>>(octagon));
    std::cout << "Octagon added successfully." << std::endl;
}

void runDemo() {
    std::cout << "\n=== Running Demo ===" << std::endl;
    
    Array<std::shared_ptr<Figure<double>>> figureArray;
    
    auto pentagon = std::make_shared<Pentagon<double>>(0, 0, 5);
    auto hexagon = std::make_shared<Hexagon<double>>(2, 2, 4);
    auto octagon = std::make_shared<Octagon<double>>(5, 5, 3);
    
    figureArray.push_back(std::static_pointer_cast<Figure<double>>(pentagon));
    figureArray.push_back(std::static_pointer_cast<Figure<double>>(hexagon));
    figureArray.push_back(std::static_pointer_cast<Figure<double>>(octagon));
    
    std::cout << "Created array with 3 figures:" << std::endl;
    figureArray.printAll();
    std::cout << "Total area: " << figureArray.totalArea() << std::endl;
    
    Array<std::shared_ptr<Figure<double>>> figureArray2;
    auto pentagon2 = std::make_shared<Pentagon<double>>(1.5, 2.5, 3.5);
    auto hexagon2 = std::make_shared<Hexagon<double>>(0.5, 1.5, 2.5);
    
    figureArray2.push_back(std::static_pointer_cast<Figure<double>>(pentagon2));
    figureArray2.push_back(std::static_pointer_cast<Figure<double>>(hexagon2));
    
    std::cout << "\nCreated second array with 2 figures:" << std::endl;
    figureArray2.printAll();
    std::cout << "Total area: " << figureArray2.totalArea() << std::endl;
    
    std::cout << "Demo completed!" << std::endl;
}

int main() {
    Array<std::shared_ptr<Figure<double>>> array;
    int choice;
    
    std::cout << "=== Laboratory Work 04 - Variant 22 ===" << std::endl;
    std::cout << "Figures: Pentagon, Hexagon, Octagon" << std::endl;
    
    while (true) {
        showMenu();
        std::cin >> choice;
        
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number." << std::endl;
            continue;
        }
        
        try {
            switch (choice) {
                case 1:
                    addPentagon(array);
                    break;
                    
                case 2:
                    addHexagon(array);
                    break;
                    
                case 3:
                    addOctagon(array);
                    break;
                    
                case 4: {
                    if (array.getSize() == 0) {
                        std::cout << "No figures to remove." << std::endl;
                        break;
                    }
                    size_t index;
                    std::cout << "Enter index to remove (0-" << array.getSize()-1 << "): ";
                    std::cin >> index;
                    if (index < array.getSize()) {
                        array.erase(index);
                        std::cout << "Figure removed successfully." << std::endl;
                    } else {
                        std::cout << "Invalid index." << std::endl;
                    }
                    break;
                }
                
                case 5:
                    if (array.getSize() == 0) {
                        std::cout << "No figures to display." << std::endl;
                    } else {
                        array.printAll();
                    }
                    break;
                    
                case 6:
                    if (array.getSize() == 0) {
                        std::cout << "No figures to calculate area." << std::endl;
                    } else {
                        std::cout << "Total area of all figures: " << array.totalArea() << std::endl;
                    }
                    break;
                    
                case 7:
                    std::cout << "Array size: " << array.getSize() << std::endl;
                    std::cout << "Array capacity: " << array.getCapacity() << std::endl;
                    break;
                    
                case 8:
                    runDemo();
                    break;
                    
                case 9:
                    std::cout << "Goodbye!" << std::endl;
                    return 0;
                    
                default:
                    std::cout << "Invalid option. Please try again." << std::endl;
            }
        } catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    
    return 0;
}