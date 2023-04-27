/* 
Function Name: integrate(...)
- Number of Arguments: 3
- Return type: float
- Description: This function uses Simpson's rule and the trapezoidal rule to accurately integrate an array of data by omputing the 
    area under the envelope of a discrete time function
 - Arguments:
        1) data[]: An array of float numbers representing y-values of a descrete-time signal y[n]. Each element in the array contains the value 
            of the function y[n] at time index n = index * dt, where index is the index of the element in the array and dt is the length of the 
            time step used to sample the input signal. 
            
        2) data_size: An integer value representing the size of the array of data, i.e., the number of samples of the input signal. 
        
        3) dt: A foat point number representing the length of the time step used to sample the input signal, i.e, the sampling period which is 
            1 divided by the sampling rate (frequency).
*/

float integrate(float data[], int data_size, float dt)
{
	float integral = 0;

	// Simpson's rule requires at least 3 data points
	if (data_size < 3) 
  {
		return integral;
    Serial.print("Integration requires at least 3 data points");
	}

	// calculate integral using Simpson's rule
	for (int i = 0; i < data_size - 2; i += 2) 
  {
		integral += (data[i] + 4 * data[i + 1] + data[i + 2]) * dt / 3.0;
	}

	// if there are an even number of data points, use trapezoidal rule for last interval
	if (data_size % 2 == 0) 
  {
		integral += (data[data_size - 2] + data[data_size - 1]) * dt / 2.0;
	}

	return integral;
}

/* 
Function Name: get_velocity(...)
Number of Arguments: 3
Return type: float
Description: The change in velocity given an discrete set of acceleration data points
       Arguments:
        1) data[]: An array of float numbers representing y-values of a descrete-time signal y[n]. Each element in the array contains the value 
            of the function y[n] at time index n = index * dt, where index is the index of the element in the array and dt is the length of the 
            time step used to sample the input signal
        
        2) data_size: An integer value representing the size of the array of data, i.e., the number of samples of the input signal. 
        
        3) dt: A foat point number representing the length of the time step used to sample the input signal, i.e, the sampling period which is 
            1 divided by the sampling rate (frequency).
*/

float get_velocity(float data[], int data_size, float dt)
{
  float integral = integrate(data, data_size, dt);
  return integral;
}

/* 
Function Name: get_position(...)
- Number of Arguments: 3
- Return type: float
- Description: This function computes the change in position from a discrete-time acceleration signal.
- Arguments:
        1) data[]:  An array of float numbers representing y-values of a descrete-time signal y[n]. Each element in the array contains the value 
            of the function y[n] at time index n = index * dt, where index is the index of the element in the array and dt is the length of the 
            time step used to sample the input signal.
            
        2) data_size: An integer value representing the size of the array of data, i.e., the number of samples of the input signal. 
        
        3) dt: A foat point number representing the length of the time step used to sample the input signal, i.e, the sampling period which is 
            1 divided by the sampling rate (frequency).
*/

float get_position(float data[], int data_size, float dt)
{
  float integral = integrate(data, data_size, dt);
  integral = integral * dt * data_size;
  return integral;
}

