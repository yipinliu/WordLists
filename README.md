# WordLists

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

