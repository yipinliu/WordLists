# Lab1-3说明文档

[TOC]

## 异常处理

### 一、预处理中的异常



### 二、接口中的异常

**1、指定的首尾字符串不是英文字母**

**检测函数：**

```c++
char check_char(char c){
    try
    {
        if(c >= 'A' && c <= 'Z'){
            return c - 'A' + 'a';
        }
        else if(!(c >= 'a' && c <= 'z') && c != 0){
            throw HEADORTAIL_ILLEGAL;
        }
        else
            return c;
    }
    catch(int err)
    {
        error_handler(err);
    }
	return c;
}
```

这一函数会检测指定的首尾字符串是否是字母，如果是字母会将其转化为小写并返回，如果不是字母则会触发异常处理函数。

**异常处理：**

因为首尾字符参数直接影响到了后续程序的执行，如果指定的不是字母，则直接抛出异常并终止程序执行。

**2、检测输入的参数len是否大于0**

**检测函数：**

```cpp
void check_len(int len){
    try
    {
        if(len <= 0)
            throw LEN_LESSTHANZERO;
    }
    catch(int err)
    {
        error_handler(err);
    }
}
```

这一函数会检测len是否大于0，如果小于等于0则会触发异常处理函数。

**异常处理：**

因为这一参数在我们的程序中作用不大，所以只会给出提示，不会终止程序执行。

**3、检测输入的参数number是否大于1**

**检测函数：**

```cpp
void check_number(int number, int len){
    try
    {
        if(number <= 1)
            throw NUMBER_LESSTHANONE;
        if(number > len)
            throw NUMBER_LARGERTHANLEN;
    }
    catch(int err)
    {
        error_handler(err);
    }
}
```

这一函数会检测指定的number是否大于1同时检测number与len的关系，如果number大于1或者number大于len则会触发异常处理函数。

**异常处理：**

如果异常是number小于等于1，因为这种异常会直接影响到后续程序的执行，所以直接终止程序。

如果异常是number大于len，因为len参数对于程序执行意义不大，所以只会给出提示，不会终止程序执行。

**4、检测调用的核心算法函数的返回值**

**检测函数：**

```cpp
void check_returnvalue(int returnvalue){
    try
    {
        if(returnvalue == -1)
            throw HEADORTAIL_ILLEGAL;
        if(returnvalue == -2)
            throw NOTFOUNDD;
        if(returnvalue == 0)
            throw UNKNOWNERROR;
    }
    catch(int err)
    {
        error_handler(err);
    }
}
```

核心算法函数的返回值如果小于等于0，则表示出现异常：返回-1代表输入的首尾字符串不合法，返回-2代表找不到符合要求的字符串。一般不会返回0，如果返回0则代表出现了超出预期的异常。

**异常处理：**

当检测到上述返回值时，代表核心的算法函数执行失败，这时会直接输出异常信息并且终止程序执行。

**5、检测mode参数的合法性**

**检测函数：**

```cpp
int check_mode(int mode, int mode_0, int mode_1){
    try
    {
        if(mode == 0)
            return mode_0;
        else if(mode == 1)
            return mode_1;
        else
            throw ILLEGAL_MODE;
    }
    catch(int err)
    {
        error_handler(err);
    }
}
```

因为gen_chain_char的返回值可能会有两种，一种是单词链的单词数，一种是单词链的字符数，所以需要调用者使用mode参数来指定，这一参数为0时表示返回单词数，为1时表示返回字符数，其余的输入均为非法，检测到非法输入时会抛出异常。

**异常处理：**

如果mode参数非法，会直接影响到函数的返回值，故会直接输出异常信息并且终止程序执行。

**6、异常处理函数**

```cpp
void error_handler(int err){
    switch(err){
        case HEADORTAIL_ILLEGAL:
            printf("ERROR:The head or tail character is illegal!\n");
            break;
        case NUMBER_LESSTHANONE:
            printf("ERROR:The specified number must be larger than 1.\n");
            break;
        case NOTFOUNDD:
            printf("ERROR:Unable to find the required word chain.\n");
            break;
        case LEN_LESSTHANZERO:
            printf("ERROR:Len must be larger than 0.\n");
            return;
            break;
        case NUMBER_LARGERTHANLEN:
            printf("ERROR:Number must be less than len.\n");
            return;
            break;
        case ILLEGAL_MODE:
            printf("ERROR:Illegal mode.\n");
            break;
        case UNKNOWNERROR:
            printf("ERROR:Unknown error happened.\n");
            break;
        default:
            return;
    }
    exit(0);

}
```

## 测试





