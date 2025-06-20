const double interest_rate_0 = 3.213;
const double interest_rate_1 = 0.5;
const double interest_rate_2 = 1.621;
const double interest_rate_3 = 2.475;

double interest_rate(double balance) {
    if (balance < 0) {
        return interest_rate_0;
    }
    if (balance >= 0 && balance < 1000) {
        return interest_rate_1;
    }
    if (balance >= 1000 && balance < 5000) {
        return interest_rate_2;
    }

    return interest_rate_3;
}

double yearly_interest(double balance) {
    return balance * interest_rate(balance) / 100;
}

double annual_balance_update(double balance) {
    return balance + yearly_interest(balance);
}

int years_until_desired_balance(double balance, double target_balance) {
    int year;
    
    for (year = 0; balance < target_balance; year++) {
        balance += yearly_interest(balance);
    }
    
    return year;
}