#include <iostream>
#include "uchar.h"
#include "any.h"
#include "byte.h"
using namespace std;
using namespace str;

void quicksort(vector<int>& result, int first, int last)  {
    if (first >= last || first < 0 || last < 0) {
        return;
    }
    int j = first - 1;
    int target = result[last];
    for (int i = first; i < last; ++i) {
        if (result[i] <= target) {
            ++j;
            std::swap(result[i], result[j]);
        }
    }
    ++j;
    std::swap(result[j], result[last]);
    quicksort(result, first, j - 1);
    quicksort(result, j + 1, last);
}

int main()
{
    Byte byte(1);
    string w = u8"几把";
    cout<<w<<endl;
    byte[0] = 1;
    byte[1] = 1;
    cout<<byte;
    return 0;
}

