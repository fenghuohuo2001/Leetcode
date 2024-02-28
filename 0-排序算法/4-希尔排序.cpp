

template<typename T>
void shell_sort(T array[], int length)
{   
    // 计算初始的间隔 h
    int h = 1;
    while(h < length / 3)
    {
        h = 3 * h + 1;
    }

    while (h >= 1)
    {
        // 对每个间隔h进行插入排序
        for (int i = h; i < length; i++)
        {
            // 插入排序，从当前元素开始，每隔h个元素比较并交换
            for (int j = i; j >= h && array[j] < array[j - h]; j -= h)
            {
                std::swap(array[j], array[j - h]);
            }
        }    
        // 缩小间隔
        h = h / 3;
    }
}