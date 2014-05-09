

Blazemarks::Blazemarks(size_t N, size_t s = 1) : size(N), steps(s), blaze_result(0) {}

inline size_t Blazemarks::GetSize() const {
    return size;
}

inline size_t Blazemarks::GetSteps() const {
    return steps;
}

inline size_t Blazemarks::GetFlops() const {
    return flops;
}

inline double Blazemarks::GetBlazeResult() const {
    return blaze_result;
}

inline void Blazemarks::SetSize(size_t newSize) {
    size = newSize;
}

inline void Blazemarks::SetSteps(size_t newSteps) {
    steps = newSteps;
}

inline void Blazemarks::EstimateFlops(size_t f) {
    flops = f;
}

void Blazemarks::DmatScalarRun(std::string benchmark) {
    
    if(benchmark == "dmatmscalaradd"){
        blaze_result = dmatmscalaradd(size, steps);
    }
    else if(benchmark == "dmatscalarmult"){
        blaze_result = dmatscalarmult(size, steps);
    }
    else if(benchmark == "custom"){
        blaze_result = custom(size, steps);
    }
    else{
        std::cerr << "Blazemarks benchmark does not exist." << std::endl;
        exit(1);
    }
    
}

void Blazemarks::VecScalarRun(std::string benchmark) {
    
    if(benchmark == "vecvscalaradd"){
        blaze_result = vecvscalaradd(size, steps);
    }
    else if(benchmark == "vecscalarmult"){
        blaze_result = vecscalarmult(size, steps);
    }
    else if(benchmark == "custom"){
        blaze_result = custom(size, steps);
    }
    else{
        std::cerr << "Blazemarks benchmark does not exist." << std::endl;
        exit(1);
    }
    
}

void Blazemarks::DmatDmatRun(std::string benchmark) {
    
    if(benchmark == "dmatdmatadd"){
        blaze_result = dmatdmatadd(size, steps);
    }
    else if(benchmark == "dmatdmatmult"){
        blaze_result = dmatdmatmult(size, steps);
    }
    else if(benchmark == "custom"){
        blaze_result = custom(size, steps);
    }
    else{
        std::cerr << "Blazemarks benchmark does not exist." << std::endl;
        exit(1);
    }
    
}

void Blazemarks::DmatVecRun(std::string benchmark) {
    
    if(benchmark == "dmatvecmult"){
        blaze_result = dmatvecmult(size, steps);
    }
    else if(benchmark == "custom"){
        blaze_result = custom(size, steps);
    }
    else{
        std::cerr << "Blazemarks benchmark does not exist." << std::endl;
        exit(1);
    }
    
}

void Blazemarks::SmatSmatRun(std::string benchmark) {
    
    if(benchmark == "saxpy"){
        blaze_result = saxpy(size, steps);
    }
    else if(benchmark == "smatsmatadd"){
        blaze_result = smatsmatadd(size, steps);
    }
    else if(benchmark == "smatsmatmult"){
        blaze_result = smatsmatmult(size, steps);
    }
    else if(benchmark == "custom"){
        blaze_result = custom(size, steps);
    }
    else{
        std::cerr << "Blazemarks benchmark does not exist." << std::endl;
        exit(1);
    }
    
}

void Blazemarks::SmatSvecRun(std::string benchmark) {
    
    if(benchmark == "smatsvecmult"){
        blaze_result = smatsvecmult(size, steps);
    }
    else if(benchmark == "custom"){
        blaze_result = custom(size, steps);
    }
    else{
        std::cerr << "Blazemarks benchmark does not exist." << std::endl;
        exit(1);
    }
    
}

void Blazemarks::VecVecRun(std::string benchmark) {
    
    if(benchmark == "daxpy"){
        blaze_result = daxpy(size, steps);
    }
    else if(benchmark == "vecvecadd"){
        blaze_result = vecvecadd(size, steps);
    }
    else if(benchmark == "vecvecmult"){
        blaze_result = vecvecmult(size, steps);
    }
    else if(benchmark == "custom"){
        blaze_result = custom(size, steps);
    }
    else{
        std::cerr << "Blazemarks benchmark does not exist." << std::endl;
        exit(1);
    }
    
}