

Eigenmarks::Eigenmarks(size_t N, size_t s = 1) : size(N), steps(s), eigen_result(0) {}

inline size_t Eigenmarks::GetSize() const {
    return size;
}

inline size_t Eigenmarks::GetSteps() const {
    return steps;
}

inline size_t Eigenmarks::GetFlops() const {
    return flops;
}

inline double Eigenmarks::GetEigenResult() const {
    return eigen_result;
}

inline void Eigenmarks::SetSize(size_t newSize) {
    size = newSize;
}

inline void Eigenmarks::SetSteps(size_t newSteps) {
    steps = newSteps;
}

inline void Eigenmarks::EstimateFlops(size_t f) {
    flops = f;
}

void Eigenmarks::DmatScalarRun(std::string benchmark) {
    
    if(benchmark == "dmatmscalaradd"){
        eigen_result = dmatmscalaradd(size, steps);
    }
    else if(benchmark == "dmatscalarmult"){
        eigen_result = dmatscalarmult(size, steps);
    }
    else if(benchmark == "custom"){
        eigen_result = custom(size, steps);
    }
    else{
        std::cerr << "Eigenmarks benchmark does not exist." << std::endl;
        exit(1);
    }
    
}

void Eigenmarks::VecScalarRun(std::string benchmark) {
    
    if(benchmark == "vecvscalaradd"){
        eigen_result = vecvscalaradd(size, steps);
    }
    else if(benchmark == "vecscalarmult"){
        eigen_result = vecscalarmult(size, steps);
    }
    else if(benchmark == "custom"){
        eigen_result = custom(size, steps);
    }
    else{
        std::cerr << "Eigenmarks benchmark does not exist." << std::endl;
        exit(1);
    }
    
}

void Eigenmarks::DmatDmatRun(std::string benchmark) {
    
    if(benchmark == "dmatdmatadd"){
        eigen_result = dmatdmatadd(size, steps);
    }
    else if(benchmark == "dmatdmatmult"){
        eigen_result = dmatdmatmult(size, steps);
    }
    else if(benchmark == "custom"){
        eigen_result = custom(size, steps);
    }
    else{
        std::cerr << "Eigenmarks benchmark does not exist." << std::endl;
        exit(1);
    }
    
}

void Eigenmarks::DmatVecRun(std::string benchmark) {
    
    if(benchmark == "dmatvecmult"){
        eigen_result = dmatvecmult(size, steps);
    }
    else if(benchmark == "custom"){
        eigen_result = custom(size, steps);
    }
    else{
        std::cerr << "Eigenmarks benchmark does not exist." << std::endl;
        exit(1);
    }
    
}

void Eigenmarks::SmatSmatRun(std::string benchmark) {
    
    if(benchmark == "saxpy"){
        eigen_result = saxpy(size, steps);
    }
    else if(benchmark == "smatsmatadd"){
        eigen_result = smatsmatadd(size, steps);
    }
    else if(benchmark == "smatsmatmult"){
        eigen_result = smatsmatmult(size, steps);
    }
    else if(benchmark == "custom"){
        eigen_result = custom(size, steps);
    }
    else{
        std::cerr << "Eigenmarks benchmark does not exist." << std::endl;
        exit(1);
    }
    
}

void Eigenmarks::SmatSvecRun(std::string benchmark) {
    
    if(benchmark == "smatsvecmult"){
        eigen_result = smatsvecmult(size, steps);
    }
    else if(benchmark == "custom"){
        eigen_result = custom(size, steps);
    }
    else{
        std::cerr << "Eigenmarks benchmark does not exist." << std::endl;
        exit(1);
    }
    
}

void Eigenmarks::VecVecRun(std::string benchmark) {
    
    if(benchmark == "daxpy"){
        eigen_result = daxpy(size, steps);
    }
    else if(benchmark == "vecvecadd"){
        eigen_result = vecvecadd(size, steps);
    }
    else if(benchmark == "vecvecmult"){
        eigen_result = vecvecmult(size, steps);
    }
    else if(benchmark == "custom"){
        eigen_result = custom(size, steps);
    }
    else{
        std::cerr << "Eigenmarks benchmark does not exist." << std::endl;
        exit(1);
    }
    
}
