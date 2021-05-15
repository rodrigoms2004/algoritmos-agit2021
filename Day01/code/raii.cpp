//Source code do curso Algoritmos com C++ por Fabio Galuppo
//Ministrado em 2021 na Agit - https://www.agit.com.br/cursoalgoritmos.php
//Fabio Galuppo - http://member.acm.org/~fabiogaluppo - fabiogaluppo@acm.org
//Maio 2021

//g++ -O3 raii.t.cpp raii.cpp -o raii.exe
//cl /Fo.\obj\ /EHsc /O2 raii.t.cpp raii.cpp /link /out:raii.exe

int raii_main(int argc, char *argv[], bool run_tests);

int main(int argc, char *argv[])
{
    raii_main(argc, argv, true);
    return 0;
}