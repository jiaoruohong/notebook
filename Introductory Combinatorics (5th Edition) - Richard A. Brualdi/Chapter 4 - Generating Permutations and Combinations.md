# Chapter 4 - Generating Permutations and Combinations

## 4.1 生成排列

**生成 $\{1,2, \cdots, n\}$ 的排列的算法**  
从 $[\overleftarrow{1},\overleftarrow{2},\cdots,\overleftarrow{n}]$ 开始。  
当存在一个可移动整数时，完成下面事情：  
1. 求出最大的可移动整数 $m$ 。  
2. 交换 $m$ 和它的箭头所指向的与它相邻的整数。  
3. 交换所有满足 $p>m$ 的整数 $p$ 上的箭头的方向。

我们以 $n=4$ 为例给出算法的具体说明。结果用两列显示，第一列给出前12个排列。  
$$\begin{array}{l}[\overleftarrow{1},\overleftarrow{2},\overleftarrow{3},\overleftarrow{4}]\quad[\overrightarrow{4},\overrightarrow{3},\overleftarrow{2},\overleftarrow{1}] \\ [\overleftarrow{1},\overleftarrow{2},\overleftarrow{4},\overleftarrow{3}]\quad[\overrightarrow{3},\overrightarrow{4},\overleftarrow{2},\overleftarrow{1}] \\ [\overleftarrow{1},\overleftarrow{4},\overleftarrow{2},\overleftarrow{3}]\quad[\overrightarrow{3},\overleftarrow{2},\overrightarrow{4},\overleftarrow{1}] \\ [\overleftarrow{4},\overleftarrow{1},\overleftarrow{2},\overleftarrow{3}]\quad[\overrightarrow{3},\overleftarrow{2},\overleftarrow{1},\overrightarrow{4}] \\ [\overrightarrow{4},\overleftarrow{1},\overleftarrow{3},\overleftarrow{2}]\quad[\overleftarrow{2},\overrightarrow{3},\overleftarrow{1},\overleftarrow{4}] \\ [\overleftarrow{1},\overrightarrow{4},\overleftarrow{3},\overleftarrow{2}]\quad[\overleftarrow{2},\overrightarrow{3},\overleftarrow{4},\overleftarrow{1}] \\ [\overleftarrow{1},\overleftarrow{3},\overrightarrow{4},\overleftarrow{2}]\quad[\overleftarrow{2},\overleftarrow{4},\overrightarrow{3},\overleftarrow{1}] \\ [\overleftarrow{1},\overleftarrow{3},\overleftarrow{2},\overrightarrow{4}]\quad[\overleftarrow{4},\overleftarrow{2},\overrightarrow{3},\overleftarrow{1}] \\ [\overleftarrow{3},\overleftarrow{1},\overleftarrow{2},\overleftarrow{4}]\quad[\overrightarrow{4},\overleftarrow{2},\overleftarrow{1},\overrightarrow{3}] \\ [\overleftarrow{3},\overleftarrow{1},\overleftarrow{4},\overleftarrow{2}]\quad[\overleftarrow{2},\overrightarrow{4},\overleftarrow{1},\overrightarrow{3}] \\ [\overleftarrow{3},\overleftarrow{4},\overleftarrow{1},\overleftarrow{2}]\quad[\overleftarrow{2},\overleftarrow{1},\overrightarrow{4},\overrightarrow{3}] \\ [\overleftarrow{4},\overleftarrow{3},\overleftarrow{1},\overleftarrow{2}]\quad[\overleftarrow{2},\overleftarrow{1},\overrightarrow{3},\overrightarrow{4}]\end{array}$$
因为在 $[\overleftarrow{2},\overleftarrow{1},\overrightarrow{3},\overrightarrow{4}]$ 中没有可移动整数，所以算法终止。

## 4.2 排列中的逆序

设 $i_{1} i_{2} \cdots i_{n}$ 是集合 $\{1,2, \cdots, n\}$ 的一个排列。如果 $k<l$ 且 $i_{k}>i_{l}$ ，则称数对 $\left(i_{k}, i_{l}\right)$ 为一个**逆序（inversion）**。

对于一个排列 $i_{1} i_{2} \cdots i_{n}$ ，我们令 $a_{j}$ 表示第二个成分是 $j$ 的逆序的数量。换句话说： $a_{j}$ 等于在排列中在 $j$ 的前面但又大于 $j$ 的整数的个数，它度量 $j$ 的无序程度。

