@echo off
echo %1.html
msxsl ../data/reference/%1.xml h-transform.xsl -o reference/%1.html
