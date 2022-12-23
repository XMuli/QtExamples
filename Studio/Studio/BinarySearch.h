#pragma once
#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> vec, int target)
{
    int left = 0;
    int right = vec.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (target < vec[mid]) {
            right = mid - 1;
        } else if (target > vec[mid]) {
            left = mid + 1;
        } else {
            return mid;
        }
    }

    return -1;
}

int binarySearch2(vector<int> vec, int target)
{
    int left = 0;
    int right = vec.size();

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (target < vec[mid]) {
            right = mid;
        } else if (target > vec[mid]) {
            left = mid + 1;
        } else {
            return mid;
        }
    }

    return -1;
}


int binarySearch3(vector<int>& vec, int left, int right, int target)
{
    if (left > right)         // target 在数组左右两侧时的场景
        return -1;

    int mid = left + (right - left) / 2;
    if (target < vec[mid]) {
        return binarySearch3(vec, left, mid -1, target);
    } else if (target > vec[mid]) {
        return binarySearch3(vec, mid + 1, right, target);
    } else {
        return mid;
    }
}

// 毒药版-错误百出版本
//int binarySearch4(vector<int> vec, int target)
//{
//    int mid = vec.size() / 2;
//
//    if (target < vec[mid]) {
//        vector<int> t(vec.begin(), vec.begin() + mid);
//        return binarySearch4(t, target);
//    } else if (target > vec[mid]) {
//        vector<int> t(vec.begin() + mid + 1, vec.end());
//        return binarySearch4(t, target);
//    } else {
//        return mid;
//    }
//    return -1;
//}

int main()
{
    vector<int> v = { 0, 3, 5, 6, 7 };
    int target = 8;
    cout << "binarySearch:" << binarySearch(v, target) << endl
        << "binarySearch2:" << binarySearch2(v, target) << endl
        << "binarySearch3:" << binarySearch3(v, 0, v.size() - 1,  target) << endl;

    return 0;
}