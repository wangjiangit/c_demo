#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>
#include <errno.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <unistd.h> // unistd.h是 C 和 C++ 程序设计语言中提供对 POSIX 操作系统 API 的访问功能的头文件的名称
#include <fcntl.h> // fcntl.h，是unix标准中通用的头文件，其中包含的相关函数有 open，fcntl，shutdown，unlink，fclose等！
#include <assert.h>

void point1();

void point2();

void multiDimenArr();

void multiDimenArr2Test(int arr[][3]);

void multiDimenArr2();

void multiDimenArr2Point(int (*p)[3]);

char *monthName(int n);

void testFun1();

int max(int, int);

void printMax(int (*maxP)(int, int));

void structFunc();

void selfStructFunc();

void defTypeFunc();

void unionFunc();

void stdandInOut();

void formatOut();

void formatIn();

void average(int num, ...);

void fileAccessFunc();

void erropeFunc();

void lineOutInFunc();

void miscellaneousFunc();

void sysLevelFunc();

struct point makepoint(int, int);


struct point {
    int x;
    int y;
};

struct rect {
    struct point pt1;
    struct point pt2;
};


int main(int argc, char *argv[]) {

    //point1();
    //point2();
    // point3();
    // multiDimenArr();
    // multiDimenArr2();
    // printf("This is %s Month",monthName(2));
    //testFun1(); //测试strrchr函数

    /* if (strrchr("abc", 'd') != NULL) {
         printf("not null");
     } else {
         printf("NULL");
     }*/

    /*int (*maxP)(int,int); //申明一个指向函数的指针
    maxP=&max; //或 maxP=max 可省略&;
    printf("num is %d",(*maxP)(3,5)); //或maxP(3,5)这样调用*/

    // printMax(max);  //指向函数的指针作为参数

    // structFunc(); //结构定义


    /**
     * 传递结构的3种方法:
     * 1.传递各个结构成员
     * 2.传递整个结构
     * 3.传递指向结构的指针
    struct rect screen;
    struct point middle;
    screen.pt1=makepoint(0,0);
    screen.pt2=makepoint(8,8);
    middle=makepoint((screen.pt1.x+screen.pt2.x)/2,(screen.pt1.y+screen.pt2.y)/2);
    printf("middle.x is %d ,middle.y is %d",middle.x,middle.y);*/

    /**
     * 指向结构的指针
       struct point pt,*p;
        p=&pt;
        pt.x=5;
       // printf("(*p).x is %d",(*p).x);
        printf("p->x  is %d",p->x);
     */

    // structArr(); //结构数组

    //  selfStructFunc();  //自引用结构

    //defTypeFunc();
    // unionFunc(); //联合体
    // bitFieldFunc(); //位域
    //stdandInOut();//标准输入和输出
    //formatOut(); //格式化输出
    // average(3,1,2,3); 函数的变长参数
    // formatIn();
    // fileAccessFunc();

    //erropeFunc();

    /* char *str;
   // fgets(str,20,stdin);
    gets(str);
    printf("this is %s",str);*/

    //lineOutInFunc(); 行输入和输出函数

    // miscellaneousFunc();

    sysLevelFunc();

    return 0; //main 函数中return 0相当于exit(0)  如：exit(EXIT_SUCCESS);
}


void point1() {
    char string1[] = "ABCD"; // 字符数组
    char *string2 = "efgh"; // 字符指针
    char **p;  //地址的地址
    char *string3[] = {  //指针数组
            "1234",
            "ddd",
            "ccc"
    };
    printf("string1 is %s\n", string1);
    printf("string2 is %s\n", string2);
    p = string3;
    for (int i = 0; i < 3; i++) {
        printf("string3 is %s\n", *(p++));
    }

}

void point2() {

    int x = 9;
    int *xp; // 指向整型的指针
    int **xpp; // 指向整型的指针的指针

    xp = &x;
    xpp = &xp; //指向指针的指针
    printf("x is %d", **xpp);
}


void point3() {

    enum DAY {  // 枚举类型
        mon = 1, tue, wed, thu, fri, sat, sun
    };

    enum DAY day;
    day = wed;

    printf("今天是星期%d", thu);
}


