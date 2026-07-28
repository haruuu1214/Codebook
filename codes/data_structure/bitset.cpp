#pragma GCC target("popcnt")
// 15 = 1111
bitset <10> bit(15); // 宣告 長度 = 10 的 bitset
cout << bit.count() << "\n"; // 回傳 幾個 1
cout << bit.none() << "\n";  // 回傳是否全為 0
cout << bit.any() << "\n";   // 回傳是否有 1
cout << bit._Find_first() << "\n"; // 回傳 第一個 bit = 1 的位置
int x = 2;
cout << bit._Find_next(x) << "\n"; // 回傳 x 後 第一個 bit = 1 的位置