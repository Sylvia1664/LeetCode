#第一百三十二题
##Palindrome Partitioning II
找到最小的切词数量，使得所有的子串都是回文

###版本1
把题目想的太简单，直接使用从左往右遍历以及从右往左遍历，寻找最长的回文子串直接切除。以为这样是可以得到最大结果的，但是忘记考虑了这种情况：

"ggcgba"

这是第27个test中提取出来的关键一部分，原文为："eegiicgaeadbcfacfhifdbiehbgejcaeggcgbahfcajfhjjdgj"。该缩短的词的关键部分是要把gcg切在一起，所以三次切词就可以完成。而使用寻找最长子串的方式会导致gg切在一起。这样次数就变多了。所以该题还是只能使用动态规划来求解。
先暂且贴上原来错误的方法的代码

###版本2
妄想使用上一题的代码，找出了所有的组合后找到最小的组合的办法在最后一个最长的test中超时了