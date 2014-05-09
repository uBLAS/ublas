

Cmarks::Cmarks(size_t N, size_t s = 1) : size(N), steps(s), clike_result(0) {}

inline size_t Cmarks::GetSize() const {
    return size;
}

inline size_t Cmarks::GetSteps() const {
    return steps;
}

inline size_t Cmarks::GetFlops() const {
    return flops;
}

inline double Cmarks::GetClikeResult() const {
    return clike_result;
}

inline void Cmarks::SetSize(size_t newSize) {
    size = newSize;
}

inline void Cmarks::SetSteps(size_t newSteps) {
    steps = newSteps;
}

inline void Cmarks::EstimateFlops(size_t f) {
    flops = f;
}

void Cmarks::DmatDmatRun(std::string benchmark) {
    
    if(benchmark == "dmatdmatadd"){
        clike_result = dmatdmatadd(size, steps);
    }
    else if(benchmark == "dmatdmatmult"){
        clike_result = dmatdmatmult(size, steps);
    }
    else if(benchmark == "custom"){
        clike_result = custom(size, steps);
    }
    else{
        std::cerr << "Cmarks benchmark does not exist." << std::endl;
        exit(1);
    }
    
}

void Cmarks::DmatVecRun(std::string benchmark) {
    
    if(benchmark == "dmatvecmult"){
        clike_result = dmatvecmult(size, steps);
    }
    else if(benchmark == "custom"){
        clike_result = custom(size, steps);
    }
    else{
        std::cerr << "Cmarks benchmark does not exist." << std::endl;
        exit(1);
    }
    
}

void Cmarks::VecVecRun(std::string benchmark) {
    
    if(benchmark == "daxpy"){
        clike_result = daxpy(size, steps);
    }
    else if(benchmark == "vecvecadd"){
        clike_result = vecvecadd(size, steps);
    }
    else if(benchmark == "vecvecmult"){
        clike_result = vecvecmult(size, steps);
    }
    else if(benchmark == "custom"){
        clike_result = custom(size, steps);
    }
    else{
        std::cerr << "Cmarks benchmark does not exist." << std::endl;
        exit(1);
    }
    
}
