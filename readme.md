# Algoritmos Agit 2021

[Professor Fabio Galuppo](https://github.com/fabiogaluppo?tab=repositories)

https://www.agit.com.br/cursoalgoritmos.php

## Dia 1 - 15/05/2021

[Resolver os problemas](https://leetcode.com/problems/find-all-duplicates-in-an-array/)

* Arquivos .cpp programa driver, onde fica o main()
* Arquivos .t.cpp classe de testes
* Arquivos .hpp conteúdo principal

CTRL+D EOF do linux *linear_search*

cpp_feature_testing.cpp verificar compatibilidades do compilador

### std::size_t

std::size_t == alias do unsigned long long, padrão dos containers

### Day01/code/benchmark_linear_search.cpp

target = 42, 4096 42 1361, 4096 iterações procurando por 42, encontrou na posição 1361
target = 1001, 4096 1001 18446744073709551615 máximo do size_t - 1

### Links úteis

* [C++](http://cplusplus.com/)
* [C++ Reference](http://cplusplus.com/reference/)
* [C++ compiler support](https://en.cppreference.com/w/cpp/compiler_support)



### Update GCC

https://gcc.gnu.org/

https://linuxize.com/post/how-to-install-gcc-compiler-on-ubuntu-18-04/

```
$ sudo apt install gcc-11 g++-11

$ sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-11 110 --slave /usr/bin/g++ g++ /usr/bin/g++-11 --slave /usr/bin/gcov gcov /usr/bin/gcov-11

$ sudo update-alternatives --config gccThere are 4 choices for the alternative gcc (providing /usr/bin/gcc).

  Selection    Path             Priority   Status
------------------------------------------------------------
* 0            /usr/bin/gcc-11   110       auto mode
  1            /usr/bin/gcc-11   110       manual mode
  2            /usr/bin/gcc-7    70        manual mode
  3            /usr/bin/gcc-8    80        manual mode
  4            /usr/bin/gcc-9    90        manual mode

Press <enter> to keep the current choice[*], or type selection number: 

$ g++ --version
g++ (Ubuntu 11.1.0-1ubuntu1~18.04.1) 11.1.0

$ gcc --version
gcc (Ubuntu 11.1.0-1ubuntu1~18.04.1) 11.1.0
```

https://linuxize.com/post/how-to-install-gcc-on-ubuntu-20-04/



## Dia 2 - 22/05/2021


https://msgpack.org/index.html

sbe simple binary encoding

Zero MQ

https://zeromq.org/get-started/?language=cpp#


i++ gera temporário

++i não gera temporário, boa prática

Usar emplace_back em vez de push_back
https://www.cplusplus.com/reference/vector/vector/emplace_back/

http://www.cplusplus.com/reference/utility/move/

https://www.cplusplus.com/reference/set/set/set/


### Layout da Memória

Day02/code/cpp_memory_layout.cpp


```
g++ -O3 cpp_memory_layout.cpp -o cpp_memory_layout.o

./cpp_memory_layout.o 

[ 8b]  140720460576096 (0x7ffc0910b560)       on stack
[ 4b]  140720460576108 (0x7ffc0910b56c):    1 on stack
[ 4b]  140720460576112 (0x7ffc0910b570):   42 on stack
[ 8b]  140720460576128 (0x7ffc0910b580)       on stack
[ 8b]  140720460576136 (0x7ffc0910b588)       on stack
[ 8b]  140720460576144 (0x7ffc0910b590)       on stack
[ 8b]  140720460576152 (0x7ffc0910b598)       on stack
[ 4b]  140720460576116 (0x7ffc0910b574):   84 on stack
[ 4b]  140720460576120 (0x7ffc0910b578):  126 on stack
[ 4b]  140720460576124 (0x7ffc0910b57c):  168 on stack
[24b]  140720460576160 (0x7ffc0910b5a0):    4 on stack
[ 4b]   94692382408304 (0x561f49d0fe70):   42 on heap
[ 4b]   94692382408336 (0x561f49d0fe90):   84 on heap
[ 4b]   94692382408368 (0x561f49d0feb0):  126 on heap
[ 4b]   94692382408400 (0x561f49d0fed0):  168 on heap
[ 4b]   94692382408432 (0x561f49d0fef0):   42 on heap
[ 4b]   94692382408436 (0x561f49d0fef4):   84 on heap
[ 4b]   94692382408440 (0x561f49d0fef8):  126 on heap
[ 4b]   94692382408444 (0x561f49d0fefc):  168 on heap
[ 4b]   94692358602788 (0x561f4865c024):    0 on data (uninitialized)
[ 4b]   94692358602792 (0x561f4865c028):    0 on data (uninitialized)
[ 4b]   94692358602772 (0x561f4865c014):   42 on data (initialized)
[ 4b]   94692358602768 (0x561f4865c010):   42 on data (initialized)
       140131755052800 (0x7f72f77b4f00):   printf on text
        94692356499536 (0x561f4845a850):     main on text
        94692356501168 (0x561f4845aeb0):    print on text
```

### Resource Acquisition Is Initialization or RAII

[Em 01:46:30](https://youtu.be/8v-wjXiBpJE)

*Day02/code/raii.hpp*

Reservar o recurso no construtor e liberar o recurso no destrutor

* Idioma para prevenção de leaks: memória, arquivos, sockets, threads, etc

O recurso é:
1. Aquirido pelo objeto na sua inicialização (constructor)
2. Mantido durante o tempo de vida do objeto
3. Liberado na destruição do objeto (destructor)


[Object lifetime and resource management (RAII)](https://docs.microsoft.com/en-us/cpp/cpp/object-lifetime-and-resource-management-modern-cpp)


### Dynamic Array (baseada em índice)

[Em 02:09:45](https://youtu.be/8v-wjXiBpJE)

*Day02/code/dynamic_array.hpp*

Sempre que tiver a possibilidade, passe um capacity. Ex: vector<T>.reserve(). Melhora a performance. 

```
 ./dynamic_array.o 
int: add an item, -: remove an item, ?: display data, !: display info
  dynamic_array<int> size:     1000 capacity:     1024
         vector<int> size:   100000 capacity:   131072
         vector<int> size:    10000 capacity:    16384
         vector<int> size:     1000 capacity:     1024
reserved vector<int> size:    10000 capacity:    10000
  dynamic_array<int> size:   100000 capacity:   131072
         vector<int> size:   100000 capacity:   131072
  dynamic_array<int> size:    10000 capacity:    16384
  dynamic_array<int> size:  1000000 capacity:  1048576
reserved vector<int> size:     1000 capacity:     1000
  dynamic_array<int> size:  1000000 capacity:  1048576
reserved vector<int> size:     1000 capacity:     1000
         vector<int> size:    10000 capacity:    16384
reserved vector<int> size:  1000000 capacity:  1000000
         vector<int> size:     1000 capacity:     1024
  dynamic_array<int> size:     1000 capacity:     1024
         vector<int> size:  1000000 capacity:  1048576
  dynamic_array<int> size:   100000 capacity:   131072
         vector<int> size:  1000000 capacity:  1048576
reserved vector<int> size:   100000 capacity:   100000
reserved vector<int> size:    10000 capacity:    10000
reserved vector<int> size:  1000000 capacity:  1000000
reserved vector<int> size:   100000 capacity:   100000
  dynamic_array<int> size:    10000 capacity:    16384
dynamic_array:
===============================================================================
   Name (baseline is *)   |   Dim   |  Total ms |  ns/op  |Baseline| Ops/second
===============================================================================
         bench_dynarr_add |    1000 |     0.006 |       5 |  0.378 |181061017.6
  bench_std_vec_push_back |    1000 |     0.011 |      10 |  0.730 | 93914350.1
 bench_std_vec_rsrvd_pb * |    1000 |     0.015 |      14 |      - | 68521310.1
         bench_dynarr_add |   10000 |     0.020 |       1 |  0.621 |512400082.0
  bench_std_vec_push_back |   10000 |     0.099 |       9 |  3.141 |101271976.0
 bench_std_vec_rsrvd_pb * |   10000 |     0.031 |       3 |      - |318126869.0
         bench_dynarr_add |  100000 |     0.856 |       8 |  4.010 |116772910.6
  bench_std_vec_push_back |  100000 |     2.431 |      24 | 11.384 | 41133592.4
 bench_std_vec_rsrvd_pb * |  100000 |     0.214 |       2 |      - |468254674.4
         bench_dynarr_add | 1000000 |    26.333 |      26 |  5.820 | 37975872.3
  bench_std_vec_push_back | 1000000 |     8.903 |       8 |  1.968 |112326572.0
 bench_std_vec_rsrvd_pb * | 1000000 |     4.524 |       4 |      - |221030475.0
===============================================================================
```

[C++ Standards Support in GCC](https://gcc.gnu.org/projects/cxx-status.html)

*Day02/code/dynamic_array_playground.cpp* compile using -std=c++20 parameter

#### Tests and perceptions in *Day02/code/dynamic_array_playground.cpp*

1. Por que o ultimo valor volta zero?
2. Por que dois operators = e dois métodos data() ?


### Node Based Stack (baseada em ponteiro)

[Em 02:50:00](https://youtu.be/8v-wjXiBpJE)

*Day02/code/node_based_stack.hpp*

```
./node_based_stack.o 
int: push an item, -: pop an item, ?: display top of stack, !: display info
      std::stack<int> size:     1000
node_based_stack<int> size:     1000
      std::stack<int> size:  1000000
      std::stack<int> size:    10000
      std::stack<int> size:    10000
      std::stack<int> size:     1000
      std::stack<int> size:   100000
      std::stack<int> size:   100000
      std::stack<int> size:  1000000
node_based_stack<int> size:    10000
node_based_stack<int> size:    10000
node_based_stack<int> size:   100000
node_based_stack<int> size:     1000
node_based_stack<int> size:  1000000
node_based_stack<int> size:   100000
node_based_stack<int> size:  1000000
node_based_stack:
===============================================================================
   Name (baseline is *)   |   Dim   |  Total ms |  ns/op  |Baseline| Ops/second
===============================================================================
    bench_nb_stack_push * |    1000 |     0.045 |      45 |      - | 22054607.2
     bench_std_stack_push |    1000 |     0.008 |       7 |  0.171 |129032258.1
    bench_nb_stack_push * |   10000 |     0.651 |      65 |      - | 15361525.8
     bench_std_stack_push |   10000 |     0.075 |       7 |  0.115 |133996167.7
    bench_nb_stack_push * |  100000 |     1.418 |      14 |      - | 70508535.8
     bench_std_stack_push |  100000 |     1.220 |      12 |  0.860 | 81965735.0
    bench_nb_stack_push * | 1000000 |    16.574 |      16 |      - | 60334238.4
     bench_std_stack_push | 1000000 |    14.623 |      14 |  0.882 | 68384817.0
===============================================================================
```

### Linear Search

Equivalente ao find do STL

[Em 02:57:57](https://youtu.be/8v-wjXiBpJE)

*Day02/code/linear_search.hpp*

```
./linear_search.o 
collection size: 10
string: find an item, ?: display collection, !: display info
?
RAVZS HFKOD EOOUX LYBJS DRJSO MRCZX VOKOL LJMED FRPNU AHMRR 
DRJSO
found at 4
!
    size: 10
capacity: 16
   delta: 6
fst addr: 0x55ebc1445b10
linear_search:
===============================================================================
   Name (baseline is *)   |   Dim   |  Total ms |  ns/op  |Baseline| Ops/second
===============================================================================
 bench_dynarr_add_lsrch * |    1000 |     0.038 |      38 |      - | 26028787.8
       bench_vec_pb_lsrch |    1000 |     0.023 |      22 |  0.586 | 44383294.1
    bench_dynarr_add_find |    1000 |     0.036 |      36 |  0.942 | 27634997.0
        bench_vec_pb_find |    1000 |     0.024 |      23 |  0.617 | 42186972.7
 bench_dynarr_add_lsrch * |   10000 |     0.522 |      52 |      - | 19158446.1
       bench_vec_pb_lsrch |   10000 |     0.263 |      26 |  0.504 | 37990312.5
    bench_dynarr_add_find |   10000 |     0.452 |      45 |  0.866 | 22116798.8
        bench_vec_pb_find |   10000 |     0.231 |      23 |  0.443 | 43285358.7
 bench_dynarr_add_lsrch * |  100000 |     7.172 |      71 |      - | 13943362.9
       bench_vec_pb_lsrch |  100000 |     5.057 |      50 |  0.705 | 19774397.8
    bench_dynarr_add_find |  100000 |     6.992 |      69 |  0.975 | 14302748.9
        bench_vec_pb_find |  100000 |     4.632 |      46 |  0.646 | 21587497.0
 bench_dynarr_add_lsrch * | 1000000 |    63.629 |      63 |      - | 15716077.4
       bench_vec_pb_lsrch | 1000000 |    46.471 |      46 |  0.730 | 21518714.7
    bench_dynarr_add_find | 1000000 |    63.236 |      63 |  0.994 | 15813793.0
        bench_vec_pb_find | 1000000 |    45.559 |      45 |  0.716 | 21949662.0
===============================================================================
```
O iterator é capaz de desacoplar o container do algoritmo 





## Dia 3 - 29/05/2021

* Lista ligada supla
* Ponteiros
* Smart Pointers

## Aulas

* [Aula 1 (15/05)](https://youtu.be/HPkbz93krJc)
* [Aula 2 (22/05)](https://youtu.be/8v-wjXiBpJE)