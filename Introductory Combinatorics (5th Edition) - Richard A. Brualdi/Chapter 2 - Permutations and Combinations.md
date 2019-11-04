# Chapter 2 - Permutations and Combinations

## 2.1 四个基本的计数原理

**加法原理** 设集合 $S$ 被划分成两两不相交的部分 $S_{1},S_{2},\cdots,S_{n}$ 。 则 $S$ 的对象数目可以通过确定它的每一个部分的对象数目并如此相加而得到：
$$|S|=|S_{1}|+|S_{2}|+...+|S_{m}|$$

**乘法原理** 令 $S$ 是对象的有序对 $(a,b)$ 的集合，其中第一个对象 $a$ 来自大小为 $p$ 的一个集合，而对于对象 $a$ 的每个选择，对象 $b$ 有 $q$ 种选择。于是， $S$ 的大小为 $p\times q$ :

$$|\mathrm{S}|=p\times q$$

**减法原理** 令 $A$ 是一个集合，而 $U$ 是包含 $A$ 的更大集合。设
$$\bar{A}=U\backslash A=\{x\in U,x\notin A \}$$
是 $A$ 在 $U$ 中的补（complement）。那么 $A$ 中的对象数目 $|A|$ 由下列法则给出：
$$|A|=|U|-|\bar{A}|$$

**除法原理** 令 $S$ 是一个有限集合，把它划分成 $k$ 个部分使得每一部分包含的对象数目相同。于是此划分中的部分数目由下述公式给出：
$$k=\frac{|S|}{\text{number of objects in a part}}$$

## 2.2 集合的排列

**定理 2.2.1** 对于正整数 $n$ 和 $r$ ， $r\leqslant n$ ，有
$$P(n,r)=n\times(n-1)\times\cdots\times(n-r+1)$$

**定理 2.2.2** $n$ 元素集合的循环 $r$ 排列的数目是
$$\frac{P(n,r)}{r}=\frac{n!}{r\cdot(n-r)!}$$
特别地，n个元素的循环排列的数目是 $(n-1)!$ 。

## 2.3 集合的组合（子集）

**定理 2.3.1** 对于 $0\leqslant r\leqslant n$ ，有
$$P(n,r)=r!\left(\begin{array}{l}{n}\\{r}\end{array}\right)$$
因此
$$\left(\begin{array}{l}{n}\\{r}\end{array}\right)=\frac{n!}{r!(n-r)!}$$

**推论 2.3.2** 对于 $0\leqslant r\leqslant n$ ，有
$$\left(\begin{array}{l}{n}\\{r}\end{array}\right)=\left(\begin{array}{c}{n}\\{n-r}\end{array}\right)$$

**定理 2.3.3 （帕斯卡公式）** 对于所有满足 $1\leqslant k\leqslant n-1$ 的整数 $n$ 和 $k$ ，有
$$\left(\begin{array}{l}{n}\\{k}\end{array}\right)=\left(\begin{array}{c}{n-1}\\{k}\end{array}\right)+\left(\begin{array}{c}{n-1}\\{k-1}\end{array}\right)$$

**定理 2.3.4** 对于 $n\geqslant 0$ ，有
$$\left(\begin{array}{l}{n}\\{0}\end{array}\right)+\left(\begin{array}{l}{n}\\{1}\end{array}\right)+\left(\begin{array}{l}{n}\\{2}\end{array}\right)+\dots+\left(\begin{array}{l}{n}\\{n}\end{array}\right)=2^{n}$$
且这个共同值等于 $n$ 元素集合的子集数量。

## 2.4 多重集合的排列

**定理 2.4.1** 设 $$ 是有 $$ 种不同类型对象的多重集合，每一个元素都有无限重复数。那么， $$ 的 $$ 排列的数目是 $$ 。

**定理 2.4.2** 设 $$ 是多重集合，它有 $$ 种不同类型的对象，且每一种类型的有限重复数分别是 $$ 。设 $$ 的大小为 $$ 。则 $$ 的排列数目等于
$$$$

**定理 2.4.3** 设 $$ 是正整数，并设 $$ 是正整数且 $$ 。把 $$ 对象集合划分成 $$ 个标有标签的盒子，且第 $$ 个盒子含有 $$ 个对象，第 $$ 个盒子含有 $$ 个对象， $$ ，第 $$ 个盒子含有 $$ 个对象，这样划分方法数等于
$$$$
如果这些盒子没有标签，且 $$ ，那么划分数等于
$$$$

**定理 2.4.4** 有 $$ 种颜色共 $$ 个车，第 $$ 种颜色有 $$ 个，第 $$ 种颜色有 $$ 个， $$ ，第 $$ 种颜色有 $$ 个。把这些车放置在一个 $$ 的棋盘上使得车之间不能相互攻击的方法数等于
$$$$

## 2.5 多重集合的组合

**定理 2.5.1** 设 $$ 是有 $$ 种类型对象的多重集合，每种元素均有无限的重复数。那么 $$ 的 $$ 组合的个数等于
$$$$

## 2.6 有限概率