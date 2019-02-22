# algorithm problem
一些有趣的算法题，尝试着用不同的语言实现（主要涉及C/C++和Java）

# C/C++:
1. 两个排序好的数列的中位数：  
已知两个排序好的数列，返回两个数列所有元素的中位数。

2. 正则表达式匹配：  
已知两个字符串，检测s2能否匹配正则表达式s1。

3. 合并链表：  
已知k个排序的链表，给出合并成一个链表的结果。  

4. 每隔k个结点翻转链表:
已知一个链表和数字k，将链表每k个结点翻转，最后一段不满k个结点则不翻转。

# Java:  
1. 手势锁：  
3x3的手势锁，其中某些点被去除，在画手势时可以绕过某些点（可能会导致团一样），但必须是一笔画成，
输入一个3x3的字符串（o表示可以经过，x表示不可以经过），输出所有可能的结果。

2. 凑硬币：  
有两种硬币，一种可以无限取，一种最多只能取一次
输入两种银币所有的币值和钱总数，输出总共有多少种可能。

3. 移动格子：  
有4x4的格子，其中15个格子有数字（1-15），剩余一个是空白的，每一次空白格可以和相邻格交换位置，
输入初始的4x4格子的状态和期望达到的状态，输出白色格子移动的路径。

4. 铺墙砖：  
给定一个mxm的方形轴对称且中心对称的图形，设计一种铺设方法铺满nxn的墙面，使铺好的墙面也是轴对称且中心对称的
输入mxm的字符串表示图形和墙面边长n，输出铺好的墙面图案。

5. 最强的队伍：  
有p个队员，每个队员有属性A和B，选取m个队员到A队，n个队员到B队，两队队员不重叠，
求分配方式使得两队的最低属性值（A队只看A属性，B队只看B属性）最高。
输入p,m,n和p个队员的两个属性值，输出分配结果。
