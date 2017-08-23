#ifndef PID_H
#define PID_H

#include <iostream>
#include <vector>
#include <cmath>

class PID {
public:

  /*
  * Coefficients aka tao
  */
  double Kp;
  double Ki;
  double Kd;

  /*
  * Errors
  */
  double p_error;
  double i_error;
  double d_error;

  /*
  * Constructor
  */
  PID();

  /*
  * Destructor.
  */
  virtual ~PID();

  /*
  * Initialize PID.
  */
  void Init();

  /*
  * Update the PID error variables given cross track error.
  */
  void UpdateError(double cte);

  /*
  * Calculate the total PID error.
  */
  double TotalError();
};

#endif /* PID_H */
