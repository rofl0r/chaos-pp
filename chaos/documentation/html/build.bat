@echo off

msxsl ../data/lookup.xml lookup.xsl -o _lookup.xsl
msxsl ../data/lookup.xml build.xsl -o _build.bat

echo headers.html
msxsl ../data/lookup.xml headers.xsl -o headers.html
echo macros.html
msxsl ../data/lookup.xml macros.xsl -o macros.html

call _build.bat
del _build.bat _lookup.xsl
