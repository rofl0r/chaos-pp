@echo off
echo _lookup.xsl
msxsl ../data/lookup.xml lookup.xsl -o _lookup.xsl

echo headers.html
msxsl ../data/lookup.xml headers.xsl -o headers.html

echo macros.html
msxsl ../data/lookup.xml macros.xsl -o macros.html

mkdir reference 2> nul
call process cat
