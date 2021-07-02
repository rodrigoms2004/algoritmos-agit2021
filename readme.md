# Algoritmos Agit 2021

[Professor Fabio Galuppo](https://github.com/fabiogaluppo?tab=repositories)

https://www.agit.com.br/cursoalgoritmos.php

## Dia 1 - 15/05/2021

[Aula](https://youtu.be/HPkbz93krJc)

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

[Aula](https://youtu.be/8v-wjXiBpJE)

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

[Aula](https://youtu.be/COwItE-XCw4)



* Lista ligada dupla
* Ponteiros
* Smart Pointers

### Linear search - detalhes de implementação

[Em 00:00:00](https://youtu.be/COwItE-XCw4)

*Day03/code/linear_search.hpp*

### Lista ligada dupla

[Em 00:11:00](https://youtu.be/COwItE-XCw4)

*Day03/code/doubly_linked_list.hpp*

### Smart pointers

*Day03/code/smart_ptr.hpp*

*Day03/code/doubly_linked_list_alt.hpp*

* https://www.internalpointers.com/post/beginner-s-look-smart-pointers-modern-c
* https://en.cppreference.com/w/cpp/utility/move
* https://en.cppreference.com/w/cpp/thread/unique_lock/lock


### Local Buffer Optimization (LBO)

*Day03/code/dynamic_array_lbo.hpp*


https://en.cppreference.com/w/cpp/language/union


#### G++ 11 error

g++ --version
g++ (Ubuntu 11.1.0-1ubuntu1~18.04.1) 11.1.0
Copyright (C) 2021 Free Software Foundation, Inc.

```
$ g++ -O3 dynamic_array_lbo.t.cpp dynamic_array_lbo.cpp -o dynamic_array_lbo.o

 g++ -O3 dynamic_array_lbo.t.cpp dynamic_array_lbo.cpp -o dynamic_array_lbo.o
In file included from dynamic_array_lbo.t.cpp:6:
dynamic_array_lbo.hpp: In member function ‘void dynamic_array_lbo::dynamic_array<T>::move(dynamic_array_lbo::dynamic_array<T>&&)’:
dynamic_array_lbo.hpp:302:32: error: invalid use of incomplete type ‘class dynamic_array_lbo::dynamic_array<T>’
  302 |                 dynamic_array::~dynamic_array();
      |                                ^~~~~~~~~~~~~~
dynamic_array_lbo.hpp:62:11: note: declaration of ‘class dynamic_array_lbo::dynamic_array<T>’
   62 |     class dynamic_array final
      |           ^~~~~~~~~~~~~
```


#### G++ 9 works!

g++-9 --version
g++-9 (Ubuntu 9.2.1-17ubuntu1~18.04.1) 9.2.1 20191102
Copyright (C) 2019 Free Software Foundation, Inc.

```
g++-9 -O3 dynamic_array_lbo.t.cpp dynamic_array_lbo.cpp -o dynamic_array_lbo.o
```


### Regular types

STL

### Recursão

*Day03/code/lucas_numbers_memoization.t.cpp*

Caso base e chamada da função


## Dia 4 - 12/06/2021

[Aula](https://www.youtube.com/watch?v=a0Ytw3bSB6s)

### Memorization

[Em 00:00:00](https://www.youtube.com/watch?v=a0Ytw3bSB6s)

### Programação Dinãmica

*Day04/code/water_recipient_filling_dp.t.cpp*

[Em 00:07:20](https://www.youtube.com/watch?v=a0Ytw3bSB6s)

### Merging

*Day04/code/merging.hpp*

[Em 00:53:10](https://www.youtube.com/watch?v=a0Ytw3bSB6s)

std::copy()

* merge_copy --> std::merge

### Inplace Merge

*Day04/code/merging.hpp*

Evita cópia (buffer extra)

[Em 01:33:25](https://www.youtube.com/watch?v=a0Ytw3bSB6s)

std::rotate() usa rotate left

* inplace_merge --> std::inplace_merge

### Mergesort - Dividir para conquistar (pode ser usado para paralelismo)

*Day04/code/sorting_mergesort.hpp*

Ordenação, estável, se ordenar por dois critérios, mantém a ordenação do primeiro critério, diferente quicksort
ideal fazer primeira ordenação com quicksort e a segunda com o mergesort

[Em 01:57:20](https://www.youtube.com/watch?v=a0Ytw3bSB6s)

* mergesort --> std:stable_sort()

[std::stable_sort](https://en.cppreference.com/w/cpp/algorithm/stable_sort)

### Binary search

*Day04/code/binary_search.hpp*

[Em 02:20:54](https://www.youtube.com/watch?v=a0Ytw3bSB6s)

[std::midpoint C++20](https://en.cppreference.com/w/cpp/numeric/midpoint)


* binary_search_leftmost --> std::lower_bound
* binary_search_rightmost --> std::upper_bound

#### STL 

* [std::lower_bound](https://en.cppreference.com/w/cpp/algorithm/lower_bound)
* [std::upper_bound](https://en.cppreference.com/w/cpp/algorithm/upper_bound)
* [std::binary_search](https://en.cppreference.com/w/cpp/algorithm/binary_search)

### Between

*Day04/code/binary_search.hpp*

[Em 03:03:28](https://www.youtube.com/watch?v=a0Ytw3bSB6s)

### Iterators

[Em 03:08:25](https://www.youtube.com/watch?v=a0Ytw3bSB6s)


* Generalização de ponteiro
* Um objeto que aponta para algum elemento num container, array ou sequencia
* Um par de iterators representa um intervalo fechado-aberto [begin, end]

#### 5 categorias

1. InputIterator, leitura
2. OutputIterator, escrita
3. ForwardIterator, incrementa o iterator, itera para frente
4. BidirectionalIterator, incrementa/ decrementa o iterator, itera para frente e para trás
5. RandomAccessIterator, faz tudo e tem acesso ao índice

*um ponteiro tem todos os requisitos de um RandomAccessIterator*

* [Iterator](https://www.cplusplus.com/reference/iterator/)


### String Utilities

*Day04/code/string_utilities.hpp*

#### Usar GCC 9

```
g++-9 -O3 string_utilities.t.cpp string_utilities.cpp -o string_utilities.o
```

[std::string](http://www.cplusplus.com/reference/string/string/)

[Em 03:31:00](https://www.youtube.com/watch?v=a0Ytw3bSB6s)

### is_sorted and iota_helper

*Day05/code/is_sorted.cpp*

[Em 03:44:35](https://www.youtube.com/watch?v=a0Ytw3bSB6s)

```
Input: 2 4 4 4 4 4 5 5 5 5 5 5 6 6 6 6 6 7 7 7 8 8 9 9 9 
Is sorted ascending: true

Input: 5 5 1 4 2 4 9 1 5 2 3 2 2 7 6 6 7 5 2 5 8 5 1 8 8 
Is sorted ascending: false

Input: 9 9 9 8 8 7 7 7 6 6 6 6 6 5 5 5 5 5 5 4 4 4 4 4 2 
Is sorted descending: true

Input: 9 9 9 8 8 7 7 7 6 6 6 6 6 5 5 5 5 5 5 4 4 4 4 4 2 
Is sorted descending: true
```

#### IOTA

[std::iota](http://www.cplusplus.com/reference/numeric/iota/)

*Day04/code/iota_helper.hpp*

```
10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 
20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 
10 12 14 16 18 20 22 24 26 28 30 32 34 36 38 40 42 44 46 48 50 52 54 56 58 
20 23 26 29 32 35 38 41 44 47 50 53 56 59 62 65 68 71 74 77 80 83 86 89 92 
14 11 57 58 42 88 31 36 69 58 14 17 26 79 51 57 94 33 61 90 62 72 90 25 65 
24 22 56 57 46 80 37 41 66 57 24 27 33 73 52 57 84 39 60 82 60 68 81 33 62
```



## Dia 5 - 19/06/2021 - Heap, Priority Queue

[Aula](https://www.youtube.com/watch?v=LMaPhryqs2U)


### Particionamento

*Day05/code/partitioning.hpp*

[Em 00:00:00](https://www.youtube.com/watch?v=LMaPhryqs2U)

std::partition

### Insert sort

*Day05/code/sorting_insertsort.hpp*

### Quick sort

*Day05/code/sorting_quicksort.hpp*

### Stanility in sorting

*Day05/code/stability_in_sorting.t.cpp*

### Heap

*Day05/code/sorting_heapsort.hpp*

*Day05/code/unbounded_heap.hpp*

## Dia 6 - 26/06/2021 - Algoritmos 

### Analise de algoritmos

*Day06/code/benchmarking_algorithms.t.cpp*


*Day06/code/estimated_running_time.t.cpp*

### Hashtables

### Pilhas e Filas


### Ring Buffer


### Stack an queue STL

## Aulas

* [Aula 1 (15/05)](https://youtu.be/HPkbz93krJc)
* [Aula 2 (22/05)](https://youtu.be/8v-wjXiBpJE)
* [Aula 3 (29/05)](https://youtu.be/COwItE-XCw4)
* [Aula 4 (12/06)](https://www.youtube.com/watch?v=a0Ytw3bSB6s)
* [Aula 5 (19/06)](https://www.youtube.com/watch?v=LMaPhryqs2U)
* [Aula 6 (26/06)](https://youtu.be/hxacEYNh7Jo)
