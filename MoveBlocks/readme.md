
## （f=g+h）与（f=h），深度优先搜索，广度优先搜索比较  
项目地址：https://github.com/gzhuchy/ArtificialIntelligence.git  

下图的测试结果是由10000组长度为10的测试样例统计而成的。
统计搜索次数：
![Alt text](https://raw.githubusercontent.com/gzhuchy/ArtificialIntelligence/master/MoveBlocks/Photos/2017-10-21%2017-01-51%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png) 
从搜索的次数来看，（f=h）搜索次数最少（712519）,而广搜搜索次数最多，（f=g+h）与深搜几乎接近。

统计的耗散值：
![Alt text](https://raw.githubusercontent.com/gzhuchy/ArtificialIntelligence/master/MoveBlocks/Photos/2017-10-21%2017-01-59%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png) 
其中深搜没有对耗散值进行控制，导致耗散值很大。广搜的扩展没有按照g最小进行顺序扩展，导致比f=g+h略大，而f=h比f=g+h和广搜略大。

