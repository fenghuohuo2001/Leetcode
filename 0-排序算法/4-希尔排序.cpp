

template<typename T>
void shell_sort(T array[], int length)
{   
    // �����ʼ�ļ�� h
    int h = 1;
    while(h < length / 3)
    {
        h = 3 * h + 1;
    }

    while (h >= 1)
    {
        // ��ÿ�����h���в�������
        for (int i = h; i < length; i++)
        {
            // �������򣬴ӵ�ǰԪ�ؿ�ʼ��ÿ��h��Ԫ�رȽϲ�����
            for (int j = i; j >= h && array[j] < array[j - h]; j -= h)
            {
                std::swap(array[j], array[j - h]);
            }
        }    
        // ��С���
        h = h / 3;
    }
}