void multiDimenArr() { //测试多维数组

    /* int arr[2][3]={
             {1,2,3},
             {4,5,6}
     };
 */
    int arr[2][3] = {1, 2, 3, 4, 5, 6};

    for (int i = 0; i < 2; i++) {
        for (int y = 0; y < 3; y++) {
            printf("arr[%d][%d] is %d", i, y, arr[i][y]);
        }
    }
}


void multiDimenArr2() { //测试多维数组

    int arr[2][3] = {
            {1, 2, 3},
            {4, 5, 6}
    };

    multiDimenArr2Test(arr);
    multiDimenArr2Point(arr);
}


void multiDimenArr2Test(int arr[][3]) {

    for (int i = 0; i < 2; i++) {
        for (int y = 0; y < 3; y++) {
            printf("arr[%d][%d] is %d\n", i, y, arr[i][y]);
        }

    }
}


void multiDimenArr2Point(int (*p)[3]) { // p是个指针，它指向具有3个整型元素的数组。

    for (int i = 0; i < 2; i++) {
        for (int y = 0; y < 3; y++) {
            printf("arr[%d][%d] = %d\n", i, y, p[i][y]);
        }
    }


}


char *monthName(int n) {  //指针数组初始化

    static char *name[] = { // 指向字符指针数组
            "January",
            "February",
            "March",
            "April",
            "May",
            "June",
            "July",
            "August",
            "Septemper",
            "October",
            "November",
            "December"
    };

    return name[n];
}

void testFun1() {
    const char *message = "abcedfg123abced";
    const char *str = NULL;
    str = strrchr(message, 'c');
    printf("this is %s", str);
}

int max(int x, int y) {

    return x > y ? x : y;
}

void printMax(int (*maxP)(int x, int)) {  //指向函数的指针作为形参
    int x = 5;
    int y = 6;
    printf("this is  %d", (*maxP)(5, 6));
}


void structFunc() {  // 结构体

    struct point {
        int x;
        int y;
    };

    struct point pt = {1, 2};
    pt.x = 4;
    pt.y = 6;


    struct rect {
        struct point pt1;
        struct point pt2;
    };

    struct rect screen = {{5, 6},
                          {7, 8}};


    printf("struct point x is %d,y is %d \n", pt.x, pt.y);

    printf("struct screen pt1.x is %d,pt2.x is %d", screen.pt1.x, screen.pt2.x);


}


struct point makepoint(int x, int y) { // 函数返回结构体

    struct point temp;
    temp.x = x;
    temp.y = y;

    return temp;
}


void structArr() {
    //结构数组
    struct key {
        char *word;
        int count;
    } keyVal[] = {
            {"one",   1},
            {"two",   2},
            {"three", 3}
    };

    //或这样声明
    //  struct key keyVal[] = {{"one",   1}, {"two",   2},{"three", 3}};


    for (int i = 0; i < sizeof(keyVal) / sizeof(struct key); i++) {

        printf("keyval is %s ----- %d \n", (keyVal[i]).word, (keyVal[i]).count);
    }


}


void selfStructFunc() {
    /**
     * 自引用结构，一个包含其自身实例的结构是非法的，但可以包含指向自身的指针
     * 如下所示：
     */
    struct A {
        int x;
        int y;
        struct A *Ap;
    };

    struct A *p;
    // struct A cc={5,6,NULL};
    struct A AInstance = {3, 4, p};


    printf("this is %d", AInstance.x);

}


void defTypeFunc() { // typedef 语句

    typedef char *String;

    String string = "typedef is very good \n";

    printf("%s", string);

    size_t c = 55;

    printf("size_t is %u", c);

}


void unionFunc() {  // union联合体

    union Data {
        int i;
        float f;
        char str[20];
    };

    union Data data;
    printf("this is %d", sizeof(data)); // union中可以定义多个成员，union的大小由最大的成员的大小决定；

    /*----------有错误，每次只能用到一个类型START---------*/
    data.i = 30;
    data.f = 1.2;
    strcpy(data.str, "abcefg");

    printf("data.i is %d \n", data.i);
    printf("data.f is %f \n", data.f);
    printf("data.str is %c \n", data.str);
    /*----------有错误，每次只能用到一个类型END---------*/



    /*----------正确的写法，每次只能用到一个类型START---------*/
    data.i = 30;
    printf("data.i is %d \n", data.i);

    data.f = 1.2;
    printf("data.f is %f \n", data.f);

    strcpy(data.str, "abcefg");

    printf("data.str is %s \n", data.str);
    /*----------正确的写法，每次只能用到一个类型END---------*/

    //每次调用联合体（共用体），只有一种类型生效，也就是同一个时刻，使用相同的位置，存储联合体中的一种类型的值


}

