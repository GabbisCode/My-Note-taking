# Linux命令

打开终端:		Ctrl + alt + t

## 命令提示符

gabbi@ubuntu:~$

gabbi 	:		用户名
@			:		分隔符
ubuntu		: 		主机名
:			:		分隔符
~			:		当前所在路径
					~ : 工作目录 /home/gabbi
$			:		当前权限
					$ : 普通权限
                    			\# : 管理员权限

命令提示符:
告诉用户,后面是 输入 命令
用户在 命令提示符 后面 命令的姿势 :

`命令 [选项] [参数]`

## 账号&密码

当前ubuntu中 有个默认的管理账号: root
	* 给 root 设置 密码

特殊账号: gabbi，是系统安装的时候设置的账号，拥有临时管理员的权限
	如何行使 临时管理员 权利  ---  sudo

设置密码的命令:

`passwd  账号`

给管理员设置密码:

```
sudo  passwd  root
```

e.g.

```
gabbi@ubuntu:$ sudo passwd root
[sudo] password gabbi:
New password:
Retype new password:
passwd: password updated successfully
gabbi@ubuntu:$
```

切换账号的命令 :

`su  切换的账号`
e.g.

```
su root
root@ubuntu:/home/gabbi#
```

## 命令 [选项] [参数]

### pwd

查看当前所在的路径

### ls

查看当前路径下的 文件或者文件夹(目录)
ls -l    	以列表的形式呈现 当前路径下 文件或者文件夹
ls -a    	查看当前路径下 所有的 文件或者文件夹(包含隐藏文件)
					隐藏文件的姿势 ： 名字 以 . 开头
ls -al	 以列表的形式呈现当前路径下 所有的 文件或者文件夹(包含隐藏文件)
ls 目录  	呈现该目录下的 文件或者文件夹

ls -l 查看是目录还是文件

```
drwxr-xr-x 2 gabbi gabbi 4096 12月 12 01:03 Desktop
-rw-rw-r-- 1 gabbi gabbi 0 3月   8 16:53 1.txt
```

看第一个字母：
	如果 是  d , 代表目录
	如果 是  - , 代表文件

### cd

切换目录命令  `cd   (带路径)目录`

`cd ..` 	去到上一级目录
`cd  -`		渠道上一次目录
`cd   `   		直接去到 家目录 (工作目录)  ~

#### 路径分类

相对路径，相对于当前路径来说的路径：

```
gabbi@ubuntu:~$ pwd
/home/gabbi
gabbi@ubuntu:~$ ls
Desktop  Documents  Downloads  Music  Pictures  Public  Templates  Videos
gabbi@ubuntu:~$ cd ./Music			//   ./  可以省略不写
gabbi@ubuntu:~/Music$ pwd
/home/gabbi/Music
gabbi@ubuntu:~/Music$
```

采用相对路径 去到  etc 下面

```
farsight@ubuntu:~/Music/oo$ cd
farsight@ubuntu:~$ cd ../../etc/
farsight@ubuntu:/etc$
```

绝对路径，相对于根目录来说的路径：

```
gabbi@ubuntu:~$ cd /home/gabbi/Music/oo/
gabbi@ubuntu:~/Music/oo$ pwd
/home/gabbi/Music/oo
gabbi@ubuntu:~/Music/oo$
```

采用绝对路径 渠道  sys 下面

```
gabbi@ubuntu:/etc$ cd
gabbi@ubuntu:~$ cd /sys/
gabbi@ubuntu:/sys$
```

### mkdir

创建目录 命令： `mkdir [选项] [参数]`

mkidr  (带路径)目录
mkdir   -p   (带路径)目录   //创建多级目录
mkdir   (带路径)目录1    (带路径)目录2   (带路径)目录3    // 创建多个目录

创建多级目录

```
gabbi@ubuntu:~$ mkdir -p  /home/gabbi/Documents/kk/qq/dd
gabbi@ubuntu:~$ pwd
/home/gabbi
gabbi@ubuntu:~$ cd Documents/
gabbi@ubuntu:~/Documents$ ls
kk
gabbi@ubuntu:~/Documents$ cd kk/
gabbi@ubuntu:~/Documents/kk$ ls
qq
gabbi@ubuntu:~/Documents/kk$ cd qq/
gabbi@ubuntu:~/Documents/kk/qq$ ls
dd
gabbi@ubuntu:~/Documents/kk/qq$ cd dd/
gabbi@ubuntu:~/Documents/kk/qq/dd$ ls
gabbit@ubuntu:~/Documents/kk/qq/dd$ pwd
/home/gabbi/Documents/kk/qq/dd
gabbi@ubuntu:~/Documents/kk/qq/dd$
```

创建多个目录

```
gabbi@ubuntu:~$ cd Pictures/
gabbi@ubuntu:~/Pictures$ pwd
/home/gabbi/Pictures
gabbi@ubuntu:~/Pictures$ ls
gabbi@ubuntu:~/Pictures$ mkdir aa bb cc dd
gabbi@ubuntu:~/Pictures$ ls
aa  bb  cc  dd
gabbi@ubuntu:~/Pictures$
```

### touch

创建文件命令 ：`touch  (带路径)文件`

创建一个 1.txt 文件

```
gabbi@ubuntu:~$ touch Pictures/aa/1.txt
gabbi@ubuntu:~$ cd Pictures
gabbi@ubuntu:~/Pictures$ ls
aa  bb  cc  dd
gabbi@ubuntu:~/Pictures$ cd aa
gabbi@ubuntu:~/Pictures/aa$ ls
1.txt
```

### rm

删除目录 `rm -r`  (路径)目录
-r   ：  目录及目录下的所有资料
-f 	 ：  忽略文件夹不存在的警告

删除 文件 `rm ` (路径)文件

### cp

复制目录 		`cp -rf (路径)源目录  (路径)目标目录`

e.g. 		`cp -rf Music/oo/yy  Pictures/dd`
		如果 dd 目录存在，则将yy复制到dd下面
		如果 dd 不存在，则将yy复制过去重命名为dd

复制文件		 `cp   源文件  目标文件`
e.g.		`cp Music/oo/xx.txt Pictures/mm`
		如果 mm 目录存在，将xx.txt 复制到 mm 下面
		如果 mm 不存在，将 xx.txt 重命名为 mm

### mv

移动		 `mv 源目录/源文件 目标目录 `

e.g.		`mv Music/oo/jj  Pictures/vv`
		如果vv目录存在，则将 jj 剪切到 vv 下面
		如果vv不存在，则将 jj 剪切到 Pictures 下面 重命名为 vv

改名字 e.g.

```
cd Music/oo
mv jj  gg
```

### 其他命令

搜索		`find`
		`grep`
		`locate`

man		`man 1 rm`

清屏		`clear`
