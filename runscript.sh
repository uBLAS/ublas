#!bin/bash

# Run script for the benchmark suite of the Boost.uBlas linear algebra library. Assumes that both g++ and gnuplot are available.

# These are the default compiler flags for g++ that will be enabled for every optimization level (O0, O1, O2, O3).
# If mkl is being used with blaze-lib then the following flags are needed as well: -DMKL_ILP64 -m64 -lmkl_intel_ilp64 -lmkl_core -lmkl_sequential -lpthread -lm -L /path/to/mkl/lib
defaultflags=" -ansi -std=c++11 -DNDEBUG -march=native "

# Locations of each linear algebra library to be used with the "-I" flag.
boostpath=~/bench/lalib/boost/
blazepath=~/bench/lalib/blaze/
eigenpath=~/bench/lalib/eigen/
mtlpath=~/bench/lalib/MTL/usr/include/

opt="O0"
flags=" -"$opt$defaultflags

for d in */ ; do
	echo "$d"
	cd "$d"
	if [ ! -d "$opt" ]; then
  		mkdir $opt
	fi
	g++ $flags -I $boostpath -I $blazepath -I $eigenpath -I $mtlpath benchmarks.cpp
	./a.out
	mv *.dat $opt
    rm a.out
	cd ..	 
done

opt="O1"
flags=" -"$opt$defaultflags

for d in */ ; do
        echo "$d"
        cd "$d"
        if [ ! -d "$opt" ]; then
                mkdir $opt
        fi
        g++ $flags -I $boostpath -I $blazepath -I $eigenpath -I $mtlpath benchmarks.cpp
        ./a.out
        mv *.dat $opt
        rm a.out
        cd ..
done

opt="O2"
flags=" -"$opt$defaultflags

for d in */ ; do
        echo "$d"
        cd "$d"
        if [ ! -d "$opt" ]; then
                mkdir $opt
        fi
        g++ $flags -I $boostpath -I $blazepath -I $eigenpath -I $mtlpath benchmarks.cpp
        ./a.out
        mv *.dat $opt
        rm a.out
        cd ..
done

opt="O3"
flags=" -"$opt$defaultflags

for d in */ ; do
        echo "$d"
        cd "$d"
        if [ ! -d "$opt" ]; then
                mkdir $opt
        fi
        g++ $flags -I $boostpath -I $blazepath -I $eigenpath -I $mtlpath benchmarks.cpp
        ./a.out
        mv *.dat $opt
        rm a.out
        cd ..
done

# Done with the benchmark runs. Now we plot the results with gnuplot.
# First make sure when have an empty directory named results to place all the plots in.
if [ ! -d "results" ]; then
        mkdir results
else
        rm -rf results/*
fi

# Now make the plots
for d in */ ; do
cd "$d"
directories=( "O0" "O1" "O2" "O3" )
for sd in "${directories[@]}" ; do
if [ -d "$sd" ]; then
cd "$sd"
output="${d%?}$sd"
if [ -f "plot.txt" ];
then
rm plot.txt
fi
touch plot.txt
cat > plot.txt <<_EOF_
set term postscript eps enhanced color "Helvetica" 18
set output "$output.eps"
set datafile commentschars "#%!"
set key box lt -1 lw 1
set key out vert
set key center bottom
set style line 10 lt 1 lw 2
set style line 1 lt -1 lw 2
set style line 2 lt 1 lw 3
set style line 3 lt 3 lw 3 pt 0
set style line 4 lt 7 lw 3 pt 0
set style line 5 lt 2 lw 3 pt 0
set style line 6 lt 8 lw 3 pt 0
set format x "%g"
set ylabel "MFLOPS"  font "Helvetica,22" offset 0.5
set format y "%g"
set origin 0,0.3
set logscale x
set xlabel "N" font "Helvetica,22"
set xtics nomirror
plot "ublas.dat" title "uBlas" w l ls 3, "blaze.dat" title "Blaze" w l ls 4, "eigen.dat" title "Eigen" w l ls 5, "mtl.dat" title "MTL" w l ls 6, "clike.dat" title "Clike" w l ls 2
_EOF_
gnuplot plot.txt
rm plot.txt
mv "$output.eps" ../../results/
cd ..
fi
done
rm -rf O*
cd ..
done
