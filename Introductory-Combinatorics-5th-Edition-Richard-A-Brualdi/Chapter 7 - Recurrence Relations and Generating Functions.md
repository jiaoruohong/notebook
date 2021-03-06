# Chapter 7 - Recurrence Relations and Generating Functions

## 7.1 若干数列

设
$$$$
表示一个数列。 $$ 叫做数列的**一般项**或**通项**。两类为人熟知的数列为：
- 算术数列，其中的每一项比前一项大一个常数 $$ 
- 几何数列，其中的每一项是前一项的常数 $$ 倍

在这两个例子中，一旦初始项 $$ 和常数 $$ 确定，数列也就唯一确定了：
- （算术数列）$$$$
- （几何数列）$$$$

对于算术数列的情况，我们有这样的法则
$$$$
而通项是
$$$$
对于几何数列的情况，我们有这样的法则
$$$$
而通项是
$$$$

**定理 7.1.1** 斐波那契数满足公式
$$$$

**定理 7.1.2** 在帕斯卡三角形从左下到右上的对角线上的二项式系数的和是斐波那契数。更精确地说，第 $$ 个斐波那契数 $$ 满足
$$$$
其中 $$ 是 $$ 的向下取整。

## 7.2 生成函数

在这一节，我们讨论生成函数的方法，因为它适合于求解计数问题。一方面，可以把生成函数看成是代数对象，其形式上的处理使得人们可以通过代数手段计算一个问题的可能性的数目。另一方面，生成函数是无限可微分函数的泰勒（Taylor）级数（幂级数展开式）。因此，如果能够找到这样一个函数以及它的泰勒级数，那么泰勒级数的系数就给出了问题的解。通常我们默认级数是收敛的且只在其形式上操作幂级数。

设
$$$$
是无穷数列。它的**生成函数（generating function）**定义为无穷级数
$$$$
在 $$ 中， $$ 的系数是式（7.9）的第 $$ 项 $$ ，因此， $$ 充当 $$ 的“占位符”。有限数列可以看成是**无穷数列**
$$$$
在这个数列中，除去有限项外其余项都等于0.因此，每个有限数列都有一个生成函数
$$$$
它是一个多项式。

**定理 7.2.1** 设 $$ 是正整数。这时
$$$$

## 7.3 指数生成函数

在7.2节中，我们利用下面的单项式的集合为数列 $$ 定义了生成函数。
$$$$
这个生成函数特别适合于某些计数数列，特别是那些涉及二项式系数的数列，这是因为它们**具有牛顿二项式定理的形式**。然而，对于某些计数排列的项的数列，**更有效的方法**是考虑关于下面单项式集合的生成函数。
$$$$
这些单项式出现在泰勒级数
$$$$
中。关于单项式集合（7.17）的生成函数称为**指数生成函数**。数列 $$ 的指数生成函数定义为
$$$$

**定理 7.3.1** 设 $$ 是多重集合 $$ ，其中 $$ 是非负整数。设 $$ 是 $$ 的 $$ 排列数。那么数列 $$ 的指数生成函数 $$ 由下式给出：
$$$$
其中，对于 $$ 有
$$$$

## 7.4 求解线性齐次递推关系

本节对于存在一般求解方法的一类递推关系给出其形式定义。然而，这种方法的应用要受到一定的限制，因为可能需要求高阶多项式方程的根。

设
$$$$
是一个数列。称这个数列满足 $$ 阶线性递推关系是指存在量 $$ 和量 $$ （这些量 $$ 都可能依赖于 $$ ），使得
$$$$

**定理 7.4.1** 设 $$ 是一个非零的数。则 $$ 是下面常系数线性齐次递推关系
$$$$
的解当且仅当 $$ 是下面这个多项式方程
$$$$
的根。如果多项式方程有 $$ 个不同的根 $$ ，则
$$$$
在下述意义之下是（7.29）的通解：无论给定什么样的初始值 $$ ，都存在常数 $$ ，使得式（7.31）是满足递推关系（7.29）和初始条件的唯一数列。

多项式方程（7.30）称为递推关系（7.29）的**特征方程（characteristic equation）**，而它的 $$ 个根叫做**特征根（characteristic root）**。根据定理 7.4.1，如果特征根互不相同，那么（7.31）就是（7.29）的通解。

**定理 7.4.2** 设 $$ 为常系数线性齐次递推关系
$$$$
的特征方程的互不相同的根。如果 $$ 是（7.39）的特征方程的 $$ 重根，那么这个递推关系的通解中对应于 $$ 的部分是
$$$$
这个递推关系的通解是
$$$$

**定理 7.4.3** 设
$$$$
是满足
$$$$
的 $$ 阶常系数齐次递推关系的数列，则它的生成函数 $$ 是如下形式的函数
$$$$
其中 $$ 是常数项不等于 $$ 的 $$ 次多项式，而 $$ 是次数小于 $$ 的多项式。反之，给定这样的多项式 $$ ， $$ ，则存在序列 $$ 满足由（7.42）给出的类型的 $$ 阶常系数线性齐次递推关系，且其生成函数是（7.43）给出的函数。

## 7.5 非齐次递推关系

通常情况下，非齐次递推关系更难求解，而且通常需要依赖于其非齐次部分（即（7.22）中的 $$ 项）的一些特殊技巧。

## 7.6 一个几何例子

**定理 7.6.1** 设 $$ 表示用下面方法把凸多边形区域分成三角形区域的方法数：在有 $$ 条边的凸多边形区域内通过插入在其中不相交的对角线而把它分成三角形区域。定义 $$ 。则 $$ 满足递推关系
$$$$
这个递推关系的解是
$$$$
