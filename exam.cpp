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

void ShowArray(int array[], int array_size)
{
    int i;
    for (i = 0; i < array_size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n\n");
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

void ShowAns(ResultData ans)
{
    if (ans.start_index == -1)
    {
        printf("There is no increasing sequence in the array.\n\n");
        printf("=============================================================================\n");
    }
    else if (ans.start_index == 0)
    {
        printf("The sequence is located at the beginning of the array.\n");
        printf("Max len - % d\nStart index - % d\n\n", ans.max_len, ans.start_index);
        printf("=============================================================================\n");
    }
    else if(ans.start_index > 0)
    {
        printf("The sequence is located inside the array.\n");
        printf("Max len - % d\nStart index - % d\n\n", ans.max_len, ans.start_index);
        printf("=============================================================================\n");
    }
}

int main()
{
    srand(time(NULL));

    const int array_size = 10;
        
    int array_one[] = { 25, 20, 14, 26, 65, 131, 148, 4, 1, 1 };
    int array_two[] = { 100, 69, 57, 42, 33, 29, 24, 12, 10, 1 };
    int array_three[] = { 125, 315, 500, 600, 512, 256, 128, 64, 32, 1 };

    ResultData ans;

    ans = GetAns(array_one, array_size);

    printf("Result for ARRAY: ");
    ShowArray(array_one, array_size);
    ShowAns(ans);

    ans = GetAns(array_two, array_size);

    printf("Result for ARRAY: ");
    ShowArray(array_two, array_size);
    ShowAns(ans);

    ans = GetAns(array_three, array_size);

    printf("Result for ARRAY: ");
    ShowArray(array_three, array_size);
    ShowAns(ans);

}
