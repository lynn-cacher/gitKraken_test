#include <iostream>
#include <vector>
#include <stdio.h>

//指针数组
void pointer_array()
{
    //p是一个二维数组，里面存放的数据是一些地址，这些地址里存放的数据是int型
    int a[2][3] = {{1,2,3},{4,5,6}};
    int *p[2];

    for (size_t i = 0; i < 2; i++)
    {
        p[i]=a[i];
    }

    //两个向量和六个数的地址分别是
    {
        printf("int size: %d\n", sizeof(int));
        printf("int pointer size: %d\n", sizeof(int*));
        //4, 8

        for (size_t i = 0; i < 2; i++)
        {
            std::cout << "vector address: " << p + i << " vector content: " << *(p + i)<<std::endl;
        }
        //140752252593088 140752252593072
        //140752252593080 140752252593060
        for (size_t i = 0; i < 2; i++)
        {
            for (size_t j = 0; j < 3; j++)
            {
                std::cout << (*(p+i)+j) << " ";
            }
            std::cout << "\n";
        }
        //140752252593072 140752252593068 140752252593064
        //140752252593060 140752252593056 140752252593052

        /*
        vector address: 0x7ffd8fbe2ed0 vector content: 0x7ffd8fbe2ee0
        vector address: 0x7ffd8fbe2ed8 vector content: 0x7ffd8fbe2eec
        0x7ffd8fbe2ee0 0x7ffd8fbe2ee4 0x7ffd8fbe2ee8 
        0x7ffd8fbe2eec 0x7ffd8fbe2ef0 0x7ffd8fbe2ef4 
        */
    }
    
    //这四个输出的结果是一样的
    /*for (size_t i = 0; i < 2; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            //std::cout << *(p[i]+j) << " ";
            //std::cout << *(*(p+i)+j) << " ";
            //std::cout << (*(p+i))[j] << " ";
            std::cout << p[i][j] << " ";
        }
        std::cout << "\n";
        
    }*/
}


//数组指针
void array_pointer()
{
    //p是一个指针，指向的是一个长度为3的数组，数组的数据是int类型
    int a[2][3] = {{1,2,3},{4,5,6}};
    int (*p)[3];
    p = a;

    //两个向量和六个数的地址分别是
    {

        for (size_t i = 0; i < 2; i++)
        {
            std::cout << "vector address: " << p + i << " vector content: " << *(p + i)<<std::endl;
        }
        for (size_t i = 0; i < 2; i++)
        {
            for (size_t j = 0; j < 3; j++)
            {
                std::cout << (*(p+i)+j) << " ";
            }
            std::cout << "\n";
        }

        /*
        vector address: 0x7ffe023ba630 vector content: 0x7ffe023ba630
        vector address: 0x7ffe023ba63c vector content: 0x7ffe023ba63c
        0x7ffe023ba630 0x7ffe023ba634 0x7ffe023ba638 
        0x7ffe023ba63c 0x7ffe023ba640 0x7ffe023ba644
        */
    }


    //这四个输出的结果都相等
    /*for (size_t i = 0; i < 2; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            std::cout << *(p[i]+j) << " ";
            std::cout << *(*(p+i)+j) << " ";
            std::cout << (*(p+i))[j] << " ";
            std::cout << p[i][j] << " ";
        }
        std::cout << "\n"; 
    }*/


}


int main()
{
    //pointer_array();
    array_pointer();
}




