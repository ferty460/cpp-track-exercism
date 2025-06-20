#include "vehicle_purchase.h"

namespace vehicle_purchase {

    bool needs_license(std::string kind) {
        return kind == "car" || kind == "truck";
    }

    std::string choose_vehicle(std::string option1, std::string option2) {
        std::string better_choice = option1 > option2 ? option2 : option1;
        return better_choice + " is clearly the better choice.";
    }

    double calculate_resell_price(double original_price, double age) {
        double price = 0.0;

        if (age >= 10) {
            price = original_price * 0.5;
        } else if (age >= 3) {
            price = original_price * 0.7;
        } else {
            price = original_price * 0.8;
        }

        return price;
    }

}