void bitFieldFunc() { // 位域，主要针对一些场景，为了节省内存

    //例如：它是否是关键词，它是否是外部的且是静态的，等等，对这些信息编码的最简介的方法是使用一个char或int对象中的位标志集合

    struct {
        unsigned int widthValidated;
        unsigned int heightValidated;
    } struct1;

    struct {
        unsigned int widthValidated:4; //4是位的宽度
        unsigned int heightValidated:1;
    } struct2;

    printf("this is%d", sizeof struct1);
    printf("this is%d", sizeof struct2);

    struct2.widthValidated = 7;
    struct2.heightValidated = 7; //超过了位的宽度
    printf("this is%d", struct2.widthValidated);
    printf("this is%d", struct2.widthValidated); //超过了位的宽度,显示出错
}


void stdandInOut() { // 标准输入和标准输出


    int c;
    while ((c = getchar()) != EOF) {
        putchar(tolower(c));
    }
}

void formatOut() { // 格式化输出

    printf("this is %-8.2ld\n", 70000);
    printf("this hex is %X\n", 15);
    printf("this octal is %o\n", 9);
    printf("this is :%-12.*s:", 3, "hello,world"); //宽度和精度可以用星号*表示,其值通过转换下一个参数获得

    const char *str;
    sprintf(str, "the dight is%d,the alpha is %c", 3, 'A');  //sprintf 将格式化字符串存入str中
    printf("this is %s", str);
}


void average(int num, ...)  // 变长参数
{
    va_list valist;
    double sum = 0.0;
    int i;
    va_start(valist, num);

    for (i = 0; i < num; i++) {
        sum += va_arg(valist, int);
    }
    /* 清理为 valist 保留的内存 */
    va_end(valist);
    printf("the average is %.2f", sum / num);

}


void formatIn() { // 格式化输入
    /* double sum,v;
     sum=0;
     while(scanf("%lf",&v)==1)
         printf("\t%.2f\n",sum+=v);*/

    //24 Dec 1988
    /*int day,year;
    char month[20];
    scanf("%d %s %d",&day,month,&year);
    printf("this is %d,this is %s,this is%d",day,month,year);*/

    // 28/04/2018
    int day, month, year;
    scanf("%d/%d/%d", &month, &day, &year);

    // 28/06/2018
    int oDay, oMonth, oYear;
    sscanf("28/06/2018", "%d/%d/%d", &oDay, &oMonth, &oYear);
    printf("the oYear is %d", oYear);

}


void fileAccessFunc() { // 文件访问
    FILE *fp;
    int c;
    fp = fopen("./a.txt", "w");
    c = putc('c', fp);

    if (c == EOF) {
        printf("error");
    } else {
        printf("success");   //fseek 提供文件定位功能
    }
}

void filecopy(FILE *ifp, FILE *ofp) {
    int c;
    while ((c = getc(ifp)) != EOF) {
        putc(c, ofp);
    }
}

/*
//文件访问2
void fileAccessFunc2()
{
    void filecopy(FILE *ifp, FILE *ofp);
    FILE *fp;
    if (argc == 1)
        filecopy(stdin, stdout);
    else
        while (--argc > 0)
            if ((fp=fopen(*++argv,"r"))==NULL) {
                printf("cat:can't open %s\n",*argv);
                return 1;
            } else {
                filecopy(fp,stdout);
                fclose(fp);
                return 0;
            }
}
*/

void erropeFunc() // 错误处理
{
    /*FILE *fp;
    int errnum;
    fp=fopen("noexist.txt","r");
    if(fp==NULL){
        errnum=errno;
        fprintf(stderr,"错误号：%d\n",errno);
        perror("通过perror输出错误");
        fprintf(stderr,"打开文件错误：%s\n",strerror(errnum));
    }else{
        fclose(fp);
    }*/
    FILE * pf;
    int errnum;
    pf = fopen ("unexist.txt", "rb");
    if (pf == NULL)
    {
        errnum = errno;
        fprintf(stderr, "错误号: %d\n", errno);
        perror("通过 perror 输出错误");
        fprintf(stderr, "打开文件错误: %s\n", strerror( errno ));
    }
    else
    {
        fclose (pf);
    }
}

