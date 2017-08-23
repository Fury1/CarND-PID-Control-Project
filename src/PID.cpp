#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {
    // Initialize the coefficient variables (aka tao)
    Kp = 0.2;
    Ki = 0.0;
    Kd = 6.0;

    // Initialize the coefficient error variables
    p_error = 0.0;
    i_error = 0.0;
    d_error = 0.0;
}

PID::~PID() {}

void PID::Init() {
}

void PID::UpdateError(double cte) {
    // p_error holds previous cte, reuse before updating it
    d_error = cte - p_error; // differential error
    p_error = cte; // proportional error
    i_error += cte; // integral of errors
}

double PID::TotalError() {
    // Return the total error from the PID formula
    return -Kp * p_error - Kd * d_error - Ki * i_error;
}