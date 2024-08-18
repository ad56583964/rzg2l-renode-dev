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