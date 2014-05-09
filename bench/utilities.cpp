/*
 Utility functions
*/

// define a random generator for randomly initializing matrices and vectors
std::mt19937 generator( std::chrono::system_clock::now().time_since_epoch().count() );
std::normal_distribution<double> distribution(0.0, 10.0);

double average_time(const std::vector<double>& times){
    
    double sum = 0;
    for(size_t i = 0; i < times.size(); ++i){
        sum += times[i];
    }
    sum /= double(times.size());
    return sum;
    
}