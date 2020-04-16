title GIT提交批处理


echo 开始提交代码到本地仓库
echo 当前目录是：%cd%

echo 开始pull远程仓库
git pull

echo 开始添加变更
git add -A .
echo 执行结束


echo 提交变更到远程仓库
set /p declation=输入修改:
git commit -m "%declation%"


echo 将变更情况提交到远程git服务器
git push -u origin master
echo http传输可能失败,sendinn-free.124.


echo 批处理执行完毕！

pause