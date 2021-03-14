# Chapter 3 - The Pigeonhole Principle

## 鸽巢原理：简单形式

**定理3.1.1** 如果要把 $n+1$ 个物体放进 $n$ 个盒子，那么至少有一个盒子包含两个或更多的物体。

## 鸽巢原理：加强版

**定理3.2.1** 设 $q_{1}, \quad q_{2}, \quad \cdots, \quad q_{n}$ 是正整数。如果将
$$iq_{1}+q_{2}+\dots+q_{n}-n+1$$
个物体放入 $n$ 个盒子内，那么或者第 $1$ 个盒子至少含有 $q_{1}$ 个物体，或者第 $2$ 个盒子至少含有 $q_{2}$ 个物体， $\cdots$ ，或者第 $n$ 个盒子至少含有 $q_{n}$ 个物体

**推论3.2.2** 设 $n$ 和 $r$ 都是正整数。如果把 $n(r-1)+1$ 个物体分配到 $n$ 个盒子中，那么至少有一个盒子含有 $r$ 个或更多的物体。

可以用另一种方法陈述这一推论中的结论，即**平均原理**：
如果 $n$ 个非负整数 $m_{1}, m_{2}, \cdots, m_{n}$ 的平均数大于 $r-1$ ，即
$$\frac{m_{1}+m_{2}+\cdots+m_{n}}{n}>r-1$$
那么至少有一个整数大于或等于 $r$ 。

## Ramsey定理

**定理3.3.1** 如果 $m \geqslant 2$ 及 $n \geqslant 2$ 是两个整数，则存在正整数 $p$ ，使得
$$K_{p} \rightarrow K_{m}, K_{n}$$

Ramsey定理的一般形式可叙述如下：  
给定整数 $t \geqslant 2$ 及整数 $q_{1}, \quad q_{2}, \quad \cdots, \quad q_{k} \geqslant t$ ，存在一个整数 $p$ ，使得
$$K_{p}^{t} \rightarrow K_{q_{1}}^{t}, K_{q_{2}}^{t}, \cdots, K_{q_{k}}^{t}$$
成立。也就是说，存在一个整数 $p$ ，使得如果给 $p$ 元素集合中的每一个 $t$ 元素子集指定 $k$ 种颜色 $c_{1}, c_{2}, \cdots, c_{k}$ 中的一种，那么或者存在 $q_{1}$ 个元素，这些元素的所有 $t$ 元素子集都被指定为颜色 $c_{1}$ ，或者存在 $q_{2}$ 个元素，这些元素的所有 $t$ 元素子集都被指定为颜色 $c_{2}, \ldots$ ，或者存在 $q_{k}$ 个元素，它的 $t$ 元素子集都被指定为颜色 $c_{k}$ 。这样的整数中最小的整数 $p$ 为Ramsey数
$$r_{t}\left(q_{1}, q_{2}, \cdots, q_{k}\right)$$