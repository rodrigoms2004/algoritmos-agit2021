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


https://linuxize.com/post/how-to-install-gcc-compiler-on-ubuntu-18-04/

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

Day02/code/raii.hpp


### Dynamic Array

Day02/code/dynamic_array.hpp

### Node Based Stack

Day02/code/node_based_stack.hpp

### Linear Search

Day02/code/linear_search.hpp