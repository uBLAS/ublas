

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
    return blaze_result / 1000.0; //convert to seconds
}

inline void Blazemarks::SetSize(size_t newSize) {
    size = newSize;
}

inline void Blazemarks::SetSteps(size_t newSteps) {
    steps = newSteps;
}

inline void Blazemarks::SetFlops(size_t f) {
    flops = f;
}

void Blazemarks::DmatScalarRun(std::string benchmark) {
    
    if(benchmark == "dmatscalarmult"){
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
    
    if(benchmark == "vecscalarmult"){
        blaze_result = vecscalarmult(size, steps);
    }
    else if(benchmark == "scale"){
        blaze_result = scale(size, steps);
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
    else if(benchmark == "cmajordmdmmult"){
        blaze_result = cmajordmdmmult(size, steps);
    }
    else if(benchmark == "rmajordmdmmult"){
        blaze_result = rmajordmdmmult(size, steps);
    }
    else if(benchmark == "nestedprod"){
        blaze_result = nestedprod(size, steps);
    }
    else if(benchmark == "symm1"){
        blaze_result = symm1(size, steps);
    }
    else if(benchmark == "symm1rect"){
        blaze_result = symm1rect(size, steps);
    }
    else if(benchmark == "symm2"){
        blaze_result = symm2(size, steps);
    }
    else if(benchmark == "syr2k"){
        blaze_result = syr2k(size, steps);
    }
    else if(benchmark == "syr2krect"){
        blaze_result = syr2krect(size, steps);
    }
    else if(benchmark == "syrk"){
        blaze_result = syrk(size, steps);
    }
    else if(benchmark == "syrkrect"){
        blaze_result = syrkrect(size, steps);
    }
    else if(benchmark == "custom"){
        blaze_result = custom(size, steps);
    }
    else{
        std::cerr << "MKLmarks benchmark does not exist." << std::endl;
        exit(1);
    }
    
}

void Blazemarks::DmatVecRun(std::string benchmark) {
    
    if(benchmark == "dmatvecmult"){
        blaze_result = dmatvecmult(size, steps);
    }
    else if(benchmark == "gemv1"){
        blaze_result = gemv1(size, steps);
    }
    else if(benchmark == "gemv2"){
        blaze_result = gemv2(size, steps);
    }
    else if(benchmark == "ger1"){
        blaze_result = ger1(size, steps);
    }
    else if(benchmark == "syr"){
        blaze_result = syr(size, steps);
    }
    else if(benchmark == "trmv1"){
        blaze_result = trmv1(size, steps);
    }
    else if(benchmark == "trmv2"){
        blaze_result = trmv2(size, steps);
    }
    else if(benchmark == "cmajordmvmult"){
        blaze_result = cmajordmvmult(size, steps);
    }
    else if(benchmark == "rmajordmvmult"){
        blaze_result = rmajordmvmult(size, steps);
    }
    else if(benchmark == "custom"){
        blaze_result = custom(size, steps);
    }
    else{
        std::cerr << "Ublasmarks benchmark does not exist." << std::endl;
        exit(1);
    }
    
}

void Blazemarks::SmatSmatRun(std::string benchmark) {
    
    if(benchmark == "smatsmatadd"){
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

void Blazemarks::SmatVecRun(std::string benchmark) {
    
    if(benchmark == "smatvecmult"){
        blaze_result = smatvecmult(size, steps);
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
    else if(benchmark == "dotproduct"){
        blaze_result = dotproduct(size, steps);
    }
    else if(benchmark == "custom"){
        blaze_result = custom(size, steps);
    }
    else{
        std::cerr << "Blazemarks benchmark does not exist." << std::endl;
        exit(1);
    }
    
}