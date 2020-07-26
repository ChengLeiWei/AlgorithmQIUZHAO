学习笔记

丑数

没找到C++的堆实现该问题，找的的Python的实现，主要让堆顶不断弹出，弹出至n次就是结果，set中存的是出现过的丑数，因为set中元素都是unique，所以可以让val*factor在set中去重，

```
class Solution(object):
    def nthUglyNumber(self, n):
        """
        :type n: int
        :rtype: int
        """
        heap = [1]
        visited = set([1])
        
        for i in range(n):
            val = heapq.heappop(heap)
            
            for factor in [2,3,5]:
                if val*factor not in visited:
                    heapq.heappush(heap, val*factor)
                    visited.add(val*factor)
        
        
        return val
```
递归：
对于二叉树的递归，使用前中后序递归确实比较容易写出来解决方案，但是只是按照这个样子写出来了，前两天还在疑惑这样照葫芦画瓢递归是能写出来，但是不知道在碰到类似或者换了一种方式的题目时还能否做出来，今天听了超哥的递归的课程，我觉得应该放弃人肉递归的方式，在后面记住二叉树递归的套路。

一个比较重要的理解的点：递归都是默认完成了任务，返回的子任务的期望的结果。