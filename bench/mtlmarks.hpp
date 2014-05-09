

MTLmarks::MTLmarks(size_t N, size_t s = 1) : size(N), steps(s), mtl_result(0) {}

inline size_t MTLmarks::GetSize() const {
    return size;
}

inline size_t MTLmarks::GetSteps() const {
    return steps;
}

inline size_t MTLmarks::GetFlops() const {
    return flops;
}

inline double MTLmarks::GetMTLResult() const {
    return mtl_result;
}

inline void MTLmarks::SetSize(size_t newSize) {
    size = newSize;
}

inline void MTLmarks::SetSteps(size_t newSteps) {
    steps = newSteps;
}

inline void MTLmarks::EstimateFlops(size_t f) {
    flops = f;
}

void MTLmarks::DmatScalarRun(std::string benchmark) {
    
    if(benchmark == "dmatscalarmult"){
        mtl_result = dmatscalarmult(size, steps);
    }
    else if(benchmark == "custom"){
        mtl_result = custom(size, steps);
    }
    else{
        std::cerr << "MKLmarks benchmark does not exist." << std::endl;
        exit(1);
    }
    
}

void MTLmarks::VecScalarRun(std::string benchmark) {
    
    if(benchmark == "vecscalarmult"){
        mtl_result = vecscalarmult(size, steps);
    }
    else if(benchmark == "custom"){
        mtl_result = custom(size, steps);
    }
    else{
        std::cerr << "MKLmarks benchmark does not exist." << std::endl;
        exit(1);
    }
    
}

void MTLmarks::DmatDmatRun(std::string benchmark) {
    
    if(benchmark == "dmatdmatadd"){
        mtl_result = dmatdmatadd(size, steps);
    }
    else if(benchmark == "dmatdmatmult"){
        mtl_result = dmatdmatmult(size, steps);
    }
    else if(benchmark == "custom"){
        mtl_result = custom(size, steps);
    }
    else{
        std::cerr << "MKLmarks benchmark does not exist." << std::endl;
        exit(1);
    }
    
}

void MTLmarks::DmatVecRun(std::string benchmark) {
    
    if(benchmark == "dmatvecmult"){
        mtl_result = dmatvecmult(size, steps);
    }
    else if(benchmark == "custom"){
        mtl_result = custom(size, steps);
    }
    else{
        std::cerr << "MKLmarks benchmark does not exist." << std::endl;
        exit(1);
    }
    
}

void MTLmarks::SmatSmatRun(std::string benchmark) {
    
    if(benchmark == "smatsmatadd"){
        mtl_result = smatsmatadd(size, steps);
    }
    else if(benchmark == "smatsmatmult"){
        mtl_result = smatsmatmult(size, steps);
    }
    else if(benchmark == "custom"){
        mtl_result = custom(size, steps);
    }
    else{
        std::cerr << "MKLmarks benchmark does not exist." << std::endl;
        exit(1);
    }
    
}

void MTLmarks::SmatSvecRun(std::string benchmark) {
    
    if(benchmark == "smatsvecmult"){
        mtl_result = smatsvecmult(size, steps);
    }
    else if(benchmark == "custom"){
        mtl_result = custom(size, steps);
    }
    else{
        std::cerr << "MKLmarks benchmark does not exist." << std::endl;
        exit(1);
    }
    
}

void MTLmarks::VecVecRun(std::string benchmark) {
    
    if(benchmark == "daxpy"){
        mtl_result = daxpy(size, steps);
    }
    else if(benchmark == "vecvecadd"){
        mtl_result = vecvecadd(size, steps);
    }
    else if(benchmark == "vecvecmult"){
        mtl_result = vecvecmult(size, steps);
    }
    else if(benchmark == "custom"){
        mtl_result = custom(size, steps);
    }
    else{
        std::cerr << "MKLmarks benchmark does not exist." << std::endl;
        exit(1);
    }
    
}
