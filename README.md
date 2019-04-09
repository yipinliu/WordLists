# WordLists

## Lab1-1

**1、Build**

```bash
1. mkdir build ; cd build
2. cmake ..
3. cmake --build . (编译环境需要支持C++11)
or make (in linux)
or msbuild WordLists.sln
4. src/WordLists params(in Unix-like)
or src/(Debug|Release)/WordLists params (Windows)
```

**2、GUI Usage**

①、直接使用现成编译好的可执行文件(在GUI/bin中)(由于`Qt`依赖的库有点多，所以这个步骤取消)

②、自行使用`Qt5.12`编译：

```bash
(在工程目录下)
1. mkdir build; cd build; cmake ..
2. cmake --build . --target install
(上面这两步主要是将src目录下的源文件拷贝到GUI工程中，如果自行拷贝(拷贝到GUI/WordListsGui/WordLists/)可忽略)
3. 使用qt打开`GUI/WordListsGui/WordListsGui.pro`文件
4. 编译运行
```

**3、Command Line Usage**

```bash
./WordList (-w/-c/-n NUM) [-h/-t CHAR] ("char"/-f path_to_the_file)
```

**4、OutPut Interpretation**

-w/-c: will display the length of the word chain and the content of the word chain(may be more than one)

-n: will display the number of word chain which meet the requirement and the content of the word chain

## Lab1-2

**接口文件目录：**

```
src/interface.cpp
```

**算法模块及接口测试文件目录：**

```
UniTest/interface_test_vs.cpp
UniTest/interface_test.cpp
```

**IO模块测试文件目录：**

```
UniTest/IO_test.cpp
```

## Lab1-3

**回归测试文件目录**：

```
测试文件：test/test1.txt
源文件：test/test.cpp
```

**预处理函数测试文件目录：**

```
Unitest/test_process_text.cpp
```

