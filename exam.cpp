#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct ResultData
{
    int max_len;
    int start_index;
};

void StartMessage()
{
    system("cls");
    printf("Please select the option to write the array values:\n1 - Auto\n2 - Manual\n\n");
}

int GetMode()
{
    int mode;
    scanf("%d", &mode);
    return mode;
}

void ShowArray(int array[], int array_size)
{
    int i;
    printf("Array:\n");
    for (i = 0; i < array_size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n\n");
}

void SetValues(int array[], int array_size, int mode)
{
    int i;

    if (mode == 1)
    {
        for (i = 0; i < array_size; i++)
        {
            array[i] = rand() % 101;
        }
    }
    if (mode == 2)
    {
        for (i = 0; i < array_size; i++)
        {
            scanf("%d", &array[i]);
        }
    }
}

ResultData GetAns(int array[], int array_size)
{
    int i = 0;
    int start_index = -1;
    int max_len = 0;
    int tmp_index = 0;
    int tmp = array[tmp_index];

    int bef_start_index = start_index;
    int bef_max_len = max_len;

    for (i = 1; i < array_size; i++)
    {
        if (array[i] > tmp)
        {
            max_len++;
            if (start_index == -1)
            {
                start_index = tmp_index;
            }
        }
        else
        {
            if (bef_max_len < max_len)
            {
                bef_start_index = start_index;
                bef_max_len = max_len;
            }

            start_index = -1;
            max_len = 0;
        }
        tmp = array[i];
        tmp_index = i;
    }

    ResultData result;
    result.max_len = bef_max_len;
    result.start_index = bef_start_index;

    return result;
}

int main()
{
    srand(time(NULL));

    const int array_size = 10;
    
    StartMessage();
        
    int mode = GetMode(); // Режим заполнения массива
    int array[array_size];
    // int array[] = { 10, 12, 5, 1, 3, 4, 5, 6, 1, 1 };

    SetValues(array, array_size, mode);
    ShowArray(array, array_size);

    ResultData ans;
    ans = GetAns(array, array_size);
    
    printf("Result:\nMax len - %d\nStart index - %d\n\na", ans.max_len, ans.start_index);

}
