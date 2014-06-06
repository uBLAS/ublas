/*
 Utility functions
*/

typedef double value_type;
const double max_variance = 100; // max variance of about 100 millisecond

// define a random generator for randomly initializing matrices and vectors
std::mt19937 generator( std::chrono::system_clock::now().time_since_epoch().count() );
std::normal_distribution<double> ndistribution(0.0, 10.0);
std::uniform_real_distribution<double> udistribution(0.0, 10.0);

double average_time(const std::vector<double>& times){
    
    double sum = 0;
    for(size_t i = 0; i < times.size(); ++i){
        sum += times[i];
    }
    sum /= double(times.size());
    return sum;
    
}

double variance(double avgt, const std::vector<double>& times) {
    
    double var = 0;
    for(size_t i = 0; i < times.size(); ++i){
        var += (times[i] - avgt) * (times[i] - avgt);
    }
    
    var /= double(times.size());
    return var;
                      
}

