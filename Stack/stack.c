/*
文件名：stack.c
时间：2016-12-5
编译环境：GCC + Atom(UTF-8)
功能：非负十进制数转八进制。
基本操作：
//栈的初始化
Status InitStack(pSqStack S)
//获取栈顶元素
Status GetTop(pSqStack S,SElemType *e)
//入栈
Status Push(pSqStack S,SElemType e)
//出栈
Status Pop(pSqStack S,SElemType *e)
//判断是否为空栈 若为空栈 返回真
Status StackEmpty(pSqStack S)

知识点：
    1. 右++是在整个运算表达式运算完才进行，而且右++的执行顺序是从左到右进行的。而左++遇到变量就会立即增加变量的值。
    2. 栈的初始化操作为：按照设定的初始分配量进行第一次存储分配，base可称为栈顶指针，在顺序栈中，它始终指向栈底的位置，若base
    的值为NULL，则表明栈结构不存在。
    称top为栈顶指针，其初始值指向栈底，即top==base可记为栈空的标记。每当插入新的栈顶元素时，指针top增1；删除栈顶元素时，指针top减1.
    因此，非空栈中的栈顶指针始终在栈顶元素的下一个位置上。
*/

#include "stack.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int SElemType;

typedef struct{
    SElemType *base;
    SElemType *top;
    int stacksize;
}SqStack,*pSqStack;

#define STACK_INIT_SIZE 100
#define STACKINCREMENT  10

//构建空栈
Status InitStack(pSqStack S)
{
    S->base = (SElemType *)malloc(STACK_INIT_SIZE*sizeof(SqStack));
    if(!S->base)
        return OVERFLOW;
    S->top = S->base;
    S->stacksize = STACK_INIT_SIZE;
    return OK;
}

Status GetTop(pSqStack S,SElemType *e)
{
    if(S->top == S->base)
        return ERROR;   //栈为空
    *e = *(S->top -1);  //非空栈中的栈顶指针始终在栈顶元素的下一个位置 S->top
    return OK;
}

//入栈
Status Push(pSqStack S,SElemType e)
{
    if((S->top - S->base )> S->stacksize)
    {
        S->base = (SElemType *)realloc(S->base,(S->stacksize+STACKINCREMENT)*sizeof(SqStack));
        if(!S->base)
            return OVERFLOW;
        S->top = S->base + S->stacksize;
        S->stacksize += STACKINCREMENT;
    }
    *S->top++ = e;    //*S->top 的地址上保存e 然后S->top 地址增加1
    return OK;
}

//出栈
Status Pop(pSqStack S,SElemType *e)
{
    if(S->top == S->base)
        return ERROR;   //栈为空
    *e = *--S->top;
    return OK;
}

Status StackEmpty(pSqStack S)
{
    if(S->top == S->base)
        return TRUE;
    else
        return ERROR;
}

int main()
{
    pSqStack S;
    int N = 0;
    int e = 0;
    InitStack(S);
    scanf("%d",&N);
    while(N)
    {
        Push(S,N%8);
        N = N/8;
    }
    while(!StackEmpty(S))
    {
        Pop(S,&e);
        printf("%d\n",e);
    }
    return 0;
}