数值序列
$$a_{1}, a_{2}, \cdots, a_{n}$$
叫做排列 $i_{1} i_{2} \cdots i_{n}$ 的逆序列。 $a_{1}+a_{2}+\dots+a_{n}$ 度量一个排列的**无序程度**。

**定理4.2.1** 设 $b_{1}, b_{2}, \cdots, b_{n}$ 是满足下面条件的整数序列：
$$i0 \leqslant b_{1} \leqslant n-1,0 \leqslant b_{2} \leqslant n-2, \cdots, 0 \leqslant b_{m 1} \leqslant 1, b_{n}=0$$
那么，一定存在唯一一个 $i\{1,2, \cdots, n\}$ 的排列，它的逆序列是 $b_{1}, b_{2}, \cdots, b_{n}$ 。

**算法I：从逆序列构建一个排列**
 $n$ ：写出 $n$ 。  
 $n-1$ ：考虑 $b_{n-1}$ 。我们知道 $0 \leqslant b_{n}, \leqslant 1$ 。如果 $b_{n-1}=0$ ，那么 $n-1$ 必须放在 $n$ 的前面。如果 $b_{n-1}=1$ ，那么 $n-1$ 必须放在 $n$ 的后面。  
...
 $$ ：（一般步骤）考虑 $$ 。我们知道 $$ 。在从步骤 $$ 直到步骤 $$ 中， $$ 个数 $$ 都已经按所要求的顺序放好。如果 $$ ，那么 $$ 必须放在由步骤 $$ 得到的所有数的前面。如果 $$ ，那么 $$ 必须放在前两个数之间 $$ 如果 $$ ，那么 $$ 必须放在所有数的后面。  
...
 $$ ：我们必须把 $$ 放在步骤 $$ 所构造的序列的第 $$ 个数的后面。  
执行上述构建算法时，步骤 $$ 唯一确定 $$ 的一个排列，它的逆序列是 $$ 。这个算法的缺点是，排列中每一个整数的位置不到最后是不得而知的；算法执行过程中只做到了这些整数的相对位置保持固定。

在第二个算法中，整数 $$ 在排列中的位置是确定的。

**算法II：从逆序列构建一个排列**
我们从 $$ 个空位置出发，把这些空位置从左到右标注上标签 $$ 。  
 $$ ：因为在这个排列中 $$ 之前应该有 $$ 个整数，因此必须把 $$ 放在位置标签为 $$ 的位置上。
 $$ ：因为在这个排列中应该有 $$ 个整数大于 $$ 且在 $$ 之前，又因为这些整数还没有被插进来，所以必须给这些数留出 $$ 个空位置。因此，把 $$ 放在第 $$ 的空位置上。
...
 $$ ：（一般步骤）因为在这个排列中 $$ 的前面还应该有 $$ 个整数，这些整数还没有被插进来，因此必须给这些数留出 $$ 个空位置。我们看到在本步骤开始时空位置的个数是 $$ 。把 $$ 放在从左边数第 $$ 个空位置上。因为 $$ ，所以有 $$ ，从而可以如此确定一个空位置。
...
 $$ ：把 $$ 放在剩下的一个空位置上。
 
按上面描述的顺序执行步骤 $$ 后，我们得到唯一一个 $$ 的排列，且它的逆序列就是 $$ 。
 
**例子** 确定 $$ 的一个排列，使其逆序列是 $$ 。

对给定的逆序列执行**定理4.2.1**证明中的两个算法的各步骤，产生下列结果：

算法I
$$$$

因此排列为 $$ 。

算法II
$$$$

我们又得到这个排列 $$ 。

如果排列 $$ 有逆序列 $$ 且 $$ 为**逆序数（number of inversion）**，那么可以通过连续 $$ 次交换相邻两个数而把 $$ 转化成 $$ 。首先，我们连续地把 $$ 与它左边的 $$ 个整数交换。然后再连续地把 $$ 与它左边大于 $$ 的整数交换，以此类推。这样就可以经过 $$ 次交换得到 $$ 。

**例子** 通过连续交换相邻的数将排列 $$ 变成 $$ 。

这个排列的逆序列是 $$ 。连续交换的结果是：
$$$$

## 4.3 生成组合

设 $$ 是 $$ 个元素的集合。为了下面分析清楚起见，取 $$ 为下面形式的集合
$$$$
现在，我们寻找一种生成 $$ 的所有 $$ 个组合（子集）的算法。这意味着要找一个将 $$ 的所有子集列出的系统程序。最终的列表应该包含 $$ 的所有子集（并且只有 $$ 的子集）且没有重复。因此，根据**定理2.3.4**，在这个列表中应该有 $$ 个子集。