void lineOutInFunc()
{
    char* words;

  /*  puts("Enter a string, please.");
    gets(words);  // typical use
    printf("Your string twice:\n");
    printf("%s\n", words);
    puts(words);
    puts("Done.");*/
    /**
     * feof判断文件结束是通过读取函数fread/fscanf等返回错误来识别的，故而判断文件是否结束应该是在读取函数之后进行判断。比如，在while循环读取一个文件时，如果是在读取函数之前进行判断，则如果文件最后一行是空白行，可能会造成内存错误。
     */
    FILE *f;
    f=fopen("./test.test","r");
    fgets(words,256,f);
    while(!feof(f)){
        printf("%s",words);
        fgets(words,256,f);
    }
    fclose(f);

   /* char line[256];
    FILE *f = fopen("test.test", "rb");
    while (!feof(f)) {
        fgets(line, sizeof(line), f);
        printf("-%s", line);
    }
    fclose(f);*/

    //fputs("hellow",f);
   // fgets()
}

// 其他函数
void miscellaneousFunc()
{

    //常用字符串操作函数,定义在<string.h>
   // char p[]="中国";
   // strncat(p," 牛world",4);
   // printf("this is %s",p);
   // printf("this is %d",strcmp("abc中天","abc中国"));
   // printf("this is %s",strchr("abcd中ef",'中'));
    //字符串操作函数
    //1.strcat 2.strncat 3.strcmp 4.strncmp 5.strcpy 6.strncpy 7.strlen 8.strchr 9.strrchr

    //字符类别测试和转换函数,定义在<ctype.h>
    //1.isalpha 2.isupper 3.islower 4.isdigit 5.isalnum 6.isspace 7.toupper 8.tolower
    //printf("isalpha is %d",isdigit('2'));

    //ungetc 函数：int ungetc(int c,FILE *fp)
    //该函数将字符c写回到文件fp中，如果执行成功，则返回c,否则返回EOF

    //命令执行函数 定义在<stdlib.h>
    //system("date");  //其返回值，在unix系统中，返回状态是exit的返回值

    //存储管理函数
    // 1. void *malloc(size_t n); 当分配成功，返回一个指针，该指针指向n字节长度的未初始化的存储空间,否在返回NULL
    // 2. void *calloc(size_t n,size_t n);当分配成功时，它返回一个指针，该指针指向的空闲空间足以容纳由n个指定长度的对象组成
    // 的数组，否则返回NULL
    // 3.free

   /* int *ip;
    ip = (int *) calloc(n, sizeof(int));*/


    //数学函数,定义在头文件<math.h>
    //sin(x) x的正弦函数，其中x用弧度表示
    //cos(x) x的余弦函数，其中x用弧度表示
    // atan(y,x) y/x反正切函数，其中x,y用弧度表示
    //exp(x) 指数函数
    // log10
    // log(x)
    // pow(x,y)
    // sqrt(x)
    // fabs(x)
   //printf("this is %.2f",fabs(-4));


    //随机数发生器函数
    /*for(int i=0;i<10;i++){
        printf("%d ",rand()%10);
    }

    srand(8);
    for (int i=0; i<10; i++)
    {
        printf("%d ", rand()%10);
    }
    srand(time(NULL));
    printf("this is %f",rand()/(double)RAND_MAX);*/

    /*time_t  time1;
    time1=time(NULL);
    printf("自 1970-01-01 起的小时数 = %ld\n", time1/3600);*/

}


