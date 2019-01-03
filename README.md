### 程序说明

解析命令行输入的命令并执行。

### 命令格式

    i2c read <0x45>
    i2c write <0x45> <0x33>

### 编译执行

    user@ubuntu:~/work/c-study/Parse-string-command$ gcc -o app main.c && ./app "i2c read 0x45"
    execute i2c read command
    reg    = 0x45(h), 69(d)

    user@ubuntu:~/work/c-study/Parse-string-command$ gcc -o app main.c && ./app "i2c write 0x45 0x33"
    execute i2c write command
    reg    = 0x45(h), 69(d)
    data   = 0x33(h), 51(d)

    # 使用 gcc -D 在编译时刻定义调试宏
    user@ubuntu:~/work/c-study/Parse-string-command$ gcc -o app main.c -DDEBUG && ./app "i2c write 0x45 0x33"
    sizeof(argv[1]) = 19
    argv[1] = i2c write 0x45 0x33
    command = i2c write 0x45 0x33
    cmd[0] = i2c
    cmd[1] = write
    cmd[2] = 0x45
    cmd[3] = 0x33
    execute i2c write command
    reg    = 0x45(h), 69(d)
    data   = 0x33(h), 51(d)

### 修订记录

#### 1. 修正参数异常导致的段错误

修正前效果:

    user@ubuntu:~/work/c-study/Parse-string-command$ gcc -o app main.c -DDEBUG && ./app "i2c write 0x45"
    sizeof(argv[1]) = 14
    argv[1] = i2c write 0x45
    command = i2c write 0x45
    cmd[0] = i2c
    cmd[1] = write
    cmd[2] = 0x45
    段错误 (核心已转储)

修正后效果:

    user@ubuntu:~/work/c-study/Parse-string-command$ gcc -o app main.c -DDEBUG && ./app "i2c write 0x45"
    sizeof(argv[1]) = 14
    argv[1] = i2c write 0x45
    command = i2c write 0x45
    cmd[0] = i2c
    cmd[1] = write
    cmd[2] = 0x45
    err: ptr == NULL, line = 78



