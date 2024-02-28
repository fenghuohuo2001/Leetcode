#include <vector>

//  ±º‰∏¥‘”∂» O(n^2)

template<typename T>
void selection_sort(std::vector<T>& arr)
{
    for(int i=0; i<arr.size(); i++)
        int min = i;
        for(int j= i+1; j<arr.size(); j++)
            if (arr[j]<arr[min])
                min = j;
        std::swap(arr[i], arr[min]);
}