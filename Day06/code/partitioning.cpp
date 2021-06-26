//Source code do curso Algoritmos com C++ por Fabio Galuppo
//Ministrado em 2021 na Agit - https://www.agit.com.br/cursoalgoritmos.php
//Fabio Galuppo - http://member.acm.org/~fabiogaluppo - fabiogaluppo@acm.org
//Maio 2021

//g++ -O3 partitioning.t.cpp partitioning.cpp -o partitioning.exe
//cl /Fo.\obj\ /EHsc /O2 partitioning.t.cpp partitioning.cpp /link /out:partitioning.exe

int partitioning_main(int argc, char *argv[], bool run_tests, bool reg_benchmarks);

int main(int argc, char *argv[])
{
    partitioning_main(argc, argv, true, false);
    return 0;
}