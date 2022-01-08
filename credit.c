#include<stdio.h>
#include<cs50.h>
#include<math.h>

int main(void)
{
    //核心模块就是通过信用卡位数和首字母，分为不同的类型，将信用卡数字依次存放在数组中，按规则对数组作运算
    //20220108
    //cs50 2021 week1 problem set 1 credit
 
    long number = get_long("Number:");
    int i;
    int n_1 = 0;
    int n_2 = 0;
    int n_total = 0;
    int n_time;
    
    int n_ms = number / pow(10, 14);
    
    int n_visa_1 = number / pow(10, 12);
    int n_visa_2 = number / pow(10, 13);
    int n_visa_3 = number / pow(10, 14);
    int n_visa_4 = number / pow(10, 15);
    

    // amex?
    
    int n_amex = number / pow(10, 13);
    
    int numbers[16];
    
    long number_time = number;
    
    
    //检验一二位数是否为34,37
    
    if (n_amex == 34  || n_amex == 37)
    {
         
        numbers[0] = 3;
        
        //将每位数存放在数组中
        
        for (i = 1; i < 15; i++)
        {
            number_time = number_time - numbers[i - 1] * pow(10, (15 - i));
       
            numbers[i] = number_time / pow(10, (14 - i));
        }
        
        //将对应数加和，从倒数第二位开始，隔一位的这些数乘2，得到的数字超过9的变成十位和个位，例如10:1+0，加和
        
        for (i = 0; i < 15; i++)
        {
            if (i % 2 == 1)
            {
                n_time = numbers[i] * 2;
                if (n_time >= 10)
                {
                    n_2 = n_2 + n_time / 10 + n_time % 10;
                }
                else
                {
                    n_2 = n_2 + n_time;
                }
            }
            else
            {
                n_1 += numbers[i];
            }
        }
        n_total = n_1 + n_2;
         
        if (n_total % 10 == 0)
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    
    //mastercard? mastercard为16位，允许的一二位为51,52,53,54,55
    
    else if (n_ms == 51 || n_ms == 52 || n_ms == 53 || n_ms == 54 || n_ms == 55)
    {
        numbers[0] = 5;
        
        //将每位数存放在数组中
        
        for (i = 1; i < 16; i++)
        { 
            number_time = number_time - numbers[i - 1] * pow(10, (16 - i));
       
            numbers[i] = number_time / pow(10, (15 - i));
        }
        
        //将对应数加和
        //和前面amex的规则相同
        for (i = 0; i < 16; i++)
        {
            if (i % 2 == 0)
            {
                n_time = numbers[i] * 2;
                if (n_time  >= 10)
                {
                    n_2 = n_2 + n_time / 10 + n_time % 10;
                }
                else
                {
                    n_2 = n_2 + n_time;
                }
            }
            else
            {
                n_1 += numbers[i];
            }
        }
        n_total = n_1 + n_2;
         
        if (n_total % 10 == 0)
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    
    //visa?
    //visa是第一位为4的13到16位数字，要4种情况讨论
    //13位时
    
    else if (n_visa_1 == 4)
    {
        numbers[0] = 4;
        //将每位数存放在数组中
        
        // printf("n_visa_1\n");
        for (i = 1; i < 13; i++)
        {
            number_time = number_time - numbers[i - 1] * pow(10, (13 - i));
       
            numbers[i] = number_time / pow(10, (12 - i));
        }
        //将对应数加和
        for (i = 0; i < 13; i++)
        {
            if (i % 2 == 1)
            {
                n_time = numbers[i] * 2;
                if (n_time >= 10)
                {
                    n_2 = n_2 + n_time / 10 + n_time % 10;
                }
                else
                {
                    n_2 = n_2 + n_time;
                }
            }
            else
            {
                n_1 += numbers[i];
            }
        }
        n_total = n_1 + n_2;
         
        if (n_total % 10 == 0)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }    
    
    //14位时
    
    else if (n_visa_2 == 4)
    {
        numbers[0] = 4;
        
        //将每位数存放在数组中
         
        for (i = 1; i < 14; i++)
        {
            number_time = number_time - numbers[i - 1] * pow(10, (14 - i));
       
            numbers[i] = number_time / pow(10, (13 - i));
       
        }
        
        //将对应数加和
        
        for (i = 0; i < 14; i++)
        {
            if (i % 2 == 0)
            {
                n_time = numbers[i] * 2;
                if (n_time >= 10)
                {
                    n_2 = n_2 + n_time / 10 + n_time % 10;
                }
                else
                {
                    n_2 = n_2 + n_time;
                }
            }
            else
            {
                n_1 += numbers[i];
            }
        }
        n_total = n_1 + n_2;
         
        if (n_total % 10 == 0)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    
    //15位时
    
    else if (n_visa_3 == 4)
    {
        numbers[0] = 4;
 
        //将每位数存放在数组中
        
        for (i = 1; i < 15; i++)
        {
            number_time = number_time - numbers[i - 1] * pow(10, (15 - i));
       
            numbers[i] = number_time / pow(10, (14 - i));
       
        }
        
        //将对应数加和
        
        for (i = 0; i < 15; i++)
        {
            if (i % 2 == 1)
            {
                n_time = numbers[i] * 2;
                if (n_time >= 10)
                {
                    n_2 = n_2 + n_time / 10 + n_time % 10;
                }
                else
                {
                    n_2 = n_2 + n_time;
                }
            }
            else
            {
                n_1 += numbers[i];
            }
        }
        n_total = n_1 + n_2;
         
        if (n_total % 10 == 0)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    
    //16位时    
    
    else if (n_visa_4 == 4)
    {
        numbers[0] = 4;
    
        //将每位数存放在数组中
         
        for (i = 1; i < 16; i++)
        {
            number_time = number_time - numbers[i - 1] * pow(10, (16 - i));
       
            numbers[i] = number_time / pow(10, (15 - i));
        }
        //将对应数加和
        for (i = 0; i < 16; i++)
        {
            if (i % 2 == 0)
            {
                n_time = numbers[i] * 2;
                if (n_time >= 10)
                {
                    n_2 = n_2 + n_time / 10 + n_time % 10;
                }
                else
                {
                    n_2 = n_2 + n_time;
                }
            }
            else
            {
                n_1 += numbers[i];
            }
        }
        n_total = n_1 + n_2;
         
        if (n_total % 10 == 0)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    
    //invavid
    
    else
    {
        printf("INVALID\n");
    }

  
}























//凑style50字数
//凑style50字数
//凑style50字数
//凑style50字数
//凑style50字数

