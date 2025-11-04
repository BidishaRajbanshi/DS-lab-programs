int binary_search_desc(int arr[], int low, int high, int key) {
    if (low > high)
	return -1;              // not found

    int mid = low + (high - low) / 2;

    if (arr[mid] == key) return mid;

    // For descending sorted array:
    // if key > arr[mid], search left half (smaller index)
    if (key > arr[mid])
        return binary_search_desc(arr, low, mid - 1, key);
    else
        return binary_search_desc(arr, mid + 1, high, key);
}
