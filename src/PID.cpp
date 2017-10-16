#include "PID.h"

#include <iostream>
#include <math.h>
#include "json.hpp"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
	
	this->Kp = Kp;
	this->Ki = Ki;
	this->Kd = Kd;
	
	p_error = 0;
	i_error = 0;
	d_error = 0;

	old_cte = 0;
	step_ = 0;
	mse = 0;
	
	//square_err = 0;
	best_error = 100000000;
	//ind = 1;
	//last_t = clock();
}

void PID::UpdateError(double cte) {
	
	/*
	t = clock();
	dt = (t - last_t) / CLOCKS_PER_SEC;
	if (dt < 0.0001) { dt = 0.0001; }

	last_t = t;
	*/

	if (step_ == 0) { p_error = cte; }

	d_error = (cte - p_error);// /dt;
	i_error += cte;
	p_error = cte;

	step_ += 1;

	/*
	mse += pow(cte, 2);
	
	cout << "mse  -  " << mse << endl << "best_error  -  " << best_error << endl << endl;

	if (mse < best_error) {
		if (mse < 1) { best_error = pow(mse, 2); } 
	
		//if (ind == 1) { Kd *= 1.1; }
		//if (ind == 2) { Kp *= 1.1; }
		//if (ind == 3) { Ki *= 1.1; }


		if (cte > old_cte) {
			if (ind == 3) { Kd *= 1.1; }
			if (ind == 1) { Kp *= 1.1; }
			if (ind == 2) { Ki *= 1.1; }
		}
		else {
			//if ((Kp + Ki + Kd) / 3 > 0.001) {
			if (ind == 3) { Kd *= 0.9; }
			if (ind == 1) { Kp *= 0.9; }
			if (ind == 2) { Ki *= 0.9; }
			//}

		}
		ind++;
		
		
		
	}
	

	//ind++;
	if (ind > 3) { ind = 1; }
	


	if (step_ == 1000) {
		step_ = 1;
		i_error = 0;
		mse = 0;
	}
	old_cte = cte;
	*/
}

double PID::TotalError() {
	return -Kp * p_error - Ki * i_error - Kd * d_error;
}

