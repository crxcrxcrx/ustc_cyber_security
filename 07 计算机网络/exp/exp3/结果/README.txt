四个源文件里的程序是不完整的，有缺失的地方都用占位符标记了。同学们可以在这个项目的基础上，完成自己的程序。
关于项目的构建过程，参见Makefile。
make使用方法：如果想编译全部程序，在当前文件夹打开终端，执行make命令。如果想只编译tcp或udp的程序，执行make tcp或make udp。make命令执行后会在当前文件夹新建build文件夹，编译生成的程序都在这里，如果想运行程序，以tcp_receiver为例，在终端执行：./build/tcp_receiver。如果想清理所有产生的文件执行make clean。
net_exp.h中提供了一些有用的宏，比如TCP_SERVER_ADDRESS、TCP_SERVER_PORT可以直接使用。
./build/tcp_receiver
./build/tcp_sender
./build/udp_receiver
./build/udp_sender
