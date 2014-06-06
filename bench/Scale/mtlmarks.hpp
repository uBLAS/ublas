

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
    return mtl_result / 1000.0; //convert to seconds
}

inline void MTLmarks::SetSize(size_t newSize) {
    size = newSize;
}

inline void MTLmarks::SetSteps(size_t newSteps) {
    steps = newSteps;
}

inline void MTLmarks::SetFlops(size_t f) {
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
        std::cerr << "MTLmarks benchmark does not exist." << std::endl;
        exit(1);
    }
    
}

void MTLmarks::VecScalarRun(std::string benchmark) {
    
    if(benchmark == "vecscalarmult"){
        mtl_result = vecscalarmult(size, steps);
    }
    else if(benchmark == "scale"){
        mtl_result = scale(size, steps);
    }
    else if(benchmark == "custom"){
        mtl_result = custom(size, steps);
    }
    else{
        std::cerr << "MTLmarks benchmark does not exist." << std::endl;
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
    else if(benchmark == "cmajordmdmmult"){
        mtl_result = cmajordmdmmult(size, steps);
    }
    else if(benchmark == "rmajordmdmmult"){
        mtl_result = rmajordmdmmult(size, steps);
    }
    else if(benchmark == "nestedprod"){
        mtl_result = nestedprod(size, steps);
    }
    else if(benchmark == "symm1"){
        mtl_result = symm1(size, steps);
    }
    else if(benchmark == "symm1rect"){
        mtl_result = symm1rect(size, steps);
    }
    else if(benchmark == "symm2"){
        mtl_result = symm2(size, steps);
    }
    else if(benchmark == "syr2k"){
        mtl_result = syr2k(size, steps);
    }
    else if(benchmark == "syr2krect"){
        mtl_result = syr2krect(size, steps);
    }
    else if(benchmark == "syrk"){
        mtl_result = syrk(size, steps);
    }
    else if(benchmark == "syrkrect"){
        mtl_result = syrkrect(size, steps);
    }
    else if(benchmark == "custom"){
        mtl_result = custom(size, steps);
    }
    else{
        std::cerr << "MTLmarks benchmark does not exist." << std::endl;
        exit(1);
    }
    
}

void MTLmarks::DmatVecRun(std::string benchmark) {
    
    if(benchmark == "dmatvecmult"){
        mtl_result = dmatvecmult(size, steps);
    }
    else if(benchmark == "gemv1"){
        mtl_result = gemv1(size, steps);
    }
    else if(benchmark == "gemv2"){
        mtl_result = gemv2(size, steps);
    }
    else if(benchmark == "ger1"){
        mtl_result = ger1(size, steps);
    }
    else if(benchmark == "syr"){
        mtl_result = syr(size, steps);
    }
    else if(benchmark == "trmv1"){
        mtl_result = trmv1(size, steps);
    }
    else if(benchmark == "trmv2"){
        mtl_result = trmv2(size, steps);
    }
    else if(benchmark == "cmajordmvmult"){
        mtl_result = cmajordmvmult(size, steps);
    }
    else if(benchmark == "rmajordmvmult"){
        mtl_result = rmajordmvmult(size, steps);
    }
    else if(benchmark == "custom"){
        mtl_result = custom(size, steps);
    }
    else{
        std::cerr << "Ublasmarks benchmark does not exist." << std::endl;
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
        std::cerr << "MTLmarks benchmark does not exist." << std::endl;
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
        std::cerr << "MTLmarks benchmark does not exist." << std::endl;
        exit(1);
    }
    
}

void MTLmarks::SmatVecRun(std::string benchmark) {
    
    if(benchmark == "smatvecmult"){
        mtl_result = smatvecmult(size, steps);
    }
    else if(benchmark == "custom"){
        mtl_result = custom(size, steps);
    }
    else{
        std::cerr << "MTLmarks benchmark does not exist." << std::endl;
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
    else if(benchmark == "dotproduct"){
        mtl_result = dotproduct(size, steps);
    }
    else if(benchmark == "custom"){
        mtl_result = custom(size, steps);
    }
    else{
        std::cerr << "MTLmarks benchmark does not exist." << std::endl;
        exit(1);
    }
    
}
