# useful methods in Cpp
* 输出x的二进制数中1的个数
```cpp
cout << __builtin_popcount(x) << '\n';
// 或
int res = 0;
while(x) x -= x & (-x), res++;
cout << res << '\n';
```
