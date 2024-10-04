尝试使用 Renode 模拟器来体会外设寄存器操作的预先验证，也试着使用它模拟特定外设，看看能不能对开发有些帮助

构建执行文件
```bash
make
```

运行 renode 测试
```bash
cd renode
renode
>> s @./demo.resc
```

开启 tftp

rzg2l uboot 输入命令
```
# uboot 存在 bootelf 命令时
setenv pulltftp 'setenv ipaddr 192.168.5.124; setenv serverip 192.168.5.9; setenv netmask 255.255.255.0; tftp 0x48000000 main.elf'
setenv loadtftp 'loadelf 0x50000000'

```