// UNIX系统级别接口函数
void sysLevelFunc()
{
    // 低级I/O --read 和 write函数
    // int nRead=read(int fd, char *buf,int n);
        //fd： 文件描述符 buf：存放读写数据的字符数组 n:要传输的字节数
    // int nWrite=read(int fd, char *buf,int n);

   /* char buf[20];
    int n;
    while((n=read(0,buf,20)) >0)
        write(1,buf,n);*/


   /* char c;
    return (read(0,&c,1)==1)?(unsigned char)c: EOF;
    */


   // open 、creat  、close 、 unlink
   // 除了默认的标准输入、标准输出和标准错误文件外，其他文件都必须在读或写之前显式地打开。系统调用open和creat用于实现功能

   /* char buf[20];
   int fd=open("./a.txt",O_RDONLY,0);
   read(fd,buf,12);
   printf("this is %s",buf);
    close(fd)
    */


   /*char buf[]="hello world中";
   int fd=creat("./test2.txt",0666);
   int nInt=write(fd,buf,sizeof(buf));
   printf("actal write length is %d",nInt);
   close(fd);   // close函数：用来断开文件描述符和已打开文件之间的连接，并释放此文件描述符，以供其它文件使用
    */
/*  uint nInt1 = unlink("./test2.txt");  //返回值：成功则返回0, 失败返回-1, 错误原因存于errno
    printf("this is %u",nInt1);*/

    // long lseek(int fd,long offset,int origin); // 可以在文件中任意移动位置而不实际读写任何数据
    // origin 0 , 1 , 2 分别用于指定offset从文件开始、从当前位置、或从文件结束处开始算起


    /*
     char *bufs;
     int fd=open("./a.txt",O_RDONLY,0777);
     if(lseek(fd,0L,SEEK_SET)>=0){
         int c=read(fd,bufs,6);
         fprintf(stderr,"错误号：%d\n",errno);
        // perror("通过perror输出错误");
         printf("this string is %s",bufs);
         close(fd);
         return c;
     }else{
         close(fd);
         return -1;
     }*/

    // 通常情况下，美国和西欧国家使用的字符集可以使用char类型进行编码，增加wchar_t的主要目的是为了表示亚洲语言


    /* wchar_t x=L'中';
    // wchat_t x=L"中国好"; // 宽字符字符串字面值
    printf("this is %s",x); */


    // 注意点-----------------START------------------------------

    /*指针比较只对相同对象才有意义：如果两个指针指向同一个简单对象，则相等；如果指针指向同一个结构的不同成员，则指向结构中
      后申明的成员的指针较大；如果指针指向同一个联合的不同成员，则相等；如果指针指向一个数组的不同成员，则他们之间的比较对应于
      下标之间的比较。如果指针指向数组的最后一个成员，尽管P+1已指向数组的界外，但P+1任然比P大*/


    /*位移运算符：
     如果右操作数为负数或大于等于左操作数类型的位数，则结果没有定义
     E1<<E2  结果为E1*2的E2次方
     E1>>E2  结果为E1/2的E2次方
     */

    /*
      按位与,按位或按位异或运算符，仅适用于整形操作数
     */

    /**
     * 逗号表达式，求值次序为从左到右，并且左表达式的值被丢弃
     */
    /*int c;
    c=(1,3);
    printf("this is %d",c);*/


    /**
     * 存储类说明符
     * auto :默认
     * register：该对象不能对它应用一元运算符&
     * static：静态存储类，可以在函数内部或外部使用
     * extern:被声明的对象的存储存储空间定义在其他地方
     * typedef: 定义类型别名
     */

    /**
     * 类型说明符
     * void
     * char
     * short
     * int
     * long
     * float
     * double
     * signed
     * unsigned
     * 类型限定符
     * const :声明可以存放在只读存储器中的对象
     * volatile：用于强制某个实现屏蔽可能的优化
     */

    /**
     * 结构：
     * 结构成员的地址按照它们声明的顺序递增，
     * 联合:
     * 联合可以被看做结构，其所有成员起始偏移量都为0，其大小足以容纳任何成员。任一时刻它最多只能存储其中的一个成员。
     *
     * 如果指向某一个结构的指针被强制转换为指向该结构第一个成员的指针类型，则结果将指向该结构的第一个成员。
     * 如果指向某一个联合的指针被强制转换为指向该联合的一个成员的指针类型，则结果将指向该成员
     * 如下结构是合法的
     * union {
           struct {
               int type;
           } n;
           struct {
               int type;
               int intnode;
           } ni;
           struct {
               int type;
               float floatnode;
           } nf;
        } u;

        u.nf.type=FLAOT;
        u.nf.floatnode=3.14
     */

    /**
     * 枚举类型
     * 枚举符表中的标识符声明为int类型的产量，如果其中不包含有=的枚举符，则相应常量值从0开始，且枚举产量值从左到右依次递增1
     */


    // 注意点-----------------END--------------------------------


    //--------------------标准库(START)-----------------------------

    /**
     * ANSI 标准定义的函数库。
     * 标准库不是C语言本身的构成部分，但是支持标准C的实现会提供函数库的函数声明、类型及其宏定义
     *
     * <assert.h> 诊断
     * <stdio.h> 输入和输出
     * <ctype.h> 字符类别测试
     * <string.h> 字符串处理函数
     * <math.h> 数学函数
     * <stdlib> 实用工具函数
     * <stdarg.h> 可变参数表
     * <setjump.h> 非局部跳转
     * <signal.h> 信号处理
     * <time.h> 日期和时间
     * <limits.h> 和 <float.h> 与具体实现相关的限制
     *
     *
     * ----输入与输出<stdio.h>----
     * //stdin stdout 和 stderr 这三个流处于打开状态
     *
     * // 文件操作
     * FILE *fopen(const char *filename,const char *mode); 如果打开失败返回null
     *
     * FILE *freopen(const char *filename,const char *mode,FILE *stream); // 如出错返回NULL
     *
     * int fflush(FILE *stream)  // 如在写的过程中发生错误，则返回EOF ,否则0
     *
     * int fclose(FILE *stream) // 关闭流，如出错则返回EOF ，否则返回0
     *
     * int remove(const char *filename) //如果删除失败，则返回非0值
     *
     * int rename(const char *oldname,const char *newname) //失败返回一个非0值
     *
     * FILE *tmpfile(void)   // 以"wb+"创建一个临时文件，该文件在关闭或程序正常结束时将被自动删除，如创建成功返回一个流，失败返回NULL
     *
     * char *tmpnam(char s[L_tmpnam]) // 创建一个与现有文件名不同的字符串，并返回一个指向一内部静态数组的指针。把创建的字符串保存在数组s中，并将它作为函数值返回。
     *
     * int setvbuf(FILE *stream,char *buf,int mode,size_t size) // 控制流stream的缓存.在执行读写及其其他操作之前必须调用该函数 mode：_IOFBF(完全缓存) _IOLBF(对文本文件进行行缓存) _IONBF(不缓存)，出错返回非0值
     *
     * void setbuf(FILE *stream,char *buf)  //buf为NULL，则关闭流stream的缓存，否则setbuf 函数等价于(void) setvbuf(stream,buf,_IOFBF,BUFSIZ)
     *
     *
     * // 格式化输出
     *
     * printf(const *format,...)
     *
     * int fprintf(FILE *stream,const *format,...) //出错返回一个负数
     *
     * int sprintf(char *s,const char *format) //返回实际输出的字符数，不包括'\0'
     *
     * //格式化输入
     *
     * int fscanf(FILE *sream,const char *format) //出错返回EOF ，成功返回输入项的数目
     *
     * int scanf(const char *format,...)
     *
     * int sscanf(const char* s,const char *format)
     *
     *
     * //字符输入/输出函数
     *
     * int fgetc(FILE *stream)  // 返回stream流的下一个字符，返回类型为unsigned char ,否则文件末尾或错误返回EOF
     *
     * char *fgets(char *s,int n,FILE *stream) // 最多将n-1个字符读入数组s中,并返回数组s,否则文件末尾或错误返回NULL
     *
     * int fputc(int c,FILE *stream) // 把字符c输出到stream中，它返回写入的字符，否则返回EOF
     *
     * int fputs(const char *s,FILE *stream) // 把字符串s输出到stream中,否则返回EOF
     *
     * int getc(FILE *stream) 同 fgetc
     *
     * int getchar(void) 等价于 getc(stdin)
     *
     * char *gets(char *s)
     *
     * int putc(int c,FILE *stream)
     *
     * int putchar(int c) //等价于 putc(c,stdout)
     *
     * int puts(const char *s)
     *
     * int ungetc(int c,FILE *stream)
     *
     *
     * //直接输入和输出函数
     *
     * size_t fread(void *ptr,size_t size,size_t nobj,FILE *stream);
     * fread 从流stream中读取最多nobj个长度为size的对象，并保存到ptr指向的数组中。它返回读取的对象数目
     * 此返回值可能小于nobj ,必须通过feof 和ferror 函数获得执行结果
     * size_t fwrite(const void *ptr,size_t size,size_t nobj,FILE *stream);
     * fwrite函数从ptr指向的数组中读取nobj个对象为size的对象，并输出到流stream中，返回输出的对象数目，
     * 如果发生错误，返回值小于nobj的值
     *
     *
     * // 文件定位函数
     *
     * int fseek(FILE *stream,long offset,int origin)
     *  fseek 设置流stream的文件位置，后续的读写操作将从新位置开始。
     *  对于二进制文件，此位置被设置为从origin开始的第offset个字符处. origin 可为 SEEK_SET(文件开始处),SEEK_CUR(当前位置),SEEK_END(文件结束处)
     *  对于文本流，offset必须设置为0或者由ftell函数返回的值(此时origin的值必须是SEEK_SET)
     *  否则出错返回非0值
     *
     *  long ftell(FILE *stream) // 返回stream流的当前文件位置，出错时该函数返回-1L
     *
     *  void rewind(FILE *stream) // 等价于fseek(fp,0L,SEEK_SET);clearerr(fp)的执行结果
     *
     *  int fgetpos(FILE *stream,fpos_t *ptr);
     *  把流stream流的当前位置记录在*ptr中，供随后的fsetpos函数调用，若出错返回一个非0值
     *
     *  int fsetpos(FILE *stream,const fpos_t *ptr)
     *  把流stream的当前位置设置为fgetpos记录在*ptr中的位置。如出错则返回一个非0值
     *
     *  // 错误处理函数
     * 整数表达式errno (在<errno.h>中) 错误编号,据此可以进一步了解最近一次出错的信息
     *
     * void clearerr(FILE *stream)
     * 清除与流stream相关的文件结束符和错误指示符
     *
     * int feof(FILE *stream)
     * 设置了与stream流相关的文件结束指示符，feof函数将符号一个非0值
     *
     * int ferror(FILE *stream)
     * 设置了与stream 流相关的错误指示符，ferror函数将返回一个非0值
     *
     * void perror(const char *s)
     * 打印字符串s及其与errno中整型值相应的错误信息
     *
     *
     *  // 字符类别测试：<ctype.h>
     *
     *  isalnum(c)  isalpha(c)或isdight(c) 为true
     *
     *  isaplha(c)
     *
     *  iscntrl(c)  c为控制符
     *
     *  isdigit(c)  c为十进制数字
     *
     *  isgraph(c)  c是除空格外的可打印字符
     *
     *  islower(c) c是小写字母
     *
     *  isprint(c) c是包括空格的可打印字符
     *
     *  ispunct(c)  是除空格，字母和数字外的可打印字符
     *
     *  isspace(c) 是空格、换页符，换行符，回车符，横向制表符 和纵向制表符
     *
     *  isupper(c) c是大写字母
     *
     *  isxdight(c) c是十六进制数字
     *
     *  tolower(c) 将c转换为小写字母
     *
     *  toupper(c) 将c转换为大写字母
     *
     *  //字符串处理函数 <string.h>
     *  参数s和t 的类型为char *, cs和 ct的类型为const char *  ,n为size_t ,c为int
     *
     *  char *strcpy(s,ct) //将字符串ct复制到字符串s中，并返回s
     *
     *  char *strncpy(s,ct,n) //将字符串ct中最多n个字符复制到字符串s中，并返回s,如果ct中少于n个字符，则用'\0'填充
     *
     *  char *strcat(s,ct) // 将字符串ct连接到s的尾部，并返回到s
     *
     *  char *strncat(s,ct,n) // 将字符串ct中最多n个字符链接到s的尾部，并以'\0'结束，返回s
     *
     *  char *strcmp(cs,ct) // 比较字符串 cs和ct;当cs<ct时，返回一个负数;当cs==ct时候，返回0，当cs>ct时，返回一个正数
     *
     *  char *strncmp(cs,ct,n) //比较字符串cs中至多前n个字符与字符串ct相比较。当cs<ct时，返回一个负数;当cs==ct时，返回0，当cs>ct时，返回一个正数
     *
     *  char *strchr(cs,c) // 返回指向字符c在字符串cs中第一次出现的位置的指针；如果cs中不包含c,则函数返回NULL
     *
     *  char *strrchr(cs,c) // 返回字符c在字符串cs中最后一次出现的位置的指针，如果cs中不包含c,则该函数返回NULL
     *
     *  size_t strspn(cs,ct) //返回字符串cs中的字符的前缀的长度
     *
     *  size_t strcspn(cs,ct) //返回字符串cs中不包含ct中的字符的前缀的长度
     *
     *  char *strpbrk(cs,ct) // 返回一个指针，它指向字符串ct中的任意字符第一次出现在字符串cs中的位置；如果cs中没有与ct相同的字符，则返回NULL
     *
     *  char *strstr(cs,ct) // 返回一个指针，它指向字符串ct中的任意字符第一次出现在字符串cs中的位置；如果cs中没有与ct相同的字符，则返回NULL
     *
     *  size_t *strlen(cs)  //返回字符串cs的长度
     *
     *  char *strerror(n) // 返回一个指针，它指向与错误编号n对应的错误信息字符串
     *
     *  char *strtok(s,ct) // 在s中搜索由ct中的的字符界定的记号
     *
     *
     *   //以mem开头的函数按照字符数组的方式操作对象,其主要目的是提供一个高效的函数接口
     *  void *memcpy(s,ct,n)
     *
     *  void *memmove(s,ct,n)
     *
     *  int memcmp(cs,ct,n)
     *
     *  void *memchr(cs,c,n)
     *
     *  void *memset(s,c,n)
     *
     *
     *  //数学函数 <math.h>
     *  宏EDOM和ERANGE (在<error.h>中有声明)是2个非0整型常量，分别用于指示函数的定义域错误和值域错误
     *
     * 以下请参考手册
     *  sin(x)
     *
     *  cos(x)
     *
     *  tan(x)
     *
     *  asin(x)
     *
     *  acos(x)
     *
     *  atan(x)
     *
     *  atan2(y,x)
     *
     *  sinh(x)
     *
     *  cosh(x)
     *
     *  tanh(x)
     *
     *  exp(x)
     *
     *  log(x)
     *
     *  log10(x)
     *
     *  pow(x,y)
     *
     *  sqrt(x)
     *
     *  ceil(x)
     *
     *  floor(x)
     *
     *  fabs(x)
     *
     *  ldexp(x)
     *
     *  ldexp(x,n)
     *
     *  frexp(x,int *ip)
     *
     *  modf(x,double *p)
     *
     *  fmod(x,y)
     *
     * // <stdlib.h>
     *  具体用法参考手册
     * double atof(const char *s) // strtod(s,(char**)NULL)
     *
     * int atoi(const char *s) // (int)strtol(s,(char**)NULL,10)
     *
     * long atol(const char *s) // (int)strtol(s,(char**)NULL,10)
     *
     * double strtod(const char *s,char **endp)
     *
     * long strtol(const char *s,char **endp,int base)
     *
     * unsigned long strtoul(const char *s,char **endp,int base)
     *
     * int rand(void)
     *
     * void srand(unsigned int seed)
     *
     * void *calloc(size_t nobj,size_t size)
     *
     * void *malloc(size_t size)
     *
     * void *realloc(void *p,size_t size)
     *
     * void free(void *p)
     *
     * void abort() //使程序非正常终止
     *
     * void exit(int status) // 使程序正常终止   EXIT_SUCCESS  和 EXIT_FAILURE
     *
     * int atexit(void (*fcn)(void)) //atexit函数登记函数fcn,该函数在程序正常终止时被调用。如果登记失败，则返回非0值
     *
     * int system(const char *s) // 将字符串s传递给执行环境
     *
     * char *getenv(const char *name)
     *
     * void *bsearch(const void *key,const void *base,size_t n,size_t size,int (*cmp)(const void *keyval,const void *datum))
     *
     * void qsort(void *base,size_t n,size_t size,int(*cmp)(const void *,const void *))
     *
     * int abs(int n)
     *
     * long labs(long n)
     *
     * div_t div(int num,int denom)
     *
     * ldiv_t ldiv(long num,long denom)
     *
     *
     * //诊断 <assert.h>
     *
     * void assert(int expression) //如果表达式的值为0，则assert宏在stderr中打印一条信息。比如：
     * Assertion failed:表达式  ，file源文件名，line行号
     *
     * //可变参数表  <stdarg.h>
     *  va_list ap
     *
     *  va_start(va_list ap,lastarg)
     *
     *  type va_arg(va_list ap,type)
     *
     *  void va_end(va_list ap)
     *
     * //非局部跳转 <setjmp.h>
     *
     *
     * // <signal.h>
     *
     * void (*signal(int sig,void(*handler)(int)))(int)
     *
     *
     *
     * // <time.h>
     *
     *
     *
     *
     *
     *
     *
     */

    const char *message="error message is";
    perror(message);

    printf("this name is %d",strtod("1",NULL));
        int a=3;
        assert(a==3?3:1);
    //--------------------标准库(END)-------------------------------
}








