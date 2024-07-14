#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

// Function to calculate the cumulative normal distribution function (CDF)
double normalCDF(double value) {
    return 0.5 * erfc(-value * M_SQRT1_2);
}

// Function to calculate d1 and d2 for the Black-Scholes formula
double d1(double S, double K, double r, double sigma, double T) {
    return (log(S / K) + (r + 0.5 * pow(sigma, 2)) * T) / (sigma * sqrt(T));
}

double d2(double S, double K, double r, double sigma, double T) {
    return d1(S, K, r, sigma, T) - sigma * sqrt(T);
}

// Function to calculate the Black-Scholes price of a call option
double callOptionPrice(double S, double K, double r, double sigma, double T) {
    double d1_val = d1(S, K, r, sigma, T);
    double d2_val = d2(S, K, r, sigma, T);
    return S * normalCDF(d1_val) - K * exp(-r * T) * normalCDF(d2_val);
}

// Function to calculate the Black-Scholes price of a put option
double putOptionPrice(double S, double K, double r, double sigma, double T) {
    double d1_val = d1(S, K, r, sigma, T);
    double d2_val = d2(S, K, r, sigma, T);
    return K * exp(-r * T) * normalCDF(-d2_val) - S * normalCDF(-d1_val);
}

int main() {
    double S;     // Underlying asset price
    double K;     // Strike price
    double r;     // Risk-free interest rate
    double sigma; // Volatility
    double T;     // Time to maturity

    // Input the values
    cout << "Enter the underlying asset price (S): ";
    cin >> S;
    cout << "Enter the strike price (K): ";
    cin >> K;
    cout << "Enter the risk-free interest rate (r): ";
    cin >> r;
    cout << "Enter the volatility (sigma): ";
    cin >> sigma;
    cout << "Enter the time to maturity (T): ";
    cin >> T;

    // Calculate call and put option prices
    double callPrice = callOptionPrice(S, K, r, sigma, T);
    double putPrice = putOptionPrice(S, K, r, sigma, T);

    // Output the results
    cout << "Call Option Price: " << callPrice << endl;
    cout << "Put Option Price: " << putPrice << endl;

    return 0;
}