<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

<xsl:output method="text" encoding="UTF-8"/>

<xsl:template match="/library">
	echo document: license.html
	msxsl license.xml document.xsl -o $3/license.html library=$1
	<xsl:apply-templates select="binary-file | directory | document | header">
		<xsl:with-param name="path" select="''"/>
	</xsl:apply-templates>
</xsl:template>

<xsl:template match="/library//directory">
	<xsl:param name="path"/>
	<xsl:variable name="new-path" select="concat($path, @name)"/>
	mkdir -p $3/<xsl:value-of select="$new-path"/>
	<xsl:apply-templates select="binary-file | directory | header">
		<xsl:with-param name="path" select="concat($new-path, '/')"/>
	</xsl:apply-templates>
</xsl:template>

<xsl:template match="/library//binary-file">
	<xsl:param name="path"/>
	cp $2/<xsl:value-of select="concat($path, @name)"/> $3/<xsl:value-of select="concat($path, @name)"/>
</xsl:template>

<xsl:template match="/library/document">
	<xsl:param name="path"/>
	echo document: <xsl:value-of select="concat($path, @id)"/>.html
	msxsl $2/<xsl:value-of select="concat($path, @id)"/>.xml document.xsl -o $3/<xsl:value-of select="concat($path, @id)"/>.html library=$1
</xsl:template>

<xsl:template match="/library//header">
	<xsl:param name="path"/>
	<xsl:variable name="sans-suffix" select="concat($path, substring-before(@name, '.'))"/>
	echo <xsl:value-of select="$sans-suffix"/>.html
	msxsl $2/<xsl:value-of select="$sans-suffix"/>.xml .meta.xsl -o .temp.xml
	msxsl .temp.xml header.xsl -o $3/<xsl:value-of select="$sans-suffix"/>.html library=$1
</xsl:template>

<xsl:template match="*" priority="-1">
	<xsl:message terminate="yes">[error: invalid element: <xsl:value-of select="name()"/>]</xsl:message>
</xsl:template>

</xsl:stylesheet>
