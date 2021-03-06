﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿﻿
## ﻿﻿**二、测试样例及结果**
#### **测试样例1**
该测试样例使用了助教提供的文档中样例，对这个测试样例进行测试可以简单检测程序是否能够正确地执行简单的样例，对test1.txt进行的操作及结果如下：

![test_1_1](https://github.com/yipinliu/WordLists/raw/master/doc/test_1_1.png?raw=true)

上图为在Windows Powershell下的运行结果，通过命令行使用-w参数加文件名的形式计算了最多单词数量的英语单词链。在得到Job done的结果提示后用户可以选择是否将存储到文件中，当确认要存入时，会要求用户提供一个文件名用以创建文件并存储。得到的结果在上图中名为solution.txt的文本文件中显示。
 
注1：-f参数的使用取决于用户是否要从文本文件中读取单词，若在命令行中以字符串的形式输入则不需要，不使用-f参数的结果如下图：

![test_1_2](https://github.com/yipinliu/WordLists/raw/master/doc/test_1_2.png?raw=true) 

该输入未使用-f参数，从而程序将输入的路径识别为字符串输入从而得到结果。


注2：为方便展示程序运行结果，以下测试结果将不再存入文件中，而是在命令行中直接输出。

![test_1_3](https://github.com/yipinliu/WordLists/raw/master/doc/test_1_3.png?raw=true)

上图为程序在命令行下执行-w参数的运行结果，数字4为单词链的单词数，后接搜索到的单词链。


![test_1_4](https://github.com/yipinliu/WordLists/raw/master/doc/test_1_4.png?raw=true)

上图为程序在命令行下执行-c参数的运行结果，数字34为搜到的字母最多的单词链的字母数，后接搜索到的单词链。


![test_1_5](https://github.com/yipinliu/WordLists/raw/master/doc/test_1_5.png?raw=true)

上图为程序在命令行下执行-t参数的运行结果，其中第二个字母t表示指定的尾字母为t的单词链，数字3为单词链的单词数，后接搜索到的单词链。


![test_1_6](https://github.com/yipinliu/WordLists/raw/master/doc/test_1_6.png?raw=true)

上图为程序在命令行下执行-h参数的运行结果，其中第二个字母e表示指定的首字母为t的单词链，数字2为单词链的单词数，后接搜索到的单词链。


![test_1_7](https://github.com/yipinliu/WordLists/raw/master/doc/test_1_7.png?raw=true)

上图为程序在命令行下-t参数及-h参数结合使用的运行结果，其中第二个字母a表示指定的首字母为a的单词链，第四个字母e表示指定的尾字母为e的单词链，二者结合即要求单词链为的首尾字母分别为a、e的单词链，搜索成功则会弹出Job done提示，输出在命令行中时，数字2为单词链的单词数，后接搜索到的单词链。


![test_1_8](https://github.com/yipinliu/WordLists/raw/master/doc/test_1_8.png?raw=true)

对于指定单词链的单词个数，可以用-n参数来查询，如上图所示，利用-n和3两个参数，搜索了test_1.txt中满足单词个数为3的单词链，得到了两个结果，将其输出在命令行中即如上图所示。
  
至此，对于简单测试文件已经测试完毕，其结果和人工运算结果相比较是完全一致的，程序的正确性得到初步的肯定。

#### **测试样例2**：
该测试样例主要目的是测试程序对文本文件中的单词大小写是否敏感，该样例所对应的测试文档test_2.txt中存在某些单词不是完全由小写字母组成的，通过该样例可以测试程序是否能将这些字母大小写不统一的大小写字母统一化。

仿照测试样例1中的5种参数输入，得到的输出结果如下，其中-h参数及-t参数不再单独测试，而改以复合形式直接测试。

![test_2_1](https://github.com/yipinliu/WordLists/raw/master/doc/test_2_1.png?raw=true)

使用-w参数查找单词数最多的单词链，得到的输出结果。


![test_2_2](https://github.com/yipinliu/WordLists/raw/master/doc/test_2_2.png?raw=true)

使用-c参数查找字母数最多的单词链，得到的输出结果。


![test_2_3](https://github.com/yipinliu/WordLists/raw/master/doc/test_2_3.png?raw=true)

复合使用-h及-t参数，查找首字母为e尾字母为r的单词链，得到的输出结果。


![test_2_4](https://github.com/yipinliu/WordLists/raw/master/doc/test_2_4.png?raw=true)

使用-n参数查找单词链长度为7的单词链，得到的输出结果。

通过以上参数测试，验证了程序具有将大小写字母统一化的功能。
#### **测试样例3：**
该测试样例主要目的是测试程序是否拥有对重复单词进行去重的功能，该样例所对应的测试文档test_3.txt中存在某些单词不仅仅只使用一次，通过该样例的测试，可以检验程序的去重功能。

![test_3_1](https://github.com/yipinliu/WordLists/raw/master/doc/test_3_1.png?raw=true)

上图为分别使用5种参数的运行结果。可以看到，无论使用哪个参数得到的单词链，均不存在重复使用某个单词的情况，从而检验了程序的去重功能。
#### **测试样例4：**
该测试样例所对应的测试文档为test_4.txt，但在指定目录下不存在名为test_4.txt的文档，故这个测试样例的设计目的是测试程序在对文件不存在/输入路径不正确/路径不合法时的给予用户的提示。

![test_4_1](https://github.com/yipinliu/WordLists/raw/master/doc/test_4_1.png?raw=true)

上图显示了当用户输入的文件不存在或输入路径不正确或路径不合法时程序的给予用户的反馈提示，此时无论使用何种参数，程序都会提示这是一个无效的输入，检验程序对该异常的处理功能。
#### **测试样例5：**
该测试样例所对应的测试文档为test_5.txt，该文档存在，但其中均为非字母符号，即文档存在但文档中无单词，设计该样例可以检验程序是否拥有对该种异常进行处理的功能。

![test_5_1](https://github.com/yipinliu/WordLists/raw/master/doc/test_5_1.png?raw=true)

由上图可以看到，当从输入路径读取到文件，但文件中不存在单词时，程序会返回no valid word!语句提示用户文件中没有有效的单词，与测试样例4进行比较，两种异常拥有两种不同的反应，检验了程序有对文件存在但无单词的情况进行反馈的功能。
#### **测试样例6：**
测试样例test_6.txt中存在单词，但这些单词都不能构成长度大于等于2的单词链，设计该样例的目的是检验程序是否有对文件存在且有单词但无单词链这一异常情况进行反馈的功能。

![test_6_1](https://github.com/yipinliu/WordLists/raw/master/doc/test_6_1.png?raw=true)

通过上图以及与测试样例5的比较，可以看到当文件存在且有单词但无单词链这种情况发生时，程序会正确运行，得到结果Job done，但无论使用何种参数，都搜索不到结果，均会向用户提示，没有查询到结果(result is not found)从而与测试样例5区分。
#### **测试样例7：**
测试样例test_7.txt中仅有3个单词，且这3个单词能够构成一个长度为3的单词链，该样例主要测试当用户使用-n参数搜索时指定数字大于最大单词链长度时程序如何反应。

![test_7_1](https://github.com/yipinliu/WordLists/raw/master/doc/test_7_1.png?raw=true)

通过比较，可以看到当用户指定的单词链长度过大，无法在文本中搜索到符合要求的单词链时，程序会向用户反馈查找不到结果(result is not found)。

#### **测试样例8：**
测试样例test_8.txt中有4个单词，这4个单词可以构成8个2长度的小环、2个3长度的中环以及1个4长度的大环，该样例的设计是为了验证程序所使用的算法能否处理对多环形成大环这一个特殊情况，并输出相对应的正确结果。

![test_8_1](https://github.com/yipinliu/WordLists/raw/master/doc/test_8_1.png?raw=true)

当使用-w以及-c参数进行查找时，环状结构对结果无影响。

![test_8_2](https://github.com/yipinliu/WordLists/raw/master/doc/test_8_2.png?raw=true)

同样地，使用-n参数查询固定长度的单词链时也能输出正确的结果，通过这个例子验证了环状结构对于程序的正确运行无影响，即程序拥有对该特殊情况进行处理的功能。

#### **测试样例9：**
测试样例2以及测试样例3分别检验了程序对大小写是否敏感以及是否有去重功能，但未将两者结合考虑。测试样例test_9.txt包含了重复单词且重复单词是用大小写区分的，设计该样例是为了检验程序是否有应对综合两种情况的功能。

![test_9_1](https://github.com/yipinliu/WordLists/raw/master/doc/test_9_1.png?raw=true)

![test_9_2](https://github.com/yipinliu/WordLists/raw/master/doc/test_9_2.png?raw=true)

以上两图给出了在复杂情况下面对4种不同参数程序运行的结果，从输出结果可以看出程序可以同时处理大小写转化以及去重的情况。
#### **测试样例10：**
测试样例test_10.txt是一个包含有999个单词的数据集，设计该样例的目的是为了检验程序是否拥有对较大数据集进行处理的能力。

![test_10_1](https://github.com/yipinliu/WordLists/raw/master/doc/test_10_1.png?raw=true)

![test_10_2](https://github.com/yipinliu/WordLists/raw/master/doc/test_10_2.png?raw=true)

![test_10_3](https://github.com/yipinliu/WordLists/raw/master/doc/test_10_3.png?raw=true)

上述结果从程序开始执行到输出结果的过程均在秒级(2s内)完成，说明算法已经进行优化，程序的性能测试是达标的。

 注：-n参数因为测试样例数据过大，输出在命令行时不方便截取以及查看，如有需要可选择存入文件查看。
#### **测试样例11：**
测试样例11主要目的是验证程序能否提示用户正确的输入参数，从而执行相应的功能，即程序应拥有在用户输入错误时引导用户正确输入的功能。

![test_11_1](https://github.com/yipinliu/WordLists/raw/master/doc/test_11_1.png?raw=true)

上图中使用了一个-s的参数，但这个参数是程序无法识别的，所以程序返回了一个Error提示，这个提示包含的信息可以引导用户输入正确的参数。













































