c_thread
========

c 进程间通信 实名通信fifo

在linux 下面直接利用gcc 编译
  gcc  server.c -o server
  gcc  client.c -o client
  
  先运行./server 等待客户进程链接发送数据
  
  然后运行./client连接server ，发送数据 并且接受返回数据。
  
  这个是阻塞式的 通信。
  
  
  