**生成 $$ 的子集的二进制算法**
从 $$ 开始。
当 $$ 时，执行下面操作：
1. 求出使得 $$ 的最小整数 $$ （在 $$ 和 $$ 之间）。
2. 用 $$ 代替 $$ 并用 $$ 代替 $$ 中的每一个（根据我们对 $$ 的选择可知，在用 $$ 代替以前它们都等于 $$ ）。
当 $$ 时算法结束，它是最终列表中最后一个二进制 $$ 元组。

通过二进制的生成方案所产生的 $$ 的 $$ 元组的顺序称为 $$ 元组的字典序。

** $$ 阶反射Gray码的递归定义如下：**
1.  $$ 阶反射Gray码是 $$ 。
2.  假设 $$ 且已经构建好了 $$ 阶反射Gray码。为了构建 $$ 阶反射Gray码，首先，以 $$ 阶反射Gray码所给出的顺序列出 $$ 的 $$ 元组，并把一个 $$ 添加到每个 $$ 元组的开头（即左边），然后，再以 $$ 阶反射Gray码所给顺序的相反顺序列出 $$ 元组，并把 $$ 添加到各 $$ 元组的开头。

于是，根据这个递归定义， $$ 阶反射Gray码以 $$ 元组 $$ 开始并以 $$ 元组 $$ 结束。由于 $$ 和 $$ 只在一处不同，因此该码是循环的。

**以反射Gray码的顺序生成 $$ 的 $$ 元组的算法**
从 $$ 元组 $$ 开始。
当 $$ 元组 $$ 时，执行下面操作：
1. 计算 $$ 。
2. 如果 $$ 是偶数，则改变 $$ （从 $$ 变到 $$ 或从 $$ 变到 $$ ）。
3. 否则，确定这样的 $$ ，使得 $$ 且对满足 $$ 的所有的 $$ 有 $$ （即这是从右边开始的第一个 $$ ），然后，改变 $$ （从 $$ 变到 $$ 或从 $$ 变到 $$ ）。

注意，如果在步骤3中 $$ ，那么 $$ ，从而 $$ ， $$ 有定义。还要注意，在步骤3中有可能 $$ ，也就是说， $$ ；在这种情形下不存在满足 $$ 的 $$ ，因此我们按步骤3的指示改变 $$ 。

**定理 4.3.1** 对于每一个正整数 $$ ，前面生成 $$ 的 $$ 元组的算法产生 $$ 阶反射Gray码。

## 4.4 生成 $$ 子集

**定理 4.4.1** 设 $$ 是 $$ 的 $$ 子集。在字典序中，第一个 $$ 子集是 $$ 。最后一个 $$ 子集是 $$ 。假设 $$ 。设 $$ 是满足 $$ 且使得 $$ 不等于 $$ 中任一个数的最大整数。那么，在字典序中， $$ 的直接后继 $$ 子集是
$$$$

**按字典序生成 $$ 的 $$ 子集的算法**
从 $$ 子集 $$ 开始。
当 $$ 时，执行下列操作：
1. 确定最大的整数 $$ ，使得 $$ 且 $$ 不是 $$ 中的一个。
2. 用 $$ 子集
$$$$
替换 $$ 。

**定理 4.4.2**  $$ 的 $$ 子集 $$ 出现在 $$ 的 $$ 子集的字典序中的位置下标是：
$$$$

## 4.5 偏序和等价关系

**定理 4.5.1** 设 $$ 是有 $$ 个元素的有限集。则 $$ 上的全序与 $$ 的排列之间存在一一对应。特别地， $$ 上不同全序的个数是 $$ 。

**定理 4.5.2** 设 $$ 是有限偏序集。则 $$ 有线性扩展。

**求偏序集线性扩展的算法**
1. 选出 $$ 中（关于偏序 $$ 的）一个极小元 $$ 。
2. 从 $$ 中删除 $$ ，并从剩下的 $$ 个元素中选择一个极小元 $$ 。
3. 再从 $$ 中删除 $$ ，并从剩下的 $$ 个元素中选择一个极小元 $$ 。
4. 再从 $$ 中删除 $$ ，并从剩下的 $$ 个元素中选择一个极小元 $$ 。
...
n. 从 $$ 中删除 $$ ，恰好留下一个元素 $$ 。

**定理 4.5.3** 设 $$ 是集合 $$ 上的等价关系。于是，不同的等价类把 $$ 划分成若干非空的部分。反之，对于任意把 $$ 分割成非空部分的划分，存在 $$ 上的等价关系，它的等价类就是这个划分的部分。
