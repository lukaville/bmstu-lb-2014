#include <vector>

int get_min(std::vector<int> arr) {
    int min = arr[0];

    for(auto el : arr) {
        if (el < min) {
            min = el;
        }
    }

    return min;
}
