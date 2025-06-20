#include <cmath>

double daily_rate(double hourly_rate) {
    int hoursInDay = 8;
    return hourly_rate * hoursInDay;
}

double apply_discount(double before_discount, double discount) {
    return before_discount * (1 - discount / 100);
}

int monthly_rate(double hourly_rate, double discount) {
    const int workDays = 22;
    const int hoursInDay = 8;
    double monthlyWithoutDiscount = hourly_rate * workDays * hoursInDay;
    double monthlyWithDiscount = monthlyWithoutDiscount * (1 - discount / 100);

    return (int)std::ceil(monthlyWithDiscount);
}

int days_in_budget(int budget, double hourly_rate, double discount) {
    double discounted_hourly_rate = hourly_rate * (1 - discount / 100);
    double daily_rate = discounted_hourly_rate * 8;
    double days = budget / daily_rate;

    return (int)std::floor(days);
}