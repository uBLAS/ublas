

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
    return eigen_result / 1000.0; //convert to seconds
}

inline void Eigenmarks::SetSize(size_t newSize) {
    size = newSize;
}

inline void Eigenmarks::SetSteps(size_t newSteps) {
    steps = newSteps;
}

inline void Eigenmarks::SetFlops(size_t f) {
    flops = f;
}

void Eigenmarks::DmatScalarRun(std::string benchmark) {
    
    if(benchmark == "dmatscalarmult"){
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
    
    if(benchmark == "vecscalarmult"){
        eigen_result = vecscalarmult(size, steps);
    }
    else if(benchmark == "scale"){
        eigen_result = scale(size, steps);
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
    else if(benchmark == "cmajordmdmmult"){
        eigen_result = cmajordmdmmult(size, steps);
    }
    else if(benchmark == "rmajordmdmmult"){
        eigen_result = rmajordmdmmult(size, steps);
    }
    else if(benchmark == "nestedprod"){
        eigen_result = nestedprod(size, steps);
    }
    else if(benchmark == "symm1"){
        eigen_result = symm1(size, steps);
    }
    else if(benchmark == "symm1rect"){
        eigen_result = symm1rect(size, steps);
    }
    else if(benchmark == "symm2"){
        eigen_result = symm2(size, steps);
    }
    else if(benchmark == "syr2k"){
        eigen_result = syr2k(size, steps);
    }
    else if(benchmark == "syr2krect"){
        eigen_result = syr2krect(size, steps);
    }
    else if(benchmark == "syrk"){
        eigen_result = syrk(size, steps);
    }
    else if(benchmark == "syrkrect"){
        eigen_result = syrkrect(size, steps);
    }
    else if(benchmark == "custom"){
        eigen_result = custom(size, steps);
    }
    else{
        std::cerr << "MKLmarks benchmark does not exist." << std::endl;
        exit(1);
    }
    
}

void Eigenmarks::DmatVecRun(std::string benchmark) {
    
    if(benchmark == "dmatvecmult"){
        eigen_result = dmatvecmult(size, steps);
    }
    else if(benchmark == "gemv1"){
        eigen_result = gemv1(size, steps);
    }
    else if(benchmark == "gemv2"){
        eigen_result = gemv2(size, steps);
    }
    else if(benchmark == "ger1"){
        eigen_result = ger1(size, steps);
    }
    else if(benchmark == "syr"){
        eigen_result = syr(size, steps);
    }
    else if(benchmark == "trmv1"){
        eigen_result = trmv1(size, steps);
    }
    else if(benchmark == "trmv2"){
        eigen_result = trmv2(size, steps);
    }
    else if(benchmark == "cmajordmvmult"){
        eigen_result = cmajordmvmult(size, steps);
    }
    else if(benchmark == "rmajordmvmult"){
        eigen_result = rmajordmvmult(size, steps);
    }
    else if(benchmark == "custom"){
        eigen_result = custom(size, steps);
    }
    else{
        std::cerr << "Ublasmarks benchmark does not exist." << std::endl;
        exit(1);
    }
    
}

void Eigenmarks::SmatSmatRun(std::string benchmark) {
    
    if(benchmark == "smatsmatadd"){
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

void Eigenmarks::SmatVecRun(std::string benchmark) {
    
    if(benchmark == "smatvecmult"){
        eigen_result = smatvecmult(size, steps);
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
    else if(benchmark == "dotproduct"){
        eigen_result = dotproduct(size, steps);
    }
    else if(benchmark == "custom"){
        eigen_result = custom(size, steps);
    }
    else{
        std::cerr << "Blazemarks benchmark does not exist." << std::endl;
        exit(1);
    }
    
}
