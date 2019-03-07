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

5. 最长括号对称的子串:  
已知一串只由左右括号组成的字符串，找到最长的子串，能够符合括号的对应原则。

6. 找到所有备选词组成的所有子串：  
已知一组字符串数组，包含所有备选词（可能会重复）和一个字符串，找到字符串中所有的位置，
满足从该位置开始的一段子串能够由所有备选词拼接而成。

7. 数独求解：  
有一个9x9的方格表，已经填入了一些数组，要求用1-9的数组填满剩下的格子，
使得1-9每个数字在每一行、每一列、每个3x3(共9个)小方格中都出现且只出现一次。

8. 找到最小的丢失整数：  
已知一个未排序的数组，找到最小的没有出现在该数组中的正整数。

9. 蓄水问题
已知一个n个元素的非负数组，每个数表示单位长度上地面的高度，求出下过雨后，这n个单位长度的地面的最大蓄水量。  

10. 通配符匹配  
已知字符串s和p，s只包含a-z，p包含a-z，?和*  
其中? 能匹配任何单一字符(a-z)，* 能匹配任何长度的字符串。判断s和p能否完全匹配。

11. 跳跃游戏  
已知一非负数组，每个数组元素存储的值表示从当前位置所能跳到的最远距离，求最少多少次跳跃能够到达数组最后一个元素。  

12. N王后  
已知正整数N，画出所有N王后问题的解（每一排、一列只有一个王后）。  

13. 插入时间段
已知一个按照开始时间排序好的时间段数组（按照（startTime， endTime）给出），该数组中没有时间段有重叠的部分，
插入一个新的时间段，如果有必要需要可以合并的时间段。

14. 有效的数  
已知一个字符串，判断其是否代表有效数字。（+/-号，e次幂，字符串前一段空格，小数都是有效的）

15. 字符排版  
已知一个字符串数组，和每一行的最大长度，要把每个单词以等间隔地填入每一行，首先要求每一行填入尽量多的单词，
相邻的单词至少相隔一个字符，如果一行内无法等间隔填入单词，则尽量让前面的间隔大（至多只会大一）。
对于最后一行无需填满，只需要间隔一地填入单词即可。

16. 最少编辑次数  
已知两个字符串（word1和word2），求最少的编辑次数能使word1变成word2，每次编辑只能是三种操作之一：
替换某一字符为其他任一字符；插入任一字符；删除一个字符。

# Java:  
1. 手势锁：  
3x3的手势锁，其中某些点被去除，在画手势时可以绕过某些点（可能会导致团一样），但必须是一笔画成，
输入一个3x3的字符串（o表示可以经过，x表示不可以经过），输出所有可能。

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
