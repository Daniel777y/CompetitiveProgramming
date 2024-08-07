/**
 * 常见证明方法:
   * 微扰（邻值交换）
   * 范围缩放
   * 决策包容性
   * 反证法
   * 数学归纳法
**/

// 区间合并问题
// 给定 n 个区间，合并所有有交集的区间，点重合也算有交集，求合并后的区间个数或总长度
sort(seg.begin(), seg.end());
// 求个数
int l = -INF, r = -INF, res = 0;
for (int i = 0; i < n; i++)
  if (seg[i].first > r) {
    res += 1;
    l = seg[i].first;
    r = seg[i].second;
  } else {
    r = max(r, seg[i].second);
  }

// 求长度
int pos = -INF, len = 0;
for (int i = 0; i < n; i++) {
  if (seg[i].second > pos) {
    if (seg[i].first < pos) {
      len += seg[i].second - pos;
    } else {
      len += seg[i].second - seg[i].first;
    }
    pos = seg[i].second;
  }
}

// 线段重叠问题
// 在多个线段中计算最长的重叠区间
int l = -INF, r = -INF, res = -INF;
for (int i = 0; i < n; i++) {
  if (a[i].S > r) {
    res = max(res, r - a[i].F);
    l = a[i].F, r = a[i].S;
  } else {
    res = max(res, a[i].S - a[i].F);
  }
}
printf("%d\n", res);

/**

// 区间部份覆盖
问题：数轴上有 n 个闭区间 [a_i,b_i] ，选择尽量少的区间覆盖一条指定的线段 [s,t]  

策略：

1. 忽略所有和 [s,t] 没有交集的区间
2. 对所有区间以 pair 默认方式排序，维护一个 pos ，初始为 s 
3. 遍历所有区间，在左端点在 pos 之前的所有区间中，选择右端点最大的一个区间，计数，并将 pos 更新为这个区间的右端点
4. 当 pos >= t，就找到答案了，若当前没有区间的左端点在 pos 之前，或者遍历了所有区间 pos 仍然小于 t ，说明无解



// 区间完全覆盖（不是很完善）

问题： 给定一个长度 m ，再给出若干个闭区间，求最少使用多少个闭区间可以将 m 完全覆盖

策略：

1. 对所有区间以 pair 默认方式排序，维护一个 pos ，初始为第一个区间的右端点
2. 遍历所有区间，在所有左端点小于等于 pos 的区间中，选择右端点最大的，直到完全覆盖 m  

**/

// 选择最多不相交区间
// n 个开区间 (a,b) ，选择尽量多个区间
// 使得这些区间两两不相交（一定要注意是左闭右开区间，注意看代码条件）
int res = 0, pos = -INF;
for (int i = 0; i < n; i++) {
	if (a[i].F >= pos) {
    // 注意条件下一个问题的区别
    res ++ ;
    pos = a[i].S;
  }
}

// 区间选点
// 数轴上有 n 个闭区间 [A,B] ，取尽量少的点
// 使得每个区间都至少有一个点
// 如果是开区间的话，将右端点减少 1 再用这个模板即可
int res = 0, pos = -INF;
for (int i = 0; i < n; i++) {
	if (a[i].F > pos) {
    // 注意条件上一个问题的区别
    res ++ ;
    pos = a[i].S;
  }
}
printf("%d\n", res);

// 最大连续子序和（不限制长度）
// 用前缀和
int res = -INF, mina = sum[0];
for (int i = L; i <= n; i++) {
  res = max(res, sum[i] - mina);
  mina = min(mina, sum[i]);
}
printf("%d\n", res);

// 最大连续子序和（限定最小长度）
// 用前缀和
int res = -INF, mina = INF;
for (int i = L; i <= n; i++) {
  mina = min(mina, sum[i - L]);
  res = max(res, sum[i] - mina);
}
printf("%d\n", res);

// 最大连续子序和（限定最大长度）
// 用单调队列
int hh = 0, tt = -1;  // 队头队尾
q[++tt] = 0;
for (int i = 1; i <= n; i ++ ) {
  while (hh <= tt && q[hh] < i - m) {
    hh++;
  }
  res = max(res, sum[i] - sum[q[hh]]);
  while (hh <= tt && sum[q[tt]] >= sum[i]) {
    tt--;
  }
  q[++tt] = i;
}
printf("%d\n", res);
