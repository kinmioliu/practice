int binary_search(const vector<int>& arr, int target)
{
    int low = 0, up = arr.size() - 1, mid;
    while (low <= up) {
        mid = (low + up) / 2; // round down
        if (target == arr[mid]) {
            return mid;
        } else if (target > arr[mid]) {
            low = mid + 1;  // had checked mid, so low need plus one
        } else {
            up = mid - 1;
        }
    }
    return -1;
}
