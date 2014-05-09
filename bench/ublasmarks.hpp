

Ublasmarks::Ublasmarks(size_t N, size_t s = 1) : size(N), steps(s), uBlas_result(0) {}

inline size_t Ublasmarks::GetSize() const {
    return size;
}

inline size_t Ublasmarks::GetSteps() const {
    return steps;
}

inline size_t Ublasmarks::GetFlops() const {
    return flops;
}

inline double Ublasmarks::GetuBlasResult() const {
    return uBlas_result;
}

inline void Ublasmarks::SetSize(size_t newSize) {
    size = newSize;
}

inline void Ublasmarks::SetSteps(size_t newSteps) {
    steps = newSteps;
}

inline void Ublasmarks::EstimateFlops(size_t f) {
    flops = f;
}

void Ublasmarks::DmatScalarRun(std::string benchmark) {
    
    if(benchmark == "dmatmscalaradd"){
        uBlas_result = dmatmscalaradd(size, steps);
    }
    else if(benchmark == "dmatscalarmult"){
        uBlas_result = dmatscalarmult(size, steps);
    }
    else if(benchmark == "custom"){
        uBlas_result = custom(size, steps);
    }
    else{
        std::cerr << "Ublasmarks benchmark does not exist." << std::endl;
        exit(1);
    }
    
}

void Ublasmarks::VecScalarRun(std::string benchmark) {
    
    if(benchmark == "vecvscalaradd"){
        uBlas_result = vecvscalaradd(size, steps);
    }
    else if(benchmark == "vecscalarmult"){
        uBlas_result = vecscalarmult(size, steps);
    }
    else if(benchmark == "custom"){
        uBlas_result = custom(size, steps);
    }
    else{
        std::cerr << "Ublasmarks benchmark does not exist." << std::endl;
        exit(1);
    }
    
}

void Ublasmarks::DmatDmatRun(std::string benchmark) {
    
    if(benchmark == "dmatdmatadd"){
        uBlas_result = dmatdmatadd(size, steps);
    }
    else if(benchmark == "dmatdmatmult"){
        uBlas_result = dmatdmatmult(size, steps);
    }
    else if(benchmark == "custom"){
        uBlas_result = custom(size, steps);
    }
    else{
        std::cerr << "Ublasmarks benchmark does not exist." << std::endl;
        exit(1);
    }
    
}

void Ublasmarks::DmatVecRun(std::string benchmark) {
    
    if(benchmark == "dmatvecmult"){
        uBlas_result = dmatvecmult(size, steps);
    }
    else if(benchmark == "custom"){
        uBlas_result = custom(size, steps);
    }
    else{
        std::cerr << "Ublasmarks benchmark does not exist." << std::endl;
        exit(1);
    }
    
}

void Ublasmarks::SmatSmatRun(std::string benchmark) {
    
    if(benchmark == "saxpy"){
        uBlas_result = saxpy(size, steps);
    }
    else if(benchmark == "smatsmatadd"){
        uBlas_result = smatsmatadd(size, steps);
    }
    else if(benchmark == "smatsmatmult"){
        uBlas_result = smatsmatmult(size, steps);
    }
    else if(benchmark == "custom"){
        uBlas_result = custom(size, steps);
    }
    else{
        std::cerr << "Ublasmarks benchmark does not exist." << std::endl;
        exit(1);
    }
    
}

void Ublasmarks::SmatSvecRun(std::string benchmark) {
    
    if(benchmark == "smatsvecmult"){
        uBlas_result = smatsvecmult(size, steps);
    }
    else if(benchmark == "custom"){
        uBlas_result = custom(size, steps);
    }
    else{
        std::cerr << "Ublasmarks benchmark does not exist." << std::endl;
        exit(1);
    }
    
}

void Ublasmarks::VecVecRun(std::string benchmark) {
    
    if(benchmark == "daxpy"){
        uBlas_result = daxpy(size, steps);
    }
    else if(benchmark == "vecvecadd"){
        uBlas_result = vecvecadd(size, steps);
    }
    else if(benchmark == "vecvecmult"){
        uBlas_result = vecvecmult(size, steps);
    }
    else if(benchmark == "custom"){
        uBlas_result = custom(size, steps);
    }
    else{
        std::cerr << "Ublasmarks benchmark does not exist." << std::endl;
        exit(1);
    }
    
}
