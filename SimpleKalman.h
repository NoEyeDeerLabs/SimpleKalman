/* SimpleKalman - No Eye Deer Labs

This is an implementation of Kalman for a single dimension. It can be used to handle noisy
sensors such as accelerometers and gyros. You will need to calculate start values for the
filter covariances used to instantiate the filter. This article has some information and 
served as the inspiration for creating this. 

http://interactive-matter.eu/blog/2009/12/18/filtering-sensor-data-with-a-kalman-filter/

Usage is fairly straight forward. Create an instance of SimpleKalman for each sample you
wish to filter. Then call getFilteredVal with the new samples to return the filtered
result.

No Eye Deer Labs - STEAM Education served family style
*/

#ifndef _SimpleKalman_h
#define _SimpleKalman_h

class SimpleKalman {
  private:
    /* SimpleKalman filter variables */
    double q; //process noise covariance
    double r; //measurement noise covariance
    double v; //value
    double p; //estimation error covariance
    double g; //Kalman gain
    
  public:
    SimpleKalman(double process_noise_cv, double sensor_noise_cv, double estimated_error_cv, double start_val) {
      /* 
      */
        this->q = process_noise_cv;
        this->r = sensor_noise_cv;
        this->p = estimated_error_cv;
        this->v = start_val; //v will hold the iterated filtered value
    }
    
    double getFilteredVal(double sample) {
      /* Updates and gets the current measurement value */
      //prediction update
      this->p = this->p + this->q;
    
      //measurement update
      this->g = this->p / (this->p + this->r);
      this->v = this->v + this->g * (sample - this->v);
      this->p = (1 - this->g) * this->p;
      
      return this->v;
    }
    
    
    //Getters and Setters
    
    void setParams(double process_noise_cv, double sensor_noise_cv, double estimated_error_cv) {
        this->q = process_noise_cv;
        this->r = sensor_noise_cv;
        this->p = estimated_error_cv;
    }
    
        void setProcessNoiseCV(double process_noise_cv) {
        this->q = process_noise_cv;
    }
    
        void setSensorNoiseCV(double sensor_noise_cv) {
        this->r = sensor_noise_cv;
    }
    
        void setEstimatedErrorCV(double estimated_error_cv) {
        this->p = estimated_error_cv;
    }

    double getProcessNoiseCV() {
      return this->q;
    }
    
    double getSensorNoiseCV() {
      return this->r;
    }
    
    double getEstimatedErrorCV() {
      return this->p;
    }
    
        double getGain() {
      return this->g;
    }
    
};

#endif
