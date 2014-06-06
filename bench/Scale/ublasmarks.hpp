

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
    return uBlas_result / 1000.0; //convert to seconds
}

inline void Ublasmarks::SetSize(size_t newSize) {
    size = newSize;
}

inline void Ublasmarks::SetSteps(size_t newSteps) {
    steps = newSteps;
}

inline void Ublasmarks::SetFlops(size_t f) {
    flops = f;
}

void Ublasmarks::DmatScalarRun(std::string benchmark) {
    
    if(benchmark == "dmatscalarmult"){
        uBlas_result = dmatscalarmult(size, steps);
    }
    else if(benchmark == "scale"){
        uBlas_result = scale(size, steps);
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
    
    if(benchmark == "vecscalarmult"){
        uBlas_result = vecscalarmult(size, steps);
    }
    else if(benchmark == "scale"){
        uBlas_result = scale(size, steps);
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
    else if(benchmark == "cmajordmdmmult"){
        uBlas_result = cmajordmdmmult(size, steps);
    }
    else if(benchmark == "rmajordmdmmult"){
        uBlas_result = rmajordmdmmult(size, steps);
    }
    else if(benchmark == "nestedprod"){
        uBlas_result = nestedprod(size, steps);
    }
    else if(benchmark == "symm1"){
        uBlas_result = symm1(size, steps);
    }
    else if(benchmark == "symm1rect"){
        uBlas_result = symm1rect(size, steps);
    }
    else if(benchmark == "symm2"){
        uBlas_result = symm2(size, steps);
    }
    else if(benchmark == "syr2k"){
        uBlas_result = syr2k(size, steps);
    }
    else if(benchmark == "syr2krect"){
        uBlas_result = syr2krect(size, steps);
    }
    else if(benchmark == "syrk"){
        uBlas_result = syrk(size, steps);
    }
    else if(benchmark == "syrkrect"){
        uBlas_result = syrkrect(size, steps);
    }
    else if(benchmark == "custom"){
        uBlas_result = custom(size, steps);
    }
    else{
        std::cerr << "MKLmarks benchmark does not exist." << std::endl;
        exit(1);
    }
    
}

void Ublasmarks::DmatVecRun(std::string benchmark) {
    
    if(benchmark == "dmatvecmult"){
        uBlas_result = dmatvecmult(size, steps);
    }
    else if(benchmark == "gemv1"){
        uBlas_result = gemv1(size, steps);
    }
    else if(benchmark == "gemv2"){
        uBlas_result = gemv2(size, steps);
    }
    else if(benchmark == "ger1"){
        uBlas_result = ger1(size, steps);
    }
    else if(benchmark == "syr"){
        uBlas_result = syr(size, steps);
    }
    else if(benchmark == "trmv1"){
        uBlas_result = trmv1(size, steps);
    }
    else if(benchmark == "trmv2"){
        uBlas_result = trmv2(size, steps);
    }
    else if(benchmark == "cmajordmvmult"){
        uBlas_result = cmajordmvmult(size, steps);
    }
    else if(benchmark == "rmajordmvmult"){
        uBlas_result = rmajordmvmult(size, steps);
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
    
    if(benchmark == "smatsmatadd"){
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

void Ublasmarks::SmatVecRun(std::string benchmark) {
    
    if(benchmark == "smatvecmult"){
        uBlas_result = smatvecmult(size, steps);
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
    else if(benchmark == "dotproduct"){
        uBlas_result = dotproduct(size, steps);
    }
    else if(benchmark == "custom"){
        uBlas_result = custom(size, steps);
    }
    else{
        std::cerr << "Blazemarks benchmark does not exist." << std::endl;
        exit(1);
    }
    
}
