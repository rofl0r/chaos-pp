<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

<xsl:output method="text" encoding="UTF-8"/>

<xsl:template match="/lookup">
	<xsl:apply-templates select="header"/>
</xsl:template>

<xsl:template match="/lookup/header">
echo <xsl:value-of select="@src"/>.html
del reference\<xsl:value-of select="@src"/>.html 2> nul
msxsl ../data/reference/<xsl:value-of select="@src"/>.xml h-transform.xsl -o reference/<xsl:value-of select="@src"/>.html 2> nul
</xsl:template>

</xsl:stylesheet>
